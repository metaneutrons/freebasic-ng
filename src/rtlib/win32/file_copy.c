/* file copy */

#include "../fb.h"
#include <windows.h>

FBCALL int fb_FileCopy( const char *source, const char *destination )
{
	BOOL res;
	res = fb_hFCopyFile( source, destination );
	return fb_ErrorSetNum( res == FALSE ? FB_RTERROR_ILLEGALFUNCTIONCALL : FB_RTERROR_OK );
}
