#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
#include "functions.h"


program* insertProgram(char *id,declarations *declarationlist){
    program *pro = (program*)malloc(sizeof(program));
    pro->declaration = declarationlist;
    if(id){
    pro->id = (char*)strdup(id);

    }
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
    listFieldDec *new = (listFieldDec*)malloc(sizeof(listFieldDec));
    new->id = (char*)strdup(id);
    new->next = head;
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
    if(!head) return new;
    new->next = head;
    return new;
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
    if(!head)return NULL;
    new->listStatement = head;
    return new;
}
listStatement * insertMultipleStatement(listStatement *head, statement * novo){
    listStatement  *new = (listStatement*)malloc(sizeof(listStatement));
    if(!novo)return head;
    new->statement = novo;
    new->next = NULL;
    if(!head) return new;
    new->next = head;
    return new;
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
    if(id){
        new->print->stringlit = (char*)strdup(id);
    }
    return new;
}

listExpression * insertListExpression(listExpression *head, expression * expression1){
    listExpression * new = (listExpression*)malloc(sizeof(listExpression));
    new->expression = expression1;
    new->next = NULL;
    if(!head) return new;
    new->next = head;
    return new;
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
    new->dotlenght = dotlength;
    if(intlit){
        new->intlit = (char *)strdup(intlit);
    }
    if(boolit){
        new->boollit = (char *)strdup(boolit);
    }
    if(reallit){
        new->realit = (char *)strdup(reallit);
    }
    if(id){
        new->id = (char *)strdup(id);
    }

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
        listFieldDec *temp = aux->listFieldDec;
        while(temp){
            printpoints();
            printf("FieldDecl\n");
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
    }
    if(state->methodInvoc){
        printpoints();
        printf("Call\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",state->methodInvoc->id);
        while(state->methodInvoc->listExpression){
            printExpression(state->methodInvoc->listExpression->expression);
            state->methodInvoc->listExpression = state->methodInvoc->listExpression->next;
        }
        nivel--;
    }
    if(state->parseArgs){
        printpoints();
        printf("ParseArgs\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",state->parseArgs->id);
        printExpression(state->parseArgs->expression);
        nivel--;
    }
    if(state->assignment){
        printpoints();
        printf("Assign\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",state->assignment->id);
        printExpression(state->assignment->expression);
        nivel--;
    }
    if(state->ifBlock){
        printpoints();
        printf("If\n");
        nivel++;
        printExpression(state->ifBlock->expression);
        if(!state->ifBlock->listState && !state->ifBlock->listElseState){
            printpoints();
            printf("Block\n");
            printpoints();
            printf("Block\n");
        } else if (state->ifBlock->listState && !state->ifBlock->listElseState){
                printStatement(state->ifBlock->listState);
                printpoints();
                printf("Block\n");
        } else if (!state->ifBlock->listState && state->ifBlock->listElseState){
                printpoints();
                printf("Block\n");
                printStatement(state->ifBlock->listElseState);
        } else {
            printStatement(state->ifBlock->listState);
            printStatement(state->ifBlock->listElseState);
        }
        nivel--;
    }
    if(state->whileBlock){
        printpoints();
        printf("While\n");
        nivel++;
        printExpression(state->whileBlock->expression);
        if(!state->whileBlock->listStatement){
            printpoints();
            printf("Block\n");
        }else{
            printStatement(state->whileBlock->listStatement);

        }
        nivel--;
    }
    if(state->returnblock){
        printpoints();
        printf("Return\n");
        nivel++;
        if(state->returnblock->expression){
            printExpression(state->returnblock->expression);
        }
        nivel--;
    }
    if(state->listStatement){
        int flag = 0;
        listStatement *aux = state->listStatement;
        if(countStatement2(aux->statement) == 1 && aux->next){
                    printpoints();        
                    printf("Block\n");
                    nivel++;
                    flag = 1;
        }
        while(aux){
            printStatement(aux->statement);
            aux = aux->next;
        }
        if(flag == 1)nivel--;
    }
}

void printStateIf(statement *state){
     listStatement *aux = state->listStatement;
        
        while(aux){
            printStatement(aux->statement);
            aux = aux->next;
        }
}

int countStatement(statement *state){
    int i = 0;
    if(state == NULL){
        return 0;
    }
    listStatement *temp = state->listStatement;
    if(state->ifBlock){
        return 2;
    }
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

int countStatement2(statement *state){
    if(state->assignment)return 1;
    if(state->ifBlock)return 1;
    if(state->methodInvoc)return 1;
    if(state->parseArgs)return 1;
    if(state->print)return 1;
    if(state->returnblock)return 1;
    if(state->whileBlock)return 1;
    if(state->listStatement)return 1;
    return 0;
}

void printExpression(expression *new){
    if(new->boollit){
        printpoints();
        printf("BoolLit(%s)\n",new->boollit);
    }
     if(new->intlit){
        printpoints();
        printf("DecLit(%s)\n",new->intlit);
    }
    if(new->realit){
        printpoints();
        printf("RealLit(%s)\n",new->realit);
    }
    if(new->id && new->dotlenght == 0){
        printpoints();
        printf("Id(%s)\n",new->id);
    }
    if(new->dotlenght == 1){
        printpoints();
        printf("Length\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n", new->id);
        nivel--; 
    }
    if(new->methodInvocation){
        printpoints();
        printf("Call\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",new->methodInvocation->id);
        while(new->methodInvocation->listExpression){
            printExpression(new->methodInvocation->listExpression->expression);
            new->methodInvocation->listExpression = new->methodInvocation->listExpression->next;
        }
        nivel--;
    }
    if(new->parseArgs){
        printpoints();
        printf("ParseArgs\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",new->parseArgs->id);
        printExpression(new->parseArgs->expression);
        nivel--;
    }
    if(new->assignment){
        printpoints();
        printf("Assign\n");
        nivel++;
        printpoints();
        printf("Id(%s)\n",new->assignment->id);
        printExpression(new->assignment->expression);
        nivel--;
    }
    if (new->operator){
        printpoints();
        printf("%s\n", new->operator);
        nivel++;
        if(new->left){
         printExpression(new->left);
        }
        printExpression(new->right);
        nivel--;
    }
    if (new->expressionext){
        printExpression(new->expressionext);
    }

}