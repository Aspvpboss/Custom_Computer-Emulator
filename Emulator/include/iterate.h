#ifndef EMU_ITERATE_H__
#define EMU_ITERATE_H__

#include "emulator.h"

typedef enum{

    EMU_CONTINUE,
    EMU_SUCCESS,
    EMU_FAILURE

} EMU_Result;

EMU_Result iterate(Emulator *emu);

#endif