/* SETMOUSE function support. */

#include "fb_gfx.h"

int fb_GfxSetMouse(int x, int y, int cursor, int clip)
{
	FB_GRAPHICS_LOCK( );

	if ((!__fb_gfx) || (!__fb_gfx->driver->set_mouse)) {
		FB_GRAPHICS_UNLOCK( );
		return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL);
	}

#ifdef FB_NATIVE_COCOA
    /* macOS provides cursor warping but no supported per-window confinement.
     * Do not report success for a clipping request that cannot be honoured. */
    if (clip > 0) {
        FB_GRAPHICS_UNLOCK( );
        return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL);
    }
#endif

	DRIVER_LOCK();
	if( __fb_gfx->scanline_size != 1 ) {
		y *= __fb_gfx->scanline_size;
	}
	__fb_gfx->driver->set_mouse(x, y, cursor, clip);
	DRIVER_UNLOCK();

	FB_GRAPHICS_UNLOCK( );
	return fb_ErrorSetNum( FB_RTERROR_OK );
}
