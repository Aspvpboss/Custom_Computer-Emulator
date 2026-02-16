#include "pipeline/fetch.h"
#include "pipeline/execute.h"
#include "debug.h"


i64 fetch(Emulator *emu){

    i32 instruction = 0;

    u8 opcode = emu->ram[emu->program_counter];

    u8 byte_amount = 0;

    // flag addressing modes
    switch(opcode >> 5){


        default:
            return -1;
    }

    d_printf("%d\n", byte_amount);

    return (i64)instruction;
}

