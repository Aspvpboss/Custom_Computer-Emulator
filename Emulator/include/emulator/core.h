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

// ALU functions

typedef int (*ALU_add)(u16, u16, u16*);
typedef int (*ALU_sub)(u16, u16, u16*);
typedef int (*ALU_mul)(u16, u16, u16*);
typedef int (*ALU_div)(u16, u16, u16*);
typedef int (*ALU_mod)(u16, u16, u16*);
typedef int (*ALU_and)(u16, u16, u16*);
typedef int (*ALU_nor)(u16, u16, u16*);
typedef int (*ALU_xor)(u16, u16, u16*);
typedef int (*ALU_cmp)(u16, u16);

typedef struct{

    u16 registers[ALU_REG_AMOUNT];
    ALU_add add;
    ALU_sub sub;
    ALU_mul mul;
    ALU_div div;
    ALU_mod mod;
    ALU_and and;
    ALU_nor nor;
    ALU_xor xor;
    ALU_cmp cmp;

} EMU_Alu;


typedef int (*FPU_add)(f16, f16, f16*);
typedef int (*FPU_sub)(f16, f16, f16*);
typedef int (*FPU_mul)(f16, f16, f16*);
typedef int (*FPU_div)(f16, f16, f16*);
typedef int (*FPU_sqrt)(f16, f16, f16*);
typedef int (*FPU_cmp)(f16, f16);


typedef struct{

    FPU_add add;
    FPU_sub sub;
    FPU_mul mul;
    FPU_div div;
    FPU_sqrt sqrt;
    FPU_cmp cmp;
    f16 registers[FPU_REG_AMOUNT];

} EMU_Fpu;



typedef struct{

    EMU_Alu alu;
    EMU_Fpu fpu;

} EMU_Core;

#endif