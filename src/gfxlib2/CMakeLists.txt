# src/gfxlib2/CMakeLists.txt
# FreeBASIC Graphics Library (libfbgfx)

# --- Collect source files ---
file(GLOB GFXLIB_COMMON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

if(WIN32)
    file(GLOB GFXLIB_PLATFORM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/win32/*.c")
elseif(FB_TARGET_OS STREQUAL "darwin" AND NOT FB_ENABLE_XQUARTZ)
    # The native backend owns the platform hooks and driver list.  Do not also
    # compile gfx_unix.c, which only registers X11 (or an empty driver list).
    set(GFXLIB_PLATFORM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/darwin/gfx_cocoa.m")
    set_source_files_properties(${GFXLIB_PLATFORM_SOURCES}
        PROPERTIES COMPILE_OPTIONS "-fobjc-arc")
    set(FB_DISABLE_X11 ON)
    set(FB_DISABLE_OPENGL ON)
elseif(UNIX)
    # Base unix source (always needed)
    set(GFXLIB_UNIX_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_unix.c")

    # Darwin builds the X11 driver only with XQuartz; libfb decides the same
    # way, and this directory has its own variable scope.
    if(FB_TARGET_OS STREQUAL "darwin" AND NOT FB_ENABLE_XQUARTZ)
        set(FB_DISABLE_X11 ON)
    endif()

    # X11 sources (only if X11 is available)
    if(NOT FB_DISABLE_X11)
        find_package(X11)
        if(X11_FOUND)
            list(APPEND GFXLIB_UNIX_SOURCES
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_x11.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_x11_icon_stub.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_driver_x11.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_driver_opengl_x11.c"
            )
        else()
            set(FB_DISABLE_X11 ON)
        endif()
    endif()

    # FB's OpenGL support lives in the X11 driver: gfx_driver_opengl_x11.c is
    # the only unix translation unit that defines fb_hGL_GetProcAddress().
    # Without it, gfx_opengl.c still calls that hook and libfbgfx keeps an
    # undefined symbol that surfaces when a user program is linked.
    if(FB_DISABLE_X11)
        set(FB_DISABLE_OPENGL ON)
    endif()

    # OS-specific overrides
    if(FB_TARGET_OS STREQUAL "linux")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/linux/*.c")
    elseif(FB_TARGET_OS STREQUAL "freebsd")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/freebsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "openbsd")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/openbsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "dragonfly")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/dragonfly/*.c")
    endif()

    set(GFXLIB_PLATFORM_SOURCES ${GFXLIB_UNIX_SOURCES} ${GFXLIB_OS_SOURCES})
endif()

# x86 asm sources
if(FB_TARGET_ARCH STREQUAL "x86" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/x86")
    file(GLOB GFXLIB_ARCH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/x86/*.s")
    # The x86 MMX sources include fb_gfx_mmx.h and were historically built
    # with GCC's preprocessed-assembly mode.
    set_source_files_properties(${GFXLIB_ARCH_SOURCES}
        PROPERTIES COMPILE_OPTIONS "-x;assembler-with-cpp")
endif()

set(GFXLIB_ALL_SOURCES ${GFXLIB_COMMON_SOURCES} ${GFXLIB_PLATFORM_SOURCES} ${GFXLIB_ARCH_SOURCES})

function(fb_add_gfxlib_variant target)
    cmake_parse_arguments(_fb_gfx "MULTITHREADED;PIC" "" "" ${ARGN})

    add_library(${target} STATIC ${GFXLIB_ALL_SOURCES})
    target_include_directories(${target} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "$<$<PLATFORM_ID:Darwin,Linux,FreeBSD,OpenBSD,NetBSD>:${CMAKE_CURRENT_SOURCE_DIR}/unix>"
        "$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/win32>"
        "${CMAKE_SOURCE_DIR}/src/rtlib"
    )
    target_compile_options(${target} PRIVATE
        -Wfatal-errors -O2
        -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
        -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
    )
    if(_fb_gfx_PIC)
        target_compile_options(${target} PRIVATE -fPIC)
    endif()
    if(FB_COMPILER_DEBUG)
        target_compile_options(${target} PRIVATE -g -UNDEBUG -Werror)
        target_compile_definitions(${target} PRIVATE DEBUG)
    endif()
    if(_fb_gfx_MULTITHREADED)
        target_compile_definitions(${target} PRIVATE ENABLE_MT)
    endif()
    if(FB_DISABLE_X11)
        target_compile_definitions(${target} PRIVATE DISABLE_X11)
    endif()
    if(FB_DISABLE_OPENGL)
        target_compile_definitions(${target} PRIVATE DISABLE_OPENGL)
    endif()

    # X11 include dirs (if found above)
    if(UNIX AND NOT FB_DISABLE_X11 AND X11_FOUND)
        target_include_directories(${target} PRIVATE ${X11_INCLUDE_DIR})
    endif()
endfunction()

# fbc composes the mt and pic suffixes independently.  Build the same matrix
# here so every archive it can select has a matching staged installation.
set(GFXLIB_TARGETS fbgfx fbgfxmt)
fb_add_gfxlib_variant(fbgfx)
fb_add_gfxlib_variant(fbgfxmt MULTITHREADED)
if(FB_NEED_PIC)
    list(APPEND GFXLIB_TARGETS fbgfxpic fbgfxmtpic)
    fb_add_gfxlib_variant(fbgfxpic PIC)
    fb_add_gfxlib_variant(fbgfxmtpic MULTITHREADED PIC)
endif()

# --- Installation ---
install(TARGETS ${GFXLIB_TARGETS} ARCHIVE DESTINATION "${FB_INSTALL_LIBDIR}")
