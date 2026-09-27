#ifndef UNICODE 
#define UNICODE 
#endif
Type T
    a As Integer
End Type
Dim Shared x(0) As T
Sub f()
    ReDim Preserve x(1) As T
End Sub
f()
Print x(0).a
