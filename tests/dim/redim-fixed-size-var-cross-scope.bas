' TEST_MODE : COMPILE_ONLY_FAIL

'' REDIM with an explicit data type on a fixed-len array visible from an
'' outer scope must not silently declare a new shadowing var-len array
'' (which would lose the data of the existing elements)

dim x(0 to 0) as integer

scope
	redim preserve x(0 to 1) as integer
end scope
