#ifndef UNICODE 
#define UNICODE 
#endif
Dim x(0) As Integer
x(0) = 7
Scope
    '' plain DIM shadowing a fixed array must stay allowed
    Dim x(1) As Integer
    x(1) = 8
    Print x(0); " "; x(1)
End Scope
Print x(0)
