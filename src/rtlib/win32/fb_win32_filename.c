/* Unicode-aware filename accessors for Win32.

   The CRT's file functions (fopen() & friends) take ANSI filenames, i.e. the
   name is converted to the process' ANSI codepage before it reaches the OS.
   Characters that aren't representable in that codepage are silently turned
   into '?' characters, and since '?' is not a legal filename character on
   Windows, such files can neither be opened nor created.  The same applies to
   the whole path, including directories.

   The functions below convert narrow filenames to UTF-16 and then call the
   wide Win32 API (or the wide CRT wrappers), which handles any filename the
   filesystem supports.

   A narrow filename is interpreted as UTF-8 if it forms valid UTF-8, and as
   the C locale's codepage otherwise.  The former is the encoding used by the
   fbc compiler for every path it works with (its paths come from the wide
   command line and from #cmdline options embedded in UTF-8 source files) and
   by Unicode-aware callers in general.  The latter matches the behaviour of
   the CRT's setlocale()-based character conversions, e.g. wide-string to
   narrow-string conversions done when passing a WString filename to the
   FB runtime.  Pure ASCII names are unaffected either way. */

#include "../fb.h"

#ifdef HOST_MINGW

#include <windows.h>
#include <direct.h> /* for _wchdir(), _wmkdir() */

/* Declared in the CRT, but not always in the headers; also used by
   strw_native.c and strw_convfrom_str.c for the same purpose */
extern unsigned int __cdecl ___lc_codepage_func( void );

/* Room for one filename, converted to UTF-16 */
#define FB_WIN32_FNAME_CHARS 4096

/* Is the given string valid UTF-8?  Additionally rejects overlong encodings,
   UTF-16 surrogates and code points beyond U+10FFFF, so that only byte
   sequences which are unambiguously UTF-8 are accepted.  A pure ASCII string
   is valid UTF-8 as well. */
static int hIsValidUTF8( const char *s )
{
	const unsigned char *p = (const unsigned char*)s;

	while( *p )
	{
		unsigned long c;
		int extra, i;

		if( *p < 0x80 ) {
			++p;
			continue;
		}

		if( (*p & 0xE0) == 0xC0 )
			extra = 1;
		else if( (*p & 0xF0) == 0xE0 )
			extra = 2;
		else if( (*p & 0xF8) == 0xF0 )
			extra = 3;
		else
			return FALSE;

		c = *p & (0x7F >> extra);
		++p;

		for( i = 0; i < extra; ++i ) {
			if( (*p & 0xC0) != 0x80 )
				return FALSE;
			c = (c << 6) | (*p & 0x3F);
			++p;
		}

		/* no overlong encodings */
		if( (extra == 1) && (c < 0x80) )
			return FALSE;
		if( (extra == 2) && (c < 0x800) )
			return FALSE;
		if( (extra == 3) && (c < 0x10000) )
			return FALSE;

		/* no surrogates, nothing beyond U+10FFFF */
		if( (c >= 0xD800) && (c <= 0xDFFF) )
			return FALSE;
		if( c > 0x10FFFF )
			return FALSE;
	}

	return TRUE;
}

/* Which codepage should the given narrow filename be interpreted in? */
unsigned int fb_hGetNarrowCodepage( const char *filename )
{
	const unsigned char *p = (const unsigned char*)filename;
	unsigned int cp;

	/* Only non-ASCII names can be ambiguous, don't bother with the UTF-8
	   validation (and with ___lc_codepage_func()) otherwise */
	while( *p ) {
		if( *p > 0x7F ) {
			if( hIsValidUTF8( filename ) )
				return CP_UTF8;
			break;
		}
		++p;
	}

	cp = ___lc_codepage_func();
	if( cp == 0 )
		cp = GetACP();

	return cp;
}

int fb_hIsValidUtf8Name( const char *s )
{
	return hIsValidUTF8( s );
}

/* Length-based variant (for counted strings, which may contain embedded
   NULs); returns TRUE if all bytes form valid UTF-8 */
int fb_hIsValidUtf8NameN( const char *s, size_t bytes )
{
	const unsigned char *p = (const unsigned char*)s;
	size_t left = bytes;

	while( left > 0 )
	{
		unsigned long c;
		int extra, i;

		if( *p < 0x80 ) {
			++p;
			--left;
			continue;
		}

		if( (*p & 0xE0) == 0xC0 )
			extra = 1;
		else if( (*p & 0xF0) == 0xE0 )
			extra = 2;
		else if( (*p & 0xF8) == 0xF0 )
			extra = 3;
		else
			return FALSE;

		if( (size_t)extra >= left )
			return FALSE;

		c = *p & (0x7F >> extra);
		++p;
		--left;

		for( i = 0; i < extra; ++i ) {
			if( (*p & 0xC0) != 0x80 )
				return FALSE;
			c = (c << 6) | (*p & 0x3F);
			++p;
			--left;
		}

		/* no overlong encodings */
		if( (extra == 1) && (c < 0x80) )
			return FALSE;
		if( (extra == 2) && (c < 0x800) )
			return FALSE;
		if( (extra == 3) && (c < 0x10000) )
			return FALSE;

		/* no surrogates, nothing beyond U+10FFFF */
		if( (c >= 0xD800) && (c <= 0xDFFF) )
			return FALSE;
		if( c > 0x10FFFF )
			return FALSE;
	}

	return TRUE;
}

/* Convert a narrow filename (UTF-8 or locale codepage, see above) to UTF-16.
   Returns the number of WCHARs written including the null terminator, or 0 on
   failure.  dst must have room for dstchars WCHARs. */
size_t fb_hFilenameToWide( const char *filename, wchar_t *dst, size_t dstchars )
{
	int chars;

	if( (filename == NULL) || (dst == NULL) || (dstchars < 2) )
		return 0;

	chars = MultiByteToWideChar( fb_hGetNarrowCodepage( filename ), 0,
	                             filename, -1, (LPWSTR)dst, (int)dstchars );
	if( chars <= 0 )
		return 0;

	/* make sure it's terminated even if it was truncated */
	dst[dstchars - 1] = 0;

	return (size_t)chars;
}

/* Convert a UTF-16 filename to UTF-8.  Returns the number of bytes written
   including the null terminator, or 0 on failure. */
size_t fb_hWideFilenameToUtf8( const wchar_t *filename, char *dst, size_t dstbytes )
{
	int bytes;

	if( (filename == NULL) || (dst == NULL) || (dstbytes < 2) )
		return 0;

	bytes = WideCharToMultiByte( CP_UTF8, 0, (LPCWSTR)filename, -1,
	                             dst, (int)dstbytes, NULL, NULL );
	if( bytes <= 0 )
		return 0;

	dst[dstbytes - 1] = 0;

	return (size_t)bytes;
}

/* Copy a narrow mode string (ASCII only) to a wide one */
static void hModeToWide( const char *mode, wchar_t *dst, size_t dstchars )
{
	size_t i;

	for( i = 0; (i + 1 < dstchars) && mode[i]; ++i )
		dst[i] = (wchar_t)(unsigned char)mode[i];
	dst[i] = 0;
}

/* fopen() with a narrow (UTF-8 or locale codepage) filename */
FILE *fb_hFOpen( const char *filename, const char *mode )
{
	wchar_t wname[FB_WIN32_FNAME_CHARS];
	wchar_t wmode[16];

	if( (filename == NULL) || (mode == NULL) )
		return NULL;

	if( fb_hFilenameToWide( filename, wname, FB_WIN32_FNAME_CHARS ) == 0 )
		return NULL;

	hModeToWide( mode, wmode, sizeof( wmode ) / sizeof( wchar_t ) );

	return _wfopen( wname, wmode );
}

/* freopen() with a narrow (UTF-8 or locale codepage) filename */
FILE *fb_hFReopen( const char *filename, const char *mode, FILE *stream )
{
	wchar_t wname[FB_WIN32_FNAME_CHARS];
	wchar_t wmode[16];

	if( (filename == NULL) || (mode == NULL) || (stream == NULL) )
		return NULL;

	if( fb_hFilenameToWide( filename, wname, FB_WIN32_FNAME_CHARS ) == 0 )
		return NULL;

	hModeToWide( mode, wmode, sizeof( wmode ) / sizeof( wchar_t ) );

	return _wfreopen( wname, wmode, stream );
}

/* remove() with a narrow (UTF-8 or locale codepage) filename */
int fb_hFRemove( const char *filename )
{
	wchar_t wname[FB_WIN32_FNAME_CHARS];

	if( fb_hFilenameToWide( filename, wname, FB_WIN32_FNAME_CHARS ) == 0 )
		return -1;

	return _wremove( wname );
}

int fb_hFChDir( const char *path )
{
	wchar_t wpath[FB_WIN32_FNAME_CHARS];

	if( fb_hFilenameToWide( path, wpath, FB_WIN32_FNAME_CHARS ) == 0 )
		return -1;

	return _wchdir( wpath );
}

int fb_hFMkDir( const char *path )
{
	wchar_t wpath[FB_WIN32_FNAME_CHARS];

	if( fb_hFilenameToWide( path, wpath, FB_WIN32_FNAME_CHARS ) == 0 )
		return -1;

	return _wmkdir( wpath );
}

int fb_hFCopyFile( const char *source, const char *destination )
{
	wchar_t wsrc[FB_WIN32_FNAME_CHARS];
	wchar_t wdst[FB_WIN32_FNAME_CHARS];

	if( (fb_hFilenameToWide( source, wsrc, FB_WIN32_FNAME_CHARS ) == 0) ||
	    (fb_hFilenameToWide( destination, wdst, FB_WIN32_FNAME_CHARS ) == 0) )
		return FALSE;

	return CopyFileW( (LPCWSTR)wsrc, (LPCWSTR)wdst, FALSE ) ? TRUE : FALSE;
}

#else /* !HOST_MINGW */

/* Other win32 hosts (Cygwin) handle UTF-8 filenames themselves.  These
   fallbacks also have to exist so that the callers can be written in a
   platform-independent way. */

#include <direct.h>

FILE *fb_hFOpen( const char *filename, const char *mode )
{
	return fopen( filename, mode );
}

FILE *fb_hFReopen( const char *filename, const char *mode, FILE *stream )
{
	return freopen( filename, mode, stream );
}

int fb_hFRemove( const char *filename )
{
	return remove( filename );
}

int fb_hFChDir( const char *path )
{
	return chdir( path );
}

int fb_hFMkDir( const char *path )
{
	return mkdir( path );
}

int fb_hFCopyFile( const char *source, const char *destination )
{
	return FALSE;
}

#endif /* HOST_MINGW */
