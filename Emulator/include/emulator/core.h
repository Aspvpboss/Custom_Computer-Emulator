#ifndef EMU_CORE__
#define EMU_CORE__

#include "my_stdtypes.h"


enum ALU_Registers{

    ALU_ONE,
    ALU_TWO,
    ALU_THREE,
    ALU_FOUR,
    ALU_FIVE,
    ALU_SIX,
    ALU_SEVEN,
    ALU_EIGHT,
    FRAME_POINTER,
    STACK_POINTER,
    ALU_REG_AMOUNT

};

enum FPU_Registers{

    FPU_ONE,
    FPU_TWO,
    FPU_THREE,
    FPU_FOUR,
    FPU_FIVE,
    FPU_SIX,
    FPU_SEVEN,
    FPU_EIGHT,
    FPU_REG_AMOUNT

};



typedef struct{

    u16 registers[ALU_REG_AMOUNT];

} EMU_Alu;

typedef struct{

    f16 registers[FPU_REG_AMOUNT];

} EMU_Fpu;



typedef struct{

    EMU_Alu alu;
    EMU_Fpu fpu;

} EMU_Core;

#endif