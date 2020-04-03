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
}returnBlock;

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
}whileBlock;

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
    struct _list_field_dec *listFieldDec;
}fieldDec;

typedef struct _list_field_dec{
    char *id;
    struct _list_field_dec *next;
}listFieldDec;

typedef struct _params{
    char *type;
    char *id;
    struct *_params *next;
}params;

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

program* insertProgram(declarations *declarationlist){
    program *pro = (program*)malloc(sizeof(program));
    pro->declaration = declarationlist;
    return pro;
}

declarations* insertDeclarationList(declarations *head,methodDec *methdec,fieldDec *fieldec,int semicolon){
    declarations *new = (declarations*)malloc(sizeof(declarations)),*temp;
    new->next = NULL;
    if(methdec){
        new->semicolon = 0;
        new->fieldDec = NULL;
        new->methodDec = methdec;
    }else if(fieldec){
        new->semicolon = 0;
        new->methodDec = NULL;
        new->fieldDec = fieldec;
    }else{
        new->methodDec = NULL;
        new->fieldDec = NULL;
        new->semicolon = semicolon;
    }
    if(!head){
        return new;
    }
    for(temp= head;temp->next;temp = temp->next);
    temp->next = new;
    return head;
}

fieldDec* insertFieldDec(char *type, listFieldDec *fieldlist){
    fieldDec *new =(fieldDec*)malloc(sizeof(fieldDec));
    new->type = (char *)strdup(type);
    new->listFieldDec = fieldlist;
    return new;
}
listFieldDec* insertListFieldDec(listFieldDec head,char *id){
    listFieldDec *new = (listFieldDec*)malloc(sizeof(listFieldDec)),*temp;
    new->id = (char*)strdup(id);
    new->next =NULL;

    if(head){
        for(temp = head;temp->next;temp = temp->next);
        temp->next = new;
        return head;
    }
    return new;
}
methodDec* insertMethodDec(methodBody *body,methodHeader *header){
    methodDec *new = (methodDec*)malloc(sizeof(methodDec));

    new ->methodBody = body;
    new->methodHeader = header;
    return new;
}

methodHeader* insertMethodHeader(char *type,char *id,params *params){
    methodHeader *new = (methodHeader*)malloc(sizeof(methodHeader));

    new->id = (char*)strdup(id);
    new->type = (char*)strdup(type);
    new->params = params;
    return new;
}
params * insertParams(params *head,char *id,char *type){
    params * new = (params*)malloc(sizeof(params));
    new->type = (char *)strdup(type);
    new->id =(char *)strdup(id);
    new->next = NULL;
    if(!head){
        return  new;
    }
    for(temp = head,temp->next;temp = temp->next);
    temp->next = new;
    return head;
}
methodBody * insertMethodBody(methodBody *head,varDec *var,statement * state){
    methodBody * new = (methodBody*)malloc(sizeof(methodBody)),*temp;
    new->next = NULL;
    if(var){
        new->varDec = var;
        new->statement = NULL;
    }else{
        new->statement = state;
        new->varDec = NULL;
    }
    if(!head) return new;
    for(temp = head;temp->next;temp = temp->next);
    temp->next = new;
    return head;
}
varDec *insertVarDec(char *type,listVarDec *list){
    varDec *new = (varDec*)malloc(sizeof(varDec));
    new->listVarDec= list;
    new->type = (char *)strdup(type);
    return new;
}
listVarDec * insertListVarDec(listVarDec *head,char *id){
    listVarDec *new = (listVarDec*)malloc(sizeof(listVarDec)),*temp;
    new->id = (char*)strdup(id);
    new->next =NULL;
    if(!head) return new;
    for(temp = head;temp->next;temp = temp->next);
    temp->next = new;
    return head;
}

