#include "init.h"
#include "iterate.h"
#include "destroy.h"
#include "debug.h"
#include "emulator/emulator.h"


int emulator_main(void *data){

    _Atomic int *emulator_state = data;

    Emulator *emu = init();
    if(!emu){
        (*emulator_state) = -1;
        return 1;
    }


    EMU_Result result = EMU_CONTINUE;
    SDK_IO *sdk_io = &emu->sdk_io;

    bool limit_fps = false;


    while(result == EMU_CONTINUE){

        result = iterate(emu);
        
        if(result == EMU_FAILURE){
            destroy(emu);
            (*emulator_state) = -1;
            return 1;
        }

        if(SDK_Keyboard_JustPressed(emu->sdk_io.input, SDL_SCANCODE_T)){
            printf("                                        \r %.2f - dt: %.10f\r", sdk_io->time->fps, sdk_io->time->dt);
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

    (*emulator_state) = 1;

    return 0;
}