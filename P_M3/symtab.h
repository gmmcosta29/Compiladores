#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "strutcs.h"

typedef enum {integer, character, doub} basic_type;

typedef struct _method_variables{
    struct _params *params;
    char *id;
    char *type;
	struct _variables_aux * variablesAux;
}methodVariables;


typedef struct _variables_aux{
	struct _var_dec * variables;
	struct _variables_aux* next;
}variablesAux;


typedef struct _t1{
	struct _method_variables* methodVariables;
	struct _field_dec * variables;
	struct _t1 *next;
} tableElement;



char* toLow(char* aux);
void show_symtab();
void check_program(program *pro);
#endif
