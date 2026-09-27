#ifndef UNICODE 
#define UNICODE 
#endif
Dim Shared x(0) As WString
x(0) = "hello"
ReDim Preserve x(1) As WString
Print x(0)
