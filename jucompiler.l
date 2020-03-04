%{
#include <stdio.h>
#include <stdlib.h>
char* remove_(char* s){
    for(int i = 0;i<strlen(s);i++){
        if(s[i] == '_'){
            s[i] = "";
        }
    }
    return s;
}    
    
    
%}


aspas                \"
numero				([0-9 | "_"]+)
numeroall           [0-9 | "_"]*
semzero             [1-9]+
aab                 "aab"
expoente           ([Ee][+-])
underscore          "_"*
f                   "\f"[A-Za-z]
n                   "\n"
r                   "\r"
t                   "t"
doubles             "\\"
singles             "\"
escape              [A-z][^n][^r][^f][^t]
id                  [A-Za-z][A-Za-z_$0-9]*
reserved            "++"|"--"|"null"|"System"|"Integer"|"abstract"|"continue"|"for"|"new"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"implements"|"protected"|"import"|"enum"|"instanceof"|"extends"|"short"|"final"|"interface"|"finally"|"long"|"strictfp"|"float"|"native"|"super"|"switch"|"throw"|"throws"|"assert"|"this"|"break"|"byte"|"case"|"transient"|"catch"|"try"|"char"|"volatile"|"const"|"_"


%X STRING
%%
[ \t\n]+          /* eat up whitespace */
{semzero}{numeroall}{expoente}{semzero}{numeroall}                          {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}"."{numeroall}{expoente}{semzero}{numeroall}            {printf("REALLIT(%s\n)",remove_(yytext));}
"0"?"."{numero}{expoente}{semzero}{numeroall}                               {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}{expoente}{semzero}{numeroall}"."{numero}               {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}{expoente}"0"?"."{numero}                               {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}"."{numero}                                             {printf("REALLIT(%s\n)",remove_(yytext));}
"0"?"."{numero}                                                             {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}"."{numeroall}{expoente}{semzero}{numeroall}"."{numero} {printf("REALLIT(%s\n)",remove_(yytext));}
"0"?"."{numero}{expoente}{semzero}{numeroall}"."{numero}                    {printf("REALLIT(%s\n)",remove_(yytext));}
{semzero}{numeroall}"."{numeroall}{expoente}"0"?"."{numero}                 {printf("REALLIT(%s\n)",remove_(yytext));}
"0"?"."{numero}{expoente}"0"?"."{numero}                                    {printf("REALLIT(%s\n)",remove_(yytext));}

"0"                                                                         {printf("INTLIT(0)\n");}
{semzero}{numeroall}                                                        {printf("INTLIT(%s)\n",remove_(yytext));}


{aspas}.{escape}.{aspas}      {printf("STR\n");}
{aspas}.{aspas}     {printf("STRLIT\n");}

"while"             {printf("WHILE\n");}
"void"              {printf("VOID\n");}
"String"            {printf("STRING\n");}
"static"            {printf("STATIC\n");}
"return"            {printf("RETURN\n");}
"public"            {printf("PUBLIC\n");}
"Integer.parseInt"  {printf("PARSEINT\n");}
"System.out.print"  {printf("PRINT\n");}
"int"               {printf("INT\n");}
"if"                {printf("IF\n");}
"else"              {printf("ELSE\n");}
"double"            {printf("DOUBLE\n");}
".length"           {printf("DOTLENGTH\n");}
"class"             {printf("CLASS\n");}
"boolean"           {printf("BOOL\n");}
"^"                 {printf("XOR\n");}
">>"                {printf("RSHIFT\n");}
"<<"                {printf("LSHIFT\n");}
"->"                {printf("ARROW\n");}
";"                 {printf("SEMICOLON\n");}
"]"                 {printf("RSQ\n");}
")"                 {printf("RPAR\n");}
"}"                 {printf("RBRACE\n");}
"+"                 {printf("PLUS\n");}
"||"                {printf("OR\n");}
"!"                 {printf("NOT\n");}
"!="                {printf("NE\n");}
"%"                 {printf("MOD\n");}
"-"                 {printf("MINUS\n");}
"<"                 {printf("LT\n");}
"["                 {printf("LSQ\n");}
"("                 {printf("LPAR\n");}
"<="                {printf("LE\n");}
"{"                 {printf("LBRACE\n");}
">"                 {printf("GT\n");}
">="                {printf("GE\n");}
"=="                {printf("EQ\n");}
"/"                 {printf("DIV\n");}
","                 {printf("COMMA\n");}
"*"                 {printf("STAR\n");}
"="                 {printf("ASSIGN\n");}
"&&"                {printf("AND\n");}
"true"              {printf("BOOLLIT\n");}
"false"             {printf("BOOLLIT\n");}
{reserved}          {printf("RESERVED\n");}
{id}                {printf("ID(%s)\n",yytext);}

%%
int main()
{
    yylex();
    return 0;
}

int yywrap()
{
return 1;
}
