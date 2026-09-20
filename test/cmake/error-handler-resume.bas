'' Regression: a handler and the error it resumes from share one procedure
'' context.  The nonlocal-frame repair must not invalidate this valid RESUME
'' NEXT path.

dim as integer resumed = FALSE

on error goto handler

error 5
resumed = TRUE

if( resumed = FALSE ) then
	print "resume next did not continue after the error"
	end 1
end if

print "resume next kept the procedure frame"
end 0

handler:
resume next
