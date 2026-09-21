'' Regression: an ON ERROR handler installed at module level must run with
'' the module frame when a nested procedure raises the error. Before the
'' nonlocal handler context, the generated code jumped directly from fail()
'' into this label, leaving fail()'s stack and frame pointer active.

declare sub fail( )

dim as integer marker = 4711
dim as integer counter = 13

on error goto handler

fail( )
print "the error handler was not reached"
end 1

handler:
if( marker <> 4711 ) or ( counter <> 13 ) then
	print "handler ran with the wrong frame"
	end 2
end if

print "module-level handler restored its frame"
end 0

sub fail( )
	'' Exercise the checked runtime-error path used by OPEN, not only an
	'' explicit ERROR statement. The generated name cannot exist below the
	'' isolated regression work directory.
	dim as integer f = freefile
	open "__fb_missing_directory__" + chr( 47 ) + "__fb_missing_file__" for input as #f
end sub
