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

#ifndef __awesomnium_h_
#define __awesomnium_h_
#include <windows.h>

#ifdef EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

#define AWE_CALLBACK __cdecl

#define AWE_LEFT_BUTTON 1
#define AWE_RIGHT_BUTTON 2
#define AWE_MIDDLE_BUTTON 3

#define AWE_TYPE_KEY_DOWN 1
#define AWE_TYPE_KEY_UP 2
#define AWE_TYPE_CHAR 3

#define AWE_MOD_SHIFT_KEY (1 << 0)
#define AWE_MOD_CONTROL_KEY (1 << 1)
#define AWE_MOD_ALT_KEY (1 << 2)
#define AWE_MOD_META_KEY (1 << 3)
#define AWE_MOD_IS_KEYPAD (1 << 4)
#define AWE_MOD_IS_AUTOREPEAT (1 << 5)

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

// AK_BACK (08) BACKSPACE key
#define AWE_AK_BACK 0x08

// AK_TAB (09) TAB key
#define AWE_AK_TAB 0x09

// AK_CLEAR (0C) CLEAR key
#define AWE_AK_CLEAR 0x0C

// AK_RETURN (0D)
#define AWE_AK_RETURN 0x0D

// AK_SHIFT (10) SHIFT key
#define AWE_AK_SHIFT 0x10

// AK_CONTROL (11) CTRL key
#define AWE_AK_CONTROL 0x11

// AK_MENU (12) ALT key
#define AWE_AK_MENU 0x12

// AK_PAUSE (13) PAUSE key
#define AWE_AK_PAUSE 0x13

// AK_CAPITAL (14) CAPS LOCK key
#define AWE_AK_CAPITAL 0x14

// AK_KANA (15) Input Method Editor (IME) Kana mode
#define AWE_AK_KANA 0x15

// AK_HANGUEL (15) IME Hanguel mode (maintained for compatibility; use AK_HANGUL)
// AK_HANGUL (15) IME Hangul mode
#define AWE_AK_HANGUL 0x15

// AK_JUNJA (17) IME Junja mode
#define AWE_AK_JUNJA 0x17

// AK_FINAL (18) IME final mode
#define AWE_AK_FINAL 0x18

// AK_HANJA (19) IME Hanja mode
#define AWE_AK_HANJA 0x19

// AK_KANJI (19) IME Kanji mode
#define AWE_AK_KANJI 0x19

// AK_ESCAPE (1B) ESC key
#define AWE_AK_ESCAPE 0x1B

// AK_CONVERT (1C) IME convert
#define AWE_AK_CONVERT 0x1C

// AK_NONCONVERT (1D) IME nonconvert
#define AWE_AK_NONCONVERT 0x1D

// AK_ACCEPT (1E) IME accept
#define AWE_AK_ACCEPT 0x1E

// AK_MODECHANGE (1F) IME mode change request
#define AWE_AK_MODECHANGE 0x1F

// AK_SPACE (20) SPACEBAR
#define AWE_AK_SPACE 0x20

// AK_PRIOR (21) PAGE UP key
#define AWE_AK_PRIOR 0x21

// AK_NEXT (22) PAGE DOWN key
#define AWE_AK_NEXT 0x22

// AK_END (23) END key
#define AWE_AK_END 0x23

// AK_HOME (24) HOME key
#define AWE_AK_HOME 0x24

// AK_LEFT (25) LEFT ARROW key
#define AWE_AK_LEFT 0x25

// AK_UP (26) UP ARROW key
#define AWE_AK_UP 0x26

// AK_RIGHT (27) RIGHT ARROW key
#define AWE_AK_RIGHT 0x27

// AK_DOWN (28) DOWN ARROW key
#define AWE_AK_DOWN 0x28

// AK_SELECT (29) SELECT key
#define AWE_AK_SELECT 0x29

// AK_PRINT (2A) PRINT key
#define AWE_AK_PRINT 0x2A

// AK_EXECUTE (2B) EXECUTE key
#define AWE_AK_EXECUTE 0x2B

// AK_SNAPSHOT (2C) PRINT SCREEN key
#define AWE_AK_SNAPSHOT 0x2C

// AK_INSERT (2D) INS key
#define AWE_AK_INSERT 0x2D

// AK_DELETE (2E) DEL key
#define AWE_AK_DELETE 0x2E

// AK_HELP (2F) HELP key
#define AWE_AK_HELP 0x2F

// (30) 0 key
#define AWE_AK_0 0x30

// (31) 1 key
#define AWE_AK_1 0x31

// (32) 2 key
#define AWE_AK_2 0x32

// (33) 3 key
#define AWE_AK_3 0x33

// (34) 4 key
#define AWE_AK_4 0x34

// (35) 5 key;
#define AWE_AK_5 0x35

// (36) 6 key
#define AWE_AK_6 0x36

// (37) 7 key
#define AWE_AK_7 0x37

// (38) 8 key
#define AWE_AK_8 0x38

// (39) 9 key
#define AWE_AK_9 0x39

// (41) A key
#define AWE_AK_A 0x41

// (42) B key
#define AWE_AK_B 0x42

// (43) C key
#define AWE_AK_C 0x43

// (44) D key
#define AWE_AK_D 0x44

// (45) E key
#define AWE_AK_E 0x45

// (46) F key
#define AWE_AK_F 0x46

// (47) G key
#define AWE_AK_G 0x47

// (48) H key
#define AWE_AK_H 0x48

// (49) I key
#define AWE_AK_I 0x49

// (4A) J key
#define AWE_AK_J 0x4A

// (4B) K key
#define AWE_AK_K 0x4B

// (4C) L key
#define AWE_AK_L 0x4C

// (4D) M key
#define AWE_AK_M 0x4D

// (4E) N key
#define AWE_AK_N 0x4E

// (4F) O key
#define AWE_AK_O 0x4F

// (50) P key
#define AWE_AK_P 0x50

// (51) Q key
#define AWE_AK_Q 0x51

// (52) R key
#define AWE_AK_R 0x52

// (53) S key
#define AWE_AK_S 0x53

// (54) T key
#define AWE_AK_T 0x54

// (55) U key
#define AWE_AK_U 0x55

// (56) V key
#define AWE_AK_V 0x56

// (57) W key
#define AWE_AK_W 0x57

// (58) X key
#define AWE_AK_X 0x58

// (59) Y key
#define AWE_AK_Y 0x59

// (5A) Z key
#define AWE_AK_Z 0x5A

// AK_LWIN (5B) Left Windows key (Microsoft Natural keyboard)
#define AWE_AK_LWIN 0x5B

// AK_RWIN (5C) Right Windows key (Natural keyboard)
#define AWE_AK_RWIN 0x5C

// AK_APPS (5D) Applications key (Natural keyboard)
#define AWE_AK_APPS 0x5D

// AK_SLEEP (5F) Computer Sleep key
#define AWE_AK_SLEEP 0x5F

// AK_NUMPAD0 (60) Numeric keypad 0 key
#define AWE_AK_NUMPAD0 0x60

// AK_NUMPAD1 (61) Numeric keypad 1 key
#define AWE_AK_NUMPAD1 0x61

// AK_NUMPAD2 (62) Numeric keypad 2 key
#define AWE_AK_NUMPAD2 0x62

// AK_NUMPAD3 (63) Numeric keypad 3 key
#define AWE_AK_NUMPAD3 0x63

// AK_NUMPAD4 (64) Numeric keypad 4 key
#define AWE_AK_NUMPAD4 0x64

// AK_NUMPAD5 (65) Numeric keypad 5 key
#define AWE_AK_NUMPAD5 0x65

// AK_NUMPAD6 (66) Numeric keypad 6 key
#define AWE_AK_NUMPAD6 0x66

// AK_NUMPAD7 (67) Numeric keypad 7 key
#define AWE_AK_NUMPAD7 0x67

// AK_NUMPAD8 (68) Numeric keypad 8 key
#define AWE_AK_NUMPAD8 0x68

// AK_NUMPAD9 (69) Numeric keypad 9 key
#define AWE_AK_NUMPAD9 0x69

// AK_MULTIPLY (6A) Multiply key
#define AWE_AK_MULTIPLY 0x6A

// AK_ADD (6B) Add key
#define AWE_AK_ADD 0x6B

// AK_SEPARATOR (6C) Separator key
#define AWE_AK_SEPARATOR 0x6C

// AK_SUBTRACT (6D) Subtract key
#define AWE_AK_SUBTRACT 0x6D

// AK_DECIMAL (6E) Decimal key
#define AWE_AK_DECIMAL 0x6E

// AK_DIVIDE (6F) Divide key
#define AWE_AK_DIVIDE 0x6F

// AK_F1 (70) F1 key
#define AWE_AK_F1 0x70

// AK_F2 (71) F2 key
#define AWE_AK_F2 0x71

// AK_F3 (72) F3 key
#define AWE_AK_F3 0x72

// AK_F4 (73) F4 key
#define AWE_AK_F4 0x73

// AK_F5 (74) F5 key
#define AWE_AK_F5 0x74

// AK_F6 (75) F6 key
#define AWE_AK_F6 0x75

// AK_F7 (76) F7 key
#define AWE_AK_F7 0x76

// AK_F8 (77) F8 key
#define AWE_AK_F8 0x77

// AK_F9 (78) F9 key
#define AWE_AK_F9 0x78

// AK_F10 (79) F10 key
#define AWE_AK_F10 0x79

// AK_F11 (7A) F11 key
#define AWE_AK_F11 0x7A

// AK_F12 (7B) F12 key
#define AWE_AK_F12 0x7B

// AK_F13 (7C) F13 key
#define AWE_AK_F13 0x7C

// AK_F14 (7D) F14 key
#define AWE_AK_F14 0x7D

// AK_F15 (7E) F15 key
#define AWE_AK_F15 0x7E

// AK_F16 (7F) F16 key
#define AWE_AK_F16 0x7F

// AK_F17 (80H) F17 key
#define AWE_AK_F17 0x80

// AK_F18 (81H) F18 key
#define AWE_AK_F18 0x81

// AK_F19 (82H) F19 key
#define AWE_AK_F19 0x82

// AK_F20 (83H) F20 key
#define AWE_AK_F20 0x83

// AK_F21 (84H) F21 key
#define AWE_AK_F21 0x84

// AK_F22 (85H) F22 key
#define AWE_AK_F22 0x85

// AK_F23 (86H) F23 key
#define AWE_AK_F23 0x86

// AK_F24 (87H) F24 key
#define AWE_AK_F24 0x87

// AK_NUMLOCK (90) NUM LOCK key
#define AWE_AK_NUMLOCK 0x90

// AK_SCROLL (91) SCROLL LOCK key
#define AWE_AK_SCROLL 0x91

// AK_LSHIFT (A0) Left SHIFT key
#define AWE_AK_LSHIFT 0xA0

// AK_RSHIFT (A1) Right SHIFT key
#define AWE_AK_RSHIFT 0xA1

// AK_LCONTROL (A2) Left CONTROL key
#define AWE_AK_LCONTROL 0xA2

// AK_RCONTROL (A3) Right CONTROL key
#define AWE_AK_RCONTROL 0xA3

// AK_LMENU (A4) Left MENU key
#define AWE_AK_LMENU 0xA4

// AK_RMENU (A5) Right MENU key
#define AWE_AK_RMENU 0xA5

// AK_BROWSER_BACK (A6) Windows 2000/XP: Browser Back key
#define AWE_AK_BROWSER_BACK 0xA6

// AK_BROWSER_FORWARD (A7) Windows 2000/XP: Browser Forward key
#define AWE_AK_BROWSER_FORWARD 0xA7

// AK_BROWSER_REFRESH (A8) Windows 2000/XP: Browser Refresh key
#define AWE_AK_BROWSER_REFRESH 0xA8

// AK_BROWSER_STOP (A9) Windows 2000/XP: Browser Stop key
#define AWE_AK_BROWSER_STOP 0xA9

// AK_BROWSER_SEARCH (AA) Windows 2000/XP: Browser Search key
#define AWE_AK_BROWSER_SEARCH 0xAA

// AK_BROWSER_FAVORITES (AB) Windows 2000/XP: Browser Favorites key
#define AWE_AK_BROWSER_FAVORITES 0xAB

// AK_BROWSER_HOME (AC) Windows 2000/XP: Browser Start and Home key
#define AWE_AK_BROWSER_HOME 0xAC

// AK_VOLUME_MUTE (AD) Windows 2000/XP: Volume Mute key
#define AWE_AK_VOLUME_MUTE 0xAD

// AK_VOLUME_DOWN (AE) Windows 2000/XP: Volume Down key
#define AWE_AK_VOLUME_DOWN 0xAE

// AK_VOLUME_UP (AF) Windows 2000/XP: Volume Up key
#define AWE_AK_VOLUME_UP 0xAF

// AK_MEDIA_NEXT_TRACK (B0) Windows 2000/XP: Next Track key
#define AWE_AK_MEDIA_NEXT_TRACK 0xB0

// AK_MEDIA_PREV_TRACK (B1) Windows 2000/XP: Previous Track key
#define AWE_AK_MEDIA_PREV_TRACK 0xB1

// AK_MEDIA_STOP (B2) Windows 2000/XP: Stop Media key
#define AWE_AK_MEDIA_STOP 0xB2

// AK_MEDIA_PLAY_PAUSE (B3) Windows 2000/XP: Play/Pause Media key
#define AWE_AK_MEDIA_PLAY_PAUSE 0xB3

// AK_LAUNCH_MAIL (B4) Windows 2000/XP: Start Mail key
#define AWE_AK_MEDIA_LAUNCH_MAIL 0xB4

// AK_LAUNCH_MEDIA_SELECT (B5) Windows 2000/XP: Select Media key
#define AWE_AK_MEDIA_LAUNCH_MEDIA_SELECT 0xB5

// AK_LAUNCH_APP1 (B6) Windows 2000/XP: Start Application 1 key
#define AWE_AK_MEDIA_LAUNCH_APP1 0xB6

// AK_LAUNCH_APP2 (B7) Windows 2000/XP: Start Application 2 key
#define AWE_AK_MEDIA_LAUNCH_APP2 0xB7

// AK_OEM_1 (BA) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ';:' key
#define AWE_AK_OEM_1 0xBA

// AK_OEM_PLUS (BB) Windows 2000/XP: For any country/region, the '+' key
#define AWE_AK_OEM_PLUS 0xBB

// AK_OEM_COMMA (BC) Windows 2000/XP: For any country/region, the ',' key
#define AWE_AK_OEM_COMMA 0xBC

// AK_OEM_MINUS (BD) Windows 2000/XP: For any country/region, the '-' key
#define AWE_AK_OEM_MINUS 0xBD

// AK_OEM_PERIOD (BE) Windows 2000/XP: For any country/region, the '.' key
#define AWE_AK_OEM_PERIOD 0xBE

// AK_OEM_2 (BF) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '/?' key
#define AWE_AK_OEM_2 0xBF

// AK_OEM_3 (C0) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '`~' key
#define AWE_AK_OEM_3 0xC0

// AK_OEM_4 (DB) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '[{' key
#define AWE_AK_OEM_4 0xDB

// AK_OEM_5 (DC) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '\|' key
#define AWE_AK_OEM_5 0xDC

// AK_OEM_6 (DD) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ']}' key
#define AWE_AK_OEM_6 0xDD

// AK_OEM_7 (DE) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the 'single-quote/double-quote' key
#define AWE_AK_OEM_7 0xDE

// AK_OEM_8 (DF) Used for miscellaneous characters; it can vary by keyboard.
#define AWE_AK_OEM_8 0xDF

// AK_OEM_102 (E2) Windows 2000/XP: Either the angle bracket key or the backslash key on the RT 102-key keyboard
#define AWE_AK_OEM_102 0xE2

// AK_PROCESSKEY (E5) Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
#define AWE_AK_PROCESSKEY 0xE5

// AK_PACKET (E7) Windows 2000/XP: Used to pass Unicode characters as if they were keystrokes. The AK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT,SendInput, WM_KEYDOWN, and WM_KEYUP
#define AWE_AK_PACKET 0xE7

// AK_ATTN (F6) Attn key
#define AWE_AK_ATTN 0xF6

// AK_CRSEL (F7) CrSel key
#define AWE_AK_CRSEL 0xF7

// AK_EXSEL (F8) ExSel key
#define AWE_AK_EXSEL 0xF8

// AK_EREOF (F9) Erase EOF key
#define AWE_AK_EREOF 0xF9

// AK_PLAY (FA) Play key
#define AWE_AK_PLAY 0xFA

// AK_ZOOM (FB) Zoom key
#define AWE_AK_ZOOM 0xFB

// AK_NONAME (FC) Reserved for future use
#define AWE_AK_NONAME 0xFC

// AK_PA1 (FD) PA1 key
#define AWE_AK_PA1 0xFD

// AK_OEM_CLEAR (FE) Clear key
#define AWE_AK_OEM_CLEAR 0xFE

#define AWE_AK_UNKNOWN 0;

#define AWE_LOG_NONE 0
#define AWE_LOG_NORMAL 1
#define AWE_LOG_VERBOSE 2

#define WebCoreC void*
#define WebViewC void*
#define ResourceInterceptorC void*
#define JSArgumentsC void*
#define JSValueC void*
#define ObjectC void*
#define ArrayC void*
#define RenderBufferC void*
//#define HeaderDefinitionC void*

typedef struct {
	int x, y, width, height;
} RectC;

typedef struct {
	void (AWE_CALLBACK *onBeginNavigation) (WebViewC webView, const char* url, const wchar_t* frameName);	
	void (AWE_CALLBACK *onBeginLoading) (WebViewC webView, const char* url, const wchar_t* frameName, int statusCode, const wchar_t* mimeType);
	void (AWE_CALLBACK *onFinishLoading) (WebViewC webView);
	void (AWE_CALLBACK *onCallback) (WebViewC webView, const wchar_t* objectName, const wchar_t* callbackName, const JSArgumentsC args);
	void (AWE_CALLBACK *onReceiveTitle) (WebViewC webView, const wchar_t* title, const wchar_t* frameName);
	void (AWE_CALLBACK *onChangeTooltip) (WebViewC webView, const wchar_t* toolTip);
	void (AWE_CALLBACK *onChangeCursor) (WebViewC webView, int cursor);
	void (AWE_CALLBACK *onChangeKeyboardFocus) (WebViewC webView, int isFocused);
	void (AWE_CALLBACK *onChangeTargetURL) (WebViewC webView, const char* url);
	void (AWE_CALLBACK *onOpenExternalLink) (WebViewC webView, const char* url, const wchar_t* source);
	void (AWE_CALLBACK *onRequestDownload) (WebViewC webView, const char* url);
	void (AWE_CALLBACK *onWebViewCrashed) (WebViewC webView);
	void (AWE_CALLBACK *onPluginCrashed) (WebViewC webView, const wchar_t* pluginName);
	void (AWE_CALLBACK *onRequestMove) (WebViewC webView, int x, int y);
	void (AWE_CALLBACK *onGetPageContents) (WebViewC webView, const char* url, const wchar_t* contents);
	void (AWE_CALLBACK *onDOMReady) (WebViewC webView);
} WebViewListenerC;

typedef struct {
	int 		type;
	int 		modifiers;
	int 		virtualKeyCode;
	int 		nativeKeyCode;
	char 		keyIdentifier [20];
	wchar_t* 	text [4];
	wchar_t* 	unmodifiedText [4];
	int 		isSystemKey;
} WebKeyboardEventC;

extern "C" {	
	extern EXPORT WebCoreC        awe_WebCore_new();
	extern EXPORT WebCoreC        awe_WebCore_newWithPlugins(const wchar_t* pluginPath);
	extern EXPORT WebCoreC        awe_WebCore_newFromConfig(int enablePlugins, int enableJavascript, const wchar_t* userDataPath, const wchar_t* pluginPath, const wchar_t* logPath, int logLevel, const char* userAgentOverride, const char* proxyServer, const char* proxyConfig, int saveCacheAndCookies, int maxCacheSize, int disableSameOriginPolicy, const char* customCss);
	extern EXPORT void	          awe_WebCore_delete(WebCoreC webCore);	
	extern EXPORT void            awe_WebCore_setBaseDirectory(WebCoreC webCore, const char* baseDirectory);
	extern EXPORT void            awe_WebCore_setBaseDirectoryW(WebCoreC webCore, const wchar_t* baseDirectory);
	extern EXPORT WebViewC        awe_WebCore_createWebView(WebCoreC webCore, int width, int height);
	extern EXPORT void            awe_WebCore_setCustomResponsePage(WebCoreC webCore, int statusCode, const wchar_t* filePath);
	extern EXPORT void            awe_WebCore_update(WebCoreC webCore);
	extern EXPORT const wchar_t*  awe_WebCore_getBaseDirectory(WebCoreC webCore);
	extern EXPORT int	          awe_WebCore_arePluginsEnabled(WebCoreC webCore);
	extern EXPORT void            awe_WebCore_clearCache(WebCoreC webCore);
	extern EXPORT void            awe_WebCore_clearCookies(WebCoreC webCore);
	extern EXPORT int             awe_WebCore_setCookie(WebCoreC webCore, const char* url, const char* cookieString, int isHTTPOnly, int forceSessionCookie);
	extern EXPORT const char*     awe_WebCore_getCookies(WebCoreC webCore, const char* url, int excludeHTTPOnly);
	extern EXPORT void            awe_WebCore_deleteCookie(WebCoreC webCore, const char* url, const char* cookieName);

	extern EXPORT void                  awe_WebView_destroy(WebViewC webView);
	extern EXPORT void                  awe_WebView_setListener(WebViewC webView, const WebViewListenerC* webViewListener);
	extern EXPORT WebViewListenerC*     awe_WebView_getListener(WebViewC webView);
	extern EXPORT ResourceInterceptorC* awe_WebView_getResourceInterceptor(WebViewC webView);
	extern EXPORT void                  awe_WebView_loadURL(WebViewC webView, const char* url, const wchar_t* frameName, const char* username, const char* password);
	extern EXPORT void                  awe_WebView_loadURLW(WebViewC webView, const wchar_t* url, const wchar_t* frameName, const char* username, const char* password);
	extern EXPORT void                  awe_WebView_loadHTML(WebViewC webView, const char* html, const wchar_t* frameName);
	extern EXPORT void                  awe_WebView_loadHTMLW(WebViewC webView, const wchar_t* html, const wchar_t* frameName);
	extern EXPORT void                  awe_WebView_loadFile(WebViewC webView, const char* file, const wchar_t* frameName);
	extern EXPORT void                  awe_WebView_goToHistoryOffset(WebViewC webView, int offset);
	extern EXPORT void                  awe_WebView_stop(WebViewC webView);
	extern EXPORT void                  awe_WebView_reload(WebViewC webView);
	extern EXPORT void                  awe_WebView_executeJavascript(WebViewC webView, const char* javascript, const wchar_t* frameName);
	extern EXPORT void                  awe_WebView_executeJavascriptW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName);
	extern EXPORT JSValueC              awe_WebView_executeJavascriptWithResult(WebViewC webView, const char* javascript, const wchar_t* frameName);
	extern EXPORT JSValueC              awe_WebView_executeJavascriptWithResultTimeout(WebViewC webView, const char* javascript, const wchar_t* frameName, int timeoutMS);
	extern EXPORT JSValueC              awe_WebView_executeJavascriptWithResultW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName);
	extern EXPORT JSValueC              awe_WebView_executeJavascriptWithResultTimeoutW(WebViewC webView, const wchar_t* javascript, const wchar_t* frameName, int timeoutMS);
	extern EXPORT void                  awe_WebView_callJavascriptFunction(WebViewC webView, const wchar_t* object, const wchar_t* function, JSArgumentsC args, const wchar_t* frameName);
	extern EXPORT void                  awe_WebView_createObject(WebViewC webView, const wchar_t* objectName);
	extern EXPORT void                  awe_WebView_destroyObject(WebViewC webView, const wchar_t* objectName);
	extern EXPORT void                  awe_WebView_setObjectProperty(WebViewC webView, const wchar_t* objectName, const wchar_t* propName, JSValueC value);
	extern EXPORT void                  awe_WebView_setObjectCallback(WebViewC webView, const wchar_t* objectName, const wchar_t* callbackName);
	extern EXPORT int                   awe_WebView_isLoadingPage(WebViewC webView);
	extern EXPORT int                   awe_WebView_isDirty(WebViewC webView);
	extern EXPORT void                  awe_WebView_getDirtyBounds(WebViewC webView, RectC* rect);
	extern EXPORT RenderBufferC         awe_WebView_render(WebViewC webView);
	extern EXPORT void                  awe_WebView_pauseRendering(WebViewC webView);
	extern EXPORT void                  awe_WebView_resumeRendering(WebViewC webView);
	extern EXPORT void                  awe_WebView_injectMouseMove(WebViewC webView, int x, int y);
	extern EXPORT void                  awe_WebView_injectMouseDown(WebViewC webView, int mouseButton);
	extern EXPORT void                  awe_WebView_injectMouseUp(WebViewC webView, int mouseButton);
	extern EXPORT void                  awe_WebView_injectMouseWheel(WebViewC webView, int scrollAmount);
	extern EXPORT void                  awe_WebView_injectKeyboardEvent(WebViewC webView, WebKeyboardEventC* keyboardEvent);
	extern EXPORT void                  awe_WebView_injectKeyboardEventArgs(WebViewC webView, int type, int modifiers, int virtualKeyCode, int nativeKeyCode, char* keyIdentifier, wchar_t* text, wchar_t* unmodifiedText, int isSystemKey);
	extern EXPORT void                  awe_WebView_injectKeyboardEventCharacter(WebViewC webView, unsigned int character);
	extern EXPORT void                  awe_WebView_injectKeyboardEventWindows(WebViewC webView, int msg, WPARAM wparam, LPARAM lparam);
	extern EXPORT void                  awe_WebView_cut(WebViewC webView);
	extern EXPORT void                  awe_WebView_copy(WebViewC webView);
	extern EXPORT void                  awe_WebView_paste(WebViewC webView);
	extern EXPORT void                  awe_WebView_selectAll(WebViewC webView);
	extern EXPORT void                  awe_WebView_setZoom(WebViewC webView, int zoomPercent);
	extern EXPORT void                  awe_WebView_resetZoom(WebViewC webView);
	extern EXPORT int                   awe_WebView_resize(WebViewC webView, int width, int height, int waitForRepaint, int repaintTimeoutMS);
	extern EXPORT int                   awe_WebView_isResizing(WebViewC webView);
	extern EXPORT void                  awe_WebView_unfocus(WebViewC webView);
	extern EXPORT void                  awe_WebView_focus(WebViewC webView);
	extern EXPORT void                  awe_WebView_setTransparent(WebViewC webView, int isTransparent);
	extern EXPORT void                  awe_WebView_setURLFilteringMode(WebViewC webView, int mode);
	extern EXPORT void                  awe_WebView_addURLFilter(WebViewC webView, const wchar_t* filter);
	extern EXPORT void                  awe_WebView_clearAllURLFilters(WebViewC webView);
//	extern EXPORT void                  awe_WebView_setHeaderDefinition(WebViewC webView, const char* name, HeaderDefinitionC definition);
//	extern EXPORT void                  awe_WebView_addHeaderRewriteRule(WebViewC webView, const wchar_t* rule, const char* name);
//	extern EXPORT void                  awe_WebView_removeHeaderRewriteRule(WebViewC webView, const wchar_t* rule);
//	extern EXPORT void                  awe_WebView_removeHeaderRewriteRulesByDefinitionName(WebViewC webView, const char* name); 	

	extern EXPORT void awe_getKeyIdentifierFromVirtualKeyCode(int keyCode, char** identifier);

	extern EXPORT RenderBufferC awe_RenderBuffer_new(int width, int height);
	extern EXPORT RenderBufferC awe_RenderBuffer_newFromBuffer(unsigned char* buffer, int width, int height, int rowSpan, int autoDeleteBuffer);
	extern EXPORT void          awe_RenderBuffer_delete(RenderBufferC renderBuffer);
	extern EXPORT void          awe_RenderBuffer_copyTo(RenderBufferC renderBuffer, unsigned char* destBuffer, int destRowSpan, int destDepth, int convertToRGBA);
	extern EXPORT void          awe_RenderBuffer_saveToPNG(RenderBufferC renderBuffer, const wchar_t* filePath, int preserveTransparency);
	extern EXPORT void          awe_RenderBuffer_saveToJPEG(RenderBufferC renderBuffer, const wchar_t* filePath, int quality);
	extern EXPORT void          awe_RenderBuffer_reserve(RenderBufferC renderBuffer, int width, int height);
	extern EXPORT void          awe_RenderBuffer_copyFrom(RenderBufferC renderBuffer, unsigned char* srcBuffer, int srcRowSpan);
	extern EXPORT void          awe_RenderBuffer_copyArea(RenderBufferC renderBuffer, unsigned char* srcBuffer, int srcRowSpan, int srcX, int srcY, int srcWidth, int srcHeight, int forceOpaque);
	extern EXPORT void          awe_RenderBuffer_copyArea2(RenderBufferC renderBuffer, RenderBufferC srcBuffer, int srcX, int srcY, int srcWidth, int srcHeight, int dstX, int dstY, int dstWidth, int dstHeight);
	extern EXPORT void          awe_RenderBuffer_scrollArea(RenderBufferC renderBuffer, int dx, int dy, int clipX, int clipY, int clipWidth, int clipHeight);
	extern EXPORT unsigned char* awe_RenderBuffer_buffer(RenderBufferC renderBuffer);
	extern EXPORT int           awe_RenderBuffer_width(RenderBufferC renderBuffer);
	extern EXPORT int           awe_RenderBuffer_height(RenderBufferC renderBuffer);
	extern EXPORT int           awe_RenderBuffer_rowSpan(RenderBufferC renderBuffer);
	extern EXPORT int           awe_RenderBuffer_ownsBuffer(RenderBufferC renderBuffer);

	extern EXPORT JSValueC awe_JSValue_newNull();
	extern EXPORT JSValueC awe_JSValue_newBool(int value);
	extern EXPORT JSValueC awe_JSValue_newInt(int value);
	extern EXPORT JSValueC awe_JSValue_newDouble(double value);
	extern EXPORT JSValueC awe_JSValue_newString(const char* value);
	extern EXPORT JSValueC awe_JSValue_newWString(const wchar_t* value);
	extern EXPORT JSValueC awe_JSValue_newObject(ObjectC value);
	extern EXPORT JSValueC awe_JSValue_newArray(ArrayC value);
	extern EXPORT void     awe_JSValue_delete(JSValueC val);
	extern EXPORT int      awe_JSValue_isBoolean(JSValueC val);
	extern EXPORT int      awe_JSValue_isInteger(JSValueC val);
	extern EXPORT int      awe_JSValue_isDouble(JSValueC val);
	extern EXPORT int      awe_JSValue_isNumber(JSValueC val);
	extern EXPORT int      awe_JSValue_isString(JSValueC val);
	extern EXPORT int      awe_JSValue_isArray(JSValueC val);
	extern EXPORT int      awe_JSValue_isObject(JSValueC val);
	extern EXPORT int      awe_JSValue_isNull(JSValueC val);
	extern EXPORT const wchar_t* awe_JSValue_toString(JSValueC val);
	extern EXPORT int      awe_JSValue_toInteger(JSValueC val);
	extern EXPORT double   awe_JSValue_toDouble(JSValueC val);
	extern EXPORT int      awe_JSValue_toBoolean(JSValueC val);
	extern EXPORT ArrayC   awe_JSValue_getArray(JSValueC val);
	extern EXPORT ObjectC  awe_JSValue_getObject(JSValueC val);

	extern EXPORT ObjectC  awe_Object_new();
	extern EXPORT void     awe_Object_delete(ObjectC obj);
	extern EXPORT void     awe_Object_put(ObjectC obj, wchar_t* key, JSValueC val);
	extern EXPORT JSValueC awe_Object_get(ObjectC obj, wchar_t* key);
	extern EXPORT int      awe_Object_contains(ObjectC obj, wchar_t* key);

	extern EXPORT ArrayC   awe_Array_new();
	extern EXPORT void     awe_Array_delete(ArrayC arr);
	extern EXPORT int      awe_Array_size(ArrayC arr);
	extern EXPORT JSValueC awe_Array_get(ArrayC arr, int index);
	extern EXPORT void     awe_Array_add(ArrayC arr, JSValueC val);

	extern EXPORT JSArgumentsC   awe_JSArguments_new();	
	extern EXPORT void			 awe_JSArguments_delete(JSArgumentsC args);
	extern EXPORT int			 awe_JSArguments_size(JSArgumentsC args);
	extern EXPORT JSValueC		 awe_JSArguments_get(JSArgumentsC args, int index);
	extern EXPORT void			 awe_JSArguments_add(JSArgumentsC args, JSValueC val);
};

#endif