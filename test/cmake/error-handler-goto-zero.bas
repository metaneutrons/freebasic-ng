'' Regression: ON ERROR GOTO 0 removes the handler, so a later error is
'' unhandled and ends the program with its own number (exit status 100).  The
'' handler installation is a setjmp() landing site; GOTO 0 has no handler to
'' land in, and the error must not return to the earlier site either.

declare sub fail( )

on error goto handler
on error goto 0

fail( )
end 1

handler:
print "the removed handler was entered"
end 2

sub fail( )
	error 100
end sub
