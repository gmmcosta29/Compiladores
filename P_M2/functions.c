#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
typedef struct _expression{
    struct _expression *right;
    struct _expression *left;
    char *operator;
    char *intlit;
    char *realit;
    char *id;
    char *boollit;
    char *dotlenght;
    struct _method_invocation *methodInvocation;
    struct _assignment *assignment;
    struct _parse_args *parseArgs;
    struct _list_expression *expressions_list;
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
    struct _statement *listState;
    struct _statement *listElseState;
}ifBlock;

typedef struct _print{
    char *stringlit;
    struct _expression *expression;
}print;

typedef struct _while{
    struct _expression *expression;
    struct _statement *listStatement;
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
        new->varDec =
 NULL;
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
void resetStatement(statement *statement1){
    statement1->semicolon = 0;
    statement1->assignment = NULL;
    statement1->print = NULL;
    statement1->ifBlock = NULL;
    statement1->listStatement = NULL;
    statement1->methodInvoc = NULL;
    statement1->parseArgs = NULL;
    statement1->whileBlock = NULL;
    statement1->returnblock = NULL;
}

statement* insertListStatement(listStatement * head){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->listStatement = head;
    return new;
}
listStatement * insertMultipleStatement(listStatement *head, statement * novo){
    listStatement  *new = (listStatement)malloc(sizeof(listStatement)),*temp;
    new->statement = novo;
    new->next = NULL;
    if(!head) return new;
    for(temp = head;temp->next;temp = temp->next);
    temp->next = new;
    return head;
}

statement* insertIfElse(expression *expression1,statement *statement1,statement *statement2){
    statement* new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    ifBlock *ifBlock1 = (ifBlock*)malloc(sizeof(ifBlock));
    new->ifBlock =ifBlock1;
    new->ifBlock->expression = expression1;
    new->ifBlock->listState = statement1;
    new->ifBlock->listElseState = statement2;
    return new;
}
statement* insertWhile(expression *expression1,statement *statement1){
    statement* new = (statement*)malloc(sizeof(statement));
    whileBlock *whileBlock1 = (whileBlock*)malloc(sizeof(whileBlock));
    resetStatement(new);
    new->whileBlock = whileBlock1;
    new->whileBlock->expression = expression1;
    new->whileBlock->listStatement = statement1;
    return new;
}

statement * insertReturn(expression *expression1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    returnBlock * returnBlock1 = (returnBlock*)malloc(sizeof(returnBlock));
    new->returnblock = returnBlock1;
    new->returnblock->expression = expression1;
    return expression;
}

statement * insertMethodInvocation(methodInvocation *methodInvocation1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->methodInvoc = methodInvocation1;
    return new;
}
statement * insertAssign(assign *assign1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->assignment = assign1;
    return new;
}

statement * insertParseArgs(parseArgs *parseArgs1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->parseArgs = parseArgs1;
    return new;
}
statement * insertPrint(expression *expression1,char *id){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    print *print1 = (print*)malloc(sizeof(print));
    new->print = print1;
    new->print->expression = expression1;
    new->print->stringlit = (char*)strdup(id);
    return new;
}

listExpression * insertListExpression(listExpression *head, expression * expression1){
    listExpression * new = (listExpression*)malloc(sizeof(listExpression)), *temp;
    new->expression = expression1;
    new->next = NULL;
    if(!head) return new;
    for(temp = head;temp->next;temp = temp->next);
    temp->next = new;
    return head;
}

methodInvocation * insertMethodInvocation(char *id,listExpression * head){
    methodInvocation * new = (methodInvocation*)malloc(sizeof(methodInvocation));
    new->id = (char*)strdup(id);
    new->listExpression = head;
    return new;
}

assign * insertAssign ( char * id, expression * expression1) {
    assign * new = (assign*)malloc(sizeof(assign));
    new->id = (char*)strdup(id);
    new->expression = expression1;
    return new
}

parseArgs * insertParseArgs (char * id, expression * expression1){
    parseArgs * new = (parseArgs*)malloc(sizeof(parseArgs))
    new->id = (char *)strdup(id);
    new->expression = expression1;
    return new;
}

expression* insertAssignment(assign *assign1){
    expression *new = (expression*)malloc(sizeof(expression));
    new->assignment = assign1;
    return new;
}
void resetExpression(expression *expression1){
    expression1->assignment =NULL;
    expression1->id = NULL;
    expression1->expressions_list = NULL;
    expression1->parseArgs = NULL;
    expression1->methodInvocation = NULL;
    expression1->boollit = NULL;
    expression1->intlit = NULL;
    expression1->dotlenght = NULL;
    expression1->left = NULL;
    expression1->operator = NULL;
    expression1->realit = NULL;
    expression1->right = NULL;
}

expression *insertMultipleExpression(expression *headexpression,expression *newexpression){
    listExpression *new  = (listExpression)malloc(sizeof(listExpression)),*aux = headexpression->expressions_list;
    new->expression = newexpression;
    new->next = NULL;
    if(aux){
        for(;aux->next;aux = aux->next);
        aux->next = new;
    }else{
        aux = new;
    }
    return headexpression;
}
expression *insertOperator(expression *expression1,char *operator,expression *expression2){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
    new->left = expression1;
    new->right = expression2;
    new->operator = (char *)strdup(operator);
    return new;
}

expression* insertUnitary(char *operator,expression *expression1){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
    new->right = expression1;
    new->operator = (char *)strdup(operator);
    return new;
}

expression* insertExpression(methodInvocation *methodInvocation1,parseArgs *parseArgs1, char * id, int dotlength, char * id, int intlit, char * true, char * false, char * reallit){
    expression *new = (expression*)malloc(sizeof(expression));
    new->methodInvocation = methodInvocation1;
    new->parseArgs = parseArgs1;
    new->id = (char *)strdup(id);
    new->dotlenght = dotlength;
    new->intlit = intlit;
    new->true = (char *)strdup(true);
    new->false = (char *)strdup(false);
    new->realit = (char *)strdup(reallit);
    return new;

}

