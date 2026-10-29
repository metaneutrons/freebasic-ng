#include <clib/debug_protos.h>
#include <dos/dos.h>
#include <proto/dos.h>

int main(int argc, char **argv)
{
    BPTR output;
    BPTR previous_output;
    BPTR segment;
    LONG result;

    if (argc != 2) {
        return RETURN_FAIL;
    }

    KPrintF("FBNG:BEGIN\n");
    output = Open("NIL:", MODE_NEWFILE);
    if (output == 0) {
        KPrintF("FBNG:EXIT=%ld\n", RETURN_FAIL);
        return RETURN_FAIL;
    }

    segment = LoadSeg(argv[1]);
    if (segment == 0) {
        Close(output);
        KPrintF("FBNG:EXIT=%ld\n", RETURN_ERROR);
        return RETURN_ERROR;
    }

    previous_output = SelectOutput(output);
    result = RunCommand(segment, 65536, "", 0);
    SelectOutput(previous_output);
    UnLoadSeg(segment);
    Close(output);

    if (result == RETURN_OK) {
        KPrintF("FBNG:PROGRAM=PASS\n");
    }
    KPrintF("FBNG:EXIT=%ld\n", result);
    return result;
}
