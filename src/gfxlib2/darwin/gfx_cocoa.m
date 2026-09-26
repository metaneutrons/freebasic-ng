/* Native macOS windowed graphics driver.  FreeBASIC owns the framebuffer;
 * AppKit and CoreGraphics only present a converted snapshot on the main thread.
 */

#include "../fb_gfx.h"
#undef MIN
#undef MAX
#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreFoundation/CFStringEncodingExt.h>
#import <dispatch/dispatch.h>
#include <limits.h>
#include <stdint.h>
#include <unistd.h>

static NSWindow *cocoa_window;
static NSView *cocoa_view;
static id<NSWindowDelegate> cocoa_delegate;
static unsigned char *cocoa_pixels;
static BLITTER *cocoa_blitter;
static int cocoa_width, cocoa_height;
static BOOL cocoa_pumping;
static BOOL cocoa_cursor_hidden;
static int cocoa_mouse_x = -1, cocoa_mouse_y = -1, cocoa_mouse_z, cocoa_buttons;
static int cocoa_window_x, cocoa_window_y;
static BOOL cocoa_virtual_down[128];

static int cocoa_screen_refresh_rate(NSScreen *screen)
{
    /* maximumFramesPerSecond arrived in macOS 12. Keep the graphics driver
     * usable on the macOS 11 deployment target. */
    if (@available(macOS 12.0, *)) {
        int refresh = (int)[screen maximumFramesPerSecond];
        if (refresh > 0)
            return refresh;
    }
    return 60;
}

/* Carbon virtual key codes describe physical key positions, not typed text.
 * Keep the mapping independent of the deprecated Carbon event APIs. */
static const unsigned char cocoa_scancodes[128] = {
    [0x00] = SC_A, [0x01] = SC_S, [0x02] = SC_D, [0x03] = SC_F,
    [0x04] = SC_H, [0x05] = SC_G, [0x06] = SC_Z, [0x07] = SC_X,
    [0x08] = SC_C, [0x09] = SC_V, [0x0b] = SC_B, [0x0c] = SC_Q,
    [0x0d] = SC_W, [0x0e] = SC_E, [0x0f] = SC_R, [0x10] = SC_Y,
    [0x11] = SC_T, [0x12] = SC_1, [0x13] = SC_2, [0x14] = SC_3,
    [0x15] = SC_4, [0x16] = SC_6, [0x17] = SC_5, [0x18] = SC_EQUALS,
    [0x19] = SC_9, [0x1a] = SC_7, [0x1b] = SC_MINUS, [0x1c] = SC_8,
    [0x1d] = SC_0, [0x1e] = SC_RIGHTBRACKET, [0x1f] = SC_O,
    [0x20] = SC_U, [0x21] = SC_LEFTBRACKET, [0x22] = SC_I,
    [0x23] = SC_P, [0x24] = SC_ENTER, [0x25] = SC_L, [0x26] = SC_J,
    [0x27] = SC_QUOTE, [0x28] = SC_K, [0x29] = SC_SEMICOLON,
    [0x2a] = SC_BACKSLASH, [0x2b] = SC_COMMA, [0x2c] = SC_SLASH,
    [0x2d] = SC_N, [0x2e] = SC_M, [0x2f] = SC_PERIOD, [0x30] = SC_TAB,
    [0x31] = SC_SPACE, [0x32] = SC_TILDE, [0x33] = SC_BACKSPACE,
    [0x35] = SC_ESCAPE, [0x36] = SC_RWIN, [0x37] = SC_LWIN,
    [0x38] = SC_LSHIFT, [0x39] = SC_CAPSLOCK, [0x3a] = SC_ALT,
    [0x3b] = SC_CONTROL, [0x3c] = SC_RSHIFT, [0x3d] = SC_ALTGR,
    [0x3e] = SC_CONTROL, [0x41] = SC_DELETE, [0x43] = SC_MULTIPLY,
    [0x45] = SC_PLUS, [0x47] = SC_CLEAR, [0x4b] = SC_SLASH,
    [0x4c] = SC_ENTER, [0x4e] = SC_MINUS, [0x51] = SC_EQUALS,
    [0x52] = SC_INSERT, [0x53] = SC_END, [0x54] = SC_DOWN,
    [0x55] = SC_PAGEDOWN, [0x56] = SC_LEFT, [0x57] = SC_CLEAR,
    [0x58] = SC_RIGHT, [0x59] = SC_HOME, [0x5b] = SC_UP,
    [0x5c] = SC_PAGEUP, [0x60] = SC_F5, [0x61] = SC_F6,
    [0x62] = SC_F7, [0x63] = SC_F3, [0x64] = SC_F8,
    [0x65] = SC_F9, [0x67] = SC_F11, [0x6d] = SC_F10,
    [0x6f] = SC_F12, [0x72] = SC_INSERT, [0x73] = SC_HOME,
    [0x74] = SC_PAGEUP, [0x75] = SC_DELETE, [0x76] = SC_F4,
    [0x77] = SC_END, [0x78] = SC_F2, [0x79] = SC_PAGEDOWN,
    [0x7a] = SC_F1, [0x7b] = SC_LEFT, [0x7c] = SC_RIGHT,
    [0x7d] = SC_DOWN, [0x7e] = SC_UP
};

static void cocoa_post_event(int type)
{
    if (!__fb_gfx)
        return;
    EVENT posted = { 0 };
    posted.type = type;
    fb_hPostEvent(&posted);
}

static void cocoa_key(NSEvent *event, int type)
{
    if (!__fb_gfx)
        return;
    unsigned code = event.keyCode;
    int scancode = code < 128 ? cocoa_scancodes[code] : 0;
    if (scancode) {
        cocoa_virtual_down[code] = type != EVENT_KEY_RELEASE;
        __fb_gfx->key[scancode] = cocoa_virtual_down[code];
        if (scancode == SC_CONTROL)
            __fb_gfx->key[scancode] = cocoa_virtual_down[0x3b] || cocoa_virtual_down[0x3e];
    }

    NSData *bytes = nil;
    if (type != EVENT_KEY_RELEASE && event.type != NSEventTypeFlagsChanged) {
        NSStringEncoding encoding = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingDOSLatinUS);
        bytes = [event.characters dataUsingEncoding:encoding allowLossyConversion:NO];
    }
    const unsigned char *characters = bytes.bytes;
    int ascii = bytes.length ? characters[0] : 0;
    if (ascii == 127)
        ascii = 8;
    EVENT posted = { 0 };
    posted.type = type;
    posted.scancode = scancode;
    posted.ascii = ascii;
    fb_hPostEvent(&posted);
    if (type != EVENT_KEY_RELEASE) {
        int extended = fb_hScancodeToExtendedKey(scancode);
        if (scancode == SC_F11) extended = KEY_F11;
        if (scancode == SC_F12) extended = KEY_F12;
        if (ascii)
            fb_hPostKey(ascii);
        else if (extended)
            fb_hPostKey(extended);
        for (NSUInteger i = 1; i < bytes.length; ++i)
            fb_hPostKey(characters[i]);
    }
}

static NSPoint cocoa_desktop_origin(NSWindow *window)
{
    NSRect desktop = [[NSScreen mainScreen] frame];
    NSRect frame = window.frame;
    return NSMakePoint(frame.origin.x - desktop.origin.x,
                       NSMaxY(desktop) - NSMaxY(frame));
}

static void cocoa_sync_window_position(NSWindow *window)
{
    NSPoint point = cocoa_desktop_origin(window);
    cocoa_window_x = (int)point.x;
    cocoa_window_y = (int)point.y;
}

@interface FBCocoaWindow : NSWindow
@end

@implementation FBCocoaWindow
- (BOOL)canBecomeKeyWindow { return YES; }
@end

@interface FBCocoaView : NSView
@end

@implementation FBCocoaView

- (BOOL)isFlipped
{
    return YES;
}

- (BOOL)acceptsFirstResponder { return YES; }

- (void)updateTrackingAreas
{
    for (NSTrackingArea *area in self.trackingAreas)
        [self removeTrackingArea:area];
    NSTrackingArea *area = [[NSTrackingArea alloc] initWithRect:NSZeroRect
        options:NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved |
                NSTrackingActiveAlways | NSTrackingInVisibleRect
        owner:self userInfo:nil];
    [self addTrackingArea:area];
    [super updateTrackingAreas];
}

- (void)keyDown:(NSEvent *)event
{
    cocoa_key(event, event.isARepeat ? EVENT_KEY_REPEAT : EVENT_KEY_PRESS);
}

- (void)keyUp:(NSEvent *)event { cocoa_key(event, EVENT_KEY_RELEASE); }

- (void)flagsChanged:(NSEvent *)event
{
    unsigned code = event.keyCode;
    int scancode = code < 128 ? cocoa_scancodes[code] : 0;
    if (!scancode || !__fb_gfx)
        return;
    /* The key code identifies which side changed even when the other side
     * remains held; the aggregate modifier flags cannot express that. */
    cocoa_key(event, cocoa_virtual_down[code] ? EVENT_KEY_RELEASE : EVENT_KEY_PRESS);
}

- (void)updateMouse:(NSEvent *)event type:(int)type button:(int)button
{
    if (!__fb_gfx)
        return;
    NSPoint point = [self convertPoint:event.locationInWindow fromView:nil];
    NSSize size = self.bounds.size;
    int x = (int)(point.x * cocoa_width / size.width);
    int y = (int)(point.y * cocoa_height / size.height);
    int dx = cocoa_mouse_x < 0 ? 0 : x - cocoa_mouse_x;
    int dy = cocoa_mouse_y < 0 ? 0 : y - cocoa_mouse_y;
    cocoa_mouse_x = x;
    cocoa_mouse_y = y;
    EVENT posted = { 0 };
    posted.type = type;
    if (type == EVENT_MOUSE_MOVE) {
        posted.x = x; posted.y = y; posted.dx = dx; posted.dy = dy;
    } else {
        posted.button = button;
        if (type == EVENT_MOUSE_BUTTON_PRESS) cocoa_buttons |= button;
        if (type == EVENT_MOUSE_BUTTON_RELEASE) cocoa_buttons &= ~button;
    }
    fb_hPostEvent(&posted);
    if (type == EVENT_MOUSE_BUTTON_PRESS && event.clickCount == 2) {
        posted.type = EVENT_MOUSE_DOUBLE_CLICK;
        fb_hPostEvent(&posted);
    }
}

- (void)mouseMoved:(NSEvent *)event { [self updateMouse:event type:EVENT_MOUSE_MOVE button:0]; }
- (void)mouseDragged:(NSEvent *)event { [self mouseMoved:event]; }
- (void)rightMouseDragged:(NSEvent *)event { [self mouseMoved:event]; }
- (void)otherMouseDragged:(NSEvent *)event { [self mouseMoved:event]; }
- (void)mouseEntered:(NSEvent *)event
{
    [self updateMouse:event type:EVENT_MOUSE_MOVE button:0];
    cocoa_post_event(EVENT_MOUSE_ENTER);
}
- (void)mouseExited:(NSEvent *)event
{
    [self updateMouse:event type:EVENT_MOUSE_MOVE button:0];
    cocoa_post_event(EVENT_MOUSE_EXIT);
}
- (void)mouseDown:(NSEvent *)event { [self updateMouse:event type:EVENT_MOUSE_BUTTON_PRESS button:BUTTON_LEFT]; }
- (void)mouseUp:(NSEvent *)event { [self updateMouse:event type:EVENT_MOUSE_BUTTON_RELEASE button:BUTTON_LEFT]; }
- (void)rightMouseDown:(NSEvent *)event { [self updateMouse:event type:EVENT_MOUSE_BUTTON_PRESS button:BUTTON_RIGHT]; }
- (void)rightMouseUp:(NSEvent *)event { [self updateMouse:event type:EVENT_MOUSE_BUTTON_RELEASE button:BUTTON_RIGHT]; }
- (void)otherMouseDown:(NSEvent *)event
{
    int button = event.buttonNumber == 2 ? BUTTON_MIDDLE :
                 event.buttonNumber == 3 ? BUTTON_X1 : BUTTON_X2;
    [self updateMouse:event type:EVENT_MOUSE_BUTTON_PRESS button:button];
}
- (void)otherMouseUp:(NSEvent *)event
{
    int button = event.buttonNumber == 2 ? BUTTON_MIDDLE :
                 event.buttonNumber == 3 ? BUTTON_X1 : BUTTON_X2;
    [self updateMouse:event type:EVENT_MOUSE_BUTTON_RELEASE button:button];
}
- (void)scrollWheel:(NSEvent *)event
{
    if (!__fb_gfx)
        return;
    EVENT posted = { 0 };
    if (event.scrollingDeltaY != 0) {
        cocoa_mouse_z += event.scrollingDeltaY > 0 ? 1 : -1;
        posted.type = EVENT_MOUSE_WHEEL;
        posted.z = cocoa_mouse_z;
        fb_hPostEvent(&posted);
    }
    if (event.scrollingDeltaX != 0) {
        posted.type = EVENT_MOUSE_HWHEEL;
        posted.w = event.scrollingDeltaX > 0 ? 1 : -1;
        fb_hPostEvent(&posted);
    }
}

- (void)drawRect:(NSRect)dirtyRect
{
    (void)dirtyRect;
    if (!cocoa_pixels)
        return;

    CGColorSpaceRef colorspace = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, cocoa_pixels,
        (size_t)cocoa_width * (size_t)cocoa_height * 4, NULL);
    if (colorspace && provider) {
        CGImageRef image = CGImageCreate(cocoa_width, cocoa_height, 8, 32,
            (size_t)cocoa_width * 4, colorspace,
            kCGBitmapByteOrder32Big | kCGImageAlphaNoneSkipLast,
            provider, NULL, false, kCGRenderingIntentDefault);
        if (image) {
            CGContextRef context = [[NSGraphicsContext currentContext] CGContext];
            CGContextSaveGState(context);
            CGContextSetInterpolationQuality(context, kCGInterpolationNone);
            NSSize size = self.bounds.size;
            CGContextTranslateCTM(context, 0, size.height);
            CGContextScaleCTM(context, size.width / cocoa_width,
                              -size.height / cocoa_height);
            CGContextDrawImage(context, CGRectMake(0, 0, cocoa_width, cocoa_height), image);
            CGContextRestoreGState(context);
            CGImageRelease(image);
        }
    }
    if (provider)
        CGDataProviderRelease(provider);
    if (colorspace)
        CGColorSpaceRelease(colorspace);
}

@end

@interface FBCocoaWindowDelegate : NSObject <NSWindowDelegate>
@end

@implementation FBCocoaWindowDelegate

- (BOOL)windowShouldClose:(NSWindow *)sender
{
    (void)sender;
    if (__fb_gfx) {
        EVENT event = { 0 };
        event.type = EVENT_WINDOW_CLOSE;
        fb_hPostEvent(&event);
    }
    return NO;
}

- (void)windowDidBecomeKey:(NSNotification *)notification
{
    (void)notification;
    cocoa_post_event(EVENT_WINDOW_GOT_FOCUS);
}

- (void)windowDidResignKey:(NSNotification *)notification
{
    (void)notification;
    if (__fb_gfx)
        memset(__fb_gfx->key, 0, 128);
    memset(cocoa_virtual_down, 0, sizeof(cocoa_virtual_down));
    cocoa_buttons = 0;
    cocoa_post_event(EVENT_WINDOW_LOST_FOCUS);
}

- (void)windowDidMove:(NSNotification *)notification
{
    cocoa_sync_window_position(notification.object);
}

@end

static void cocoa_poll_events(void)
{
    if (![NSThread isMainThread] || !cocoa_window || cocoa_pumping)
        return;

    @autoreleasepool {
        cocoa_pumping = YES;
        NSEvent *event;
        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                  untilDate:[NSDate distantPast]
                                     inMode:NSDefaultRunLoopMode
                                    dequeue:YES])) {
            [NSApp sendEvent:event];
        }
        [NSApp updateWindows];
        cocoa_pumping = NO;
    }
}

static void cocoa_present(void)
{
    if (![NSThread isMainThread] || !cocoa_window || !__fb_gfx)
        return;

    int rows = __fb_gfx->h * __fb_gfx->scanline_size;
    BOOL dirty = NO;
    for (int y = 0; y < __fb_gfx->h; ++y) {
        if (__fb_gfx->dirty[y]) {
            dirty = YES;
            break;
        }
    }
    if (dirty) {
        cocoa_blitter(cocoa_pixels, cocoa_width * 4);
        memset(__fb_gfx->dirty, 0, (size_t)rows);
        [cocoa_view setNeedsDisplay:YES];
        [cocoa_view displayIfNeeded];
    }
}

static int cocoa_init(char *title, int w, int h, int depth,
                      int refresh_rate, int flags)
{
    (void)refresh_rate; /* A window cannot change the display's refresh rate. */
    if (![NSThread isMainThread] || w <= 0 || h <= 0 ||
        (flags & (DRIVER_OPENGL | DRIVER_SHAPED_WINDOW)) ||
        (depth != 8 && depth != 16 && depth != 32))
        return -1;

    if ((size_t)w > SIZE_MAX / 4 / (size_t)h || w > INT_MAX / 4)
        return -1;

    @autoreleasepool {
        cocoa_width = w;
        cocoa_height = h;
        cocoa_pixels = calloc((size_t)w * (size_t)h, 4);
        if (!cocoa_pixels)
            return -1;

        /* Indexed palette entries are stored R,G,B; truecolor needs the
         * channel-swapping RGB blitter.  Both paths then yield RGBX bytes. */
        cocoa_blitter = fb_hGetBlitter(32, depth != 8);
        if (!cocoa_blitter)
            return -1;

        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        [NSApp finishLaunching];
        __fb_gfx->refresh_rate = cocoa_screen_refresh_rate([NSScreen mainScreen]);

        NSRect rect = NSMakeRect(0, 0, w, h);
        NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                           NSWindowStyleMaskMiniaturizable;
        if (flags & DRIVER_FULLSCREEN) {
            rect = [[NSScreen mainScreen] frame];
            style = NSWindowStyleMaskBorderless;
        } else if (flags & DRIVER_NO_FRAME) {
            style = NSWindowStyleMaskBorderless;
        }

        cocoa_window = [[FBCocoaWindow alloc] initWithContentRect:rect
                                                   styleMask:style
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
        if (!cocoa_window)
            return -1;
        /* ARC owns this NSWindow through cocoa_window.  The AppKit default
         * would release it again on close, leaving that strong reference
         * dangling when SCREEN 0 tears down a second graphics mode. */
        [cocoa_window setReleasedWhenClosed:NO];

        cocoa_view = [[FBCocoaView alloc] initWithFrame:rect];
        cocoa_delegate = [[FBCocoaWindowDelegate alloc] init];
        [cocoa_window setDelegate:cocoa_delegate];
        [cocoa_window setContentView:cocoa_view];
        [cocoa_window setAcceptsMouseMovedEvents:YES];
        [cocoa_window makeFirstResponder:cocoa_view];
        [cocoa_window setTitle:[NSString stringWithUTF8String:title ? title : "FreeBASIC"] ?: @"FreeBASIC"];
        if (flags & DRIVER_ALWAYS_ON_TOP)
            [cocoa_window setLevel:NSFloatingWindowLevel];
        if (flags & DRIVER_FULLSCREEN)
            [cocoa_window setLevel:NSMainMenuWindowLevel + 1];
        else
            [cocoa_window center];
        cocoa_sync_window_position(cocoa_window);
        cocoa_mouse_x = cocoa_mouse_y = -1;
        cocoa_mouse_z = cocoa_buttons = 0;
        memset(cocoa_virtual_down, 0, sizeof(cocoa_virtual_down));
        [NSApp activateIgnoringOtherApps:YES];
        [cocoa_window makeKeyAndOrderFront:nil];

        /* Palette setup can present before set_mode() clears the pages. */
        memset(__fb_gfx->framebuffer, 0,
               (size_t)__fb_gfx->pitch * (size_t)__fb_gfx->h);
        return 0;
    }
}

static void cocoa_exit(void)
{
    /* set_mode() rejects worker-thread teardown before it frees gfx memory. */
    if (![NSThread isMainThread])
        return;
    @autoreleasepool {
        [cocoa_window setDelegate:nil];
        [cocoa_window orderOut:nil];
        [cocoa_window close];
        cocoa_view = nil;
        cocoa_delegate = nil;
        cocoa_window = nil;
        if (cocoa_cursor_hidden) {
            [NSCursor unhide];
            cocoa_cursor_hidden = NO;
        }
    }
    free(cocoa_pixels);
    cocoa_pixels = NULL;
    cocoa_blitter = NULL;
    cocoa_width = cocoa_height = 0;
}

static void cocoa_lock(void)
{
}

static void cocoa_unlock(void)
{
    cocoa_present();
    cocoa_poll_events();
}

static void cocoa_set_palette(int index, int r, int g, int b)
{
    (void)index;
    (void)r;
    (void)g;
    (void)b;
    /* gfx_palette.c marks the framebuffer dirty after changing the palette. */
}

static void cocoa_wait_vsync(void)
{
    cocoa_present();
    cocoa_poll_events();
    usleep(1000000 / (__fb_gfx->refresh_rate > 0 ? __fb_gfx->refresh_rate : 60));
}

static void cocoa_set_window_title(char *title)
{
    NSString *value = [NSString stringWithUTF8String:title ? title : ""] ?: @"";
    if ([NSThread isMainThread]) {
        [cocoa_window setTitle:value];
    } else {
        NSWindow *target = cocoa_window;
        dispatch_async(dispatch_get_main_queue(), ^{
            if (target == cocoa_window)
                [target setTitle:value];
        });
    }
}

static int cocoa_get_mouse(int *x, int *y, int *z, int *buttons, int *clip)
{
    if (x) *x = cocoa_mouse_x;
    if (y) *y = cocoa_mouse_y;
    if (z) *z = cocoa_mouse_z;
    if (buttons) *buttons = cocoa_buttons;
    if (clip) *clip = 0;
    return 0;
}

static void cocoa_set_mouse_main(int x, int y, int cursor)
{
    if (!cocoa_window)
        return;
    if (cursor == 0 && !cocoa_cursor_hidden) {
        [NSCursor hide];
        cocoa_cursor_hidden = YES;
    } else if (cursor > 0 && cocoa_cursor_hidden) {
        [NSCursor unhide];
        cocoa_cursor_hidden = NO;
    }
    if (x >= 0 || y >= 0) {
        if (x >= 0) cocoa_mouse_x = x;
        if (y >= 0) cocoa_mouse_y = y;
        if (cocoa_mouse_x < 0) cocoa_mouse_x = 0;
        if (cocoa_mouse_y < 0) cocoa_mouse_y = 0;
        NSPoint point = NSMakePoint((cocoa_mouse_x + 0.5) * cocoa_view.bounds.size.width / cocoa_width,
                                   (cocoa_mouse_y + 0.5) * cocoa_view.bounds.size.height / cocoa_height);
        point = [cocoa_view convertPoint:point toView:nil];
        point = [cocoa_window convertPointToScreen:point];
        NSScreen *screen = cocoa_window.screen ?: [NSScreen mainScreen];
        NSRect frame = screen.frame;
        CGWarpMouseCursorPosition(CGPointMake(point.x, NSMaxY(frame) - point.y));
    }
}

static void cocoa_set_mouse(int x, int y, int cursor, int clip)
{
    (void)clip; /* Positive clipping is rejected by fb_GfxSetMouse(). */
    if ([NSThread isMainThread]) {
        cocoa_set_mouse_main(x, y, cursor);
    } else {
        NSWindow *target = cocoa_window;
        dispatch_async(dispatch_get_main_queue(), ^{
            if (target == cocoa_window)
                cocoa_set_mouse_main(x, y, cursor);
        });
    }
}

static int cocoa_set_window_pos(int x, int y)
{
    if (cocoa_window && (x != INT_MIN || y != INT_MIN)) {
        int next_x = x == INT_MIN ? cocoa_window_x : x;
        int next_y = y == INT_MIN ? cocoa_window_y : y;
        NSWindow *target = cocoa_window;
        void (^move)(void) = ^{
            if (target != cocoa_window)
                return;
            NSRect desktop = [[NSScreen mainScreen] frame];
            [target setFrameTopLeftPoint:NSMakePoint(desktop.origin.x + next_x,
                                                    NSMaxY(desktop) - next_y)];
            cocoa_sync_window_position(target);
        };
        if ([NSThread isMainThread]) move();
        else dispatch_async(dispatch_get_main_queue(), move);
    }
    return (cocoa_window_x & 0xffff) | ((cocoa_window_y & 0xffff) << 16);
}

static int *cocoa_fetch_modes(int depth, int *size)
{
    *size = 0;
    if (![NSThread isMainThread] || (depth != 8 && depth != 16 && depth != 32))
        return NULL;
    NSRect frame = [[NSScreen mainScreen] frame];
    if (frame.size.width <= 0 || frame.size.height <= 0 ||
        frame.size.width > 65535 || frame.size.height > 65535)
        return NULL;
    int *modes = malloc(sizeof(int));
    if (modes) {
        modes[0] = ((int)frame.size.width << 16) | (int)frame.size.height;
        *size = 1;
    }
    return modes;
}

static void cocoa_update(void)
{
    cocoa_present();
    cocoa_poll_events();
}

static const GFXDRIVER fb_gfxDriverCocoa = {
    "Cocoa",
    cocoa_init,
    cocoa_exit,
    cocoa_lock,
    cocoa_unlock,
    cocoa_set_palette,
    cocoa_wait_vsync,
    cocoa_get_mouse,
    cocoa_set_mouse,
    cocoa_set_window_title,
    cocoa_set_window_pos,
    cocoa_fetch_modes,
    NULL, /* OpenGL page flip is unsupported */
    cocoa_poll_events,
    cocoa_update
};

const GFXDRIVER *__fb_gfx_drivers_list[] = { &fb_gfxDriverCocoa, NULL };

void fb_hScreenInfo(ssize_t *width, ssize_t *height,
                    ssize_t *depth, ssize_t *refresh)
{
    *width = *height = *depth = *refresh = 0;
    if (![NSThread isMainThread])
        return;
    @autoreleasepool {
        NSScreen *screen = [NSScreen mainScreen];
        if (screen) {
            NSRect frame = [screen frame];
            *width = (ssize_t)frame.size.width;
            *height = (ssize_t)frame.size.height;
            *depth = 32;
            *refresh = cocoa_screen_refresh_rate(screen);
        }
    }
}

ssize_t fb_hGetWindowHandle(void)
{
    return (ssize_t)(intptr_t)(__bridge void *)cocoa_window;
}

ssize_t fb_hGetDisplayHandle(void)
{
    return 0;
}

int fb_hCocoaIsMainThread(void)
{
    return [NSThread isMainThread];
}
