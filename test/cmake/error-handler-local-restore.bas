'' Regression: ON LOCAL ERROR has a per-procedure handler that is removed on
'' return, restoring the enclosing handler for a later error.

declare sub child( )

dim as integer outer_hits = 0

on error goto outer_handler

child( )
error 5
end 1

outer_handler:
outer_hits += 1
if( outer_hits <> 1 ) then
	print "outer handler ran an unexpected number of times"
	end 2
end if
end 0

sub child( )
	dim as integer inner_hits = 0

	on local error goto inner_handler

	error 5
	exit sub

inner_handler:
	inner_hits += 1
	if( inner_hits <> 1 ) then
		print "inner handler ran an unexpected number of times"
		end 3
	end if
	resume next
end sub
