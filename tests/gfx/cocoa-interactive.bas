' Human-operated Cocoa qualification probe. Compile with the staged fbc.
#include "fbgfx.bi"
using fb

dim flags as integer
select case lcase(command(1))
case "fullscreen": flags = fb.GFX_FULLSCREEN
case "borderless": flags = fb.GFX_NO_FRAME
case "floating": flags = fb.GFX_ALWAYS_ON_TOP
end select

if screenres(640, 480, 32, 1, flags) <> 0 then
    print "Could not open Cocoa graphics"
    end 1
end if
windowtitle "FreeBASIC-NG Cocoa interactive probe"

line (0, 0)-(15, 15), rgb(255, 0, 0), bf
line (624, 0)-(639, 15), rgb(0, 255, 0), bf
line (0, 464)-(15, 479), rgb(0, 0, 255), bf
line (624, 464)-(639, 479), rgb(255, 255, 0), bf
locate 3, 1
print "Esc: exit  C: cursor  P: move window  T: rename"
print "Check keyboard/text, mouse, wheel, focus, close and four corners."

dim e as fb.Event
dim visible as integer = 1
dim moved as integer
dim renamed as integer
dim running as integer = 1
do while running
    if screenevent(@e) then
        locate 7, 1
        select case e.type
        case fb.EVENT_KEY_PRESS
            print "key down: SC="; e.scancode; " CP437="; e.ascii; "         "
            select case e.scancode
            case fb.SC_ESCAPE
                running = 0
            case fb.SC_C
                visible = 1 - visible
                setmouse -1, -1, visible, 0
            case fb.SC_P
                moved = 1 - moved
                screencontrol fb.SET_WINDOW_POS, 80 + moved * 80, 80
            case fb.SC_T
                renamed = 1 - renamed
                if renamed then
                    windowtitle "FreeBASIC-NG Cocoa probe: renamed"
                else
                    windowtitle "FreeBASIC-NG Cocoa interactive probe"
                end if
            end select
        case fb.EVENT_KEY_RELEASE
            print "key up: SC="; e.scancode; "                   "
        case fb.EVENT_MOUSE_MOVE
            print "mouse:"; e.x; ","; e.y; " delta:"; e.dx; ","; e.dy; "       "
        case fb.EVENT_MOUSE_BUTTON_PRESS
            print "button down:"; e.button; "                       "
        case fb.EVENT_MOUSE_BUTTON_RELEASE
            print "button up:"; e.button; "                         "
        case fb.EVENT_MOUSE_WHEEL
            print "wheel:"; e.z; "                             "
        case fb.EVENT_MOUSE_HWHEEL
            print "horizontal wheel:"; e.w; "                  "
        case fb.EVENT_WINDOW_GOT_FOCUS
            print "window focused                             "
        case fb.EVENT_WINDOW_LOST_FOCUS
            print "window unfocused                           "
        case fb.EVENT_WINDOW_CLOSE
            running = 0
        end select
    end if
    sleep 10
loop

screen 0
