%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;


%}

%token <id> INTLIT REALLIT STRLIT 
%token <id> ID
%token WHILE VOID STRING1 STATIC RETURN PUBLIC PARSEINT PRINT ARROW RESERVED
%token INT IF ELSE DOUBLE DOTLENGTH BOOL CLASS
%token XOR RSHIFT LSHIFT
%token SEMICOLON RSQ RPAR RBRACE LSQ LPAR LBRACE
%token <id> PLUS STAR MINUS DIV MOD
%token <id> LT GT EQ NE LE GE
%token <id> OR AND
%token <id> NOT
%token COMMA ASSIGN TRUE FALSE

%left ASSIGN
%left OR
%left XOR
%left AND
%left EQ NE  
%left GE GT LE LT
%left RSHIFT LSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%left NOT // PLUS  MINUS também são unitárias

%type <id>MethodInvocation


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%union{
    char *id;
}
%%
Program: CLASS ID LBRACE ProgramAux RBRACE    
;
ProgramAux: ProgramAux MethodDecl 
        | ProgramAux FieldDecl
        | ProgramAux SEMICOLON
        |
;
MethodDecl: PUBLIC STATIC MethodHeader MethodBody
;
FieldDecl: PUBLIC STATIC Type FieldIdAux SEMICOLON
        | error SEMICOLON
;
FieldIdAux: ID FieldCommaIdAux;

FieldCommaIdAux: FieldCommaIdAux COMMA ID 
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
MethodBodyAux:MethodBodyAux Statement 
        | MethodBodyAux VarDecl
        |
;
VarDecl: Type VarIdAux SEMICOLON
;

VarIdAux: ID VarCommaIdAux;

VarCommaIdAux: VarCommaIdAux COMMA ID 
        |
;
Statement: LBRACE StatementAux RBRACE     
        | IF LPAR Expr RPAR Statement %prec LOWER_THAN_ELSE  
        | IF LPAR Expr RPAR Statement ELSE Statement
        | WHILE LPAR Expr RPAR Statement
        | RETURN Expr SEMICOLON 
        | RETURN SEMICOLON
        | SEMICOLON
        | MethodInvocation SEMICOLON
        | Assignment SEMICOLON
        | ParseArgs SEMICOLON
        | PRINT LPAR Expr RPAR SEMICOLON                       
        | PRINT LPAR STRLIT RPAR SEMICOLON                           
        | error SEMICOLON
;
StatementAux: StatementAux Statement 
        |
;
AuxExprComma: AuxExprComma COMMA Expr       
        |
;
AuxExpr: Expr AuxExprComma 
        |
;
MethodInvocation: ID LPAR AuxExpr RPAR
                | ID LPAR error RPAR                                     
;
Assignment: ID ASSIGN Expr 
;
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR
        | PARSEINT LPAR error RPAR
;
Expr: InitialExpr TextExpr
        |Expr OR Expr
        |Expr AND Expr
        |Expr LT Expr
        |Expr GT Expr
        |Expr EQ Expr
        |Expr NE Expr    
        |Expr LE Expr
        |Expr GE Expr
        |Expr PLUS Expr
        |Expr MINUS Expr
        |Expr STAR Expr
        |Expr DIV Expr
        |Expr MOD Expr
        |Expr XOR Expr
        |Expr LSHIFT Expr
        |Expr RSHIFT Expr
;
InitialExpr: InitialExpr PLUS
        |InitialExpr MINUS
        |InitialExpr NOT 
        |
;
TextExpr:LPAR Expr RPAR
        |MethodInvocation
        |Assignment
        |ParseArgs
        |ID DOTLENGTH
        |ID
        |INTLIT
        |TRUE
        |FALSE
        |REALLIT
        |LPAR error RPAR 
;
%%


