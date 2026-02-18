#include "pipeline/fetch.h"
#include "debug.h"


int fetch(Emulator *emu, EMU_Decoded_Instruction *instruction){

    u8 *ram = emu->ram;

    if(emu->program_counter == __UINT16_MAX__ / 2){
        emu->program_counter = 0;
    } 
    
    u8 extra_bytes = 0;
    u8 opcode = ram[emu->program_counter];
    instruction->raw_instruction |= opcode;
    

    // flag addressing modes
    switch((EMU_Addressing_Modes)(opcode >> 5)){

        case ADDR_REG:
            extra_bytes = 2;
            break;

        case ADDR_REG_INDIRECT:
            extra_bytes = 1;
            break;

        case ADDR_REG_INDEX_EIGHT:
            extra_bytes = 3;
            break;

        case ADDR_REG_INDEX_SIXTEEN:
            extra_bytes = 4;
            break;

        case ADDR_REG_IMMEDIATE_EIGHT:
            extra_bytes = 2;
            break;

        case ADDR_REG_IMMEDIATE_SIXTEEN:
            extra_bytes = 3;
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
        instruction->raw_instruction |= ((u64)ram[emu->program_counter] << (8 * i));
        if(emu->program_counter == __UINT16_MAX__ / 2){
            emu->program_counter = 0;
        } 
    }


    emu->program_counter++;
    emu->program_counter = 0; //debug 

    printf("%d\n", (opcode >> 5));
    print_individual_bytes(instruction->raw_instruction);

    return 0;
}
