#ifndef EMU_CORE__
#define EMU_CORE__

#include "my_stdtypes.h"
#include "MemTrack.h"

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


enum CMP_FlagMasks{

    CMP_EQU = 1 << 0,
    CMP_NEQ = 1 << 1,
    CMP_IF0 = 1 << 2,
    
    CMP_ULT = 1 << 3,
    CMP_ULE = 1 << 4,
    CMP_UGR = 1 << 5,
    CMP_UGE = 1 << 6,
    
    CMP_SLT = 1 << 7,
    CMP_SLE = 1 << 8,
    CMP_SGR = 1 << 9,
    CMP_SGE = 1 << 10,
    
    CMP_CAR = 1 << 11,
    CMP_OVER = 1 << 12,

};

typedef u16 CMP_Flags;


// ALU functions

typedef void (*ALU_add)(u16, u16, u16*);
typedef void (*ALU_sub)(u16, u16, u16*);
typedef void (*ALU_mul)(u16, u16, u16*);
typedef void (*ALU_div)(u16, u16, u16*);
typedef void (*ALU_mod)(u16, u16, u16*);
typedef void (*ALU_and)(u16, u16, u16*);
typedef void (*ALU_nor)(u16, u16, u16*);
typedef void (*ALU_xor)(u16, u16, u16*);
typedef void (*ALU_cmp)(u16, u16, CMP_Flags*);

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


typedef void (*FPU_add)(f16, f16, f16*);
typedef void (*FPU_sub)(f16, f16, f16*);
typedef void (*FPU_mul)(f16, f16, f16*);
typedef void (*FPU_div)(f16, f16, f16*);
typedef void (*FPU_sqrt)(f16, f16, f16*);
typedef void (*FPU_cmp)(f16, f16, CMP_Flags*);


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
    CMP_Flags flags;

} EMU_Core;




void alu_cmp(u16 a, u16 b, CMP_Flags *dst);


#endif