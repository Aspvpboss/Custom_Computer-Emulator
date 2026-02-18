#ifndef EMU_EXECUTE_H_
#define EMU_EXECUTE_H_

#include "emulator/emulator.h"

typedef enum{

    ADDR_REG,
    ADDR_REG_INDIRECT,
    ADDR_REG_INDEX_EIGHT,
    ADDR_REG_INDEX_SIXTEEN,
    ADDR_REG_IMMEDIATE_EIGHT,
    ADDR_REG_IMMEDIATE_SIXTEEN,
    ADDR_IMMEDIATE_EIGHT,
    ADDR_IMMEDIATE_SIXTEEN

} EMU_Addressing_Modes;

typedef enum{

    EMU_LOAD,
    EMU_STR,
    EMU_PUSH,
    EMU_POP,
    EMU_LDI,
    EMU_MOV,
    EMU_SYSCALL,
    EMU_JMP,
    EMU_JIF,
    EMU_CAL,
    EMU_CIF,
    EMU_RET,
    EMU_ADD,
    EMU_SUB,
    EMU_MUL,
    EMU_DIV,
    EMU_MOD,
    EMU_CMP,
    EMU_AND,
    EMU_NOR,
    EMU_XOR,
    EMU_ARS,
    EMU_LRS,
    EMU_LLS,
    EMU_FADD,
    EMU_FSUB,
    EMU_FMUL,
    EMU_FDIV,
    EMU_FSQRT,
    EMU_FCMP,
    EMU_FINT,
    EMU_IFLO

} EMU_Instructions;




int execute(Emulator *emu, u32 instruction);

#endif