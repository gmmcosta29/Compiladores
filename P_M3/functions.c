#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strutcs.h"
#include "symtab.h"
#include "functions.h"

extern tableElement* symtab;
char *methodId;

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

statement * insertReturn(expression *expression1, int line, int column){
    statement *new = (statement*)malloc(sizeof(statement));
    resetStatement(new);
    returnBlock * returnBlock1 = (returnBlock*)malloc(sizeof(returnBlock));
    returnBlock1->line = line;
    returnBlock1->col = column;
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

methodInvocation * insertMethodInvocation(char *id,listExpression * head, int line, int column){
    methodInvocation * new = (methodInvocation*)malloc(sizeof(methodInvocation));
    new->id = (char*)strdup(id);
    new->line = line;
    new->col = column;
    new->listExpression = head;
    return new;
}

assignment * insertAssign( char * id, expression * expression1, int line, int column) {
    assignment * new = (assignment*)malloc(sizeof(assignment));
    new->id = (char*)strdup(id);
    new->line = line;
    new->col = column;
    new->expression = expression1;
    return new;
}

parseArgs * insertParseArgs (char * id, expression * expression1, int line, int column){
    parseArgs * new = (parseArgs*)malloc(sizeof(parseArgs));
    new->line = line;
    new->col = column;
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
expression *insertOperator(expression *expression1,char *operator,expression *expression2,int line,int column){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
    new->line = line;
    new->col = column;
    new->left = expression1;
    new->right = expression2;
    new->operator = (char *)strdup(operator);
    return new;
}

expression* insertUnitary(char *operator,expression *expression1,int line,int column){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
    new->line = line;
    new->col = column;
    new->right = expression1;
    new->operator = (char *)strdup(operator);
    return new;
}

expression* insertExpression(methodInvocation *methodInvocation1,parseArgs *parseArgs1,  int dotlength, char * id, char *intlit, char * boolit, char * reallit, int line,int column){
    expression *new = (expression*)malloc(sizeof(expression));
    resetExpression(new);
    new->methodInvocation = methodInvocation1;
    new->parseArgs = parseArgs1;
    new->dotlenght = dotlength;
    new->line = line;
    new->col = column;
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
    methodId = (char*)strdup(base->methodHeader->id);
    if(base->methodBody){
        printMethodBody(base->methodBody);
    }
    free(methodId);
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
extern tableElement* symtab;
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
        printf("Call - %s\n", getMethodType(state->methodInvoc->id));
        nivel++;
        printpoints();
        printf("Id(%s) - (%s)\n",state->methodInvoc->id,getMethodParams(state->methodInvoc->id));
        while(state->methodInvoc->listExpression){
            printExpression(state->methodInvoc->listExpression->expression);
            state->methodInvoc->listExpression = state->methodInvoc->listExpression->next;
        }
        nivel--;
    }
    if(state->parseArgs){
        printpoints();
        printf("ParseArgs - int\n");
        nivel++;
        char * type = (char*)strdup(getType(state->parseArgs->id));
        printpoints();
        printf("Id(%s) - %s\n",state->parseArgs->id, type);
        printExpression(state->parseArgs->expression);
        nivel--;
    }
    if(state->assignment){
        char * type = (char*)strdup(getType(state->assignment->id));
        printpoints();        
        printf("Assign - %s\n", type);
        nivel++;                  
        printpoints();
        printf("Id(%s) - %s\n",state->assignment->id, type);
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

char* getType(char *id){
    tableElement *temp;
	listVarDec *aux1;
    params *temp2;
    variablesAux  *temp1;
    if(methodId){
        for(temp=symtab;temp;temp=temp->next){
            if(temp->methodVariables){
                if(strcmp(temp->methodVariables->id,methodId) == 0){
                    if(temp->methodVariables->variablesAux){
                        for(temp1 = temp->methodVariables->variablesAux;temp1;temp1 = temp1->next){
                            char *type = (char *)strdup(temp1->variables->type); 
                            for(aux1 = temp1->variables->listVarDec;aux1;aux1 = aux1->next){
                                if(strcmp(aux1->id, id) == 0){
                                    return toLow(type);
                                }
                            }
                        }
                    }
                    if(temp->methodVariables->params){
                        for(temp2 = temp->methodVariables->params;temp2;temp2=temp2->next){
                            if(strcmp(temp2->id, id) == 0){
                                return toLow(temp2->type);
                            }
                        }
                    } 
                }
            }
        }   
    } 
    for(temp=symtab;temp;temp = temp->next){
        if(temp->variables){
            char *type = (char *)strdup(temp->variables->type);
            listFieldDec *aux1;
            for(aux1 = temp->variables->listFieldDec;aux1;aux1 = aux1->next){
                if(strcmp(aux1->id, id) == 0){
                  return toLow(type);
               }
		    }
        }
    }    
}
 char* getMethodType(char * id){
     tableElement *temp;
     for(temp=symtab; temp; temp=temp->next){
         if(temp->methodVariables){
             if(strcmp(temp->methodVariables->id, id) == 0){
                 return toLow(temp->methodVariables->type);
             }
         }
     }
 }
char * concatString(char *init, char * new){
    char *resp;
    size_t initlen;
    if(init){
        strcat(init, ", ");
        initlen = strlen(init);
    }else{
        initlen = 0;
    }
    size_t newlen = strlen(new);
    size_t buffer = initlen + newlen + 1;
    if(init){
        resp = realloc(resp, buffer * sizeof(char));
        strcpy(resp,init);
        strcat(resp,new);        
    }else{
        resp = malloc(buffer * sizeof(char));
        strcpy(resp,new);
    }
    return resp;

}
 char* getMethodParams(char *id){
     tableElement *temp;
     char *answer = NULL;
     for(temp=symtab; temp; temp=temp->next){
         if(temp->methodVariables){
             if(strcmp(temp->methodVariables->id, id) == 0){
                params *temp1;
                for(temp1=temp->methodVariables->params; temp1;temp1 =  temp1->next){
                    //retrurn da concatenação de todos os temp1->type
                 answer = concatString(answer,toLow(temp1->type));   
                }
                if(!answer){
                    return "TODO";                
                }
                answer[strlen(answer)] = '\0';
                return answer;
             }
         }
     }
     return "TODO-ERRO";
 }

char* getExpressionType (expression *new){
    if(new->boollit){
        return "boolean";
    }
    if(new->intlit){
        return "int";
    }
    if(new->realit){
        return "double";
    }
    if(new->id && new->dotlenght == 0){
        char * type = (char*)strdup(getType(new->id));
        return type;
    }
    if(new->dotlenght == 1){
        return "int";
    }
    if(new->methodInvocation){
        char *type = getMethodType(new->methodInvocation->id);
        return type;
    }
    if(new->parseArgs){
        return "int";
    }
    if(new->assignment){
        char * type = (char*)strdup(getType(new->id));
        return type;
    }
    if (new->operator){
        if(!new->left && new->right){
            if(strcmp(new->operator, "Not")){
                return "boolean";
            }
            else {
                return getExpressionType(new->right);
            }
        } else {
                char *operator = (char*) strdup(new->operator);
                char *typeLeft = getExpressionType(new->left);
                char *typeRight = getExpressionType(new->right);
                if(strcmp(operator, "Xor") == 0 || strcmp(operator, "Or") == 0 || strcmp(operator, "And") == 0 || strcmp(operator, "Lt") == 0 || strcmp(operator, "Gt") == 0 || strcmp(operator, "Eq") == 0 || strcmp(operator, "Ne") == 0 || strcmp(operator, "Le") == 0 || strcmp(operator, "Ge") == 0) {
                   return "boolean";    
                }
                else if(strcmp("Lshift",operator) == 0 || strcmp("Rshift",operator) == 0){
                    if(strcmp(typeLeft,"double")== 0 || strcmp(typeRight,"double")== 0 ){
                        printf("ERROR - LSHIFHT|RSHIFT with double\tLINE:%d\tCOL:%d\n",new->line,new->col);
                        return "error";
                    }
                    return "int";
                }
                else {
                    if(strcmp(typeLeft,"double")== 0 || strcmp(typeRight,"double")== 0 ){
                        return "double";
                    }
                    return "int";
                }
        }
    }
    if(new->expressionext){
        return(getExpressionType(new->expressionext));
        //printf("%s\n", new->expressionext->assignment->id);
    }
    return NULL;
}
void printExpression(expression *new){
    if(new->boollit){
        printpoints();
        printf("BoolLit(%s) - boolean\n",new->boollit);
    }
     if(new->intlit){
        printpoints();
        printf("DecLit(%s) - int\n",new->intlit);
    }
    if(new->realit){
        printpoints();
        printf("RealLit(%s) - double\n",new->realit);
    }
    if(new->id && new->dotlenght == 0){
        printpoints();
        char * type = (char*)strdup(getType(new->id));
        printf("Id(%s) - %s\n",new->id, type);
    }
    if(new->dotlenght == 1){
        printpoints();
        printf("Length - int\n");
        nivel++;
        printpoints();
        char * type = (char*)strdup(getType(new->id));
        printf("Id(%s) - %s\n", new->id, type);
        nivel--; 
    }
    if(new->methodInvocation){
        printpoints();
        //GetMethodPArams está apenas a verificar os paramentros do methodo e não se os temos na nossa metodo invocation, esses "calculas" tẽm de ser feitos antes pois se hover algum erro o call sai com undef
        printf("Call - %s\n", getMethodType(new->methodInvocation->id));
        nivel++;
        printpoints();
        printf("Id(%s) - (%s)\n",new->methodInvocation->id,getMethodParams(new->methodInvocation->id));
        while(new->methodInvocation->listExpression){
            printExpression(new->methodInvocation->listExpression->expression);
            new->methodInvocation->listExpression = new->methodInvocation->listExpression->next;
        }
        nivel--;
    }
    if(new->parseArgs){
        printpoints();
        printf("ParseArgs - int\n");
        nivel++;
        char * type = (char*)strdup(getType(new->parseArgs->id));
        printpoints();
        printf("Id(%s) - %s\n",new->parseArgs->id, type);
        printExpression(new->parseArgs->expression);
        nivel--;
    }
    if(new->assignment){
        char * type = (char*)strdup(getType(new->assignment->id));
        printpoints();       
        nivel--;
    }
    if (new->operator){
        printpoints();
        printf("%s - %s\n", new->operator, getExpressionType(new));
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
