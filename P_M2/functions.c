#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
#include "functions.h"


program* insertProgram(char *id,declarations *declarationlist){
    program *pro = (program*)malloc(sizeof(program));
    pro->declaration = declarationlist;
    pro->id = (char*)strdup(id);
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
    listVarDec *new = (listVarDec*)malloc(sizeof(listVarDec));
    new->id = (char*)strdup(id);
    new->next =NULL;
    if(!head) return new;
    new->next = head;
    return new;
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
    expression1->expressionext = NULL;
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

expression *insertMultipleExpression(expression *newexpression){
    expression *new  = (expression *)malloc(sizeof(expression));
    resetExpression(new);
    new->expressionext = newexpression;
    return new;
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
    resetExpression(new);
    new->methodInvocation = methodInvocation1;
    new->parseArgs = parseArgs1;
    new->id = (char *)strdup(id);
    new->dotlenght = dotlength;
    new->intlit = (char *)strdup(intlit);
    new->boollit = (char *)strdup(boolit);
    new->realit = (char *)strdup(reallit);
    return new;

}
int nivel = 0;

void printpoints(){
    int i;
    for ( i = 0; i < nivel * 2; i++){
        printf(".");
    }
}


void printTree(program *pro){
    printf("Program\n");
    nivel++;
    printpoints();
    printf("Id(%s)\n",pro->id);
    if(!pro->declaration){
        return;
    }
    while(pro->declaration){
        if(pro->declaration->methodDec){
            printMethodDecl(pro->declaration->methodDec);
        }else if(pro->declaration->fieldDec){
            printFieldDecl(pro->declaration->fieldDec);
        }
        pro->declaration = pro->declaration->next;
    }
    nivel--;
    return;
}

void printMethodDecl(methodDec *base){
    printpoints();
    printf("MethodDecl\n");
    nivel++;

    printpoints();
    printf("MethodHeader\n");
    nivel++;

    printpoints();
    printf("%s\n",base->methodHeader->type);

    printpoints();
    printf("Id(%s)\n",base->methodHeader->id);
    


    printpoints();
    printf("MethodParams\n");
    if(base->methodHeader->params){
        nivel++;
        nivel++;
        while(base->methodHeader->params){
            nivel--;
            printpoints();
            printf("ParamDecl\n");
            nivel++;
            printpoints();
            printf("%s\n",base->methodHeader->params->type);
            printpoints();
            printf("Id(%s)\n",base->methodHeader->params->id);
            base->methodHeader->params = base->methodHeader->params->next;
        }
        nivel--;
        nivel--;
    }
    nivel--;
    printpoints();
    printf("MethodBody\n");
    nivel++;
    if(base->methodBody){
        printMethodBody(base->methodBody);
    }
    nivel--;
    nivel--;
}

void printMethodBody(methodBody * aux){
    while(aux){
        if(aux->statement){
            printStatement(aux->statement);
        }else if (aux->varDec){
            printVarDecl(aux->varDec);
        }
        aux = aux->next;
    }
}

void printVarDecl(varDec *aux){
        listVarDec *temp = aux->listVarDec;
        while(temp){
            printpoints();
            printf("VarDecl\n");
            nivel++;
            printpoints();
            printf("%s\n", aux->type);
            printpoints();
            printf("Id(%s)\n", temp->id);
            temp = temp->next;
            nivel--;
        }
        return;
}
void printFieldDecl(fieldDec *aux){
        printpoints();
        printf("FieldDecl\n");
        nivel++;
        printpoints();
        printf("%s\n", aux->type);
        listFieldDec *temp = aux->listFieldDec;
        while(temp){
            printpoints();
            printf("Id(%s)\n", aux->listFieldDec->id);
            temp = temp->next;
        }
        nivel--;
        return;
}
void printStatement(statement *state){
    if(state->print){
        printpoints();
        printf("Print\n");
        nivel++;
        if(state->print->stringlit){
            printpoints();
            printf("StrLit(%s)\n",state->print->stringlit);
        }
        else if(state->print->expression){
            printExpression(state->print->expression);
        }
        nivel--;
        return;
    }
    if(state->methodInvoc){
        printpoints();
        printf("Call\n");
        nivel++;
        printf("Id(%s)\n",state->methodInvoc->id);
        while(state->methodInvoc->listExpression){
            printExpression(state->methodInvoc->listExpression->expression);
            state->methodInvoc->listExpression = state->methodInvoc->listExpression->next;
        }
        nivel--;
        return;
    }
    if(state->parseArgs){
        printpoints();
        printf("ParseArgs\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",state->parseArgs->id);
        printExpression(state->parseArgs->expression);
        nivel--;
        return;
    }
    if(state->assignment){
        printpoints();
        printf("Assign\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",state->assignment->id);
        printExpression(state->assignment->expression);
        nivel--;
        return;
    }
    if(state->ifBlock){
        int numero = countStatement(state->ifBlock->listState) + countStatement(state->ifBlock->listElseState);
        printpoints();
        printf("If\n");
        printExpression(state->ifBlock->expression);
        if(numero >1){
            printpoints();
            printf("Block\n");
            nivel++;
            printStatement(state->ifBlock->listState);
            nivel--;
            printStatement(state->ifBlock->listElseState);
        }else if(numero == 1){
            nivel++;
            printStatement(state->ifBlock->listState);
            printpoints();
            printf("Block\n");
        }else{
            printpoints();
            printf("Block\n");
            printpoints();
            printf("Block\n");
        }
        nivel--;
        return;
    }
    if(state->whileBlock){
        printpoints();
        printf("While\n");
        printExpression(state->whileBlock->expression);
        nivel++;
        printStatement(state->whileBlock->listStatement);
        nivel--;
        return;
    }
    if(state->returnblock){
        printpoints();
        printf("Return\n");
        printExpression(state->returnblock->expression);
        nivel--;
        return;
    }
    if(state->listStatement){
        while(state->listStatement){
            printStatement(state->listStatement->statement);
            state->listStatement = state->listStatement->next;
        }
    }
}

int countStatement(statement *state){
    int i = 0;
    listStatement *temp = state->listStatement;
    if(!temp){
        return 0;
    }
    while(temp){
        i++;
        if(i > 1){
            return 2;
        }
        temp = temp->next;
    }
    return 1;
}

void printExpression(expression *expr){
    printpoints();
    printf("Expression\n");
    if(!expr->operator){
            //expressao final
    }else{
            //expressao nao final
    }
}