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

    emu->sdk_io.time = SDK_CreateTime(1000);
    if(!emu->sdk_io.time){
        SDK_DestroyInput(emu->sdk_io.input); 
        SDK_DestroyDisplay(emu->sdk_io.display);
        t_free(emu);
        return NULL;
    }

    EMU_init_alu(&emu->alu);
    EMU_init_fpu(&emu->fpu);
    memset(emu->ram, 0, sizeof(emu->ram));
    emu->program_counter = 0;

    emu->ram[0] = 0b01100101;
    emu->ram[1] = 0xf0;
    emu->ram[2] = 0x0f;
    emu->ram[3] = 0xaa;
    emu->ram[4] = 0xaa;
    emu->ram[5] = 0xff;

    return emu;
}