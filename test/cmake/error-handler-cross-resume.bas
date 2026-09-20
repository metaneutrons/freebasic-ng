'' Regression: a RESUME from a handler in another procedure cannot enter the
'' frame that was discarded by the nonlocal transfer.  The runtime reports
'' illegal resume (exit status 5) instead of jumping into the dead frame.

declare sub fail( )

on error goto handler

fail( )
end 1

handler:
resume next

sub fail( )
	error 5
end sub
