' Native Cocoa presentation smoke; run via scripts/verify-cocoa-gfx.py on macOS.
#include "fbgfx.bi"
using fb

declare function cocoa_pixel cdecl alias "fb_cocoa_test_pixel" (byval x as integer, byval y as integer) as integer
declare function cocoa_title cdecl alias "fb_cocoa_test_title" () as integer
declare sub cocoa_checkpoint cdecl alias "fb_cocoa_test_checkpoint" (byval checkpoint as integer)

dim depths(0 to 2) as integer = {8, 16, 32}
for i as integer = 0 to 2
    dim depth as integer = depths(i)
    cocoa_checkpoint(100 + depth)
    if screenres(64, 64, depth, 2) <> 0 then end 10 + i
    windowtitle "Cocoa baseline smoke"
    if cocoa_title() = 0 then end 20 + i

    if depth = 8 then
        palette 1, rgb(255, 0, 0)
        palette 2, rgb(0, 0, 255)
    end if

    screenlock
    pset (4, 4), iif(depth = 8, 1, rgb(255, 0, 0))
    pset (4, 56), iif(depth = 8, 2, rgb(0, 0, 255))
    screenunlock
    dim top_pixel as integer = cocoa_pixel(4, 4)
    dim bottom_pixel as integer = cocoa_pixel(4, 56)
    if ((top_pixel shr 16) and 255) < 200 or _
       ((top_pixel shr 8) and 255) > 100 or _
       (top_pixel and 255) > 100 then end 30 + i
    if ((bottom_pixel shr 16) and 255) > 100 or _
       ((bottom_pixel shr 8) and 255) > 100 or _
       (bottom_pixel and 255) < 200 then end 40 + i

    if depth = 8 then
        ' Changing the palette must recolor pixels already in the framebuffer.
        palette 1, rgb(0, 255, 0)
        dim recolored as integer = cocoa_pixel(4, 4)
        dim green as integer = (recolored shr 8) and 255
        if green < 180 or green < (((recolored shr 16) and 255) + 80) or _
           green < ((recolored and 255) + 80) then end 70
        palette 1, rgb(255, 0, 0)
    end if

    screenset 1, 0
    pset (32, 32), iif(depth = 8, 1, rgb(255, 0, 0))
    screenset 0, 1
    dim page_pixel as integer = cocoa_pixel(32, 32)
    if ((page_pixel shr 16) and 255) < 200 or _
       ((page_pixel shr 8) and 255) > 100 or _
       (page_pixel and 255) > 100 then end 50 + i
    cocoa_checkpoint(200 + depth)
    screen 0
    cocoa_checkpoint(300 + depth)
next

if screenres(64, 64, 32, 1, fb.GFX_OPENGL) = 0 then end 60
print "Cocoa baseline smoke passed"
