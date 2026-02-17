#include "pipeline/fetch.h"
#include "pipeline/execute.h"
#include "debug.h"


i64 fetch(Emulator *emu){

    u8 *ram = emu->ram;

    u8 opcode = ram[emu->program_counter];
    i32 instruction = 0;
    instruction |= opcode;
    
    u8 extra_bytes = 0;

    // flag addressing modes
    switch((EMU_Addressing_Modes)(opcode >> 5)){

        case ADDR_REG:
            extra_bytes = 1;
            break;

        case ADDR_REG_INDIRECT:
            extra_bytes = 1;
            break;

        case ADDR_REG_EIGHT_IMED:
            extra_bytes = 2;
            break;

        case ADDR_REG_SIXTEEN_IMED:
            extra_bytes = 3;
            break;

        case ADDR_PC_COND_RELATIVE_SIXTEEN:
            extra_bytes = 3;
            break;

        case ADDR_PC_RELATIVE_SIXTEEN:
            extra_bytes = 2;
            break;

        case ADDR_IMMEDIATE_EIGHT:
            extra_bytes = 1;
            break;

        case ADDR_IMMEDIATE_SIXTEEN:
            extra_bytes = 2;
            break;

        default:
            return -1;
    }


    for(u8 i = 1; i <= extra_bytes; i++){
        emu->program_counter++;
        instruction |= (ram[emu->program_counter] << (8 * i));
    }

    print_individual_bytes(instruction);

    emu->program_counter = 0;

    return (i64)instruction;
}

