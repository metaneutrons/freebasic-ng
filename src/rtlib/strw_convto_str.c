/* unicode to ascii string convertion function */

#include "fb.h"

#if defined HOST_WIN32
	#include <windows.h>
#endif

/* dst_chars == room in dst buffer without null terminator. Thus, the dst buffer
   must be at least dst_chars+1 bytes.
   src must be null-terminated.
   result = number of chars written, excluding null terminator that is always written */
ssize_t fb_wstr_ConvToA(char *dst, ssize_t dst_chars, const FB_WCHAR *src)
{
	if (src == NULL) {
		*dst = '\0';
		return 0;
	}

#if defined DISABLE_WCHAR
	ssize_t chars = strlen(src);
	if (chars > dst_chars)
		chars = dst_chars;

	memcpy(dst, src, chars + 1);
	return chars;
#else
	char *origdst = dst;
	char *dstlimit = dst + dst_chars;

#if defined HOST_WIN32
	/* Windows: convert to UTF-8.  This is the encoding fbc uses internally
	   for all paths (they come from the wide command line and from #cmdline
	   options in UTF-8 source files), so WSTRING -> STRING conversions of
	   filenames produce names the FB runtime's Unicode-aware file functions
	   can open.  The ANSI codepage cannot represent most non-ASCII
	   filenames at all (they would be mangled into '?'), and wcstombs()
	   depends on the CRT locale, which defaults to "C" and mangles every
	   non-ASCII unit into '?'. */
	int wbytes = WideCharToMultiByte( CP_UTF8, 0, src, -1, dst,
	                                  (int)dst_chars + 1, NULL, NULL );
	if( wbytes > 0 ) {
		/* WideCharToMultiByte() counted the null terminator */
		return (ssize_t)wbytes - 1;
	}
	/* conversion failed (insufficient room or best-fit loss); fall
	   through to the ASCII + '?' translation below */
#endif

	/* translate at least ASCII chars and write out '?' for the others
	   (also the truncation path, like wcstombs() does) */
	while (dst < dstlimit) {
#if defined HOST_WIN32
		UTF_16 c = *src++;
		if (c == 0)
			break;
		if (c > 127) {
			if (c >= UTF16_SUR_HIGH_START && c <= UTF16_SUR_HIGH_END)
				src++;
			c = '?';
		}
#else
		UTF_32 c = *src++;
		if (c == 0)
			break;
		if (c > 127)
			c = '?';
#endif
		*dst++ = (char)c;
	}
	*dst = '\0';
	return dst - origdst;
#endif
}

FBCALL FBSTRING *fb_WstrToStr( const FB_WCHAR *src )
{
	FBSTRING *dst;
	ssize_t chars;

    if( src == NULL )
        return &__fb_ctx.null_desc;

#if defined HOST_DOS
    /* on DOS, wcstombs() simply calls memcpy() and won't compute
       length  see fb_unicode.h */
    chars = fb_wstr_Len( src );
#elif defined HOST_WIN32
    /* measure in UTF-8, the encoding fb_wstr_ConvToA() writes (wcstombs()
       would measure in the CRT locale's codepage instead, which can differ) */
    chars = WideCharToMultiByte( CP_UTF8, 0, src, -1, NULL, 0, NULL, NULL );
    if( chars > 0 )
        chars -= 1; /* don't count the null terminator */
    if( chars < 0 )
        chars = 0;
#else
    chars = wcstombs( NULL, src, 0 );
#endif
    if( chars == 0 )
        return &__fb_ctx.null_desc;

    dst = fb_hStrAllocTemp( NULL, chars );
    if( dst == NULL )
        return &__fb_ctx.null_desc;

    fb_wstr_ConvToA( dst->data, chars, src );

    return dst;
}
