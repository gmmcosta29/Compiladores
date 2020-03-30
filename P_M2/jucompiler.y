%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;


%}

%token RESERVED
%token <id> INTLIT REALLIT STRLIT 
%token <id> ID
%token WHILE VOID STRING1 STATIC RETURN PUBLIC PARSEINT PRINT 
%token INT IF ELSE DOUBLE DOTLENGTH BOOL CLASS
%token XOR RSHIFT LSHIFT
%token ARROW SEMICOLON RSQ RPAR RBRACE LSQ LPAR LBRACE
%token <id> PLUS STAR MINUS DIV MOD
%token <id> LT GT EQ NE LE GE
%token <id> OR AND
%token <id> NOT
%token COMMA ASSIGN TRUE FALSE

%left OR
%left AND
%left LT GT EQ NE LE GE
%left PLUS MINUS
%left STAR DIV MOD

%type <id>MethodInvocation


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%union{
    char *id;
}
%%
Program: CLASS ID LBRACE ProgramAux RBRACE      {printf("LEolsad\n");} 
;
ProgramAux: ProgramAux MethodDecl 
        | ProgramAux FieldDecl
        | ProgramAux SEMICOLON
        |
;
MethodDecl: PUBLIC STATIC MethodHeader MethodBody
;
FieldDecl: PUBLIC STATIC Type ID CommaIdAux SEMICOLON
;
CommaIdAux: COMMA ID CommaIdAux
        |
;
Type: BOOL | INT | DOUBLE
;
MethodHeader: Type ID LPAR FormalParams RPAR
            | VOID ID LPAR FormalParams RPAR
;
FormalParams: Type ID FormalParamsAux
            | STRING1 LSQ RSQ ID 
            | 
;
FormalParamsAux:FormalParamsAux COMMA Type ID 
            |
;
MethodBody: LBRACE MethodBodyAux RBRACE
;
MethodBodyAux:MethodBodyAux Statement {printf("we\n");}
        | MethodBodyAux VarDecl
        |
;
VarDecl: Type ID CommaIdAux SEMICOLON
;
Statement: LBRACE StatementAux RBRACE     {printf("1\n");}
        | LBRACE RBRACE 
        | IF LPAR Expr RPAR Statement %prec LOWER_THAN_ELSE  {printf("lolol\n");}
        | IF LPAR Expr RPAR Statement ELSE Statement
        | WHILE LPAR Expr RPAR Statement
        | RETURN Expr SEMICOLON 
        | RETURN SEMICOLON
        | SEMICOLON
        | MethodInvocation SEMICOLON
        | Assignment SEMICOLON
        | ParseArgs SEMICOLON
        | PRINT LPAR Expr RPAR SEMICOLON                       {printf("++++++++++++++++++++++++aqui\n");}
        | PRINT LPAR STRLIT RPAR SEMICOLON                             {printf("sdgislnjsdfksdfsdkfkd\n");}
;
StatementAux: StatementAux Statement 
        |
;
AuxExpr:AuxExpr COMMA Expr     
        |
;
MethodInvocation: ID LPAR Expr AuxExpr RPAR
                | ID LPAR RPAR 
                | ID LPAR error RPAR                                     {printf("erro\n");error_yacc=1;$$=NULL;}
;
Assignment: ID ASSIGN Expr
;
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR
;
Op1: PLUS | MINUS | STAR | DIV | MOD
;
Op2: AND | OR | XOR | LSHIFT | RSHIFT
;
Op3: EQ | GE | GT | LE | LT | NE
;
Op4: MINUS | NOT | PLUS
;
Expr: Expr Op1 Expr
        |Expr Op2 Expr
        |Expr Op3 Expr           
        |Op4 Expr
        |LPAR Expr RPAR
        |MethodInvocation
        |Assignment
        |ParseArgs
        |ID DOTLENGTH
        |ID
        |INTLIT
        |TRUE
        |FALSE
        |REALLIT
;
%%


