#include "pipeline/decode.h"


int decode(Emulator *emu, EMU_Decoded_Instruction *instruction){

    u64 raw_instruction = instruction->raw_instruction;

    switch(instruction->addressing_mode){

        case ADDR_REG:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0f; 
            instruction->operands[1] = (raw_instruction >> 12) & 0x0f;
            instruction->operands[2] = (raw_instruction >> 16) & 0x0f; 
            break;

        case ADDR_REG_INDIRECT:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0ff; 
            break;

        case ADDR_REG_INDEX_EIGHT:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0ff; 
            instruction->operands[1] = (raw_instruction >> 16) & 0xff; 
            break;

        case ADDR_REG_INDEX_SIXTEEN:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0ff; 
            instruction->operands[1] = (raw_instruction >> 16) & 0xffff; 
            break;

        case ADDR_REG_IMMEDIATE_EIGHT:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0f; 
            instruction->operands[1] = (raw_instruction >> 12) & 0x0f;
            instruction->operands[2] = (raw_instruction >> 16) & 0xff; 
            break;

        case ADDR_REG_IMMEDIATE_SIXTEEN:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0f; 
            instruction->operands[1] = (raw_instruction >> 12) & 0x0f;
            instruction->operands[2] = (raw_instruction >> 16) & 0xffff; 
            break;

        case ADDR_IMMEDIATE_EIGHT:
            instruction->operands[0] = (raw_instruction >> 8) & 0x0f; 
            break;
            
        case ADDR_IMMEDIATE_SIXTEEN:
            instruction->operands[0] = (raw_instruction >> 8) & 0xff; 
            break;
    }
   

    return 0;
}