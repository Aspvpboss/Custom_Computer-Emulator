#include "pipeline/fetch.h"
#include "pipeline/execute.h"
#include "debug.h"


u32 fetch(Emulator *emu){

    u8 *ram = emu->ram;

    if(emu->program_counter == __UINT16_MAX__ / 2){
        emu->program_counter = 0;
    } 
    
    u8 opcode = ram[emu->program_counter];
    u32 instruction = 0;
    instruction |= opcode;
    
    u8 extra_bytes = 0;

    // flag addressing modes
    switch((EMU_Addressing_Modes)(opcode >> 5)){

        case ADDR_REG:
            extra_bytes = 3;
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

        case ADDR_PC_RELATIVE_SIXTEEN:
            extra_bytes = 3;
            break;

        case ADDR_PC_RELATIVE_EIGHT:
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
        instruction |= ((u32)ram[emu->program_counter] << (8 * i));
        if(emu->program_counter == __UINT16_MAX__ / 2){
            emu->program_counter = 0;
        } 
    }


    emu->program_counter++;

    return instruction;
}
