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
%%
{numero}"."{numero}{expoente}{numero}   return REALLIT
"."{numero}{expoente}{numero}   return REALLIT
{numero}"."{expoente}{numero}   return REALLIT
{numero0}{numero}{expoente}{numero}   return REALLIT
{numero}"."{numero}     return REALLINT
"."{numero}         return REALLIT
{numero0}{numero1}   return INTLIT
"0"                 return INTLIT
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