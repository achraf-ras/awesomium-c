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
#include once "awesomium.bi"

sub onBeginLoading cdecl (byval webView as any ptr, _
						  byval url as zstring ptr, _
						  byval frameName as wstring ptr, _
						  byval statusCode as integer, _
						  byval mimeType as wstring ptr)
	print "begin loading", *url, *mimeType
end sub

dim webCore as any ptr
dim webView as any ptr
dim renderBuffer as any ptr
dim listener as WebViewListenerC

webCore = awe_WebCore_new()
webView = awe_WebCore_createWebView(webcore, 512, 512)
listener.onBeginLoading = @onBeginLoading

awe_WebView_setListener(webView, @listener)
awe_WebView_loadURL(webView, "http://www.google.at", "", "", "")

print "Loading page"
while(awe_WebView_isLoadingPage(webView) <> 0)
	Sleep(50)
	awe_WebCore_update(webCore)
wend
print "done"

renderBuffer = awe_WebView_render(webView)
if(renderBuffer <> 0) then
	awe_RenderBuffer_saveToPNG(renderBuffer, "./result.png", -1)
	exec("start", "result.png")
end if

awe_WebView_destroy(webView)
awe_WebCore_delete(webCore)
