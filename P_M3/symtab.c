#include	"symtab.h"
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
extern tableElement* symtab;

void insert_FieldDec (fieldDec *aux){
    tableElement *temp, *new = (tableElement*)malloc(sizeof(tableElement));
    new->next = NULL;
	new->variables = (fieldDec*)malloc(sizeof(fieldDec));
	new->variables = aux;
	if(!symtab){
		symtab = new;
		return;
	}
    for(temp = symtab; temp->next; temp = temp->next);
    temp->next = new;
}

variablesAux* insertVarAux(variablesAux *head , varDec * new){
	variablesAux *aux = (variablesAux*)malloc(sizeof(variablesAux)),*temp;
	aux->next = NULL;
	aux->variables = (varDec*)malloc(sizeof(varDec));
	aux->variables = new;
	if(!head){
		head = aux;
		return head;
	}
	for(temp = head;temp->next;temp = temp->next);
	temp->next = aux;
	return head;
}
void insert_MethodDec (methodDec *aux){
    tableElement *temp, *new = (tableElement*)malloc(sizeof(tableElement));
	methodBody *bla;

	new->methodVariables = (methodVariables*)malloc(sizeof(methodVariables));
	for(bla = aux->methodBody;bla;bla = bla->next){
		if(bla->varDec){
			new->methodVariables->variablesAux = insertVarAux(new->methodVariables->variablesAux, bla->varDec);
		}
	}
	new->next = NULL;
   	new->methodVariables->id =  (char *)strdup(aux->methodHeader->id);
    new->methodVariables->type = (char *)strdup(aux->methodHeader->type);
    new->methodVariables->params = (params*)malloc(sizeof(params));
	new->methodVariables->params = aux->methodHeader->params;
	//printf("%s\n", new->methodVariables->variablesAux->variables->listVarDec->id);

	if(!symtab){
		symtab = new;
		return;
	}
	for(temp = symtab; temp->next; temp = temp->next);
    temp->next = new;
}

char* toLow(char* str){
	if(str==NULL){return "null";}
	if(strcmp(str,"Int")==0)return "int";
	if(strcmp(str,"Bool")==0)return "boolean";
	if(strcmp(str,"StringArray")==0)return "String[]";
	if(strcmp(str,"Void")==0)return "void";	
	if(strcmp(str,"Double")==0)return "double";	
	return str;	
}

void check_program(program *pro){
    declarations *temp;
    if (pro == NULL) return;
    for(temp = pro->declaration;temp;temp = temp->next){
		if(temp->methodDec != NULL){

			insert_MethodDec(temp->methodDec);

        }else if (temp->fieldDec != NULL){

			insert_FieldDec(temp->fieldDec);
        }
    }
}
void show_symtab(program *pro){
	
	tableElement* tab;
	if(symtab==NULL) return;
	printf("===== Class %s Symbol Table =====\n",pro->id);
	for(tab=symtab; tab; tab=tab->next){

		if(tab->methodVariables!=NULL) {
			
			printf("%s\t(",tab->methodVariables->id);
			params* p;
			for(p=tab->methodVariables->params; p; p=p->next){
				if(p->next==NULL){printf("%s",toLow(p->type));}
				else{printf("%s,",toLow(p->type));}			
			}
			if(tab->methodVariables->type==NULL){
				printf(")\tnone\n");			
			}
			else{	printf(")\t%s\n",toLow(tab->methodVariables->type)); }			
		}
		else{
			char *vartype=(char*)strdup(tab->variables->type);
			listFieldDec* var;			
			
			for(var=tab->variables->listFieldDec; var; var=var->next){
				printf("%s\t\t%s\n",var->id, toLow(vartype));
			}

		}
	}
	printf("\n");
	for(tab=symtab; tab; tab=tab->next){
		if(tab->methodVariables!=NULL) {
			params* aux;
			printf("===== Method %s(",tab->methodVariables->id);
			for(aux=tab->methodVariables->params; aux; aux=aux->next){
				if(aux->next==NULL){printf("%s",toLow(aux->type));}
				else{printf("%s,",toLow(aux->type));}	
			}	
			printf(") Symbol Table =====\n");
			if(tab->methodVariables->type==NULL){
				printf("return\t\tnone\n");			
			}else{
				printf("return\t\t%s\n",toLow(tab->methodVariables->type));
			}
			//params
			
			for(aux=tab->methodVariables->params; aux; aux=aux->next){
				printf("%s\t\t%s\tparam\n",aux->id,toLow(aux->type));
			}
			variablesAux  * temp;
			for(temp = tab->methodVariables->variablesAux;temp;temp = temp->next){
				listVarDec *aux1;
				char *type = (char *)strdup(temp->variables->type); 
				for(aux1 = temp->variables->listVarDec;aux1;aux1 = aux1->next){
					printf("%s\t\t%s\n",aux1->id,toLow(type));
				}
			}
			printf("\n");
		}
	}
}