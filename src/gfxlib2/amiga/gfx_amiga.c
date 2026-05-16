/* FreeBASIC gfxlib2 driver for AmigaOS via intuition.library + graphics.library */

#include "../fb_gfx.h"

#if defined(HOST_AMIGAOS)
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <intuition/screens.h>

extern struct ExecBase *SysBase;
static struct IntuitionBase *IntuitionBase;
static struct GfxBase *GfxBase;
static struct Screen *amiga_screen;
static struct Window *amiga_window;
static int mouse_x, mouse_y, mouse_z, mouse_buttons;

static int driver_init(char *title, int w, int h, int depth, int refresh_rate, int flags) {
    if (flags & DRIVER_OPENGL) return -1;

    IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 36);
    GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 36);
    if (!IntuitionBase || !GfxBase) goto fail;

    amiga_screen = OpenScreenTags(NULL,
        SA_Width, w, SA_Height, h, SA_Depth, depth > 8 ? 8 : depth,
        SA_Title, (ULONG)(title ? title : "FreeBASIC"),
        SA_ShowTitle, FALSE, SA_Quiet, TRUE, TAG_DONE);
    if (!amiga_screen) goto fail;

    amiga_window = OpenWindowTags(NULL,
        WA_CustomScreen, (ULONG)amiga_screen,
        WA_Left, 0, WA_Top, 0, WA_Width, w, WA_Height, h,
        WA_Borderless, TRUE, WA_Activate, TRUE, WA_RMBTrap, TRUE,
        WA_IDCMP, IDCMP_RAWKEY | IDCMP_MOUSEBUTTONS | IDCMP_MOUSEMOVE,
        WA_Flags, WFLG_BACKDROP | WFLG_BORDERLESS | WFLG_REPORTMOUSE,
        TAG_DONE);
    if (!amiga_window) goto fail;

    return 0;
fail:
    if (amiga_screen) { CloseScreen(amiga_screen); amiga_screen = NULL; }
    if (GfxBase) { CloseLibrary((struct Library *)GfxBase); GfxBase = NULL; }
    if (IntuitionBase) { CloseLibrary((struct Library *)IntuitionBase); IntuitionBase = NULL; }
    return -1;
}

static void driver_exit(void) {
    if (amiga_window) { CloseWindow(amiga_window); amiga_window = NULL; }
    if (amiga_screen) { CloseScreen(amiga_screen); amiga_screen = NULL; }
    if (GfxBase) { CloseLibrary((struct Library *)GfxBase); GfxBase = NULL; }
    if (IntuitionBase) { CloseLibrary((struct Library *)IntuitionBase); IntuitionBase = NULL; }
}

static void driver_lock(void) { }
static void driver_unlock(void) { }

static void driver_set_palette(int index, int r, int g, int b) {
    if (amiga_screen && GfxBase) {
        /* Scale 0-63 to 0-15 for AGA (4-bit per channel in SetRGB4) */
        SetRGB4(&amiga_screen->ViewPort, index, r >> 2, g >> 2, b >> 2);
    }
}

static void driver_wait_vsync(void) {
    if (GfxBase) WaitTOF();
}

static int driver_get_mouse(int *x, int *y, int *z, int *buttons, int *clip) {
    *x = mouse_x; *y = mouse_y; *z = mouse_z;
    *buttons = mouse_buttons; *clip = 0;
    return 0;
}

static void driver_set_mouse(int x, int y, int cursor, int clip) {
    /* Not easily supported without pointer sprite manipulation */
}

static void driver_set_window_title(char *title) {
    if (amiga_screen) SetWindowTitles(amiga_window, (UBYTE *)title, (UBYTE *)-1);
}

static void driver_update(void) {
    /* Copy framebuffer to screen using WriteChunkyPixels (OS 3.1+) or
       manual planar conversion for older systems */
    if (!amiga_window || !__fb_gfx) return;

    struct RastPort *rp = amiga_window->RPort;
    unsigned char *src = __fb_gfx->framebuffer;
    int w = __fb_gfx->w, h = __fb_gfx->h;

    /* Use WritePixelArray8 for chunky-to-planar conversion */
    struct RastPort tmp_rp;
    InitRastPort(&tmp_rp);
    tmp_rp.BitMap = AllocBitMap(w, 1, amiga_screen->RastPort.BitMap->Depth, 0, NULL);
    if (tmp_rp.BitMap) {
        int y;
        for (y = 0; y < h; y++) {
            WritePixelLine8(rp, 0, y, w, src + y * __fb_gfx->pitch, &tmp_rp);
        }
        FreeBitMap(tmp_rp.BitMap);
    }
}

static void driver_poll_events(void) {
    if (!amiga_window) return;
    struct IntuiMessage *msg;
    while ((msg = (struct IntuiMessage *)GetMsg(amiga_window->UserPort))) {
        switch (msg->Class) {
            case IDCMP_MOUSEMOVE:
                mouse_x = msg->MouseX;
                mouse_y = msg->MouseY;
                break;
            case IDCMP_MOUSEBUTTONS:
                if (msg->Code == SELECTDOWN) mouse_buttons |= 1;
                else if (msg->Code == SELECTUP) mouse_buttons &= ~1;
                else if (msg->Code == MENUDOWN) mouse_buttons |= 2;
                else if (msg->Code == MENUUP) mouse_buttons &= ~2;
                break;
            case IDCMP_RAWKEY:
                fb_hPostKey(msg->Code & 0x7F, (msg->Code & 0x80) ? 0 : 1);
                break;
        }
        ReplyMsg((struct Message *)msg);
    }
}

const GFXDRIVER fb_gfxDriverAmiga = {
    "Amiga",
    driver_init,
    driver_exit,
    driver_lock,
    driver_unlock,
    driver_set_palette,
    driver_wait_vsync,
    driver_get_mouse,
    driver_set_mouse,
    driver_set_window_title,
    NULL,               /* set_window_pos */
    NULL,               /* fetch_modes */
    NULL,               /* flip */
    driver_poll_events,
    driver_update
};

/* Driver list for Amiga */
const GFXDRIVER *__fb_gfx_drivers_list[] = {
    &fb_gfxDriverAmiga,
    NULL
};

void fb_hScreenInfo(ssize_t *width, ssize_t *height, ssize_t *depth, ssize_t *refresh) {
    *width = 640; *height = 480; *depth = 8; *refresh = 50;
}

#endif /* HOST_AMIGAOS */
