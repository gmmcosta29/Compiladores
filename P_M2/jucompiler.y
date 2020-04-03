%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;


%}

%token <id> INTLIT REALLIT STRLIT ESTRING
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
%left NOT // PLUS  MINUS também são unitárias BATATA
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
        | IF LPAR Expression RPAR Statement %prec LOWER_THAN_ELSE  
        | IF LPAR Expression RPAR Statement ELSE Statement
        | WHILE LPAR Expression RPAR Statement
        | RETURN Expression SEMICOLON 
        | RETURN SEMICOLON
        | SEMICOLON
        | MethodInvocation SEMICOLON
        | Assignment SEMICOLON
        | ParseArgs SEMICOLON
        | PRINT LPAR Expression RPAR SEMICOLON                       
        | PRINT LPAR STRLIT RPAR SEMICOLON                           
        | error SEMICOLON
;
StatementAux: StatementAux Statement 
        |
;
AuxExprComma: AuxExprComma COMMA Expression       
        |
;
AuxExpr: Expression AuxExprComma 
        |
;
MethodInvocation: ID LPAR AuxExpr RPAR
                | ID LPAR error RPAR                          
;
Assignment: ID ASSIGN Expression 
;
ParseArgs: PARSEINT LPAR ID LSQ Expression RSQ RPAR
        | PARSEINT LPAR error RPAR
;
Expression: Expr
        |Assignment
;
Expr:  TextExpr
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
        |PLUS Expr 
        |MINUS Expr
        |NOT Expr
;

TextExpr:LPAR Expression RPAR
        |MethodInvocation
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


