#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
typedef struct _expression{
    struct _expression *right;
    struct _expression *left;
    char *operator;structs
    char *intlit;
    char *realit;
    char *id;
    char *boollit;
    char *dotlenght;
    struct _method_invocation *methodInvocation;
    struct _assignment *assignment;
    struct _parse_args *parseArgs;
}expression;

typedef struct  _expr_initial{
    char *strinitial;
    struct _expr_initial *next;
}exprInitial;

typedef struct _statement{
    struct _print *print;
    struct _method_invoc *methodInvoc;
    struct _parse_args *parseArgs;
    struct _assignment *assignment;
    struct _if  *ifBlock;
    struct  _while *whileBlock;
    struct _list_statement *listStatement;
    struct _return *returnblock;
    int semicolon; //flag  para separar semicolon de lpar rpar
}statement;

typedef struct _list_statement{
    struct _statement *statement;
    struct _list_statement *next;
}listStatement;

typedef struct _list_expression {
    struct _expression *expression;
    struct _list_expression *next;
}listExpression;

typedef struct _method_invocation{
    char id*;
    struct _list_expression *listExpression;
}methodInvocation;

typedef struct _parse_args{
    char *id:
    struct _expression *expression;
}parseArgs;

typedef struct _return{
    struct _expression *expression;
}returnblock;

typedef struct _assign{
    char *id;
    struct _expression *expression;
}assign;

typedef struct _if{
    struct _expression *expression;
    struct _list_statement *listState;
    struct _list_statement *listElseState;
}ifBlock;

typedef struct _print{
    char *stringlit;
    struct _expression *expression;
}print;

typedef struct _while{
    struct _expression *expression;
    struct _list_statement *listStatement;
}whileblock;

typedef struct _var_dec{
    char *type;
    struct _list_var_dec *listVarDec;
}varDec;

typedef struct _list_var_dec{
    char *id;
    struct _list_var_dec *next;
}listVarDec;

typedef struct _field_dec{
    char *type;
    struct __list_field_dec *listFieldDec;
}fieldDec;

typedef struct _list_field_dec{
    char *id;
    struct _list_field_dec *next;
}listFieldDec;

typedef struct _params{
    char *type;
    char *id;
    struct *_params *next;
}Params;_declaration

typedef struct _method_header{
    char *type;
    char *id;
    struct _params *params;
}methodHeader;

typedef struct _method_dec{
    struct _method_header *methodHeader;
    struct _method_body *methodBody;
}methodDec;

typedef struct _method_body{
    struct _statement *statement;
    struct _var_dec *varDec;
    struct _method_body *next;
}methodBody;

typedef struct _declarations{
    struct _method_dec *methodDec;
    struct _field_dec *fieldDec;
    int semicolon;
    struct _declarations *next;
}declarations;

typedef struct _program{
    struct _declarations *declaration;
}program;



_program* insert_program(_declarations * declarationlist){
    _program *pro = (_program*)malloc(sizeof(_program));
    pro->declaration = declarationlist;
    return pro;
}

_declarations* insert_declaration_list(s_declarations *head,_method_dec *methdec,_field_dec *fieldec,int semicolon){
    _declarations *new = (_declarations*)malloc(sizeof(struct _declarations));
    _declarations *temp;
    if(methdec){

        new->methodDec = methdec;
        new->next = NULL;
        if(!head){
            return new;
        }
        for(temp= head;temp->next;temp = temp->next);
        temp->next = new;
    }else if(fieldec){
        new->fieldDec = fieldec;
        new->next = NULL;
        if(!head){
            return new;
        }
        for(temp= head;temp->next;temp = temp->next);
        temp->next = new;
    }else{
        new->semicolon = semicolon;
        new->next = NULL;
        if(!head){
            return new;
        }
        for(temp= head;temp->next;temp = temp->next);
        temp->next = new;
    }
    return head;
}

_field_dec*
