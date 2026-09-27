#ifndef UNICODE 
#define UNICODE 
#endif
Type T
    a As Integer
End Type
Dim Shared x() As T
Dim Shared s() As String
Dim Shared w() As WString
ReDim x(0) As T
ReDim s(0) As String
ReDim w(0) As WString
x(0).a = 111
s(0) = "keep"
w(0) = "wkeep"

Sub g()
    '' legit: ReDim var-len (dynamic) arrays from inner scope
    ReDim Preserve x(1) As T
    ReDim Preserve s(1) As String
    ReDim Preserve w(1) As WString
    x(1).a = 222
    s(1) = "new"
    w(1) = "wnew"
    Print x(0).a; " "; x(1).a; " "; s(0); " "; s(1); " "; w(0); " "; w(1)
End Sub

g()
ReDim Preserve x(2) As T
x(2).a = 333
Print x(0).a; " "; x(1).a; " "; x(2).a
