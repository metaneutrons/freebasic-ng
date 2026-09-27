#ifndef UNICODE 
#define UNICODE 
#endif
Sub h( p() As Integer )
    ReDim Preserve p(4) As Integer
    p(4) = 41
    Print "bydesc:"; p(4)
End Sub

Dim arr(1) As Integer
h( arr() )
