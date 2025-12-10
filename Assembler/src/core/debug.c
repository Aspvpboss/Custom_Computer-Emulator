#include "debug.h"
#include "error.h"

int debug(Appstate *state){

    if(!state->configs.Dump_Debug_Info)
        return 0;

    ErrorData result = {};

    char file_name[] = "debug_dump.txt";
    FILE *dump_file = fopen(file_name, "w");

    if(!dump_file){
        Set_ErrorData(&result, 1, 0, file_name, NULL);
        LogError(FILE_ERROR, &result);
        return 1;
    }

    debug_dump_symbols(&state->symbol_manager, dump_file);
    debug_dump_file(&state->tk_manager, dump_file);

    fclose(dump_file);

    return 0;
}
