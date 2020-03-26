%{
#include <stdio.h>
#include <stdlib.h>
    int nline = 1;
    int column = 1;
    int errors = 0;
    int state = 0;
    int errol = 1;
    int erroc = 1;

  void resetline(){
  	nline++;
	column=1;
}

    
%}
NEWLINE             \r|\n|\r\n
STARTCOMMENT_1	    "//"
NUMEROZERO          ([1-9]([0-9|_]*[0-9])?)|0   
NUMERO                 [0-9]([0-9|_]*[0-9])?              
INITSTRING           \"
UNDERSCORE          "_"
numeroall           [0-9|_]*
numerof             [0-9]+
semzero             [1-9]+
expoente           ([Ee][+-]?)
id                  [A-Za-z_$][A-Za-z_$0-9]*
reserved            "++"|"--"|"null"|"System"|"Integer"|"abstract"|"continue"|"for"|"new"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"implements"|"protected"|"import"|"enum"|"instanceof"|"extends"|"short"|"final"|"interface"|"finally"|"long"|"strictfp"|"float"|"native"|"super"|"switch"|"throw"|"throws"|"assert"|"this"|"break"|"byte"|"case"|"transient"|"catch"|"try"|"char"|"volatile"|"const"
IGNORE		        " "|\t|\f


%X STRING COMMENT COMMENT_1 
%%
{reserved}          {if (state==1)printf("RESERVED(%s)\n",yytext);column+=yyleng;}

"0"                                                                         {if (state==1)printf("INTLIT(0)\n");column+=yyleng;}
{semzero}{numeroall}{numerof}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;}
{semzero}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;}


{NUMERO}"."{NUMERO}?                      {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{NUMERO}?"."{NUMERO}                      {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{NUMERO}?"."{NUMERO}?{expoente}{NUMERO}                       {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{NUMERO}{expoente}{NUMERO}                       {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}


"while"             {if (state==1)printf("WHILE\n");column+=yyleng;}
"void"              {if (state==1)printf("VOID\n");column+=yyleng;}
"String"            {if (state==1)printf("STRING\n");column+=yyleng;}
"static"            {if (state==1)printf("STATIC\n");column+=yyleng;}
"return"            {if (state==1)printf("RETURN\n");column+=yyleng;}
"public"            {if (state==1)printf("PUBLIC\n");column+=yyleng;}
"Integer.parseInt"  {if (state==1)printf("PARSEINT\n");column+=yyleng;}
"System.out.print"  {if (state==1)printf("PRINT\n");column+=yyleng;}
"int"               {if (state==1)printf("INT\n");column+=yyleng;}
"if"                {if (state==1)printf("IF\n");column+=yyleng;}
"else"              {if (state==1)printf("ELSE\n");column+=yyleng;}
"double"            {if (state==1)printf("DOUBLE\n");column+=yyleng;}
".length"           {if (state==1)printf("DOTLENGTH\n");column+=yyleng;}
"class"             {if (state==1)printf("CLASS\n");column+=yyleng;}
"boolean"           {if (state==1)printf("BOOL\n");column+=yyleng;}
"^"                 {if (state==1)printf("XOR\n");column+=yyleng;}
">>"                {if (state==1)printf("RSHIFT\n");column+=yyleng;}
"<<"                {if (state==1)printf("LSHIFT\n");column+=yyleng;}
"->"                {if (state==1)printf("ARROW\n");column+=yyleng;}
";"                 {if (state==1)printf("SEMICOLON\n");column+=yyleng;}
"]"                 {if (state==1)printf("RSQ\n");column+=yyleng;}
")"                 {if (state==1)printf("RPAR\n");column+=yyleng;}
"}"                 {if (state==1)printf("RBRACE\n");column+=yyleng;}
"+"                 {if (state==1)printf("PLUS\n");column+=yyleng;}
"||"                {if (state==1)printf("OR\n");column+=yyleng;}
"!"                 {if (state==1)printf("NOT\n");column+=yyleng;}
"!="                {if (state==1)printf("NE\n");column+=yyleng;}
"%"                 {if (state==1)printf("MOD\n");column+=yyleng;}
"-"                 {if (state==1)printf("MINUS\n");column+=yyleng;}
"<"                 {if (state==1)printf("LT\n");column+=yyleng;}
"["                 {if (state==1)printf("LSQ\n");column+=yyleng;}
"("                 {if (state==1)printf("LPAR\n");column+=yyleng;}
"<="                {if (state==1)printf("LE\n");column+=yyleng;}
"{"                 {if (state==1)printf("LBRACE\n");column+=yyleng;}
">"                 {if (state==1)printf("GT\n");column+=yyleng;}
">="                {if (state==1)printf("GE\n");column+=yyleng;}
"=="                {if (state==1)printf("EQ\n");column+=yyleng;}
"/"                 {if (state==1)printf("DIV\n");column+=yyleng;}
","                 {if (state==1)printf("COMMA\n");column+=yyleng;}
"*"                 {if (state==1)printf("STAR\n");column+=yyleng;}
"="                 {if (state==1)printf("ASSIGN\n");column+=yyleng;}
"&&"                {if (state==1)printf("AND\n");column+=yyleng;}
"true"              {if (state==1)printf("BOOLLIT(true)\n");column+=yyleng;}
"false"             {if (state==1)printf("BOOLLIT(false)\n");column+=yyleng;}
{id}                {if (state==1)printf("ID(%s)\n",yytext);column+=yyleng;}

<STRING><<EOF>>	                {printf("Line %d, col %d: unterminated string literal\n",errol,erroc);yyterminate();}
\"                              {BEGIN(STRING);errors = 0;errol = nline;erroc = column;column+=yyleng;}
<STRING>\"                      {yytext[yyleng-1] = '\0'; if(errors == 0 && state == 1){printf("STRLIT(\"%s\")\n",yytext);} BEGIN INITIAL;column+=1;}
<STRING>\n|\r\n|\r              {printf("Line %d, col %d: unterminated string literal\n",errol,erroc);BEGIN 0;resetline();}
<STRING>\\[\\fnrt"]             {yymore();column+=2;}
<STRING>\\		                {printf("Line %d, col %d: invalid escape sequence (\\)\n",nline,column);errors = 1;column+=1;}
<STRING>\\[^\n\r]?		        {printf("Line %d, col %d: invalid escape sequence (\\%c)\n",nline,column,yytext[yyleng - 1]);errors = 1;column+=2;}
<STRING>.                       {yymore();column+=1;}

{STARTCOMMENT_1}				{BEGIN COMMENT_1;}
<COMMENT_1>{NEWLINE}				{BEGIN 0; resetline();}
<COMMENT_1>.					

<COMMENT><<EOF>>	    {printf("Line %d, col %d: unterminated comment\n",errol, erroc);yyterminate();} 
"/*"                   {BEGIN COMMENT;errol = nline;erroc = column;column+=yyleng;}
<COMMENT>"*/"           {BEGIN INITIAL;column+=yyleng;}
<COMMENT>{NEWLINE}             {resetline();}
<COMMENT>.                      {column+=yyleng;}

{IGNORE}            {column+=yyleng;}
{NEWLINE}		    {resetline();}



.					{printf("Line %d, col %d: illegal character (%s)\n",nline,column,yytext);column+=yyleng;}

%%
int main(int argc, char *argv[ ]){
    if(argc==2){
        char * str = "-l";
        if(strcmp(argv[1],str)==0){
            state=1;
        }
    }
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
