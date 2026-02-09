#ifndef EMULATOR_H
#define EMULATOR_H

#include "my_stdtypes.h"
#include "SDK.h"

typedef struct{

    u8 memory[0xffff];
    SDK_Input *input;
    SDK_Display *display;

} Emulator;


#endif