#include "init.h"



Emulator* init(){

    if(SDK_Init(NULL, NULL, false, true, false))
        return NULL;

    Emulator *emu = t_malloc(sizeof(Emulator));
    if(!emu) return NULL;


    emu->sdk_io.input = SDK_CreateInput();
    if(!emu->sdk_io.input){
        t_free(emu);
        return NULL;
    }

    emu->sdk_io.display = SDK_CreateDisplay("EMU", 800, 800, SDL_WINDOW_MAXIMIZED);
    if(!emu->sdk_io.display){
        SDK_DestroyInput(emu->sdk_io.input); 
        t_free(emu);
        return NULL;
    }

    EMU_init_alu(&emu->alu);
    EMU_init_fpu(&emu->fpu);
    memset(emu->ram, 0, sizeof(emu->ram));
    emu->program_counter = 0;

    emu->ram[0] = 0xa0;

    return emu;
}