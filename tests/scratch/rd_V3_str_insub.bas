Dim Shared x(0) As String
x(0) = "hello"
Sub f()
    ReDim Preserve x(1) As String
    Print x(0), x(1)
End Sub
f()
Print x(0)
