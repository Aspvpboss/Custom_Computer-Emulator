#ifndef EMU_DEBUG_H_
#define EMU_DEBUG_H_

#include "emulator/flags.h"

void print_cmp_flags(CMP_Flags flags);

#ifdef DEBUG
    #define d_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define d_printf(fmt, ...)
#endif

#endif