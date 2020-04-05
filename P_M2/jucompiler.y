%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "strutcs.h"
#include "y.tab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;

program *programafinal;
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
%left NOT // PLUS  MINUS também são unitárias 

%type<programVar> Program
%type<declarationsVar> ProgramAux
%type<methodDecVar> MethodDecl
%type<fieldDecVar> FieldDecl
%type<listFieldDecVar> FieldIdAux FieldCommaIdAux
%type<id> Type  
%type<methodHeaderVar> MethodHeader
%type<paramsVar> FormalParams FormalParamsAux
%type<methodBodyVar> MethodBody MethodBodyAux
%type<varDecVar> VarDecl
%type<listVarDecVar> VarIdAux VarCommaIdAux
%type<statementVar> Statement
%type<listStatementVar> StatementAux
%type<listExpressionVar> AuxExpr AuxExprComma
%type<methodInvocationVar> MethodInvocation
%type<assignmentVar> Assignment
%type<parseArgsVar> ParseArgs
%type<expressionVar> Expression Expr TextExpr


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%union{
    char *id;
    program *programVar;
    declarations *declarationsVar;
    methodDec *methodDecVar;
    fieldDec *fieldDecVar;
    listFieldDec *listFieldDecVar;
    methodHeader *methodHeaderVar;
    params *paramsVar;
    methodBody *methodBodyVar;
    varDec *varDecVar;
    listVarDec *listVarDecVar;
    statement *statementVar;
    listStatement *listStatementVar;
    listExpression *listExpressionVar;
    methodInvocation *methodInvocationVar;
    assignment *assignmentVar;
    parseArgs *parseArgsVar;
    expression *expressionVar;
}
%%
Program: CLASS ID LBRACE ProgramAux RBRACE    { $$ = programafinal = insertProgram($2,$4);}
;
ProgramAux: ProgramAux MethodDecl             {$$ = insertDeclarationList($1,$2,NULL,0);}
        | ProgramAux FieldDecl                  {$$ = insertDeclarationList($1,NULL,$2,0);}
        | ProgramAux SEMICOLON                  {$$ = insertDeclarationList($1,NULL,NULL,1);}
        |                                       {$$ = NULL;}
;
MethodDecl: PUBLIC STATIC MethodHeader MethodBody       {$$ = insertMethodDec($4,$3);}
;
FieldDecl: PUBLIC STATIC Type FieldIdAux SEMICOLON      {$$ = insertFieldDec($3,$4);}
        | error SEMICOLON                               {error_yacc = 1;$$ = NULL;}
;
FieldIdAux: ID FieldCommaIdAux         {$$ = insertListFieldDec($2,$1);}
;
FieldCommaIdAux: FieldCommaIdAux COMMA ID        {$$ = insertListFieldDec($1,$3);}
        |                                       {$$ = NULL;}
;
Type:   BOOL            {$$ = "Bool";} 
        |INT           {$$ = "Int";}
        |DOUBLE        {$$ = "Double";}
;
MethodHeader: Type ID LPAR FormalParams RPAR           {$$ = insertMethodHeader($1,$2,$4);}
            | VOID ID LPAR FormalParams RPAR            {$$ = insertMethodHeader("Void",$2,$4);}
;
FormalParams: Type ID FormalParamsAux           {$$ = insertParams($3,$2,$1);}
            | STRING1 LSQ RSQ ID                {$$ = insertParams(NULL,$4,"StringArray");}
            |                                   {$$ = NULL;}
;
FormalParamsAux:FormalParamsAux COMMA Type ID   {$$ = insertParams($1,$4,$3);}
            |                                   {$$ = NULL;}
;
MethodBody: LBRACE MethodBodyAux RBRACE         {$$ = $2;}
;
MethodBodyAux: MethodBodyAux Statement           {$$ = insertMethodBody($1,NULL,$2);} 
        | MethodBodyAux VarDecl                 {$$ = insertMethodBody($1,$2,NULL);}
        |                                       {$$ = NULL;}
;
VarDecl: Type VarIdAux SEMICOLON        {$$ = insertVarDec($1,$2);}
;

VarIdAux: ID VarCommaIdAux             {$$ = insertListVarDec($2,$1);}
;
VarCommaIdAux: VarCommaIdAux COMMA ID   {$$ = insertListVarDec($1,$3);}
        |                               {$$ = NULL;}
;
Statement: LBRACE StatementAux RBRACE     { $$ = insertListStatement($2);}
        | IF LPAR Expression RPAR Statement %prec LOWER_THAN_ELSE       {$$ = insertIfElse($3,$5,NULL);}  
        | IF LPAR Expression RPAR Statement ELSE Statement              {$$ = insertIfElse($3,$5,$7);}
        | WHILE LPAR Expression RPAR Statement                          {$$ = insertWhile($3,$5);}
        | RETURN Expression SEMICOLON                                   {$$ = insertReturn($2);}
        | RETURN SEMICOLON                                              {$$ = insertReturn(NULL);}
        | SEMICOLON                                                     {$$ = NULL;}
        | MethodInvocation SEMICOLON                                    {$$ = insertMethodInvocationStatement($1);}
        | Assignment SEMICOLON                                          {$$ = insertAssignStatement($1);}
        | ParseArgs SEMICOLON                                           {$$ = insertParseArgsStatement($1);}
        | PRINT LPAR Expression RPAR SEMICOLON                          {$$ = insertPrint($3,NULL);}
        | PRINT LPAR STRLIT RPAR SEMICOLON                              {$$ = insertPrint(NULL,$3);}
        | error SEMICOLON                                               {error_yacc = 1;$$ = NULL;}
;
StatementAux: StatementAux Statement    {$$ = insertMultipleStatement($1,$2);}
        |                               {$$ = NULL;}
;
AuxExprComma: AuxExprComma COMMA Expression       {$$ = insertListExpression($1, $3);}
        |                                         {$$ = NULL;}
;       
AuxExpr: Expression AuxExprComma                {$$ = insertListExpression($2, $1);}
        |                                       {$$ = NULL;} 
;
MethodInvocation: ID LPAR AuxExpr RPAR          {$$ = insertMethodInvocation($1, $3);}
                | ID LPAR error RPAR            {error_yacc = 1; $$ = NULL;}              
;
Assignment: ID ASSIGN Expression                {$$ = insertAssign($1, $3);}
;
ParseArgs: PARSEINT LPAR ID LSQ Expression RSQ RPAR     {$$ = insertParseArgs($3, $5);}
        | PARSEINT LPAR error RPAR                      {error_yacc = 1; $$ = NULL;}
;
Expression: Expr                                        {$$ = $1;}    
        |Assignment                                     {$$ = insertAssignment($1);}
;
Expr:  TextExpr                                         {$$ = $1;}              
        |Expr OR Expr                                   {$$ = insertOperator($1, "Or", $3);}        
        |Expr AND Expr                                  {$$ = insertOperator($1, "And", $3);}
        |Expr LT Expr                                   {$$ = insertOperator($1, "Lt", $3);}
        |Expr GT Expr                                   {$$ = insertOperator($1, "Gt", $3);}
        |Expr EQ Expr                                   {$$ = insertOperator($1, "Eq", $3);}
        |Expr NE Expr                                       {$$ = insertOperator($1, "Ne", $3);}
        |Expr LE Expr                                   {$$ = insertOperator($1, "Le", $3);}
        |Expr GE Expr                                   {$$ = insertOperator($1, "Ge", $3);}
        |Expr PLUS Expr                                   {$$ = insertOperator($1, "Plus", $3);}
        |Expr MINUS Expr                                   {$$ = insertOperator($1, "Minus", $3);}
        |Expr STAR Expr                                   {$$ = insertOperator($1, "Star", $3);}
        |Expr DIV Expr                                   {$$ = insertOperator($1, "Div", $3);}
        |Expr MOD Expr                                   {$$ = insertOperator($1, "Mod", $3);}
        |Expr XOR Expr                                   {$$ = insertOperator($1, "Xor", $3);}
        |Expr LSHIFT Expr                                   {$$ = insertOperator($1, "Lshift", $3);}
        |Expr RSHIFT Expr                                   {$$ = insertOperator($1, "Rshift", $3);}
        |PLUS Expr                                   {$$ = insertUnitary("Plus", $2);}                                      
        |MINUS Expr                                   {$$ = insertUnitary("Minus", $2);}
        |NOT Expr                                   {$$ = insertUnitary("Not", $2);}
;

TextExpr: LPAR Expression RPAR                         {$$ = insertMultipleExpression($2);}
        |MethodInvocation                               {$$ = insertExpression($1, NULL, 0, NULL, NULL, NULL, NULL);}
        |ParseArgs                                {$$ = insertExpression(NULL, $1, 0, NULL, NULL, NULL, NULL);}
        |ID DOTLENGTH                               {$$ = insertExpression(NULL, NULL, 1, $1, NULL, NULL, NULL);}                                  
        |ID                                     {$$ = insertExpression(NULL, NULL, 0, $1, NULL, NULL, NULL);}
        |INTLIT                               {$$ = insertExpression(NULL, NULL, 0, NULL, $1, NULL, NULL);}                                 
        |TRUE                               {$$ = insertExpression(NULL, NULL, 0, NULL, NULL, "True", NULL);}
        |FALSE                               {$$ = insertExpression(NULL, NULL, 0, NULL, NULL, "False", NULL);}
        |REALLIT                               {$$ = insertExpression(NULL, NULL, 0, NULL, NULL, NULL, $1);}
        |LPAR error RPAR                       {error_yacc = 1; $$ = NULL;}  
;
%%


