#pragma once
#include <stdbool.h>


enum Output_Type{
    
    NO_OUTPUT,
    BINARY_OUTPUT,
    HEX_OUTPUT

};



typedef struct{

    enum Output_Type output_type;
    bool Dump_Debug_Info;
    
} Assembler_Configs;
