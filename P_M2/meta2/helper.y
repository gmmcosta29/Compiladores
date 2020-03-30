

%token RESERVED
%token <id> INTLIT REALLIT STRLIT 
%token <id> ID
%token WHILE VOID STRING STATIC RETURN PUBLIC PARSEINT PRINT 
%token INT IF ELSE DOUBLE DOTLENGTH CLASS BOOL
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






Program: CLASS ID LBRACE ProgramAux RBRACE      {printf("LEolsad");} 
;
ProgramAux: MethodDecl ProgramAux
        | FieldDecl ProgramAux
        | SEMICOLON ProgramAux
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
FormalParams: Type ID  
            | COMMA Type ID FormalParams
            | STRING LSQ RSQ ID 
            | COMMA STRING LSQ RSQ ID FormalParams
            | 
;
MethodBody: LBRACE MethodBodyAux RBRACE
;
MethodBodyAux: Statement MethodBodyAux
        | VarDecl MethodBodyAux
        |
;
VarDecl: Type ID CommaIdAux SEMICOLON
;
Statement: LBRACE Statement RBRACE  
        | LBRACE RBRACE 
        | IF LPAR Expr RPAR Statement ELSE Statement
        | IF LPAR Expr RPAR Statement
        | WHILE LPAR Expr RPAR Statement
        | RETURN MultExpr SEMICOLON 
        | PRINT LPAR Expr RPAR SEMICOLON
        | PRINT LPAR STRLIT RPAR SEMICOLON 
;
MultExpr: MultExpr Expr
        |
;
AuxExpr: Expr AuxExpr
        | COMMA Expr AuxExpr     
        |
;
MethodInvocation: ID LPAR AuxExpr RPAR
;
Assignment: ID ASSIGN Expr
;
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ LPAR
;
Op1: PLUS | MINUS | STAR | DIV | MOD
;
Op2: AND | OR | XOR | LSHIFT | RSHIFT
;
Op3: EQ | GE | GT | LE | LT | NE
;
Op4: MINUS | NOT | PLUS
;
DotLength: DOTLENGTH DotLength
        |
;
Expr: Expr Op1 Expr
        |Expr Op2 Expr
        |Expr Op3 Expr
        |Op4 Expr
        |LPAR Expr RPAR
        |MethodInvocation
        |Assignment
        |ParseArgs
        |ID DotLength
        |INTLIT
        |TRUE
        |FALSE
        |REALLIT
;