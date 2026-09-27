#ifndef UNICODE
#define UNICODE
#endif

Function p_from_fixed( ByRef u As Const WString ) ByRef As WString
    Dim As Const WString Ptr p = @u
    Return UCase( u )
End Function

Dim s As WString
s = p_from_fixed( "hello" )
If s <> WStr( "HELLO" ) Then End 1
End 0
