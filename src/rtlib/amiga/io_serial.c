/* AmigaOS serial port via serial.device */
#include "../fb.h"

#if defined(HOST_AMIGAOS)
#include <proto/exec.h>
#include <devices/serial.h>

extern struct ExecBase *SysBase;

typedef struct {
    struct MsgPort *port;
    struct IOExtSer *io;
    int is_open;
} AMIGA_SERIAL;

int fb_SerialOpen(FB_FILE *handle, int iPort, FB_SERIAL_OPTIONS *options,
                  const char *pszDevice, void **ppvHandle) {
    AMIGA_SERIAL *ser = (AMIGA_SERIAL *)malloc(sizeof(AMIGA_SERIAL));
    if (!ser) return fb_ErrorSetNum(FB_RTERROR_OUTOFMEM);

    ser->port = CreateMsgPort();
    if (!ser->port) { free(ser); return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }

    ser->io = (struct IOExtSer *)CreateIORequest(ser->port, sizeof(struct IOExtSer));
    if (!ser->io) { DeleteMsgPort(ser->port); free(ser); return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }

    if (OpenDevice("serial.device", iPort, (struct IORequest *)ser->io, 0)) {
        DeleteIORequest((struct IORequest *)ser->io);
        DeleteMsgPort(ser->port);
        free(ser);
        return fb_ErrorSetNum(FB_RTERROR_FILENOTFOUND);
    }

    /* Set baud rate if specified */
    if (options && options->speed > 0) {
        ser->io->io_Baud = options->speed;
        ser->io->IOSer.io_Command = SDCMD_SETPARAMS;
        DoIO((struct IORequest *)ser->io);
    }

    ser->is_open = 1;
    *ppvHandle = ser;
    return fb_ErrorSetNum(FB_RTERROR_OK);
}

int fb_SerialWrite(FB_FILE *handle, void *pvHandle, const void *data, size_t length) {
    AMIGA_SERIAL *ser = (AMIGA_SERIAL *)pvHandle;
    if (!ser || !ser->is_open) return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL);

    ser->io->IOSer.io_Command = CMD_WRITE;
    ser->io->IOSer.io_Data = (APTR)data;
    ser->io->IOSer.io_Length = length;
    DoIO((struct IORequest *)ser->io);
    return fb_ErrorSetNum(FB_RTERROR_OK);
}

int fb_SerialRead(FB_FILE *handle, void *pvHandle, void *data, size_t *pLength) {
    AMIGA_SERIAL *ser = (AMIGA_SERIAL *)pvHandle;
    if (!ser || !ser->is_open) return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL);

    ser->io->IOSer.io_Command = CMD_READ;
    ser->io->IOSer.io_Data = data;
    ser->io->IOSer.io_Length = *pLength;
    DoIO((struct IORequest *)ser->io);
    *pLength = ser->io->IOSer.io_Actual;
    return fb_ErrorSetNum(FB_RTERROR_OK);
}

int fb_SerialGetRemaining(FB_FILE *handle, void *pvHandle, fb_off_t *pLength) {
    AMIGA_SERIAL *ser = (AMIGA_SERIAL *)pvHandle;
    if (!ser || !ser->is_open) { *pLength = 0; return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }

    ser->io->IOSer.io_Command = SDCMD_QUERY;
    DoIO((struct IORequest *)ser->io);
    *pLength = ser->io->IOSer.io_Actual;
    return fb_ErrorSetNum(FB_RTERROR_OK);
}

int fb_SerialClose(FB_FILE *handle, void *pvHandle) {
    AMIGA_SERIAL *ser = (AMIGA_SERIAL *)pvHandle;
    if (!ser) return fb_ErrorSetNum(FB_RTERROR_OK);

    if (ser->is_open) {
        CloseDevice((struct IORequest *)ser->io);
        ser->is_open = 0;
    }
    DeleteIORequest((struct IORequest *)ser->io);
    DeleteMsgPort(ser->port);
    free(ser);
    return fb_ErrorSetNum(FB_RTERROR_OK);
}

#else
/* AROS/MorphOS - stub for now */
int fb_SerialOpen(FB_FILE *handle, int iPort, FB_SERIAL_OPTIONS *options,
                  const char *pszDevice, void **ppvHandle) {
    return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL);
}
int fb_SerialWrite(FB_FILE *handle, void *pvHandle, const void *data, size_t length) { return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }
int fb_SerialRead(FB_FILE *handle, void *pvHandle, void *data, size_t *pLength) { return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }
int fb_SerialGetRemaining(FB_FILE *handle, void *pvHandle, fb_off_t *pLength) { return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }
int fb_SerialClose(FB_FILE *handle, void *pvHandle) { return fb_ErrorSetNum(FB_RTERROR_ILLEGALFUNCTIONCALL); }
#endif
