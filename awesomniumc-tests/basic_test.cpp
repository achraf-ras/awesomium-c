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
#include "awesomiumc.h"
#include <windows.h>
#include <stdio.h>

static int run = -1;

void onBeginNavigation (WebViewC webView, const char* url, const wchar_t* frameName) {
	printf("begin navigation\n");
}

void onBeginLoading (WebViewC webView, const char* url, const wchar_t* frameName, int statusCode, const wchar_t* mimeType) {
	printf("begin loading %s\n", url);
}

void onFinishLoading (WebViewC webView) {
	printf("finish loading\n");
}

void onCallback (WebViewC webView, const wchar_t* objectName, const wchar_t* callbackName, const JSArgumentsC args) {
	printf("callback\n");
	JSValueC val = awe_JSArguments_get((void*)args, 0);
	int intval = awe_JSValue_toInteger((void*)val);
	printf("%d %d\n", intval, awe_JSValue_isInteger((void*)val));
	val = awe_JSArguments_get((void*)args, 1);
	intval = awe_JSValue_toInteger((void*)val);
	printf("%d\n", intval);
	run = 0;
}

void onReceiveTitle (WebViewC webView, const wchar_t* title, const wchar_t* frameName) {
	printf("received title %s\n", title);
}

void onChangeTooltip (WebViewC webView, const wchar_t* toolTip) {
	printf("changed tooltip\n");
}

void onChangeCursor (WebViewC webView, int cursor) {
	printf("changed cursor\n");
}

void onChangeKeyboardFocus (WebViewC webView, int isFocused) {
	printf("changed keyboard focus\n");
}

void onChangeTargetURL (WebViewC webView, const char* url) {
	printf("change target URL\n");
}
void onOpenExternalLink (WebViewC webView, const char* url, const wchar_t* source) {
	printf("open external link\n");
}

void onRequestDownload (WebViewC webView, const char* url) {
	printf("request download\n");
}

void onWebViewCrashed (WebViewC webView) {
	printf("webview crashed\n");
}

void onPluginCrashed (WebViewC webView, const wchar_t* pluginName) {
	printf("plugin crashed\n");
}

void onRequestMove (WebViewC webView, int x, int y) {
	printf("request move\n");
}

void onGetPageContents (WebViewC webView, const char* url, const wchar_t* contents) {	
	printf("get page contents\n");
}

void onDOMReady (WebViewC webView) {
	printf("DOM ready\n");
}

int main() {		
	WebCoreC webCore = awe_WebCore_new();
	WebViewC webView = awe_WebCore_createWebView(webCore, 512, 512);
	WebViewListenerC listener;
	memset(&listener, 0, sizeof(WebViewListenerC));
	listener.onBeginLoading = onBeginLoading;
	listener.onDOMReady = onDOMReady;
	listener.onCallback = onCallback;

	awe_WebView_createObject(webView, L"derp");
	awe_WebView_setObjectCallback(webView, L"derp", L"mycallback");
	awe_WebView_setListener(webView, &listener);
	awe_WebView_loadFile(webView, "data/web/html/debug.html", L"");

	printf("loading page...");
	while(run) {	
		awe_WebCore_update(webCore);
		
		if(awe_WebView_isDirty(webView)) {
			RenderBufferC renderBuffer = awe_WebView_render(webView);
			if(renderBuffer != 0) {
				awe_RenderBuffer_saveToJPEG(renderBuffer, L"./result.jpg", -1);								
			}
		}
	}
	printf("done\n");

	awe_WebView_destroy(webView);
	awe_WebCore_delete(webCore);	
	getc(stdin);
	return 0;
}