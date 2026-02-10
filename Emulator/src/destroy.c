#include "destroy.h"


void destroy_emu(Emulator *emu){

    SDK_DestroyDisplay(emu->sdk_io.display);
    SDK_DestroyInput(emu->sdk_io.input);
    t_free(emu);
}


void destroy(Emulator *emu){

    destroy_emu(emu);
    SDK_Quit();

}