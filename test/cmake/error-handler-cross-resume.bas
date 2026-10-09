'' Regression: a RESUME from a handler in another procedure cannot enter the
'' frame that was discarded by the nonlocal transfer.  The runtime reports
'' illegal resume (exit status 5) instead of jumping into the dead frame.
'' fail() raises a different error number, so a handler that is never reached
'' ends with status 100 and cannot pass for the illegal resume.

declare sub fail( )

on error goto handler

fail( )
end 1

handler:
resume next

sub fail( )
	error 100
end sub
