/* dir() */

#include "../fb.h"
#ifndef HOST_CYGWIN
	#include <direct.h>
#endif
#include <windows.h>

/* Room for one returned filename, converted to UTF-8 */
#define FB_DIR_NAME_CHARS 1024

typedef struct {
	int in_use;
	int attrib;
	WIN32_FIND_DATAW data;
	HANDLE handle;
	char name[FB_DIR_NAME_CHARS]; /* last found filename, as UTF-8 */
} FB_DIRCTX;

static void close_dir_internal ( FB_DIRCTX *ctx )
{
	FindClose( ctx->handle );
	ctx->in_use = FALSE;
}

void fb_DIRCTX_Destructor ( void* data )
{
	FB_DIRCTX *ctx = ( FB_DIRCTX *)data;
	if( ctx->in_use )
		close_dir_internal( ctx );
}

static void close_dir ( void )
{
	FB_DIRCTX *ctx = FB_TLSGETCTX( DIR );
	close_dir_internal( ctx );
}

/* Copy the wide filename from the find data into the context's UTF-8 buffer.
   Returns NULL if the conversion failed. */
static char *hGetName( FB_DIRCTX *ctx )
{
	if( fb_hWideFilenameToUtf8( ctx->data.cFileName, ctx->name,
	                            sizeof( ctx->name ) ) == 0 )
		return NULL;

	return ctx->name;
}

static char *find_next ( int *attrib )
{
	char *name = NULL;
	FB_DIRCTX *ctx = FB_TLSGETCTX( DIR );

	do
	{
		if( !FindNextFileW( ctx->handle, &ctx->data ) ) {
			close_dir( );
			name = NULL;
			break;
		}
		name = hGetName( ctx );
	}
	while( ctx->data.dwFileAttributes & ~ctx->attrib );

	*attrib = ctx->data.dwFileAttributes & ~0xFFFFFF00;

	return name;
}

FBCALL FBSTRING *fb_Dir( FBSTRING *filespec, int attrib, int *out_attrib )
{
	FB_DIRCTX *ctx;
	FBSTRING *res;
	ssize_t len;
	int tmp_attrib;
    char *name;
    int handle_ok;
	WCHAR wspec[FB_DIR_NAME_CHARS];

	if( out_attrib == NULL )
		out_attrib = &tmp_attrib;

	len = FB_STRSIZE( filespec );
	name = NULL;

	ctx = FB_TLSGETCTX( DIR );

	if( len > 0 )
	{
		/* findfirst */
		if( ctx->in_use )
			close_dir( );

		if( fb_hFilenameToWide( filespec->data, wspec, sizeof( wspec ) / sizeof( wspec[0] ) ) == 0 ) {
			handle_ok = FALSE;
		} else {
			ctx->handle = FindFirstFileW( wspec, &ctx->data );
			handle_ok = ctx->handle != INVALID_HANDLE_VALUE;
		}
		if( handle_ok )
		{
			/* Handle any other possible bits different Windows versions could return */
			ctx->attrib = attrib | 0xFFFFFF00;

			/* archive bit not set? set the dir bit at least.. */
			if( (attrib & 0x10) == 0 )
				ctx->attrib |= 0x20;

			if( ctx->data.dwFileAttributes & ~ctx->attrib )
				name = find_next( out_attrib );
			else
			{
				name = hGetName( ctx );
				*out_attrib = ctx->data.dwFileAttributes & ~0xFFFFFF00;
            }
			if( name )
				ctx->in_use = TRUE;
		}
	} else {
		/* findnext */
		if( ctx->in_use )
			name = find_next( out_attrib );
	}

	FB_STRLOCK();

	/* store filename if found */
	if( name ) {
		len = strlen( name );
		res = fb_hStrAllocTemp_NoLock( NULL, len );
		if( res )
			fb_hStrCopy( res->data, name, len );
		else
			res = &__fb_ctx.null_desc;
	} else {
		res = &__fb_ctx.null_desc;
		*out_attrib = 0;
	}

	fb_hStrDelTemp_NoLock( filespec );

	FB_STRUNLOCK();

	return res;
}
