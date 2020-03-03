%{
    #include "header.h"

    /*
        perguntar ao Prof:
            RESERVED
            SEQUENCIAS DE ESCAPE
            ULTIMA PARTE DE REALLIT E INTLIT "_"

    */
%}

aspas "
numero				[0-9]+
expoente            [eE][+-]
numero0             [1-9]
numero1             [0-9]*
underscore          "-"*
f                   "\f"
n                   "\n"
r                   "\r"
t                   "t"
doubles             "\\"
singles             "\"
escape              [A-z][^n][^r][^f][^t]

%X STRING
%%
{numero0}{numero1}"."{numero}{expoente}{numero0}{numero}   return REALLIT
"."{numero}{expoente}{numero0}{numero}   return REALLIT
{numero0}{numero1}"."{expoente}{numero0}{numero}   return REALLIT
{numero0}{numero}{expoente}{numero0}{numero}   return REALLIT
{numero0}{numero1}"."{numero1}     return REALLINT
"."{numero}         return REALLIT
{numero0}{numero1}{underscore}{numero}     return INTLIT
{numero0}{numero1}   return INTLIT
"0"                 return INTLIT
{aspas}             {BEGIN STRING;}
<STRING> {singles}{escape}      return Erro
<STRING> {aspas}            {BEGIN 0;}
{aspas}.{escape}.{aspas}

{aspas}.{aspas}     return STRLIT
"while"             return WHILE
"void"              return VOID
"String"            return STRING
"static"            return STATIC
"return"            return RETURN
"public"            return PUBLIC
"Integer.parseInt"  return PARSEINT
"System.out.print"  return PRINT
"int"               return INT
"if"                return IF
"else"              return ELSE
"double"            return DOUBLE
".length"           return DOTLENGTH
"class"             return CLASS
"boolean"           return BOOL
"^"                 return XOR
">>"                return RSHIFT
"<<"                return LSHIFT
"->"                return ARROW
";"                 return SEMICOLON
"]"                 return RSQ
")"                 return RPAR
"}"                 return RBRACE
"+"                 return PLUS
"||"                return OR
"!"                 return NOT
"!="                return NE
"%"                 return MOD
"-"                 return MINUS
"<"                 return LT
"["                 return LSQ
"("                 return LPAR
"<="                return LE
"{"                 return LBRACE
">"                 return GT
">="                return GE
"=="                return EQ
"/"                 return DIV
","                 return COMMA
"*"                 return STAR
"="                 return ASSIGN
"&&"                return AND
"true"              return BOOLLIT
"false"             return BOOLLIT


%%
int main(){
    yylex();return 0;
}

int yywrap(){
    return 1;
}