/* mkdir function */

#include "fb.h"
#ifdef HOST_MINGW
#include <direct.h>
#else
#include <sys/stat.h>
#endif

/*:::::*/
FBCALL int fb_MkDir( FBSTRING *path )
{
	int res;

	res = fb_hFMkDir( path->data );

	/* del if temp */
	fb_hStrDelTemp( path );

	return res;
}
