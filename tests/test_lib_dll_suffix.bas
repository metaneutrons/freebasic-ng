#ifndef UNICODE
#define UNICODE
#endif

'' Regression test: Lib "#...dll" names (trailing .dll extension) must be
'' accepted and resolved to the corresponding import library (libxxx.a).
#include once "windows.bi"

'' shcore.dll / user32.dll with explicit .dll suffix, own alias names so
'' they don't clash with the declarations from windows.bi
Declare Function MyGetDpiForMonitor Lib "shcore.dll" Alias "GetDpiForMonitor" ( _
	ByVal hmonitor As HANDLE, _
	ByVal dpiType As Long, _
	ByRef dpiX As ULONG, _
	ByRef dpiY As ULONG ) As HRESULT

Declare Function MyIsWindow Lib "user32.dll" Alias "IsWindow" ( _
	ByVal hWnd As HWND ) As BOOL

'' #inclib with .dll suffix as well
#inclib "gdiplus.dll"

Dim dpiX As ULONG, dpiY As ULONG
Dim res As HRESULT

res = MyIsWindow(GetDesktopWindow())
Print "IsWindow(desktop): "; res

Print "OK"
