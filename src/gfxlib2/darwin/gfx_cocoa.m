/* Native macOS windowed graphics driver.  FreeBASIC owns the framebuffer;
 * AppKit and CoreGraphics only present a converted snapshot on the main thread.
 */

#include "../fb_gfx.h"
#undef MIN
#undef MAX
#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
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

@interface FBCocoaView : NSView
@end

@implementation FBCocoaView

- (BOOL)isFlipped
{
    return YES;
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
            CGContextTranslateCTM(context, 0, cocoa_height);
            CGContextScaleCTM(context, 1, -1);
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
        (flags & (DRIVER_OPENGL | DRIVER_FULLSCREEN | DRIVER_SHAPED_WINDOW)) ||
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
        int display_refresh = (int)[[NSScreen mainScreen] maximumFramesPerSecond];
        __fb_gfx->refresh_rate = display_refresh > 0 ? display_refresh : 60;

        NSRect rect = NSMakeRect(0, 0, w, h);
        NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                           NSWindowStyleMaskMiniaturizable;
        if (flags & DRIVER_NO_FRAME)
            style = NSWindowStyleMaskBorderless;

        cocoa_window = [[NSWindow alloc] initWithContentRect:rect
                                                   styleMask:style
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
        if (!cocoa_window)
            return -1;

        cocoa_view = [[FBCocoaView alloc] initWithFrame:rect];
        cocoa_delegate = [[FBCocoaWindowDelegate alloc] init];
        [cocoa_window setDelegate:cocoa_delegate];
        [cocoa_window setContentView:cocoa_view];
        [cocoa_window setTitle:[NSString stringWithUTF8String:title ? title : "FreeBASIC"] ?: @"FreeBASIC"];
        if (flags & DRIVER_ALWAYS_ON_TOP)
            [cocoa_window setLevel:NSFloatingWindowLevel];
        [cocoa_window center];
        [cocoa_window makeKeyAndOrderFront:nil];
        [NSApp activateIgnoringOtherApps:YES];

        /* Palette setup can present before set_mode() clears the pages. */
        memset(__fb_gfx->framebuffer, 0,
               (size_t)__fb_gfx->pitch * (size_t)__fb_gfx->h);
        return 0;
    }
}

static void cocoa_exit(void)
{
    if ([NSThread isMainThread]) {
        @autoreleasepool {
            [cocoa_window setDelegate:nil];
            [cocoa_window orderOut:nil];
            [cocoa_window close];
            cocoa_view = nil;
            cocoa_delegate = nil;
            cocoa_window = nil;
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
    if ([NSThread isMainThread] && cocoa_window)
        [cocoa_window setTitle:[NSString stringWithUTF8String:title ? title : ""] ?: @""];
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
    NULL, /* mouse input: #169 */
    NULL, /* mouse control: #169 */
    cocoa_set_window_title,
    NULL, /* window placement: #169 */
    NULL, /* fullscreen mode inventory: #169 */
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
            *refresh = (ssize_t)[screen maximumFramesPerSecond];
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
