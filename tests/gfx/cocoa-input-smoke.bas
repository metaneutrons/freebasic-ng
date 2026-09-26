' Native Cocoa event/window smoke; run via scripts/verify-cocoa-gfx.py.
#include "fbgfx.bi"
using fb

declare sub test_key cdecl alias "fb_cocoa_test_key" (byval code as integer, byval text as zstring ptr, byval kind as integer)
declare sub test_mouse cdecl alias "fb_cocoa_test_mouse" (byval kind as integer, byval x as integer, byval y as integer)
declare sub test_close cdecl alias "fb_cocoa_test_close" ()
declare sub test_focus_lost cdecl alias "fb_cocoa_test_focus_lost" ()
declare function test_window cdecl alias "fb_cocoa_test_window" (byval flag as integer) as integer

dim e as fb.Event
dim found as integer

if screenres(96, 64, 32, 1, fb.GFX_NO_FRAME or fb.GFX_ALWAYS_ON_TOP) <> 0 then end 10
screencontrol fb.POLL_EVENTS
if test_window(0) = 0 or test_window(1) = 0 then end 11
while screenevent(@e): wend

' Physical A is scancode 0x1e; typed character comes from the layout text.
test_key(&h00, "a", 0)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_KEY_PRESS and e.scancode = fb.SC_A and e.ascii = asc("a") then found = 1
wend
if found = 0 or multikey(fb.SC_A) = 0 or inkey$ <> "a" then end 12
test_key(&h00, "a", 1)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_KEY_RELEASE and e.scancode = fb.SC_A then found = 1
wend
if found = 0 or multikey(fb.SC_A) <> 0 then end 13

' F1 has no text byte; a German umlaut is representable in CP437.
test_key(&h7a, "", 0)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_KEY_PRESS and e.scancode = fb.SC_F1 and e.ascii = 0 then found = 1
wend
if found = 0 or multikey(fb.SC_F1) = 0 then end 28
test_key(&h7a, "", 1)
while screenevent(@e): wend
if multikey(fb.SC_F1) <> 0 then end 29
dim utf8_umlaut as string = chr(195, 164)
test_key(&h00, utf8_umlaut, 0)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_KEY_PRESS and e.ascii = &h84 then found = 1
wend
if found = 0 then end 30
test_key(&h00, utf8_umlaut, 1)
while screenevent(@e): wend

' Numeric keypad text takes precedence over its DOS navigation scancode.
while inkey$ <> "": wend
test_key(&h53, "1", 0)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_KEY_PRESS and e.scancode = fb.SC_END and e.ascii = asc("1") then found = 1
wend
if found = 0 or inkey$ <> "1" then end 31
test_key(&h53, "1", 1)
while screenevent(@e): wend

test_key(&h00, "a", 0)
while screenevent(@e): wend
test_focus_lost()
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_WINDOW_LOST_FOCUS then found = 1
wend
if found = 0 or multikey(fb.SC_A) <> 0 then end 27

test_mouse(0, 16, 24)
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_MOUSE_MOVE and e.x = 16 and e.y = 24 then found = 1
wend
if found = 0 then end 14
dim mx as integer, my as integer, mz as integer, mb as integer
if getmouse(mx, my, mz, mb) <> 0 or mx <> 16 or my <> 24 then end 15
test_mouse(1, 16, 24)
while screenevent(@e): wend
if getmouse(mx, my, mz, mb) <> 0 or (mb and fb.BUTTON_LEFT) = 0 then end 16
test_mouse(2, 16, 24)
while screenevent(@e): wend
if getmouse(mx, my, mz, mb) <> 0 or mb <> 0 then end 17

windowtitle "Cocoa input smoke"
dim title as string
screencontrol fb.GET_WINDOW_TITLE, title
if title <> "Cocoa input smoke" then end 18
screencontrol fb.SET_WINDOW_POS, 40, 50
dim wx as integer, wy as integer
screencontrol fb.GET_WINDOW_POS, wx, wy
if abs(wx - 40) > 1 or abs(wy - 50) > 1 then end 19

test_close()
found = 0
while screenevent(@e)
    if e.type = fb.EVENT_WINDOW_CLOSE then found = 1
wend
if found = 0 then end 20

#ifdef FB_COCOA_MT
dim shared worker_result as integer
sub worker(byval unused as any ptr)
    worker_result = screenres(32, 32, 32)
    windowtitle "Worker title"
end sub
dim thread as any ptr = threadcreate(@worker)
if thread = 0 then end 21
threadwait(thread)
if worker_result = 0 then end 22
screencontrol fb.POLL_EVENTS
screencontrol fb.GET_WINDOW_TITLE, title
if title <> "Worker title" then end 23
dim sw as integer, sh as integer
screencontrol fb.GET_SCREEN_SIZE, sw, sh
if sw <> 96 or sh <> 64 then end 24
#endif

screen 0
if screenres(64, 48, 32, 1, fb.GFX_FULLSCREEN) <> 0 then end 25
if test_window(0) = 0 or test_window(3) < 64 or test_window(4) < 48 then end 26
screen 0
print "Cocoa input/window smoke passed"
