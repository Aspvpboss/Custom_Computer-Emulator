#include "init.h"
#include "iterate.h"
#include "destroy.h"
#include "assert.h"


int main(){

    Emulator *emu = init();
    if(!emu){
        return 1;
    }

    EMU_Result result = EMU_CONTINUE;

    while(result == EMU_CONTINUE){

        result = iterate(emu);

        if(result == EMU_FAILURE){
            d_printf("EMU failed\n"); 
            destroy(emu);
            return 1;
        }

        SDK_Update_Previous_Inputs(emu->input);
        
    }

    destroy(emu);

    return 0;
}