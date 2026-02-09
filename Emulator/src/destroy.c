#include "destroy.h"


void destroy_emu(Emulator *emu){

    SDK_DestroyDisplay(emu->display);
    SDK_DestroyInput(emu->input);
    t_free(emu);
}


void destroy(Emulator *emu){

    destroy_emu(emu);
    SDK_Quit();

}