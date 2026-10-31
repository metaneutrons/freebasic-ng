'' A valid pointer dereference under -exx must compile and fall through the
'' null check.  This covers the same C-backend handler transfer as array bounds.

dim value as integer
dim p as integer ptr = @value

*p = 42
if value <> 42 then end 1
