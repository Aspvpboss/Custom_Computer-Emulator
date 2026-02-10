#ifndef EMULATOR_H
#define EMULATOR_H

#include "my_stdtypes.h"
#include "SDK.h"


typedef struct{

    SDK_Input *input;
    SDK_Display *display;

} SDK_IO;


typedef struct{

    u8 memory[0xffff];
    SDK_IO sdk_io;

} Emulator;


#endif