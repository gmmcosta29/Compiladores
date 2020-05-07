%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "strutcs.h"
#include "y.tab.h"
#include "symtab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;

program *programafinal;
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
%left NOT UNITARY // PLUS  MINUS também são unitárias 

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
Program: CLASS ID LBRACE ProgramAux RBRACE    {if(error_yacc==0)$$ = programafinal = insertProgram($2,$4);}
;
ProgramAux: ProgramAux MethodDecl             {if(error_yacc==0)$$ = insertDeclarationList($1,$2,NULL,0);}
        | ProgramAux FieldDecl                  {if(error_yacc==0)$$ = insertDeclarationList($1,NULL,$2,0);}
        | ProgramAux SEMICOLON                  {if(error_yacc==0)$$ = insertDeclarationList($1,NULL,NULL,1);}
        |                                       {if(error_yacc==0)$$ = NULL;}
;
MethodDecl: PUBLIC STATIC MethodHeader MethodBody       {if(error_yacc==0)$$ = insertMethodDec($4,$3);}
;
FieldDecl: PUBLIC STATIC Type FieldIdAux SEMICOLON      {if(error_yacc==0)$$ = insertFieldDec($3,$4);}
        | error SEMICOLON                               {error_yacc = 1;$$ = NULL;}
;
FieldIdAux: ID FieldCommaIdAux         {if(error_yacc==0)$$ = insertListFieldDec($2,$1);}
;
FieldCommaIdAux: COMMA ID FieldCommaIdAux        {if(error_yacc==0)$$ = insertListFieldDec($3,$2);}
        |                                       {if(error_yacc==0)$$ = NULL;}
;
Type:   BOOL            {if(error_yacc==0)$$ = "Bool";} 
        |INT           {if(error_yacc==0)$$ = "Int";}
        |DOUBLE        {if(error_yacc==0)$$ = "Double";}
;
MethodHeader: Type ID LPAR FormalParams RPAR           {if(error_yacc==0)$$ = insertMethodHeader($1,$2,$4);}
            | VOID ID LPAR FormalParams RPAR            {if(error_yacc==0)$$ = insertMethodHeader("Void",$2,$4);}
;
FormalParams: Type ID FormalParamsAux           {if(error_yacc==0)$$ = insertParams($3,$2,$1);}
            | STRING1 LSQ RSQ ID                {if(error_yacc==0)$$ = insertParams(NULL,$4,"StringArray");}
            |                                   {if(error_yacc==0)$$ = NULL;}
;
FormalParamsAux:COMMA Type ID FormalParamsAux   {if(error_yacc==0)$$ = insertParams($4,$3,$2);}
            |                                   {if(error_yacc==0)$$ = NULL;}
;
MethodBody: LBRACE MethodBodyAux RBRACE         {if(error_yacc==0)$$ = $2;}
;
MethodBodyAux: MethodBodyAux Statement           {if(error_yacc==0)$$ = insertMethodBody($1,NULL,$2);} 
        | MethodBodyAux VarDecl                 {if(error_yacc==0)$$ = insertMethodBody($1,$2,NULL);}
        |                                       {if(error_yacc==0)$$ = NULL;}
;
VarDecl: Type VarIdAux SEMICOLON        {if(error_yacc==0)$$ = insertVarDec($1,$2);}
;

VarIdAux: ID VarCommaIdAux             {if(error_yacc==0)$$ = insertListVarDec($2,$1);}
;
VarCommaIdAux: COMMA ID VarCommaIdAux   {if(error_yacc==0)$$ = insertListVarDec($3,$2);}
        |                               {if(error_yacc==0)$$ = NULL;}
;
Statement: LBRACE StatementAux RBRACE     { $$ = insertListStatement($2);}
        | IF LPAR Expression RPAR Statement %prec LOWER_THAN_ELSE       {if(error_yacc==0)$$ = insertIfElse($3,$5,NULL);}  
        | IF LPAR Expression RPAR Statement ELSE Statement              {if(error_yacc==0)$$ = insertIfElse($3,$5,$7);}
        | WHILE LPAR Expression RPAR Statement                          {if(error_yacc==0)$$ = insertWhile($3,$5);}
        | RETURN Expression SEMICOLON                                   {if(error_yacc==0)$$ = insertReturn($2, @1.first_line, @1.first_column);}
        | RETURN SEMICOLON                                              {if(error_yacc==0)$$ = insertReturn(NULL, @1.first_line, @1.first_column);}
        | SEMICOLON                                                     {if(error_yacc==0)$$ = NULL;}
        | MethodInvocation SEMICOLON                                    {if(error_yacc==0)$$ = insertMethodInvocationStatement($1);}
        | Assignment SEMICOLON                                          {if(error_yacc==0)$$ = insertAssignStatement($1);}
        | ParseArgs SEMICOLON                                           {if(error_yacc==0)$$ = insertParseArgsStatement($1);}
        | PRINT LPAR Expression RPAR SEMICOLON                          {if(error_yacc==0)$$ = insertPrint($3,NULL);}
        | PRINT LPAR STRLIT RPAR SEMICOLON                              {if(error_yacc==0)$$ = insertPrint(NULL,$3);}
        | error SEMICOLON                                               {error_yacc = 1;$$ = NULL;}
;
StatementAux: Statement StatementAux    {if(error_yacc==0)$$ = insertMultipleStatement($2,$1);}
        |                               {if(error_yacc==0)$$ = NULL;}
;
AuxExprComma: COMMA Expression AuxExprComma       {if(error_yacc==0)$$ = insertListExpression($3, $2);}
        |                                         {if(error_yacc==0)$$ = NULL;}
;       
AuxExpr: Expression AuxExprComma                {if(error_yacc==0)$$ = insertListExpression($2, $1);}
        |                                       {if(error_yacc==0)$$ = NULL;} 
;
MethodInvocation: ID LPAR AuxExpr RPAR          {if(error_yacc==0)$$ = insertMethodInvocation($1, $3 ,@1.first_line,@1.first_column);}
                | ID LPAR error RPAR            {error_yacc = 1; $$ = NULL;}              
;
Assignment: ID ASSIGN Expression                {if(error_yacc==0)$$ = insertAssign($1, $3,@2.first_line,@2.first_column);}
;
ParseArgs: PARSEINT LPAR ID LSQ Expression RSQ RPAR     {if(error_yacc==0)$$ = insertParseArgs($3, $5,@1.first_line,@1.first_column);}
        | PARSEINT LPAR error RPAR                      {error_yacc = 1; $$ = NULL;}
;
Expression: Expr                                        {if(error_yacc==0)$$ = $1;}    
        |Assignment                                     {if(error_yacc==0)$$ = insertAssignment($1);}
;
Expr:  TextExpr                                         {if(error_yacc==0)$$ = $1;}              
        |Expr OR Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Or", $3,@2.first_line,@2.first_column);}        
        |Expr AND Expr                                  {if(error_yacc==0)$$ = insertOperator($1, "And", $3,@2.first_line,@2.first_column);}
        |Expr LT Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Lt", $3,@2.first_line,@2.first_column);}
        |Expr GT Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Gt", $3,@2.first_line,@2.first_column);}
        |Expr EQ Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Eq", $3,@2.first_line,@2.first_column);}
        |Expr NE Expr                                       {if(error_yacc==0)$$ = insertOperator($1, "Ne", $3,@2.first_line,@2.first_column);}
        |Expr LE Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Le", $3,@2.first_line,@2.first_column);}
        |Expr GE Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Ge", $3,@2.first_line,@2.first_column);}
        |Expr PLUS Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Add", $3,@2.first_line,@2.first_column);}
        |Expr MINUS Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Sub", $3,@2.first_line,@2.first_column);}
        |Expr STAR Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Mul", $3,@2.first_line,@2.first_column);}
        |Expr DIV Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Div", $3,@2.first_line,@2.first_column);}
        |Expr MOD Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Mod", $3,@2.first_line,@2.first_column);}
        |Expr XOR Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Xor", $3,@2.first_line,@2.first_column);}
        |Expr LSHIFT Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Lshift", $3,@2.first_line,@2.first_column);}
        |Expr RSHIFT Expr                                   {if(error_yacc==0)$$ = insertOperator($1, "Rshift", $3,@2.first_line,@2.first_column);}
        |PLUS Expr %prec UNITARY                                   {if(error_yacc==0)$$ = insertUnitary("Plus", $2,@1.first_line,@1.first_column);}                                      
        |MINUS Expr %prec UNITARY                                   {if(error_yacc==0)$$ = insertUnitary("Minus", $2,@1.first_line,@1.first_column);}
        |NOT Expr                                   {if(error_yacc==0)$$ = insertUnitary("Not", $2,@1.first_line,@1.first_column);}
;

TextExpr: LPAR Expression RPAR                          {if(error_yacc==0)$$ = insertMultipleExpression($2);}
        |MethodInvocation                               {if(error_yacc==0)$$ = insertExpression($1, NULL, 0, NULL, NULL, NULL, NULL,0,0);}
        |ParseArgs                                      {if(error_yacc==0)$$ = insertExpression(NULL, $1, 0, NULL, NULL, NULL, NULL,0,0);}
        |ID DOTLENGTH                                   {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 1, $1, NULL, NULL, NULL,@2.first_line,@2.first_column);}                                  
        |ID                                             {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 0, $1, NULL, NULL, NULL,@1.first_line,@1.first_column);}
        |INTLIT                                         {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 0, NULL, $1, NULL, NULL,@1.first_line,@1.first_column);}                                 
        |TRUE                                           {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 0, NULL, NULL, "true", NULL,0,0);}
        |FALSE                                          {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 0, NULL, NULL, "false", NULL,0,0);}
        |REALLIT                                        {if(error_yacc==0)$$ = insertExpression(NULL, NULL, 0, NULL, NULL, NULL, $1,@1.first_line,@1.first_column);}
        |LPAR error RPAR                                {error_yacc = 1; $$ = NULL;}  
;
%%


