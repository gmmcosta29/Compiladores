#include <stdio.h>
#include "header.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void){
    int vtoken;
    char *ntoken = yylex();
    while(ntoken != EOF){
        printf("%s\n",ntoken);
        ntoken = yylex();
    }
    return 0;
}
 