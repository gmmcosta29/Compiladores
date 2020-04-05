#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
#include "functions.h"


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
listFieldDec* insertListFieldDec(listFieldDec *head,char *id){
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
    params * new = (params*)malloc(sizeof(params)),*temp;
    new->type = (char *)strdup(type);
    new->id =(char *)strdup(id);
    new->next = NULL;
    if(!head){
        return  new;
    }
    for(temp = head;temp->next;temp = temp->next);
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
        new->varDec =NULL;
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

statement* insertListStatement(listStatement *head){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->listStatement = head;
    return new;
}
listStatement * insertMultipleStatement(listStatement *head, statement * novo){
    listStatement  *new = (listStatement*)malloc(sizeof(listStatement)),*temp;
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
    return new;
}

statement * insertMethodInvocationStatement(methodInvocation *methodInvocation1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->methodInvoc = methodInvocation1;

    return new;
}
statement * insertAssignStatement(assignment *assign1){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    new->assignment = assign1;
    return new;
}

statement * insertParseArgsStatement(parseArgs *parseArgs1){
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

assignment * insertAssign( char * id, expression * expression1) {
    assignment * new = (assignment*)malloc(sizeof(assignment));
    new->id = (char*)strdup(id);
    new->expression = expression1;
    return new;
}

parseArgs * insertParseArgs (char * id, expression * expression1){
    parseArgs * new = (parseArgs*)malloc(sizeof(parseArgs));
    new->id = (char *)strdup(id);
    new->expression = expression1;
    return new;
}

expression* insertAssignment(assignment *assign1){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
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
    expression1->dotlenght = 0;
    expression1->left = NULL;
    expression1->operator = NULL;
    expression1->realit = NULL;
    expression1->right = NULL;
}                           

expression *insertMultipleExpression(expression *headexpression,expression *newexpression){
    listExpression *new  = (listExpression *)malloc(sizeof(listExpression)),*aux = headexpression->expressions_list;
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

expression* insertExpression(methodInvocation *methodInvocation1,parseArgs *parseArgs1,  int dotlength, char * id, char *intlit, char * boolit, char * reallit){
    expression *new = (expression*)malloc(sizeof(expression));
    new->methodInvocation = methodInvocation1;
    new->parseArgs = parseArgs1;
    new->id = (char *)strdup(id);
    new->dotlenght = dotlength;
    new->intlit = (char *)strdup(intlit);
    new->boollit = (char *)strdup(boolit);
    new->realit = (char *)strdup(reallit);
    return new;

}

