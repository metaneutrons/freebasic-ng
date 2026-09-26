/* Test-only readback of what the Cocoa view actually drew. */
#import <Cocoa/Cocoa.h>
#include <math.h>
#include <stdio.h>

int fb_cocoa_test_pixel(int x, int y)
{
    @autoreleasepool {
        NSWindow *window = [NSApp keyWindow] ?: [[NSApp windows] firstObject];
        NSView *view = [window contentView];
        if (!view)
            return -1;
        NSBitmapImageRep *rep = [view bitmapImageRepForCachingDisplayInRect:view.bounds];
        if (!rep)
            return -1;
        [view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];
        CGFloat scale = [view.window backingScaleFactor];
        NSColor *color = [[rep colorAtX:(NSInteger)((x + 0.5) * scale)
                                      y:(NSInteger)((y + 0.5) * scale)]
                          colorUsingColorSpace:[NSColorSpace sRGBColorSpace]];
        if (!color)
            return -1;
        int value = ((int)lrint(color.redComponent * 255) << 16) |
               ((int)lrint(color.greenComponent * 255) << 8) |
               (int)lrint(color.blueComponent * 255);
        fprintf(stderr, "pixel %d,%d = %06x (rep %ldx%ld, scale %.1f)\n",
                x, y, value, (long)rep.pixelsWide, (long)rep.pixelsHigh, scale);
        return value;
    }
}

int fb_cocoa_test_title(void)
{
    @autoreleasepool {
        NSWindow *window = [NSApp keyWindow] ?: [[NSApp windows] firstObject];
        return [[window title] isEqualToString:@"Cocoa baseline smoke"];
    }
}

void fb_cocoa_test_checkpoint(int checkpoint)
{
    fprintf(stderr, "Cocoa smoke checkpoint %d\n", checkpoint);
}
