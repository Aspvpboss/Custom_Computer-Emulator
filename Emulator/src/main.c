#include "init.h"
#include "iterate.h"
#include "destroy.h"
#include "assert.h"




void print_cmp_flags(CMP_Flags flags){
 
    if (flags == 0) {
        printf("CMP: none\n");
        return;
    }

    printf("CMP:");

    if (flags & CMP_EQU) printf(" EQU");
    if (flags & CMP_NEQ) printf(" NEQ");
    if (flags & CMP_IF0) printf(" IF0");

    if (flags & CMP_ULT) printf(" ULT");
    if (flags & CMP_ULE) printf(" ULE");
    if (flags & CMP_UGR) printf(" UGR");
    if (flags & CMP_UGE) printf(" UGE");

    if (flags & CMP_SLT) printf(" SLT");
    if (flags & CMP_SLE) printf(" SLE");
    if (flags & CMP_SGR) printf(" SGR");
    if (flags & CMP_SGE) printf(" SGE");

    if (flags & CMP_CAR)  printf(" CAR");
    if (flags & CMP_OVER) printf(" OVER");

    printf("\n");

}




int main(){

    Emulator *emu = init();
    if(!emu){
        return 1;
    }

    EMU_Result result = EMU_CONTINUE;


    CMP_Flags flags = 0;
    alu_cmp(0, 3, &flags);

    print_cmp_flags(flags);    

    while(result == EMU_CONTINUE){

        result = iterate(emu);

        if(result == EMU_FAILURE){
            d_printf("EMU failed\n"); 
            destroy(emu);
            return 1;
        }

        SDK_Update_Previous_Inputs(emu->sdk_io.input);
        
    }

    destroy(emu);

    return 0;
}