#include "debug_functions.h"



const char *debug_symbol_type_to_string(Symbol_Type type) {
    switch (type) {
        case SYMBOL_NONE:        return "SYMBOL_NONE";
        case SYMBOL_LABEL:       return "SYMBOL_LABEL";
        case SYMBOL_MACRO_MUL:   return "SYMBOL_MACRO_MUL";
        case SYMBOL_MACRO_SINGLE:return "SYMBOL_MACRO_SINGLE";
        default:                 return "UNKNOWN_SYMBOL_TYPE";
    }
}





void debug_dump_file(Token_File_Manager *manager, FILE *debug_file){

    fprintf(debug_file, "\nDump File (pre macro expansions)\n");

    Token_Line *token_line = manager->tk_files[0]->head;

    if(!token_line)
        return;

    char *file_name = token_line->file;

    while(token_line){

        if(token_line->file != file_name)
            fprintf(debug_file, "\n");
        file_name = token_line->file;

        fprintf(debug_file, "%s - %-3d:   ", token_line->file, token_line->original_line);

        for(int x = 0; x < token_line->amount_tokens; x++){
            fprintf(debug_file, "%s ", token_line->tk[x].text);
        }

        fprintf(debug_file, "\n");


        

        token_line = token_line->next;
    }
    
    fprintf(debug_file, "\n\n");
}





void debug_dump_symbols(Symbol_Table_Manager *manager, FILE *debug_file){

    fprintf(debug_file, "Symbol info");

    for(int file_table = 0; file_table < manager->amount_tables; file_table++){

        Symbol_Table *table = &manager->tables[file_table];
        fprintf(debug_file, "\n\n%s\n", table->file);

        for(int symbol = 0; symbol < table->amount_symbols; symbol++){

            const char *symbol_type = debug_symbol_type_to_string(table->symbols[symbol].type);

            fprintf(debug_file, "%s - %s - exported %s - imported %s\n",
                table->symbols[symbol].text, symbol_type, 
                table->symbols[symbol].is_exported ? "true" : "false", table->symbols[symbol].is_imported ? "true" : "false");

        }
        fprintf(debug_file, "\n");

    }

    fprintf(debug_file, "\n\n");

}
