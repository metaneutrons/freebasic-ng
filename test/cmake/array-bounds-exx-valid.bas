'' A valid array access under -exx must compile and fall through the bounds
'' check.  In particular, the C backend must not emit a computed goto that
'' AppleClang rejects before the program can run.

dim shared values(1 to 2) as integer

sub store(byval index as integer)
	values(index) = 42
end sub

store 1
if values(1) <> 42 then end 1
