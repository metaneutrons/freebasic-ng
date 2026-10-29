'' Counter-probe for null-pointer-exx-valid.bas: the generated check must still
'' reject a null dereference with FB_RTERROR_NULLPTR (exit status 7).

dim p as integer ptr

*p = 42
end 1
