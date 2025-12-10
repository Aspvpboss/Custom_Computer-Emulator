#pragma once

#include "appstate.h"


void debug_dump_symbols(Symbol_Table_Manager *manager, FILE *debug_file);
void debug_dump_file(Token_File_Manager *manager, FILE *debug_file);
