#include "iterate.h"

#include "pipeline/execute.h"
#include "pipeline/fetch.h"
#include "pipeline/mmio.h"


EMU_Result iterate(Emulator *emu){

    static SDL_Event e;
    SDK_Input *input = emu->sdk_io.input;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_EVENT_QUIT){
            return EMU_SUCCESS;
        }            
    }

    if(SDK_Keyboard_Pressed(input, SDL_SCANCODE_Q) &&
       SDK_Keyboard_Pressed(input, SDL_SCANCODE_LSHIFT)){

        return EMU_SUCCESS;
    }
   
    if(SDK_Keyboard_JustPressed(input, SDL_SCANCODE_F)){
        return EMU_FAILURE;
    }

    u32 instruction = fetch(emu);

    execute(emu, instruction);

    

    return EMU_CONTINUE;
}