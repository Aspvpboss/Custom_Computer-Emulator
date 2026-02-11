#include "emulator/core.h"




void print_cmp_flags(CMP_Flags flags){
 
    if (flags == 0) {
        d_printf("CMP: none\n");
        return;
    }

    d_printf("CMP:");

    if (flags & CMP_EQU) d_printf(" EQU");
    if (flags & CMP_NEQ) d_printf(" NEQ");
    if (flags & CMP_IF0) d_printf(" IF0");

    if (flags & CMP_ULT) d_printf(" ULT");
    if (flags & CMP_ULE) d_printf(" ULE");
    if (flags & CMP_UGR) d_printf(" UGR");
    if (flags & CMP_UGE) d_printf(" UGE");

    if (flags & CMP_SLT) d_printf(" SLT");
    if (flags & CMP_SLE) d_printf(" SLE");
    if (flags & CMP_SGR) d_printf(" SGR");
    if (flags & CMP_SGE) d_printf(" SGE");

    if (flags & CMP_CAR)  d_printf(" CAR");
    if (flags & CMP_OVER) d_printf(" OVER");

    d_printf("\n");

}




static void alu_add(u16 a, u16 b, u16 *dst, CMP_Flags *flags){
    
    u32 wide = (u32)a + (u32)b;
    u16 result = (u16)wide;
    *dst = result;

    if(wide > 0xFFFF)
        *flags |= CMP_CAR;

    if((~(a ^ b) & (a ^ result) & 0x8000) != 0)
        *flags |= CMP_OVER;

}

static void alu_sub(u16 a, u16 b, u16 *dst, CMP_Flags *flags){
    
    u32 wide = (u32)a - (u32)b;

    u16 result = (u16)wide;
    
    if(a >= b)
        *flags |= CMP_CAR;

    if(((a ^ b) & (a ^ result) & 0x8000) != 0)
        *flags |= CMP_OVER;

}

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

static void alu_cmp(u16 a, u16 b, CMP_Flags *dst){
    
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

    bool Z = (result == 0);
    bool N = (result & 0x8000) != 0;
    bool V = ((a ^ b) & (a ^ result) & 0x8000) != 0;

    bool signed_lt = N ^ V;
    bool signed_ge = !signed_lt;
    bool signed_le = Z || signed_lt;
    bool signed_gt = !Z && signed_ge;

    if(signed_lt)  t_flags |= CMP_SLT;
    if(signed_le)  t_flags |= CMP_SLE;
    if(signed_gt)  t_flags |= CMP_SGR;
    if(signed_ge)  t_flags |= CMP_SGE;
    (*dst) = t_flags;

}


EMU_Core* EMU_CreateCore(){

    EMU_Core *core = t_malloc(sizeof(EMU_Core));

    core->flags = 0;

    core->alu.cmp = alu_cmp;

    u16 result = 0;
    alu_add(__INT16_MAX__, 10, &result, &core->flags);

    print_cmp_flags(core->flags);
    d_printf("%d\n", result);

    return core;
}