#ifndef UNICODE 
#define UNICODE 
#endif
Type T
    a As Integer
End Type
Dim Shared x(0) As T
x(0).a = 111
Sub f()
    ReDim Preserve x(1) As T
    Print "inside f: x(0).a ="; x(0).a
End Sub
f()
