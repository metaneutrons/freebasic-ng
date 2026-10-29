'' Counter-probe for array-bounds-exx-valid.bas: the generated check must still
'' reject an invalid variable index with FB_RTERROR_OUTOFBOUNDS (exit status 6).

dim shared values(1 to 2) as integer

sub store(byval index as integer)
	values(index) = 42
end sub

store 3
end 1
