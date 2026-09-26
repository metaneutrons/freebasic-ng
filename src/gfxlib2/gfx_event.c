/* system events retrieving */

#include "fb_gfx.h"

FBCALL int fb_GfxEvent(EVENT *event)
{
	EVENT *e = NULL;

	FB_GRAPHICS_LOCK( );

	if (!__fb_gfx) {
		FB_GRAPHICS_UNLOCK( );
		return FB_FALSE;
	}

#ifdef FB_NATIVE_COCOA
    /* ScreenEvent loops commonly do no drawing.  Pump the AppKit queue here
     * so input and close/focus events still reach FreeBASIC. */
    if (__fb_gfx->driver->poll_events)
        __fb_gfx->driver->poll_events();
#endif

	EVENT_LOCK();
	if (__fb_gfx->event_head != __fb_gfx->event_tail) {
		e = &__fb_gfx->event_queue[__fb_gfx->event_head];
		if (event)
			__fb_gfx->event_head = (__fb_gfx->event_head + 1) & (MAX_EVENTS - 1);
	}
	if (e && event)
		fb_hMemCpy(event, e, sizeof(EVENT));
	EVENT_UNLOCK();

	FB_GRAPHICS_UNLOCK( );

	return e ? FB_TRUE : FB_FALSE;
}
