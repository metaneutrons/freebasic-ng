/* Synthetic AppKit events for a native, window-backed FreeBASIC smoke test. */
#import <Cocoa/Cocoa.h>

static NSWindow *test_window(void)
{
    return [NSApp keyWindow] ?: [[NSApp windows] firstObject];
}

void fb_cocoa_test_key(int code, const char *text, int kind)
{
    NSWindow *window = test_window();
    NSString *characters = [NSString stringWithUTF8String:text] ?: @"";
    NSEventType type = kind == 0 ? NSEventTypeKeyDown :
                       kind == 1 ? NSEventTypeKeyUp : NSEventTypeFlagsChanged;
    NSEvent *event = [NSEvent keyEventWithType:type location:NSZeroPoint
        modifierFlags:0 timestamp:0 windowNumber:window.windowNumber
        context:nil characters:characters charactersIgnoringModifiers:characters
        isARepeat:NO keyCode:(unsigned short)code];
    [NSApp postEvent:event atStart:NO];
}

void fb_cocoa_test_mouse(int kind, int x, int y)
{
    NSWindow *window = test_window();
    NSView *view = window.contentView;
    NSPoint location = [view convertPoint:NSMakePoint(x, y) toView:nil];
    NSEventType type = kind == 0 ? NSEventTypeMouseMoved :
                       kind == 1 ? NSEventTypeLeftMouseDown : NSEventTypeLeftMouseUp;
    NSEvent *event = [NSEvent mouseEventWithType:type location:location
        modifierFlags:0 timestamp:0 windowNumber:window.windowNumber
        context:nil eventNumber:0 clickCount:1 pressure:1];
    [NSApp postEvent:event atStart:NO];
}

void fb_cocoa_test_close(void)
{
    NSWindow *window = test_window();
    [window.delegate windowShouldClose:window];
}

void fb_cocoa_test_focus_lost(void)
{
    NSWindow *window = test_window();
    [window.delegate windowDidResignKey:
        [NSNotification notificationWithName:NSWindowDidResignKeyNotification object:window]];
}

int fb_cocoa_test_window(int flag)
{
    NSWindow *window = test_window();
    if (flag == 0) return window.styleMask == NSWindowStyleMaskBorderless;
    if (flag == 1) return window.level == NSFloatingWindowLevel;
    if (flag == 2) return window.isKeyWindow;
    if (flag == 3) return (int)window.contentView.bounds.size.width;
    if (flag == 4) return (int)window.contentView.bounds.size.height;
    return 0;
}
