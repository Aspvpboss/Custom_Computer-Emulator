#ifndef EMULATOR_H
#define EMULATOR_H

#include "my_stdtypes.h"
#include "SDK.h"
#include "emulator/alu.h"
#include "emulator/fpu.h"


typedef struct{

    SDK_Input *input;
    SDK_Display *display;

} SDK_IO;


typedef struct{

    u8 ram[0x7fff];
    SDK_IO sdk_io;
    EMU_Alu alu;
    EMU_Fpu fpu;
    CMP_Flags flags;

} Emulator;


#endif