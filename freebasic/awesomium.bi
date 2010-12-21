''
'' 	  This file is part of Awesomiumc.
''    Copyright (C) 2010  Mario Zechner
''
''    Awesomiumc is free software: you can redistribute it and/or modify
''    it under the terms of the GNU Affero General Public License as published by
''    the Free Software Foundation, either version 3 of the License, or
''    (at your option) any later version.
''
''    Awesomiumc is distributed in the hope that it will be useful,
''    but WITHOUT ANY WARRANTY; without even the implied warranty of
''    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
''    GNU Affero General Public License for more details.
''
''    You should have received a copy of the GNU Affero General Public License
''    along with this program.  If not, see <http://www.gnu.org/licenses/>.
''
#ifndef __awesomiumc_bi__
#define __awesomiumc_bi__

#include once "windows.bi"

#define AWE_LEFT_BUTTON 1
#define AWE_RIGHT_BUTTON 2
#define AWE_MIDDLE_BUTTON 3
#define AWE_TYPE_KEY_DOWN 1
#define AWE_TYPE_KEY_UP 2
#define AWE_TYPE_CHAR 3
#define AWE_MOD_SHIFT_KEY (1 shl 0)
#define AWE_MOD_CONTROL_KEY (1 shl 1)
#define AWE_MOD_ALT_KEY (1 shl 2)
#define AWE_MOD_META_KEY (1 shl 3)
#define AWE_MOD_IS_KEYPAD (1 shl 4)
#define AWE_MOD_IS_AUTOREPEAT (1 shl 5)
#define AWE_CURSOR_POINTER 0
#define AWE_CURSOR_CROSS 1
#define AWE_CURSOR_HAND 2
#define AWE_CURSOR_IBEAM 3
#define AWE_CURSOR_WAIT 4
#define AWE_CURSOR_HELP 5
#define AWE_CURSOR_EAST_RESIZE 6
#define AWE_CURSOR_NORTH_RESIZE 7
#define AWE_CURSOR_NORTH_EAST_RESIZE 8
#define AWE_CURSOR_NORTH_WEST_RESIZE 9
#define AWE_CURSOR_SOUTH_RESIZE 10
#define AWE_CURSOR_SOUTH_EAST_RESIZE 11
#define AWE_CURSOR_SOUTH_WEST_RESIZE 12
#define AWE_CURSOR_WEST_RESIZE 13
#define AWE_CURSOR_NORTH_SOUTH_RESIZE 14
#define AWE_CURSOR_EAST_WEST_RESIZE 15
#define AWE_CURSOR_NORTH_EAST_SOUTH_WEST_RESIZE 16
#define AWE_CURSOR_NORTH_WEST_SOUTH_EAST_RESIZE 17
#define AWE_CURSOR_COLUMN_RESIZE 18
#define AWE_CURSOR_ROW_RESIZE 19
#define AWE_CURSOR_MIDDLE_PANNING 20
#define AWE_CURSOR_EAST_PANNING 21
#define AWE_CURSOR_NORTH_PANNING 22
#define AWE_CURSOR_NORTH_EAST_PANNING 23
#define AWE_CURSOR_NORTH_WEST_PANNING 24
#define AWE_CURSOR_SOUTH_PANNIN 25
#define AWE_CURSOR_SOUTH_EAST_PANNING 26
#define AWE_CURSOR_SOUTH_WEST_PANNING 27
#define AWE_CURSOR_WEST_PANNING 28
#define AWE_CURSOR_MOVE 29
#define AWE_CURSOR_VERTICAL_TEXT 30
#define AWE_CURSOR_CELL 31
#define AWE_CURSOR_CONTEXT_MENU 32
#define AWE_CURSOR_ALIAS 33
#define AWE_CURSOR_PROGRESS 34
#define AWE_CURSOR_NO_DROP 35
#define AWE_CURSOR_COPY 36
#define AWE_CURSOR_NONE 37
#define AWE_CURSOR_NOT_ALLOWED 38
#define AWE_CURSOR_ZOOM_IN 39
#define AWE_CURSOR_ZOOM_OUT 40
#define AWE_CURSOR_CUSTOM 41
#define AWE_UFM_NONE 0
#define AWE_UFM_BLACKLIST 1
#define AWE_UFM_WHITELIST 2
#define AWE_LOG_NONE 0
#define AWE_LOG_NORMAL 1
#define AWE_LOG_VERBOSE 2

type RectC
	x as integer
	y as integer
	width as integer
	height as integer
end type

type WebViewListenerC	
	onBeginNavigation as sub cdecl(byval webView as any ptr, byval url as zstring ptr, byval frameName as wstring ptr) = 0
	onBeginLoading as sub cdecl(byval webView as any ptr, byval url as zstring ptr, byval frameName as wstring ptr, byval statusCode as integer, byval mimeType as wstring ptr) = 0
	onFinishLoading as sub cdecl(byval webView as any ptr) = 0
	onCallback as sub cdecl(byval webView as any ptr, byval objectName as wstring ptr, byval callbackName as wstring ptr, byval args as any ptr) = 0
	onReceiveTitle as sub cdecl(byval webView as any ptr, byval title as wstring ptr, byval frameName as wstring ptr) = 0
	onChangeCursor as sub cdecl(byval webView as any ptr, byval toolTip as wstring ptr) = 0
	onChangeKeyboardFocus as sub cdecl(byval webView as any ptr, byval isFocused as integer) = 0
	onChangeTargetURL as sub cdecl(byval webView as any ptr, byval url as zstring ptr) = 0
	onOpenExternalLink as sub cdecl(byval webView as any ptr, byval url as zstring ptr, byval source as wstring ptr) = 0
	onRequestDownload as sub cdecl(byval webView as any ptr, byval url as zstring ptr) = 0
	onWebViewCrashed as sub cdecl(byval webView as any ptr) = 0
	onPluginCrashed as sub cdecl(byval webView as any ptr, byval pluginName as wstring ptr) = 0
	onRequestMove as sub cdecl(byval webView as any ptr, byval x as integer, byval y as integer) = 0
	onGetPageContents as sub cdecl(byval webView as any ptr, byval url as zstring ptr, byval contents as wstring ptr) = 0
	onDOMReady as sub cdecl(byval webView as any ptr) = 0
end type

type WebKeyboardEventC field = 1
	type as integer
	modifiers as integer
	virtualKeyCode as integer
	nativeKeyCode as integer
	keyIdentifier as ubyte ptr
	text as ushort ptr
	unmodifiedText as ushort ptr
	isSystemKey as integer
end type

extern "C"
declare function awe_WebCore_new cdecl alias "awe_WebCore_new" () as any ptr
declare function awe_WebCore_newWithPlugins cdecl alias "awe_WebCore_newWithPlugins" (byval pluginPath as wstring ptr) as any ptr
declare function awe_WebCore_newFromConfig cdecl alias "awe_WebCore_newFromConfig" (byval enablePlugins as integer, byval enableJavascript as integer, byval userDataPath as wstring ptr, byval pluginPath as wstring ptr, byval logPath as wstring ptr, byval logLevel as integer, byval userAgentOverride as zstring ptr, byval proxyServer as zstring ptr, byval proxyConfig as zstring ptr, byval saveCacheAndCookies as integer, byval maxCacheSize as integer, byval disableSameOriginPolicy as integer, byval customCss as zstring ptr) as any ptr
declare sub awe_WebCore_delete cdecl alias "awe_WebCore_delete" (byval webCore as any ptr)
declare sub awe_WebCore_setBaseDirectory cdecl alias "awe_WebCore_setBaseDirectory" (byval webCore as any ptr, byval baseDirectory as zstring ptr)
declare sub awe_WebCore_setBaseDirectoryW cdecl alias "awe_WebCore_setBaseDirectoryW" (byval webCore as any ptr, byval baseDirectory as wstring ptr)
declare function awe_WebCore_createWebView cdecl alias "awe_WebCore_createWebView" (byval webCore as any ptr, byval width as integer, byval height as integer) as any ptr
declare sub awe_WebCore_setCustomResponsePage cdecl alias "awe_WebCore_setCustomResponsePage" (byval webCore as any ptr, byval statusCode as integer, byval filePath as wstring ptr)
declare sub awe_WebCore_update cdecl alias "awe_WebCore_update" (byval webCore as any ptr)
declare function awe_WebCore_getBaseDirectory cdecl alias "awe_WebCore_getBaseDirectory" (byval webCore as any ptr) as wstring ptr
declare function awe_WebCore_arePluginsEnabled cdecl alias "awe_WebCore_arePluginsEnabled" (byval webCore as any ptr) as integer
declare sub awe_WebCore_clearCache cdecl alias "awe_WebCore_clearCache" (byval webCore as any ptr)
declare sub awe_WebCore_clearCookies cdecl alias "awe_WebCore_clearCookies" (byval webCore as any ptr)
declare function awe_WebCore_setCookie cdecl alias "awe_WebCore_setCookie" (byval webCore as any ptr, byval url as zstring ptr, byval cookieString as zstring ptr, byval isHTTPOnly as integer, byval forceSessionCookie as integer) as integer
declare function awe_WebCore_getCookies cdecl alias "awe_WebCore_getCookies" (byval webCore as any ptr, byval url as zstring ptr, byval excludeHTTPOnly as integer) as zstring ptr
declare sub awe_WebCore_deleteCookie cdecl alias "awe_WebCore_deleteCookie" (byval webCore as any ptr, byval url as zstring ptr, byval cookieName as zstring ptr)

declare sub awe_WebView_destroy cdecl alias "awe_WebView_destroy" (byval webView as any ptr)
declare sub awe_WebView_setListener cdecl alias "awe_WebView_setListener" (byval webView as any ptr, byval webViewListener as WebViewListenerC ptr)
declare function awe_WebView_getListener cdecl alias "awe_WebView_getListener" (byval webView as any ptr) as WebViewListenerC ptr
declare function awe_WebView_getResourceInterceptor cdecl alias "awe_WebView_getResourceInterceptor" (byval webView as any ptr) as any ptr ptr
declare sub awe_WebView_loadURL cdecl alias "awe_WebView_loadURL" (byval webView as any ptr, byval url as zstring ptr, byval frameName as wstring ptr, byval username as zstring ptr, byval password as zstring ptr)
declare sub awe_WebView_loadURLW cdecl alias "awe_WebView_loadURLW" (byval webView as any ptr, byval url as wstring ptr, byval frameName as wstring ptr, byval username as zstring ptr, byval password as zstring ptr)
declare sub awe_WebView_loadHTML cdecl alias "awe_WebView_loadHTML" (byval webView as any ptr, byval html as zstring ptr, byval frameName as wstring ptr)
declare sub awe_WebView_loadHTMLW cdecl alias "awe_WebView_loadHTMLW" (byval webView as any ptr, byval html as wstring ptr, byval frameName as wstring ptr)
declare sub awe_WebView_loadFile cdecl alias "awe_WebView_loadFile" (byval webView as any ptr, byval file as zstring ptr, byval frameName as wstring ptr)
declare sub awe_WebView_goToHistoryOffset cdecl alias "awe_WebView_goToHistoryOffset" (byval webView as any ptr, byval offset as integer)
declare sub awe_WebView_stop cdecl alias "awe_WebView_stop" (byval webView as any ptr)
declare sub awe_WebView_reload cdecl alias "awe_WebView_reload" (byval webView as any ptr)
declare sub awe_WebView_executeJavascript cdecl alias "awe_WebView_executeJavascript" (byval webView as any ptr, byval javascript as zstring ptr, byval frameName as wstring ptr)
declare sub awe_WebView_executeJavascriptW cdecl alias "awe_WebView_executeJavascriptW" (byval webView as any ptr, byval javascript as wstring ptr, byval frameName as wstring ptr)
declare function awe_WebView_executeJavascriptWithResult cdecl alias "awe_WebView_executeJavascriptWithResult" (byval webView as any ptr, byval javascript as zstring ptr, byval frameName as wstring ptr) as any ptr
declare function awe_WebView_executeJavascriptWithResultTimeout cdecl alias "awe_WebView_executeJavascriptWithResultTimeout" (byval webView as any ptr, byval javascript as zstring ptr, byval frameName as wstring ptr, byval timeoutMS as integer) as any ptr
declare function awe_WebView_executeJavascriptWithResultW cdecl alias "awe_WebView_executeJavascriptWithResultW" (byval webView as any ptr, byval javascript as wstring ptr, byval frameName as wstring ptr) as any ptr
declare function awe_WebView_executeJavascriptWithResultTimeoutW cdecl alias "awe_WebView_executeJavascriptWithResultTimeoutW" (byval webView as any ptr, byval javascript as wstring ptr, byval frameName as wstring ptr, byval timeoutMS as integer) as any ptr
declare sub awe_WebView_callJavascriptFunction cdecl alias "awe_WebView_callJavascriptFunction" (byval webView as any ptr, byval object as wstring ptr, byval function as wstring ptr, byval args as any ptr, byval frameName as wstring ptr)
declare sub awe_WebView_createObject cdecl alias "awe_WebView_createObject" (byval webView as any ptr, byval objectName as wstring ptr)
declare sub awe_WebView_destroyObject cdecl alias "awe_WebView_destroyObject" (byval webView as any ptr, byval objectName as wstring ptr)
declare sub awe_WebView_setObjectProperty cdecl alias "awe_WebView_setObjectProperty" (byval webView as any ptr, byval objectName as wstring ptr, byval propName as wstring ptr, byval value as any ptr)
declare sub awe_WebView_setObjectCallback cdecl alias "awe_WebView_setObjectCallback" (byval webView as any ptr, byval objectName as wstring ptr, byval callbackName as wstring ptr)
declare function awe_WebView_isLoadingPage cdecl alias "awe_WebView_isLoadingPage" (byval webView as any ptr) as integer
declare function awe_WebView_isDirty cdecl alias "awe_WebView_isDirty" (byval webView as any ptr) as integer
declare sub awe_WebView_getDirtyBounds cdecl alias "awe_WebView_getDirtyBounds" (byval webView as any ptr, byval rect as RectC ptr)
declare function awe_WebView_render cdecl alias "awe_WebView_render" (byval webView as any ptr) as any ptr
declare sub awe_WebView_pauseRendering cdecl alias "awe_WebView_pauseRendering" (byval webView as any ptr)
declare sub awe_WebView_resumeRendering cdecl alias "awe_WebView_resumeRendering" (byval webView as any ptr)
declare sub awe_WebView_injectMouseMove cdecl alias "awe_WebView_injectMouseMove" (byval webView as any ptr, byval x as integer, byval y as integer)
declare sub awe_WebView_injectMouseDown cdecl alias "awe_WebView_injectMouseDown" (byval webView as any ptr, byval mouseButton as integer)
declare sub awe_WebView_injectMouseUp cdecl alias "awe_WebView_injectMouseUp" (byval webView as any ptr, byval mouseButton as integer)
declare sub awe_WebView_injectMouseWheel cdecl alias "awe_WebView_injectMouseWheel" (byval webView as any ptr, byval scrollAmount as integer)
declare sub awe_WebView_injectKeyboardEvent cdecl alias "awe_WebView_injectKeyboardEvent" (byval webView as any ptr, byval keyboardEvent as WebKeyboardEventC ptr)
declare sub awe_WebView_injectKeyboardEventWindows cdecl alias "awe_WebView_injectKeyboardEventWindows" (byval webView as any ptr, byval msg as integer, byval w as WPARAM, byval l as LPARAM)
declare sub awe_WebView_injectKeyboardEventCharacter cdecl alias "awe_WebView_injectKeyboardEventCharacter" (byval webView as any ptr, byval character as integer)
declare sub awe_WebView_injectKeyboardEventArgs cdecl alias "awe_WebView_injectKeyboardEventArgs"(byval webView as any ptr, byval typ as integer, byval modifiers as integer, byval virtualKeyCode as integer, byval nativeKeyCode as integer, byval keyIdentifier as ubyte ptr, byval text as ushort ptr, byval unmodifiedText as any ptr, byval isSystemKey as integer)
declare sub awe_WebView_cut cdecl alias "awe_WebView_cut" (byval webView as any ptr)
declare sub awe_WebView_copy cdecl alias "awe_WebView_copy" (byval webView as any ptr)
declare sub awe_WebView_paste cdecl alias "awe_WebView_paste" (byval webView as any ptr)
declare sub awe_WebView_selectAll cdecl alias "awe_WebView_selectAll" (byval webView as any ptr)
declare sub awe_WebView_setZoom cdecl alias "awe_WebView_setZoom" (byval webView as any ptr, byval zoomPercent as integer)
declare sub awe_WebView_resetZoom cdecl alias "awe_WebView_resetZoom" (byval webView as any ptr)
declare function awe_WebView_resize cdecl alias "awe_WebView_resize" (byval webView as any ptr, byval width as integer, byval height as integer, byval waitForRepaint as integer, byval repaintTimeoutMS as integer) as integer
declare function awe_WebView_isResizing cdecl alias "awe_WebView_isResizing" (byval webView as any ptr) as integer
declare sub awe_WebView_unfocus cdecl alias "awe_WebView_unfocus" (byval webView as any ptr)
declare sub awe_WebView_focus cdecl alias "awe_WebView_focus" (byval webView as any ptr)
declare sub awe_WebView_setTransparent cdecl alias "awe_WebView_setTransparent" (byval webView as any ptr, byval isTransparent as integer)
declare sub awe_WebView_setURLFilteringMode cdecl alias "awe_WebView_setURLFilteringMode" (byval webView as any ptr, byval mode as integer)
declare sub awe_WebView_addURLFilter cdecl alias "awe_WebView_addURLFilter" (byval webView as any ptr, byval filter as wstring ptr)
declare sub awe_WebView_clearAllURLFilters cdecl alias "awe_WebView_clearAllURLFilters" (byval webView as any ptr)

declare sub awe_getKeyIdentifierFromVirtualKeyCode cdecl alias "awe_getKeyIdentifierFromVirtualKeyCode" (byval keyCode as integer, byval identifier as any ptr)

declare function awe_RenderBuffer_new cdecl alias "awe_RenderBuffer_new" (byval width as integer, byval height as integer) as any ptr
declare function awe_RenderBuffer_newFromBuffer cdecl alias "awe_RenderBuffer_newFromBuffer" (byval buffer as ubyte ptr, byval width as integer, byval height as integer, byval rowSpan as integer, byval autoDeleteBuffer as integer) as any ptr
declare sub awe_RenderBuffer_delete cdecl alias "awe_RenderBuffer_delete" (byval renderBuffer as any ptr)
declare sub awe_RenderBuffer_copyTo cdecl alias "awe_RenderBuffer_copyTo" (byval renderBuffer as any ptr, byval destBuffer as ubyte ptr, byval destRowSpan as integer, byval destDepth as integer, byval convertToRGBA as integer)
declare sub awe_RenderBuffer_saveToPNG cdecl alias "awe_RenderBuffer_saveToPNG" (byval renderBuffer as any ptr, byval filePath as wstring ptr, byval preserveTransparency as integer)
declare sub awe_RenderBuffer_saveToJPEG cdecl alias "awe_RenderBuffer_saveToJPEG" (byval renderBuffer as any ptr, byval filePath as wstring ptr, byval quality as integer)
declare sub awe_RenderBuffer_reserve cdecl alias "awe_RenderBuffer_reserve" (byval renderBuffer as any ptr, byval width as integer, byval height as integer)
declare sub awe_RenderBuffer_copyFrom cdecl alias "awe_RenderBuffer_copyFrom" (byval renderBuffer as any ptr, byval srcBuffer as ubyte ptr, byval srcRowSpan as integer)
declare sub awe_RenderBuffer_copyArea cdecl alias "awe_RenderBuffer_copyArea" (byval renderBuffer as any ptr, byval srcBuffer as ubyte ptr, byval srcRowSpan as integer, byval srcX as integer, byval srcY as integer, byval srcWidth as integer, byval srcHeight as integer, byval forceOpaque as integer)
declare sub awe_RenderBuffer_copyArea2 cdecl alias "awe_RenderBuffer_copyArea2" (byval renderBuffer as any ptr, byval srcBuffer as any ptr, byval srcX as integer, byval srcY as integer, byval srcWidth as integer, byval srcHeight as integer, byval dstX as integer, byval dstY as integer, byval dstWidth as integer, byval dstHeight as integer)
declare sub awe_RenderBuffer_scrollArea cdecl alias "awe_RenderBuffer_scrollArea" (byval renderBufferC as any ptr, byval dx as integer, byval dy as integer, byval clipX as integer, byval clipY as integer, byval clipWidth as integer, byval clipHeight as integer)
declare function awe_RenderBuffer_buffer cdecl alias "awe_RenderBuffer_buffer" (byval renderBuffer as any ptr) as ubyte ptr
declare function awe_RenderBuffer_width cdecl alias "awe_RenderBuffer_width" (byval renderBuffer as any ptr) as integer
declare function awe_RenderBuffer_height cdecl alias "awe_RenderBuffer_height" (byval renderBuffer as any ptr) as integer
declare function awe_RenderBuffer_rowSpan cdecl alias "awe_RenderBuffer_rowSpan" (byval renderBuffer as any ptr) as integer
declare function awe_RenderBuffer_ownsBuffer cdecl alias "awe_RenderBuffer_ownsBuffer" (byval renderBuffer as any ptr) as integer

declare function awe_JSValue_newNull cdecl alias "awe_JSValue_newNull" () as any ptr
declare function awe_JSValue_newBool cdecl alias "awe_JSValue_newBool" (byval value as integer) as any ptr
declare function awe_JSValue_newInt cdecl alias "awe_JSValue_newInt" (byval value as integer) as any ptr
declare function awe_JSValue_newDouble cdecl alias "awe_JSValue_newDouble" (byval value as double) as any ptr
declare function awe_JSValue_newString cdecl alias "awe_JSValue_newString" (byval value as zstring ptr) as any ptr
declare function awe_JSValue_newWString cdecl alias "awe_JSValue_newWString" (byval value as wstring ptr) as any ptr
declare function awe_JSValue_newObject cdecl alias "awe_JSValue_newObject" (byval value as any ptr) as any ptr
declare function awe_JSValue_newArray cdecl alias "awe_JSValue_newArray" (byval value as any ptr) as any ptr
declare sub awe_JSValue_delete cdecl alias "awe_JSValue_delete" (byval val as any ptr)
declare function awe_JSValue_isBoolean cdecl alias "awe_JSValue_isBoolean" (byval val as any ptr) as integer
declare function awe_JSValue_isInteger cdecl alias "awe_JSValue_isInteger" (byval val as any ptr) as integer
declare function awe_JSValue_isDouble cdecl alias "awe_JSValue_isDouble" (byval val as any ptr) as integer
declare function awe_JSValue_isNumber cdecl alias "awe_JSValue_isNumber" (byval val as any ptr) as integer
declare function awe_JSValue_isString cdecl alias "awe_JSValue_isString" (byval val as any ptr) as integer
declare function awe_JSValue_isArray cdecl alias "awe_JSValue_isArray" (byval val as any ptr) as integer
declare function awe_JSValue_isObject cdecl alias "awe_JSValue_isObject" (byval val as any ptr) as integer
declare function awe_JSValue_isNull cdecl alias "awe_JSValue_isNull" (byval val as any ptr) as integer
declare function awe_JSValue_toString cdecl alias "awe_JSValue_toString" (byval val as any ptr) as wstring ptr
declare function awe_JSValue_toInteger cdecl alias "awe_JSValue_toInteger" (byval val as any ptr) as integer
declare function awe_JSValue_toDouble cdecl alias "awe_JSValue_toDouble" (byval val as any ptr) as double
declare function awe_JSValue_toBoolean cdecl alias "awe_JSValue_toBoolean" (byval val as any ptr) as integer
declare function awe_JSValue_getArray cdecl alias "awe_JSValue_getArray" (byval val as any ptr) as any ptr
declare function awe_JSValue_getObject cdecl alias "awe_JSValue_getObject" (byval val as any ptr) as any ptr

declare function awe_Object_new cdecl alias "awe_Object_new" () as any ptr
declare sub awe_Object_delete cdecl alias "awe_Object_delete" (byval obj as any ptr)
declare sub awe_Object_put cdecl alias "awe_Object_put" (byval obj as any ptr, byval key as wstring ptr, byval val as any ptr)
declare function awe_Object_get cdecl alias "awe_Object_get" (byval obj as any ptr, byval key as wstring ptr) as any ptr
declare function awe_Object_contains cdecl alias "awe_Object_contains" (byval obj as any ptr, byval key as wstring ptr) as integer

declare function awe_Array_new cdecl alias "awe_Array_new" () as any ptr
declare sub awe_Array_delete cdecl alias "awe_Array_delete" (byval arr as any ptr)
declare function awe_Array_size cdecl alias "awe_Array_size" (byval arr as any ptr) as integer
declare function awe_Array_get cdecl alias "awe_Array_get" (byval arr as any ptr, byval index as integer) as any ptr
declare sub awe_Array_add cdecl alias "awe_Array_add" (byval arr as any ptr, byval val as any ptr)
declare function awe_JSArguments_new cdecl alias "awe_JSArguments_new" () as any ptr
declare sub awe_JSArguments_delete cdecl alias "awe_JSArguments_delete" (byval args as any ptr)
declare function awe_JSArguments_size cdecl alias "awe_JSArguments_size" (byval args as any ptr) as integer
declare function awe_JSArguments_get cdecl alias "awe_JSArguments_get" (byval args as any ptr, byval index as integer) as any ptr
declare sub awe_JSArguments_add cdecl alias "awe_JSArguments_add" (byval args as any ptr, byval val as any ptr)
end extern

'' AK_BACK (08) BACKSPACE key
#define AWE_AK_BACK &h08

'' AK_TAB (09) TAB key
#define AWE_AK_TAB &h09

'' AK_CLEAR (0C) CLEAR key
#define AWE_AK_CLEAR &h0C

'' AK_RETURN (0D)
#define AWE_AK_RETURN &h0D

'' AK_SHIFT (10) SHIFT key
#define AWE_AK_SHIFT &h10

'' AK_CONTROL (11) CTRL key
#define AWE_AK_CONTROL &h11

'' AK_MENU (12) ALT key
#define AWE_AK_MENU &h12

'' AK_PAUSE (13) PAUSE key
#define AWE_AK_PAUSE &h13

'' AK_CAPITAL (14) CAPS LOCK key
#define AWE_AK_CAPITAL &h14

'' AK_KANA (15) Input Method Editor (IME) Kana mode
#define AWE_AK_KANA &h15

'' AK_HANGUEL (15) IME Hanguel mode (maintained for compatibility; use AK_HANGUL)
'' AK_HANGUL (15) IME Hangul mode
#define AWE_AK_HANGUL &h15

'' AK_JUNJA (17) IME Junja mode
#define AWE_AK_JUNJA &h17

'' AK_FINAL (18) IME final mode
#define AWE_AK_FINAL &h18

'' AK_HANJA (19) IME Hanja mode
#define AWE_AK_HANJA &h19

'' AK_KANJI (19) IME Kanji mode
#define AWE_AK_KANJI &h19

'' AK_ESCAPE (1B) ESC key
#define AWE_AK_ESCAPE &h1B

'' AK_CONVERT (1C) IME convert
#define AWE_AK_CONVERT &h1C

'' AK_NONCONVERT (1D) IME nonconvert
#define AWE_AK_NONCONVERT &h1D

'' AK_ACCEPT (1E) IME accept
#define AWE_AK_ACCEPT &h1E

'' AK_MODECHANGE (1F) IME mode change request
#define AWE_AK_MODECHANGE &h1F

'' AK_SPACE (20) SPACEBAR
#define AWE_AK_SPACE &h20

'' AK_PRIOR (21) PAGE UP key
#define AWE_AK_PRIOR &h21

'' AK_NEXT (22) PAGE DOWN key
#define AWE_AK_NEXT &h22

'' AK_END (23) END key
#define AWE_AK_END &h23

'' AK_HOME (24) HOME key
#define AWE_AK_HOME &h24

'' AK_LEFT (25) LEFT ARROW key
#define AWE_AK_LEFT &h25

'' AK_UP (26) UP ARROW key
#define AWE_AK_UP &h26

'' AK_RIGHT (27) RIGHT ARROW key
#define AWE_AK_RIGHT &h27

'' AK_DOWN (28) DOWN ARROW key
#define AWE_AK_DOWN &h28

'' AK_SELECT (29) SELECT key
#define AWE_AK_SELECT &h29

'' AK_PRINT (2A) PRINT key
#define AWE_AK_PRINT &h2A

'' AK_EXECUTE (2B) EXECUTE key
#define AWE_AK_EXECUTE &h2B

'' AK_SNAPSHOT (2C) PRINT SCREEN key
#define AWE_AK_SNAPSHOT &h2C

'' AK_INSERT (2D) INS key
#define AWE_AK_INSERT &h2D

'' AK_DELETE (2E) DEL key
#define AWE_AK_DELETE &h2E

'' AK_HELP (2F) HELP key
#define AWE_AK_HELP &h2F

'' (30) 0 key
#define AWE_AK_0 &h30

'' (31) 1 key
#define AWE_AK_1 &h31

'' (32) 2 key
#define AWE_AK_2 &h32

'' (33) 3 key
#define AWE_AK_3 &h33

'' (34) 4 key
#define AWE_AK_4 &h34

'' (35) 5 key;
#define AWE_AK_5 &h35

'' (36) 6 key
#define AWE_AK_6 &h36

'' (37) 7 key
#define AWE_AK_7 &h37

'' (38) 8 key
#define AWE_AK_8 &h38

'' (39) 9 key
#define AWE_AK_9 &h39

'' (41) A key
#define AWE_AK_A &h41

'' (42) B key
#define AWE_AK_B &h42

'' (43) C key
#define AWE_AK_C &h43

'' (44) D key
#define AWE_AK_D &h44

'' (45) E key
#define AWE_AK_E &h45

'' (46) F key
#define AWE_AK_F &h46

'' (47) G key
#define AWE_AK_G &h47

'' (48) H key
#define AWE_AK_H &h48

'' (49) I key
#define AWE_AK_I &h49

'' (4A) J key
#define AWE_AK_J &h4A

'' (4B) K key
#define AWE_AK_K &h4B

'' (4C) L key
#define AWE_AK_L &h4C

'' (4D) M key
#define AWE_AK_M &h4D

'' (4E) N key
#define AWE_AK_N &h4E

'' (4F) O key
#define AWE_AK_O &h4F

'' (50) P key
#define AWE_AK_P &h50

'' (51) Q key
#define AWE_AK_Q &h51

'' (52) R key
#define AWE_AK_R &h52

'' (53) S key
#define AWE_AK_S &h53

'' (54) T key
#define AWE_AK_T &h54

'' (55) U key
#define AWE_AK_U &h55

'' (56) V key
#define AWE_AK_V &h56

'' (57) W key
#define AWE_AK_W &h57

'' (58) X key
#define AWE_AK_X &h58

'' (59) Y key
#define AWE_AK_Y &h59

'' (5A) Z key
#define AWE_AK_Z &h5A

'' AK_LWIN (5B) Left Windows key (Microsoft Natural keyboard)
#define AWE_AK_LWIN &h5B

'' AK_RWIN (5C) Right Windows key (Natural keyboard)
#define AWE_AK_RWIN &h5C

'' AK_APPS (5D) Applications key (Natural keyboard)
#define AWE_AK_APPS &h5D

'' AK_SLEEP (5F) Computer Sleep key
#define AWE_AK_SLEEP &h5F

'' AK_NUMPAD0 (60) Numeric keypad 0 key
#define AWE_AK_NUMPAD0 &h60

'' AK_NUMPAD1 (61) Numeric keypad 1 key
#define AWE_AK_NUMPAD1 &h61

'' AK_NUMPAD2 (62) Numeric keypad 2 key
#define AWE_AK_NUMPAD2 &h62

'' AK_NUMPAD3 (63) Numeric keypad 3 key
#define AWE_AK_NUMPAD3 &h63

'' AK_NUMPAD4 (64) Numeric keypad 4 key
#define AWE_AK_NUMPAD4 &h64

'' AK_NUMPAD5 (65) Numeric keypad 5 key
#define AWE_AK_NUMPAD5 &h65

'' AK_NUMPAD6 (66) Numeric keypad 6 key
#define AWE_AK_NUMPAD6 &h66

'' AK_NUMPAD7 (67) Numeric keypad 7 key
#define AWE_AK_NUMPAD7 &h67

'' AK_NUMPAD8 (68) Numeric keypad 8 key
#define AWE_AK_NUMPAD8 &h68

'' AK_NUMPAD9 (69) Numeric keypad 9 key
#define AWE_AK_NUMPAD9 &h69

'' AK_MULTIPLY (6A) Multiply key
#define AWE_AK_MULTIPLY &h6A

'' AK_ADD (6B) Add key
#define AWE_AK_ADD &h6B

'' AK_SEPARATOR (6C) Separator key
#define AWE_AK_SEPARATOR &h6C

'' AK_SUBTRACT (6D) Subtract key
#define AWE_AK_SUBTRACT &h6D

'' AK_DECIMAL (6E) Decimal key
#define AWE_AK_DECIMAL &h6E

'' AK_DIVIDE (6F) Divide key
#define AWE_AK_DIVIDE &h6F

'' AK_F1 (70) F1 key
#define AWE_AK_F1 &h70

'' AK_F2 (71) F2 key
#define AWE_AK_F2 &h71

'' AK_F3 (72) F3 key
#define AWE_AK_F3 &h72

'' AK_F4 (73) F4 key
#define AWE_AK_F4 &h73

'' AK_F5 (74) F5 key
#define AWE_AK_F5 &h74

'' AK_F6 (75) F6 key
#define AWE_AK_F6 &h75

'' AK_F7 (76) F7 key
#define AWE_AK_F7 &h76

'' AK_F8 (77) F8 key
#define AWE_AK_F8 &h77

'' AK_F9 (78) F9 key
#define AWE_AK_F9 &h78

'' AK_F10 (79) F10 key
#define AWE_AK_F10 &h79

'' AK_F11 (7A) F11 key
#define AWE_AK_F11 &h7A

'' AK_F12 (7B) F12 key
#define AWE_AK_F12 &h7B

'' AK_F13 (7C) F13 key
#define AWE_AK_F13 &h7C

'' AK_F14 (7D) F14 key
#define AWE_AK_F14 &h7D

'' AK_F15 (7E) F15 key
#define AWE_AK_F15 &h7E

'' AK_F16 (7F) F16 key
#define AWE_AK_F16 &h7F

'' AK_F17 (80H) F17 key
#define AWE_AK_F17 &h80

'' AK_F18 (81H) F18 key
#define AWE_AK_F18 &h81

'' AK_F19 (82H) F19 key
#define AWE_AK_F19 &h82

'' AK_F20 (83H) F20 key
#define AWE_AK_F20 &h83

'' AK_F21 (84H) F21 key
#define AWE_AK_F21 &h84

'' AK_F22 (85H) F22 key
#define AWE_AK_F22 &h85

'' AK_F23 (86H) F23 key
#define AWE_AK_F23 &h86

'' AK_F24 (87H) F24 key
#define AWE_AK_F24 &h87

'' AK_NUMLOCK (90) NUM LOCK key
#define AWE_AK_NUMLOCK &h90

'' AK_SCROLL (91) SCROLL LOCK key
#define AWE_AK_SCROLL &h91

'' AK_LSHIFT (A0) Left SHIFT key
#define AWE_AK_LSHIFT &hA0

'' AK_RSHIFT (A1) Right SHIFT key
#define AWE_AK_RSHIFT &hA1

'' AK_LCONTROL (A2) Left CONTROL key
#define AWE_AK_LCONTROL &hA2

'' AK_RCONTROL (A3) Right CONTROL key
#define AWE_AK_RCONTROL &hA3

'' AK_LMENU (A4) Left MENU key
#define AWE_AK_LMENU &hA4

'' AK_RMENU (A5) Right MENU key
#define AWE_AK_RMENU &hA5

'' AK_BROWSER_BACK (A6) Windows 2000/XP: Browser Back key
#define AWE_AK_BROWSER_BACK &hA6

'' AK_BROWSER_FORWARD (A7) Windows 2000/XP: Browser Forward key
#define AWE_AK_BROWSER_FORWARD &hA7

'' AK_BROWSER_REFRESH (A8) Windows 2000/XP: Browser Refresh key
#define AWE_AK_BROWSER_REFRESH &hA8

'' AK_BROWSER_STOP (A9) Windows 2000/XP: Browser Stop key
#define AWE_AK_BROWSER_STOP &hA9

'' AK_BROWSER_SEARCH (AA) Windows 2000/XP: Browser Search key
#define AWE_AK_BROWSER_SEARCH &hAA

'' AK_BROWSER_FAVORITES (AB) Windows 2000/XP: Browser Favorites key
#define AWE_AK_BROWSER_FAVORITES &hAB

'' AK_BROWSER_HOME (AC) Windows 2000/XP: Browser Start and Home key
#define AWE_AK_BROWSER_HOME &hAC

'' AK_VOLUME_MUTE (AD) Windows 2000/XP: Volume Mute key
#define AWE_AK_VOLUME_MUTE &hAD

'' AK_VOLUME_DOWN (AE) Windows 2000/XP: Volume Down key
#define AWE_AK_VOLUME_DOWN &hAE

'' AK_VOLUME_UP (AF) Windows 2000/XP: Volume Up key
#define AWE_AK_VOLUME_UP &hAF

'' AK_MEDIA_NEXT_TRACK (B0) Windows 2000/XP: Next Track key
#define AWE_AK_MEDIA_NEXT_TRACK &hB0

'' AK_MEDIA_PREV_TRACK (B1) Windows 2000/XP: Previous Track key
#define AWE_AK_MEDIA_PREV_TRACK &hB1

'' AK_MEDIA_STOP (B2) Windows 2000/XP: Stop Media key
#define AWE_AK_MEDIA_STOP &hB2

'' AK_MEDIA_PLAY_PAUSE (B3) Windows 2000/XP: Play/Pause Media key
#define AWE_AK_MEDIA_PLAY_PAUSE &hB3

'' AK_LAUNCH_MAIL (B4) Windows 2000/XP: Start Mail key
#define AWE_AK_MEDIA_LAUNCH_MAIL &hB4

'' AK_LAUNCH_MEDIA_SELECT (B5) Windows 2000/XP: Select Media key
#define AWE_AK_MEDIA_LAUNCH_MEDIA_SELECT &hB5

'' AK_LAUNCH_APP1 (B6) Windows 2000/XP: Start Application 1 key
#define AWE_AK_MEDIA_LAUNCH_APP1 &hB6

'' AK_LAUNCH_APP2 (B7) Windows 2000/XP: Start Application 2 key
#define AWE_AK_MEDIA_LAUNCH_APP2 &hB7

'' AK_OEM_1 (BA) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ';:' key
#define AWE_AK_OEM_1 &hBA

'' AK_OEM_PLUS (BB) Windows 2000/XP: For any country/region, the '+' key
#define AWE_AK_OEM_PLUS &hBB

'' AK_OEM_COMMA (BC) Windows 2000/XP: For any country/region, the ',' key
#define AWE_AK_OEM_COMMA &hBC

'' AK_OEM_MINUS (BD) Windows 2000/XP: For any country/region, the '-' key
#define AWE_AK_OEM_MINUS &hBD

'' AK_OEM_PERIOD (BE) Windows 2000/XP: For any country/region, the '.' key
#define AWE_AK_OEM_PERIOD &hBE

'' AK_OEM_2 (BF) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '/?' key
#define AWE_AK_OEM_2 &hBF

'' AK_OEM_3 (C0) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '`~' key
#define AWE_AK_OEM_3 &hC0

'' AK_OEM_4 (DB) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '[{' key
#define AWE_AK_OEM_4 &hDB

'' AK_OEM_5 (DC) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '\|' key
#define AWE_AK_OEM_5 &hDC

'' AK_OEM_6 (DD) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ']}' key
#define AWE_AK_OEM_6 &hDD

'' AK_OEM_7 (DE) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the 'single-quote/double-quote' key
#define AWE_AK_OEM_7 &hDE

'' AK_OEM_8 (DF) Used for miscellaneous characters; it can vary by keyboard.
#define AWE_AK_OEM_8 &hDF

'' AK_OEM_102 (E2) Windows 2000/XP: Either the angle bracket key or the backslash key on the RT 102-key keyboard
#define AWE_AK_OEM_102 &hE2

'' AK_PROCESSKEY (E5) Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
#define AWE_AK_PROCESSKEY &hE5

'' AK_PACKET (E7) Windows 2000/XP: Used to pass Unicode characters as if they were keystrokes. The AK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT,SendInput, WM_KEYDOWN, and WM_KEYUP
#define AWE_AK_PACKET &hE7

'' AK_ATTN (F6) Attn key
#define AWE_AK_ATTN &hF6

'' AK_CRSEL (F7) CrSel key
#define AWE_AK_CRSEL &hF7

'' AK_EXSEL (F8) ExSel key
#define AWE_AK_EXSEL &hF8

'' AK_EREOF (F9) Erase EOF key
#define AWE_AK_EREOF &hF9

'' AK_PLAY (FA) Play key
#define AWE_AK_PLAY &hFA

'' AK_ZOOM (FB) Zoom key
#define AWE_AK_ZOOM &hFB

'' AK_NONAME (FC) Reserved for future use
#define AWE_AK_NONAME &hFC

'' AK_PA1 (FD) PA1 key
#define AWE_AK_PA1 &hFD

'' AK_OEM_CLEAR (FE) Clear key
#define AWE_AK_OEM_CLEAR &hFE

#define AWE_AK_UNKNOWN 0;

#endif
