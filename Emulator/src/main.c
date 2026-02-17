#include "init.h"
#include "iterate.h"
#include "destroy.h"
#include "debug.h"



int main(){

    Emulator *emu = init();
    if(!emu){
        return 1;
    }


    EMU_Result result = EMU_CONTINUE;
    SDK_IO *sdk_io = &emu->sdk_io;

    bool limit_fps = false;

    while(result == EMU_CONTINUE){

        result = iterate(emu);
        
        if(result == EMU_FAILURE){
            d_printf("EMU failed\n"); 
            destroy(emu);
            return 1;
        }

        if(SDK_Keyboard_JustPressed(emu->sdk_io.input, SDL_SCANCODE_T)){
            d_printf("                                        \r %.2f - dt: %.10f\r", sdk_io->time->fps, sdk_io->time->dt);
        }

        if(SDK_Keyboard_JustPressed(sdk_io->input, SDL_SCANCODE_SPACE)){
            limit_fps = !limit_fps;
        }

        SDK_Update_Previous_Inputs(emu->sdk_io.input);
        SDK_CalculateDT(emu->sdk_io.time);
        if(limit_fps){
            SDK_LimitFPS(sdk_io->time);
        }
        SDK_CalculateFPS(emu->sdk_io.time);

    }

    destroy(emu);

    return 0;
}