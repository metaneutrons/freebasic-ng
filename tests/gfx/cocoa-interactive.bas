' Human-operated Cocoa qualification probe. Compile with the staged fbc.
'
' Every event type keeps its own row with a running count, so a burst of mouse
' movement cannot overwrite a key, button or focus event before it is read.
' The GETMOUSE and state rows are polled and show the current values.
#include "fbgfx.bi"
using fb

const ROW_WIDTH = 79
const LABEL_WIDTH = 17
const TEXT_WIDTH = 55

enum ProbeRow
    ROW_KEY_DOWN = 7
    ROW_KEY_REPEAT
    ROW_KEY_UP
    ROW_TEXT
    ROW_MOUSE_MOVE = 12
    ROW_GETMOUSE
    ROW_BUTTON_DOWN
    ROW_BUTTON_UP
    ROW_DOUBLE_CLICK
    ROW_WHEEL
    ROW_HWHEEL
    ROW_MOUSE_ENTER
    ROW_MOUSE_EXIT
    ROW_FOCUS_GAINED = 22
    ROW_FOCUS_LOST
    ROW_STATE = 25
    ROW_OTHER
end enum

' Indexed by the fb.EVENT_* value. A row of 0 means the event has no row.
dim shared labels(1 to 14) as string
dim shared rows(1 to 14) as integer
dim shared counts(1 to 14) as integer
dim shared other_count as integer

sub assign(byval event_type as integer, byref label as const string, byval row as integer)
    labels(event_type) = label
    rows(event_type) = row
end sub

sub show_row(byval row as integer, byref label as const string, byref detail as const string)
    locate row, 1
    print left(left(label & space(LABEL_WIDTH), LABEL_WIDTH) & detail & space(ROW_WIDTH), ROW_WIDTH);
end sub

function counted(byval count as integer, byref detail as const string) as string
    return "[" & count & "] " & detail
end function

sub record(byref e as fb.Event, byref detail as const string)
    if e.type >= 1 andalso e.type <= 14 andalso rows(e.type) <> 0 then
        counts(e.type) += 1
        show_row rows(e.type), labels(e.type), counted(counts(e.type), detail)
    else
        other_count += 1
        show_row ROW_OTHER, "other event", counted(other_count, "type=" & e.type)
    end if
end sub

function key_detail(byref e as fb.Event) as string
    dim s as string = "SC=" & e.scancode & " CP437=" & e.ascii
    if e.ascii >= 32 then
        s &= " '" & chr(e.ascii) & "'"
    end if
    return s
end function

assign fb.EVENT_KEY_PRESS, "key down", ROW_KEY_DOWN
assign fb.EVENT_KEY_REPEAT, "key repeat", ROW_KEY_REPEAT
assign fb.EVENT_KEY_RELEASE, "key up", ROW_KEY_UP
assign fb.EVENT_MOUSE_MOVE, "mouse move", ROW_MOUSE_MOVE
assign fb.EVENT_MOUSE_BUTTON_PRESS, "button down", ROW_BUTTON_DOWN
assign fb.EVENT_MOUSE_BUTTON_RELEASE, "button up", ROW_BUTTON_UP
assign fb.EVENT_MOUSE_DOUBLE_CLICK, "double click", ROW_DOUBLE_CLICK
assign fb.EVENT_MOUSE_WHEEL, "wheel", ROW_WHEEL
assign fb.EVENT_MOUSE_HWHEEL, "horizontal wheel", ROW_HWHEEL
assign fb.EVENT_MOUSE_ENTER, "mouse entered", ROW_MOUSE_ENTER
assign fb.EVENT_MOUSE_EXIT, "mouse left", ROW_MOUSE_EXIT
assign fb.EVENT_WINDOW_GOT_FOCUS, "focus gained", ROW_FOCUS_GAINED
assign fb.EVENT_WINDOW_LOST_FOCUS, "focus lost", ROW_FOCUS_LOST
' A close request ends the probe, so it has no row; the summary reports it.
assign fb.EVENT_WINDOW_CLOSE, "close request", 0

dim flags as integer
dim mode as string = lcase(command(1))
select case mode
case "fullscreen": flags = fb.GFX_FULLSCREEN
case "borderless": flags = fb.GFX_NO_FRAME
case "floating": flags = fb.GFX_ALWAYS_ON_TOP
case else: mode = "normal"
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
print "Cocoa interactive probe, mode: "; mode
print "Esc: exit  C: cursor  P: move window  T: rename  Backspace: edit text"
print "Each row keeps the last event of its kind; [n] counts them."

dim t as integer
for t = 1 to 14
    if rows(t) <> 0 then
        show_row rows(t), labels(t), counted(0, "-")
    end if
next
dim typed as string
show_row ROW_TEXT, "text", counted(0, "")

dim e as fb.Event
dim visible as integer = 1
dim moved as integer
dim renamed as integer
dim running as integer = 1
dim as long mx, my, mwheel, mbuttons, wx, wy
dim as string polled, shown_getmouse, shown_state

do while running
    ' Drain the queue on every pass so a flood of mouse movement cannot
    ' delay a key or focus event behind it.
    do while running andalso screenevent(@e)
        select case e.type
        case fb.EVENT_KEY_PRESS, fb.EVENT_KEY_REPEAT
            record e, key_detail(e)
            if e.ascii = 8 then
                typed = left(typed, len(typed) - 1)
            elseif e.ascii >= 32 andalso e.ascii <> 127 then
                typed = right(typed & chr(e.ascii), TEXT_WIDTH)
            end if
            show_row ROW_TEXT, "text", counted(len(typed), typed)
            if e.type = fb.EVENT_KEY_PRESS then
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
            end if
        case fb.EVENT_KEY_RELEASE
            record e, "SC=" & e.scancode
        case fb.EVENT_MOUSE_MOVE
            record e, "x=" & e.x & " y=" & e.y & " dx=" & e.dx & " dy=" & e.dy
        case fb.EVENT_MOUSE_BUTTON_PRESS, fb.EVENT_MOUSE_BUTTON_RELEASE, _
             fb.EVENT_MOUSE_DOUBLE_CLICK
            record e, "button=" & e.button
        case fb.EVENT_MOUSE_WHEEL
            record e, "z=" & e.z
        case fb.EVENT_MOUSE_HWHEEL
            record e, "w=" & e.w
        case fb.EVENT_WINDOW_CLOSE
            counts(fb.EVENT_WINDOW_CLOSE) += 1
            running = 0
        case else
            record e, "seen"
        end select
    loop

    if getmouse(mx, my, mwheel, mbuttons) = 0 then
        polled = "x=" & mx & " y=" & my & " wheel=" & mwheel & " buttons=" & mbuttons
    else
        polled = "pointer outside the window"
    end if
    if polled <> shown_getmouse then
        show_row ROW_GETMOUSE, "GETMOUSE", polled
        shown_getmouse = polled
    end if

    screencontrol fb.GET_WINDOW_POS, wx, wy
    polled = "cursor " & iif(visible, "shown", "hidden") & _
             ", window at " & wx & "," & wy & _
             ", title " & iif(renamed, "renamed", "original")
    if polled <> shown_state then
        show_row ROW_STATE, "state", polled
        shown_state = polled
    end if

    sleep 10
loop

screen 0

' Printed to the terminal after the window closes, for the qualification record.
print "Cocoa interactive probe, mode: "; mode
for t = 1 to 14
    print labels(t); ": "; counts(t)
next
print "other events: "; other_count
print "text: "; typed
