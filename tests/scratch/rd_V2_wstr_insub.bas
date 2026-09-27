#ifndef UNICODE 
#define UNICODE 
#endif
Dim Shared x(0) As WString
x(0) = "hello"
Sub f()
    ReDim Preserve x(1) As WString
    Print x(0), x(1)
End Sub
f()
Print x(0)
