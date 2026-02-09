#include "init.h"


Emulator* init(){

    if(SDK_Init(NULL, NULL, false, true, false))
        return NULL;

    Emulator *emu = t_malloc(sizeof(Emulator));
    if(!emu) return NULL;

    memset(emu->memory, 0, sizeof(emu->memory));

    emu->input = SDK_CreateInput();
    if(!emu->input){
        t_free(emu);
        return NULL;
    }

    emu->display = SDK_CreateDisplay("EMU", 100, 100, SDL_WINDOW_MAXIMIZED);
    if(!emu->display){
        SDK_DestroyInput(emu->input); 
        t_free(emu);
        return NULL;
    }

    return emu;
}