/**
	This file is part of Awesomiumc.
    Copyright (C) 2010  Mario Zechner

    Awesomiumc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Awesomiumc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#define EXPORTS
#include "awesomiumc.h"
#include "WebCore.h"
#include <iostream>
#include <string>

using namespace Awesomium;

class WebViewListenerImpl: public WebViewListener {
protected:
	const WebViewListenerC* funcs;
public:

	WebViewListenerImpl(const WebViewListenerC* funcs) {
		this->funcs = funcs;
	}

	virtual ~WebViewListenerImpl() {
	}

	const WebViewListenerC* getFuncs() {
		return funcs;
	}

	void onBeginNavigation(Awesomium::WebView* caller, 
						   const std::string& url, 
						   const std::wstring& frameName) {
		if(funcs->onBeginNavigation)
			funcs->onBeginNavigation(caller, url.c_str(), frameName.c_str());
	}
	
	void onBeginLoading(Awesomium::WebView* caller, 
						const std::string& url, 
						const std::wstring& frameName, 
						int statusCode, 
						const std::wstring& mimeType) {
		if(funcs->onBeginLoading)
			funcs->onBeginLoading(caller, url.c_str(), frameName.c_str(), statusCode, mimeType.c_str());
	}
	
	void onFinishLoading(Awesomium::WebView* caller) {
		if(funcs->onFinishLoading)
			funcs->onFinishLoading(caller);
	}
	
	void onCallback(Awesomium::WebView* caller, 
					const std::wstring& objectName, 
					const std::wstring& callbackName, 
					const Awesomium::JSArguments& args) {
		if(funcs->onCallback)
			funcs->onCallback(caller, objectName.c_str(), callbackName.c_str(), &args);
	}
	
	void onReceiveTitle(Awesomium::WebView* caller, 
						const std::wstring& title,
						const std::wstring& frameName) {
		if(funcs->onReceiveTitle)
			funcs->onReceiveTitle(caller, title.c_str(), frameName.c_str());
	}
	
	void onChangeTooltip(Awesomium::WebView* caller, 
		const std::wstring& tooltip) {
		if(funcs->onChangeTooltip)
			funcs->onChangeTooltip(caller, tooltip.c_str());
	}
	
	void onChangeCursor(Awesomium::WebView* caller, 
		Awesomium::CursorType cursor) {
		if(funcs->onChangeCursor)
			funcs->onChangeCursor(caller, cursor);
	}
	
	void onChangeKeyboardFocus(Awesomium::WebView* caller, 
		bool isFocused) {
		if(funcs->onChangeKeyboardFocus)
			funcs->onChangeKeyboardFocus(caller, isFocused?-1:0);
	}
	
	void onChangeTargetURL(Awesomium::WebView* caller, 
		const std::string& url) {
		if(funcs->onChangeTargetURL)
			funcs->onChangeTargetURL(caller, url.c_str());
	}
	
	void onOpenExternalLink(Awesomium::WebView* caller, 
									const std::string& url, 
									const std::wstring& source) {
		if(funcs->onOpenExternalLink)
			funcs->onOpenExternalLink(caller, url.c_str(), source.c_str());
	}

	void onRequestDownload(Awesomium::WebView* caller,
		const std::string& url) {
		if(funcs->onRequestDownload)
			funcs->onRequestDownload(caller, url.c_str());
	}
	
	void onWebViewCrashed(Awesomium::WebView* caller) {
		if(funcs->onWebViewCrashed)
			funcs->onWebViewCrashed(caller);
	}
			
	void onPluginCrashed(Awesomium::WebView* caller, 
		const std::wstring& pluginName) {
		if(funcs->onPluginCrashed)
			funcs->onPluginCrashed(caller, pluginName.c_str());
	}
			
	void onRequestMove(Awesomium::WebView* caller, 
		int x, int y) {
		if(funcs->onRequestMove)
			funcs->onRequestMove(caller, x, y);
	}
	
	void onGetPageContents(Awesomium::WebView* caller, 
								   const std::string& url, 
								   const std::wstring& contents) {
		if(funcs->onGetPageContents)
			funcs->onGetPageContents(caller, url.c_str(), contents.c_str());
	}
			
	void onDOMReady(Awesomium::WebView* caller) {
		if(funcs->onDOMReady)
			funcs->onDOMReady(caller);
	}
};

/*-----------------------------------------------------------------------------
  WebCore API
-----------------------------------------------------------------------------*/
EXPORT WebCoreC awe_WebCore_new() {
	WebCore* webCore = new WebCore();
	return webCore;
}

EXPORT WebCoreC awe_WebCore_newWithPlugins(const wchar_t* pluginPath) {
	WebCoreConfig config;
	config.setEnablePlugins(true);
	config.setPluginPath(std::wstring(pluginPath));	
	WebCore* webCore = new WebCore(config);
	return webCore;
}

EXPORT void awe_WebCore_delete(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	delete ptr;
}

EXPORT void awe_WebCore_setBaseDirectory(WebCoreC webCore, const char* baseDirectory) {
	WebCore* ptr = static_cast<WebCore*> (webCore);	
	ptr->setBaseDirectory(std::string(baseDirectory));
}

EXPORT void awe_WebCore_setBaseDirectoryW(WebCoreC webCore, const wchar_t* baseDirectory) {
	WebCore* ptr = static_cast<WebCore*> (webCore);	
	ptr->setBaseDirectory(std::wstring(baseDirectory));
}

EXPORT WebViewC awe_WebCore_createWebView(WebCoreC webCore, int width, int height) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	return ptr->createWebView(width, height);	
}

EXPORT void awe_WebCore_setCustomResponsePage(WebCoreC webCore, int statusCode, const wchar_t* filePath) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	ptr->setCustomResponsePage(statusCode, std::wstring(filePath));
}

EXPORT void awe_WebCore_update(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	ptr->update();
}

EXPORT const wchar_t* awe_WebCore_getBaseDirectory(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	const std::wstring& str = ptr->getBaseDirectory();
	return str.c_str();
}

EXPORT int awe_WebCore_arePluginsEnabled(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	return ptr->arePluginsEnabled()?-1:0;
}

EXPORT void awe_WebCore_clearCache(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	ptr->clearCache();
}

EXPORT void awe_WebCore_clearCookies(WebCoreC webCore) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	ptr->clearCookies();
}

EXPORT int awe_WebCore_setCookie(WebCoreC webCore, const char* url, const char* cookieString, int isHTTPOnly, int forceSessionCookie) {
	WebCore* ptr = static_cast<WebCore*> (webCore);
	bool result = ptr->setCookie(std::string(url), std::string(cookieString), isHTTPOnly!=0?true:false, forceSessionCookie!=0?true:false);
	return 0;
}

EXPORT const char* awe_WebCore_getCookies(WebCoreC webCore, const char* url, int excludeHTTPOnly) {
	return 0;
}

/*-----------------------------------------------------------------------------
  WebView API
-----------------------------------------------------------------------------*/
EXPORT void awe_WebView_destroy(WebViewC webView) { 
	WebView* ptr = static_cast<WebView*> (webView);	
	if(ptr->getListener())
		delete ptr->getListener();
	ptr->destroy();
}

EXPORT void awe_WebView_setListener(WebViewC webView, const WebViewListenerC* webViewListener) {
	WebView* ptr = static_cast<WebView*> (webView);
	if(ptr->getListener())
		delete ptr->getListener();
	ptr->setListener(new WebViewListenerImpl(webViewListener));
}

EXPORT WebViewListenerC* awe_WebView_getListener(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	if(ptr->getListener())
		return (WebViewListenerC*)(dynamic_cast<WebViewListenerImpl*>(ptr->getListener())->getFuncs());
	else
		return 0;	
}

EXPORT ResourceInterceptorC* awe_WebView_getResourceInterceptor(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	// FIXME
	return 0;
}

EXPORT void awe_WebView_loadURL(WebViewC webView, const char* url, const wchar_t* frameName, const char* username, const char* password) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->loadURL(std::string(url),std::wstring(frameName), std::string(username), std::string(password));	
}

EXPORT void awe_WebView_loadURLW(WebViewC webView, const wchar_t* url, const wchar_t* frameName, const char* username, const char* password) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->loadURL(std::wstring(url), std::wstring(frameName), std::string(username), std::string(password));
}

EXPORT void awe_WebView_loadHTML(WebViewC webView, const char* html, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->loadHTML(std::string(html), std::wstring(frameName));
}

EXPORT void awe_WebView_loadHTMLW(WebViewC webView, const wchar_t* html, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->loadHTML(std::wstring(html), std::wstring(frameName));
}

EXPORT void awe_WebView_loadFile(WebViewC webView, const char* file, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->loadFile(std::string(file), std::wstring(frameName));
}

EXPORT void awe_WebView_goToHistoryOffset(WebViewC webView, int offset) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->goToHistoryOffset(offset);
}

EXPORT void awe_WebView_stop(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->stop();
}

EXPORT void awe_WebView_reload(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->reload();
}

EXPORT void awe_WebView_executeJavascript(WebViewC webView, const char* javascript, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->executeJavascript(std::string(javascript), std::wstring(frameName));
}

EXPORT void awe_WebView_executeJavascriptW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->executeJavascript(std::wstring(javascript), std::wstring(frameName));
}

EXPORT JSValueC awe_WebView_executeJavascriptWithResult(WebViewC webView, const char* javascript, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	return (JSValueC)&(ptr->executeJavascriptWithResult(std::string(javascript), std::wstring(frameName)).get());
}

EXPORT JSValueC awe_WebView_executeJavascriptWithResultTimeout(WebViewC webView, const char* javascript, const wchar_t* frameName, int timeoutMS) {
	WebView* ptr = static_cast<WebView*> (webView);
	return (JSValueC)&(ptr->executeJavascriptWithResult(std::string(javascript), std::wstring(frameName)).getWithTimeout(timeoutMS));
}

EXPORT JSValueC awe_WebView_executeJavascriptWithResultW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	return (JSValueC)&(ptr->executeJavascriptWithResult(std::wstring(javascript), std::wstring(frameName)).get());
}

EXPORT JSValueC awe_WebView_executeJavascriptWithResultTimeoutW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName, int timeoutMS) {
	WebView* ptr = static_cast<WebView*> (webView);
	return (JSValueC)&(ptr->executeJavascriptWithResult(std::wstring(javascript), std::wstring(frameName)).getWithTimeout(timeoutMS));
}

EXPORT void awe_WebView_callJavascriptFunction(WebViewC webView, const wchar_t* object, const wchar_t* function, JSArgumentsC args, const wchar_t* frameName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->callJavascriptFunction(std::wstring(object), std::wstring(function), *(reinterpret_cast<const JSArguments*> (args)), std::wstring(frameName));
}

EXPORT void awe_WebView_createObject(WebViewC webView, const wchar_t* objectName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->createObject(std::wstring(objectName));
}

EXPORT void awe_WebView_destroyObject(WebViewC webView, const wchar_t* objectName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->destroyObject(std::wstring(objectName));
}

EXPORT void awe_WebView_setObjectProperty(WebViewC webView, const wchar_t* objectName, const wchar_t* propName, JSValueC value) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->setObjectProperty(std::wstring(objectName), std::wstring(propName),  *(reinterpret_cast<const JSValue*> (value)));
}

EXPORT void awe_WebView_setObjectCallback(WebViewC webView, const wchar_t* objectName, const wchar_t* callbackName) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->setObjectCallback(std::wstring(objectName), std::wstring(callbackName));
}

EXPORT int awe_WebView_isLoadingPage(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	return ptr->isLoadingPage()?-1:0;
}

EXPORT int awe_WebView_isDirty(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	return ptr->isDirty()?-1:0;
}

EXPORT void awe_WebView_getDirtyBounds(WebViewC webView, RectC* rect) {
	WebView* ptr = static_cast<WebView*> (webView);
	Rect r = ptr->getDirtyBounds();
	rect->x = r.x;
	rect->y = r.y;
	rect->width = r.width;
	rect->height = r.height;	
}

EXPORT RenderBufferC awe_WebView_render(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);	
	return (RenderBufferC)ptr->render();
}

EXPORT void awe_WebView_pauseRendering(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->pauseRendering();
}

EXPORT void awe_WebView_resumeRendering(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->resumeRendering();
}

EXPORT void awe_WebView_injectMouseMove(WebViewC webView, int x, int y) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->injectMouseMove(x, y);
}

EXPORT void awe_WebView_injectMouseDown(WebViewC webView, int mouseButton) {
	WebView* ptr = static_cast<WebView*> (webView);
	if(mouseButton == AWE_LEFT_BUTTON)
		ptr->injectMouseDown(LEFT_MOUSE_BTN);
	if(mouseButton == AWE_RIGHT_BUTTON)
		ptr->injectMouseDown(RIGHT_MOUSE_BTN);
	if(mouseButton == AWE_MIDDLE_BUTTON)
		ptr->injectMouseDown(MIDDLE_MOUSE_BTN);
}

EXPORT void awe_WebView_injectMouseUp(WebViewC webView, int mouseButton) {
	WebView* ptr = static_cast<WebView*> (webView);
	if(mouseButton == AWE_LEFT_BUTTON)
		ptr->injectMouseUp(LEFT_MOUSE_BTN);
	if(mouseButton == AWE_RIGHT_BUTTON)
		ptr->injectMouseUp(RIGHT_MOUSE_BTN);
	if(mouseButton == AWE_MIDDLE_BUTTON)
		ptr->injectMouseUp(MIDDLE_MOUSE_BTN);
}

EXPORT void awe_WebView_injectMouseWheel(WebViewC webView, int scrollAmount) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->injectMouseWheel(scrollAmount);
}

EXPORT void awe_WebView_injectKeyboardEvent(WebViewC webView, WebKeyboardEventC* keyboardEvent) {
	WebView* ptr = static_cast<WebView*> (webView);
	WebKeyboardEvent kevent;
	kevent.isSystemKey = keyboardEvent->isSystemKey!=0?true:false;
	memcpy(kevent.keyIdentifier, keyboardEvent->keyIdentifier, sizeof(char) * 20);
	kevent.modifiers = keyboardEvent->modifiers;
	kevent.nativeKeyCode = keyboardEvent->nativeKeyCode;
	memcpy(kevent.text, keyboardEvent->text, sizeof(wchar_t)*4);
	switch(keyboardEvent->type) {
		case AWE_TYPE_CHAR: kevent.type = Awesomium::WebKeyboardEvent::TYPE_CHAR; break;
		case AWE_TYPE_KEY_DOWN: kevent.type =  Awesomium::WebKeyboardEvent::TYPE_KEY_DOWN; break;
		case AWE_TYPE_KEY_UP: kevent.type =  Awesomium::WebKeyboardEvent::TYPE_KEY_UP; break;
		default: kevent.type = Awesomium::WebKeyboardEvent::TYPE_KEY_UP;
	}
	memcpy(kevent.unmodifiedText, keyboardEvent->unmodifiedText, sizeof(wchar_t)*4);
	kevent.virtualKeyCode = keyboardEvent->virtualKeyCode;

	printf("%d %d %d\n", kevent.virtualKeyCode, keyboardEvent->text[0], keyboardEvent->unmodifiedText[0]);
	ptr->injectKeyboardEvent(kevent);	
}

EXPORT void awe_WebView_injectKeyboardEventArgs(WebViewC webView, int type, int modifiers, int virtualKeyCode, int nativeKeyCode, char* keyIdentifier, wchar_t* text, wchar_t* unmodifiedText, int isSystemKey) {
	WebView* ptr = static_cast<WebView*> (webView);	
	WebKeyboardEvent kevent;
	switch(type) {
		case AWE_TYPE_CHAR: kevent.type = Awesomium::WebKeyboardEvent::TYPE_CHAR; break;
		case AWE_TYPE_KEY_DOWN: kevent.type =  Awesomium::WebKeyboardEvent::TYPE_KEY_DOWN; break;
		case AWE_TYPE_KEY_UP: kevent.type =  Awesomium::WebKeyboardEvent::TYPE_KEY_UP; break;
		default: kevent.type = Awesomium::WebKeyboardEvent::TYPE_KEY_UP;
	}
	kevent.modifiers = modifiers;
	kevent.virtualKeyCode = virtualKeyCode;
	kevent.nativeKeyCode = nativeKeyCode;
	memcpy(kevent.keyIdentifier, keyIdentifier, 20);
	memcpy(kevent.text, text, sizeof(wchar_t)*4);
	memcpy(kevent.unmodifiedText, unmodifiedText, sizeof(wchar_t)*4);
	kevent.isSystemKey = isSystemKey!=0?true:false;

	ptr->injectKeyboardEvent(kevent);
	printf("%d %d %d %d\n", kevent.virtualKeyCode, kevent.nativeKeyCode, kevent.text[0], kevent.unmodifiedText[0]);
}

EXPORT void awe_WebView_injectKeyboardEventCharacter(WebViewC webView, unsigned int key) {
	WebView* ptr = static_cast<WebView*> (webView);	
	Awesomium::WebKeyboardEvent keyEvent;
	keyEvent.text[0] = key;
	keyEvent.unmodifiedText[0] = key;
	keyEvent.type = Awesomium::WebKeyboardEvent::TYPE_CHAR;
	keyEvent.virtualKeyCode = key;
	keyEvent.nativeKeyCode = key;
	ptr->injectKeyboardEvent(keyEvent);	
}

EXPORT void awe_WebView_injectKeyboardEventWindows(WebViewC webView, int msg, WPARAM wparam, LPARAM lparam) {
	WebView* ptr = static_cast<WebView*> (webView);
	WebKeyboardEvent keyEvent(msg, wparam, lparam);
	ptr->injectKeyboardEvent(keyEvent);
}

EXPORT void awe_WebView_cut(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->cut();
}

EXPORT void awe_WebView_copy(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->copy();
}

EXPORT void awe_WebView_paste(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->paste();
}

EXPORT void awe_WebView_selectAll(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->selectAll();
}

EXPORT void awe_WebView_setZoom(WebViewC webView, int zoomPercent) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->setZoom(zoomPercent);
}

EXPORT void awe_WebView_resetZoom(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->resetZoom();
}

EXPORT int awe_WebView_resize(WebViewC webView, int width, int height, int waitForRepaint, int repaintTimeoutMS) {
	WebView* ptr = static_cast<WebView*> (webView);
	bool result = ptr->resize(width, height, waitForRepaint!=0?true:false, repaintTimeoutMS);
	return result?-1:0;
}

EXPORT int awe_WebView_isResizing(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	return ptr->isResizing()?-1:0;
}

EXPORT void awe_WebView_unfocus(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->unfocus();
}

EXPORT void awe_WebView_focus(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->focus();
}

EXPORT void awe_WebView_setTransparent(WebViewC webView, int isTransparent) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->setTransparent(isTransparent!=0?true:false);
}

EXPORT void awe_WebView_setURLFilteringMode(WebViewC webView, int mode) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->setURLFilteringMode((Awesomium::URLFilteringMode)mode);
}

EXPORT void awe_WebView_addURLFilter(WebViewC webView, const wchar_t* filter) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->addURLFilter(std::wstring(filter));
}

EXPORT void awe_WebView_clearAllURLFilters(WebViewC webView) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->clearAllURLFilters();
}

/*EXPORT void awe_WebView_setHeaderDefinition(WebViewC webView, const char* name, HeaderDefinitionC definition) {
	WebView* ptr = static_cast<WebView*> (webView);
	// FIXME
}

EXPORT void awe_WebView_addHeaderRewriteRule(WebViewC webView, const wchar_t* rule, const char* name) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->addHeaderRewriteRule(std::wstring(rule), std::string(name));
}

EXPORT void awe_WebView_removeHeaderRewriteRule(WebViewC webView, const wchar_t* rule) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->removeHeaderRewriteRule(std::wstring(rule));
}

EXPORT void awe_WebView_removeHeaderRewriteRulesByDefinitionName(WebViewC webView, const char* name) {
	WebView* ptr = static_cast<WebView*> (webView);
	ptr->removeHeaderRewriteRulesByDefinitionName(std::string(name));
}*/

/*-----------------------------------------------------------------------------
  RenderBuffer API
-----------------------------------------------------------------------------*/
EXPORT RenderBufferC awe_RenderBuffer_new(int width, int height) {
	RenderBuffer* renderBuffer = new RenderBuffer(width, height);
	return renderBuffer;
}

EXPORT RenderBufferC awe_RenderBuffer_newFromBuffer(unsigned char* buffer, int width, int height, int rowSpan, int autoDeleteBuffer) {
	RenderBuffer* renderBuffer = new RenderBuffer(buffer, width, height, rowSpan, autoDeleteBuffer!=0?true:false);
	return renderBuffer;
}

EXPORT void awe_RenderBuffer_delete(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	delete ptr;
}

EXPORT void awe_RenderBuffer_copyTo(RenderBufferC renderBuffer, unsigned char* destBuffer, int destRowSpan, int destDepth, int convertToRGBA) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	ptr->copyTo(destBuffer, destRowSpan, destDepth, convertToRGBA!=0?true:false);
}

EXPORT void awe_RenderBuffer_saveToPNG(RenderBufferC renderBuffer, const wchar_t* filePath, int preserveTransparency) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	ptr->saveToPNG(std::wstring(filePath), preserveTransparency!=0?true:false);
}

EXPORT void awe_RenderBuffer_saveToJPEG(RenderBufferC renderBuffer, const wchar_t* filePath, int quality) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	ptr->saveToJPEG(std::wstring(filePath), quality);
}

EXPORT void awe_RenderBuffer_reserve(RenderBufferC renderBuffer, int width, int height) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	ptr->reserve(width, height);
}

EXPORT void awe_RenderBuffer_copyFrom(RenderBufferC renderBuffer, unsigned char* srcBuffer, int srcRowSpan) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	ptr->copyFrom(srcBuffer, srcRowSpan);
}

EXPORT void awe_RenderBuffer_copyArea(RenderBufferC renderBuffer, unsigned char* srcBuffer, int srcRowSpan, int srcX, int srcY, int srcWidth, int srcHeight, int forceOpaque) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	Rect srcRect(srcX, srcY, srcWidth, srcHeight);	
	ptr->copyArea(srcBuffer, srcRowSpan, srcRect, forceOpaque!=0?true:false);
}

EXPORT void awe_RenderBuffer_copyArea2(RenderBufferC renderBuffer, RenderBufferC srcBuffer, int srcX, int srcY, int srcWidth, int srcHeight, int dstX, int dstY, int dstWidth, int dstHeight) {
	RenderBuffer* ptr = static_cast<RenderBuffer*> (renderBuffer);
	RenderBuffer* srcPtr = static_cast<RenderBuffer*> (srcBuffer);
	Rect srcRect(srcX, srcY, srcWidth, srcHeight);
	Rect dstRect(dstX, dstY, dstWidth, dstHeight);
	ptr->copyArea(*srcPtr, srcRect, dstRect);
}

EXPORT void awe_RenderBuffer_scrollArea(RenderBufferC renderBuffer, int dx, int dy, int clipX, int clipY, int clipWidth, int clipHeight) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	Rect clip(clipX, clipY, clipWidth, clipHeight);
	ptr->scrollArea(dx, dy, clip);
}

EXPORT unsigned char* awe_RenderBuffer_buffer(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	return ptr->buffer;
}

EXPORT int awe_RenderBuffer_width(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	return ptr->width;
}

EXPORT int awe_RenderBuffer_height(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	return ptr->height;
}

EXPORT int awe_RenderBuffer_rowSpan(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	return ptr->rowSpan;
}

EXPORT int awe_RenderBuffer_ownsBuffer(RenderBufferC renderBuffer) {
	RenderBuffer* ptr = static_cast<RenderBuffer*>(renderBuffer);
	return ptr->ownsBuffer?-1:0;
}

/*-----------------------------------------------------------------------------
  JSValue API
-----------------------------------------------------------------------------*/
EXPORT JSValueC awe_JSValue_newNull() {
	JSValue* val = new JSValue();
	return val;
}

EXPORT JSValueC awe_JSValue_newBool(int value) {
	JSValue* val = new JSValue(value!=0?true:false);
	return val;
}

EXPORT JSValueC awe_JSValue_newInt(int value) {
	JSValue* val = new JSValue(value);
	return val;
}

EXPORT JSValueC awe_JSValue_newDouble(double value) {
	JSValue* val = new JSValue(value);
	return val;
}

EXPORT JSValueC awe_JSValue_newString(const char* value) {
	JSValue* val = new JSValue(value);
	return val;
}

EXPORT JSValueC awe_JSValue_newWString(const wchar_t* value) {
	JSValue* val = new JSValue(value);
	return val;
}

EXPORT JSValueC awe_JSValue_newObject(ObjectC value) {
	JSValue* val = new JSValue(*(static_cast<JSValue::Object*>(value)));
	return val;
}

EXPORT JSValueC awe_JSValue_newArray(ObjectC value) {
	JSValue* val = new JSValue(*(static_cast<JSValue::Array*>(value)));
	return val;
}

EXPORT void awe_JSValue_delete(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	delete ptr;
}

EXPORT int awe_JSValue_isBoolean(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isBoolean()?-1:0;
}

EXPORT int awe_JSValue_isInteger(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isInteger()?-1:0;
}

EXPORT int awe_JSValue_isDouble(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isDouble()?-1:0;
}

EXPORT int awe_JSValue_isNumber(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isNumber()?-1:0;
}

EXPORT int awe_JSValue_isString(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isString()?-1:0;
}

EXPORT int awe_JSValue_isArray(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isArray()?-1:0;
}

EXPORT int awe_JSValue_isObject(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isObject()?-1:0;
}

EXPORT int awe_JSValue_isNull(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->isNull()?-1:0;
}

EXPORT const wchar_t* awe_JSValue_toString(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->toString().c_str();
}

EXPORT int awe_JSValue_toInteger(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->toInteger();
}

EXPORT double awe_JSValue_toDouble(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->toDouble();
}

EXPORT int awe_JSValue_toBoolean(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return ptr->toBoolean()?-1:0;
}

EXPORT ArrayC awe_JSValue_getArray(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return (ArrayC)&(ptr->getArray());
}

EXPORT ObjectC awe_JSValue_getObject(JSValueC val) {
	JSValue* ptr = static_cast<JSValue*>(val);
	return (ObjectC)&(ptr->getObject());
}


/*-----------------------------------------------------------------------------
  JSValue::Object API
-----------------------------------------------------------------------------*/
EXPORT ObjectC awe_Object_new() {
	JSValue::Object* obj = new JSValue::Object();
	return obj;
}

EXPORT void awe_Object_delete(ObjectC obj) {
	JSValue::Object* ptr = static_cast<JSValue::Object*>(obj);
	delete ptr;
}

EXPORT void awe_Object_put(ObjectC obj, wchar_t* key, JSValueC val) {
	JSValue::Object* ptr = static_cast<JSValue::Object*>(obj);
	ptr->insert(std::pair<std::wstring, JSValue>(std::wstring(key), *ptr));
}

EXPORT JSValueC awe_Object_get(ObjectC obj, wchar_t* key) {
	JSValue::Object* ptr = static_cast<JSValue::Object*>(obj);
	JSValue::Object::iterator result = ptr->find(std::wstring(key));
	if(result != ptr->end())
		return new JSValue(result->second);
	else
		return 0;
}

EXPORT int awe_Object_contains(ObjectC obj, wchar_t* key) {
	JSValue::Object* ptr = static_cast<JSValue::Object*>(obj);
	JSValue::Object::iterator result = ptr->find(std::wstring(key));
	if(result != ptr->end())
		return -1;
	else
		return 0;
}

/*-----------------------------------------------------------------------------
  JSValue::Array API
-----------------------------------------------------------------------------*/
EXPORT ArrayC awe_Array_new() {
	JSValue::Array* arr = new JSValue::Array();
	return arr;
}

EXPORT void awe_Array_delete(ArrayC arr) {
	JSValue::Array* ptr = static_cast<JSValue::Array*>(arr);
	delete ptr;
}

EXPORT int awe_Array_size(ArrayC arr) {
	JSValue::Array* ptr = static_cast<JSValue::Array*>(arr);
	return ptr->size();
}

EXPORT JSValueC awe_Array_get(ArrayC arr, int index) {
	JSValue::Array* ptr = static_cast<JSValue::Array*>(arr);
	return new JSValue(ptr[index]);
}

EXPORT void awe_Array_add(ArrayC arr, JSValueC val) {
	JSValue::Array* ptr = static_cast<JSValue::Array*>(arr);
	JSValue* valPtr = static_cast<JSValue*>(val);
	ptr->push_back(*valPtr);
}

EXPORT JSArgumentsC awe_JSArguments_new() {
	JSArguments* args = new JSArguments();
	return args;
}

EXPORT void awe_JSArguments_delete(JSArgumentsC args) {
	JSArguments* ptr = static_cast<JSArguments*>(args);
	delete ptr;
}

EXPORT int awe_JSArguments_size(JSArgumentsC args) {
	JSArguments* ptr = static_cast<JSArguments*>(args);
	return ptr->size();
}

EXPORT JSValueC awe_JSArguments_get(JSArgumentsC args, int index) {
	JSArguments* ptr = static_cast<JSArguments*>(args);
	return new JSValue(ptr[index]);
}

EXPORT void awe_JSArguments_add(JSArgumentsC args, JSValueC val) {
	JSArguments* ptr = static_cast<JSArguments*>(args);
	JSValue* valPtr = static_cast<JSValue*>(val);
	ptr->push_back(*valPtr);
}

EXPORT void awe_getKeyIdentifierFromVirtualKeyCode(int keyCode, char** identifier) {
	Awesomium::getKeyIdentifierFromVirtualKeyCode(keyCode, identifier);
}