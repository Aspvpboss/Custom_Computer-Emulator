#include "emulator/core.h"


// static void alu_add(u16 a, u16 b, u16 *dst){
//     (*dst) = a + b;
// }

// static void alu_sub(u16 a, u16 b, u16 *dst){
//     (*dst) = a - b;
// }

// static void alu_mul(u16 a, u16 b, u16 *dst){
//     (*dst) = a * b;
// }

// static void alu_div(u16 a, u16 b, u16 *dst){
//     (*dst) = (u16)(a / b);
// }

// static void alu_mod(u16 a, u16 b, u16 *dst){
//     (*dst) = (u16)(a % b);
// }

// static void alu_and(u16 a, u16 b, u16 *dst){
//     (*dst) = a & b;
// }

// static void alu_nor(u16 a, u16 b, u16 *dst){
//     (*dst) = ~(a || b);
// }

// static void alu_xor(u16 a, u16 b, u16 *dst){
//     (*dst) = a ^ b;
// }

void alu_cmp(u16 a, u16 b, CMP_Flags *dst){
    
    u16 result = a - b;
    CMP_Flags t_flags = 0;

    if(a == 0){
        t_flags |= CMP_IF0;
    }

    if(result == 0){
        t_flags |= CMP_EQU;
        t_flags |= CMP_ULE;
        t_flags |= CMP_UGE;
    } else{
        t_flags |= CMP_NEQ;
    } 

    if((i16)result < 0){
        t_flags |= CMP_ULT;
        t_flags |= CMP_ULE; 
    }
    if((i16)result > 0){
        t_flags |= CMP_UGR;
        t_flags |= CMP_UGE; 
    }

    (*dst) = t_flags;
}


EMU_Core* EMU_CreateCore(){

    EMU_Core *core = t_malloc(sizeof(EMU_Core));

    core->flags = 0;

    return core;
}