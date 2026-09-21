'' Regression: values changed after ON ERROR must still be visible to its
'' handler after the nonlocal transfer. C setjmp/longjmp requires the
'' generated code to preserve such automatic variables under optimization.

declare sub fail( )

dim as integer marker = 0

on error goto handler

marker = 4711
fail( )
end 1

handler:
if( marker <> 4711 ) then
	print "handler lost a local changed after ON ERROR"
	end 2
end if
end 0

sub fail( )
	error 5
end sub
