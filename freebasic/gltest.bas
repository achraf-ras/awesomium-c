#include once "awesomium.bi"
#include once "GL/gl.bi"
#include once "GL/glu.bi"
#include once "windows.bi"
#include "fbgfx.bi"
#if __FB_LANG__ = "fb"
Using fb '' constants and structures are stored in the FB namespace in lang fb
#endif

'' some defines
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512

'' some globals cause i'm lazy
dim shared webCore as any ptr
dim shared webView as any ptr
dim shared texture as GLuint

''
'' for logging...
''
sub info(text as string)
	print #1, text
end sub

''
'' sets the projection matrix to ortho makes 
'' the modelview matrix the active matrix and
'' sets the clear color to white
''
sub initGL() 
	glMatrixMode(GL_PROJECTION)
	glLoadIdentity()
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1)
	glMatrixMode(GL_MODELVIEW)
	glLoadIdentity()
	glClearColor(1, 1, 1, 1)
end sub

''
'' inits Awesomium, creates the WebCore
'' and WebView, starts loading the
'' url and focuses the WebView so it
'' receives input events (which we inject manually)
'' Also initializes the keyboard hook
''
sub init(url as string)
	dim renderBuffer as any ptr
	
	'' prepare for console output
	open cons for output as #1
	
	'' initialize OpenGL 
	initGL()

	''  create the awesomium datastructures
	info "creating awesomium datastructures"
	webCore = awe_WebCore_newWithPlugins(".\")
	webView = awe_WebCore_createWebView(webCore, SCREEN_WIDTH, SCREEN_HEIGHT)
	awe_WebView_loadURL(webView, strptr(url), "", "", "")
	awe_WebView_focus(webView)	
	
	info "plugins enabled: " + str(awe_WebCore_arePluginsEnabled(webCore))
	
	'' create the OpenGL texture
	info "creating texture"
	glGenTextures(1, @texture)
	glBindTexture(GL_TEXTURE_2D, texture)	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
	glBindTexture(GL_TEXTURE_2D, 0)	
	
end sub

''
'' disposes any awesomium resources
''
sub dispose() 
	awe_WebView_destroy(webView)
	awe_WebCore_delete(webCore)
end sub

''
'' updates the texture based on the latest content
'' of the WebView
''
sub updateTexture()
	dim renderBuffer as any ptr
	dim pixels as ubyte ptr
	dim w as integer
	dim h as integer
	dim r as integer
	
	renderBuffer = awe_WebView_render(webView)		
	
	if(renderBuffer <> 0) then
		pixels = awe_RenderBuffer_buffer(renderBuffer)
		w = awe_RenderBuffer_width(renderBuffer)
		h = awe_RenderBuffer_height(renderBuffer)
		r = awe_RenderBuffer_rowSpan(renderBuffer)
	
		if(r <> w * 4) then
			info "rowspan != width * 4"
			return
		end if
		
		info "updating texture"
		glBindTexture(GL_TEXTURE_2D, texture)
		glTexImage2D(GL_TEXTURE_2D, 0, 4, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels)
		glBindTexture(GL_TEXTURE_2D, 0)
	end if
end sub

''
'' injects a normal ascii character into the WebView
''
sub injectChar(byval char as uinteger)
	dim text as ushort ptr = callocate(20)
	dim unmodifiedText as ushort ptr = callocate(20)
	dim keyIdentifier as ubyte ptr = callocate(20)
	text[0] = char
	unmodifiedText[0] = char					
	awe_WebView_injectKeyboardEventArgs(webView, AWE_TYPE_CHAR, 0, char, char, keyIdentifier, text, unmodifiedText, 0)	
	
	deallocate(text)
	deallocate(unmodifiedText)
	deallocate(keyIdentifier)	
end sub

sub injectSpecialKey(byval scancode as uinteger) 
	dim text as ushort ptr = callocate(20)
	dim unmodifiedText as ushort ptr = callocate(20)
	dim keyIdentifier as ubyte ptr = callocate(20)
	dim keyCode as uinteger
	
	select case scancode
	case SC_BACKSPACE
		keyCode = AWE_AK_BACK
	case SC_TAB
		keyCode = AWE_AK_TAB	
	case SC_LEFT
		keyCode = AWE_AK_LEFT
	case SC_RIGHT
		keyCode = AWE_AK_RIGHT
	case SC_UP
		keyCode = AWE_AK_UP
	case SC_DOWN
		keyCode = AWE_AK_DOWN
	end select
		
	awe_getKeyIdentifierFromVirtualKeyCode(keyCode, @keyIdentifier)
	awe_WebView_injectKeyboardEventArgs(webView, AWE_TYPE_KEY_DOWN, 0, keyCode, 0, keyIdentifier, text, unmodifiedText, 0)				
	awe_WebView_injectKeyboardEventArgs(webView, AWE_TYPE_KEY_UP, 0, keyCode, 0, keyIdentifier, text, unmodifiedText, 0)				
	
	deallocate(text)
	deallocate(unmodifiedText)
	deallocate(keyIdentifier)	
end sub

''
'' injects mouse and keyboard events into the WebView
''
sub updateInput() 
	dim event as Event
	dim result as integer	
	dim keyEvent as WebKeyboardEventC
	
	if(screenevent(@event)) then
		select case event.type 
			case EVENT_MOUSE_BUTTON_PRESS
				if(event.button = BUTTON_LEFT) then
					awe_WebView_injectMouseDown(webView, AWE_LEFT_BUTTON)
				elseif(event.button = BUTTON_RIGHT) then
					awe_WebView_injectMouseDown(webView, AWE_RIGHT_BUTTON)
				else
					awe_WebView_injectMouseDown(webView, AWE_MIDDLE_BUTTON)
				end if
				
			case EVENT_MOUSE_BUTTON_RELEASE
				if(event.button = BUTTON_LEFT) then
					awe_WebView_injectMouseUp(webView, AWE_LEFT_BUTTON)
				elseif(event.button = BUTTON_RIGHT) then
					awe_WebView_injectMouseUp(webView, AWE_RIGHT_BUTTON)
				else
					awe_WebView_injectMouseUp(webView, AWE_MIDDLE_BUTTON)
				end if
				
			case EVENT_MOUSE_MOVE				
				awe_WebView_injectMouseMove(webView, event.x, event.y)					
				
			case EVENT_KEY_PRESS, EVENT_KEY_REPEAT				
				select case event.scancode
					case SC_BACKSPACE, SC_TAB, SC_LEFT, SC_RIGHT, SC_UP, SC_DOWN
						injectSpecialKey(event.scancode)
					case else
						injectChar(event.ascii)
				end select
		end select
	end if
end sub

''
'' updates awesomium by updating the WebCore and
'' potentially reuploading the texture from the
'' RenderBuffer of the WebView if it is dirty.
'' also injects mouse and keyboard events
''
sub update() 	
	awe_WebCore_update(webCore)	
	if(awe_WebView_isDirty(webView) <> 0) then
		updateTexture()
	end if
	updateInput()
end sub

''
'' clears the screen and renders a full screen quad
'' textured with the last pixel data fetched from awesomium
''
sub render()
	glClear(GL_COLOR_BUFFER_BIT)	
	glEnable(GL_TEXTURE_2D)
	glBindTexture(GL_TEXTURE_2D, texture)
	
	glBegin(GL_QUADS)
		glTexCoord2f(0, 0)
		glVertex2f(0, 0)
		glTexCoord2f(1, 0)
		glVertex2f(SCREEN_WIDTH, 0)
		glTexCoord2f(1, 1)
		glVertex2f(SCREEN_WIDTH, SCREEN_HEIGHT)
		glTexCoord2f(0, 1)
		glVertex2f(0, SCREEN_HEIGHT)
	glEnd()
	
	glBindTexture(GL_TEXTURE_2D, 0)
	glDisable(GL_TEXTURE_2D)
end sub

''
'' main
''
screenres SCREEN_WIDTH, SCREEN_HEIGHT, 32,, &h2
init(command(1))
do	
	update
	render
	flip
	''screensync
loop until multikey(&h01)

dispose()
