%{
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "strutcs.h"
#include "y.tab.h"
    /*      Francisco Forte Nº2016225674
            Guilherme Costa Nº2017249276
    */

    extern int error_yacc;
    int nline = 1;
    int column = 1;
    int errors = 0;
    int state = 0;
    int parseState = 0;
    int errol = 1;
    int erroc = 1;
    extern program* programafinal;
  void resetline(){
  	nline++;
	column=1;
}

    
%}
NEWLINE             \r|\n|\r\n
STARTCOMMENT_1	    "//"
NUMEROZERO          ([1-9]([0-9_]*[0-9])?)|0   
NUMERO                 [0-9]([0-9_]*[0-9])?              
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
{reserved}          {if (state==1)printf("RESERVED(%s)\n",yytext);column+=yyleng;if(parseState==1) return RESERVED;}

"0"                                                                         {if (state==1)printf("INTLIT(0)\n");column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return INTLIT;}}
{semzero}{numeroall}{numerof}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return INTLIT;}}
{semzero}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return INTLIT;}}


{NUMERO}"."{NUMERO}?                      {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return REALLIT;}}
{NUMERO}?"."{NUMERO}                      {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return REALLIT;}}
{NUMERO}?"."{NUMERO}?{expoente}{NUMERO}                       {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return REALLIT;}}
{NUMERO}{expoente}{NUMERO}                       {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return REALLIT;}}

"while"             {if (state==1)printf("WHILE\n");column+=yyleng;if(parseState==1) return WHILE;}
"void"              {if (state==1)printf("VOID\n");column+=yyleng;if(parseState==1) return VOID;}
"String"            {if (state==1)printf("STRING\n");column+=yyleng;if(parseState==1) return STRING1;}
"static"            {if (state==1)printf("STATIC\n");column+=yyleng;if(parseState==1) return STATIC;}
"return"            {if (state==1)printf("RETURN\n");column+=yyleng;if(parseState==1) return RETURN;}
"public"            {if (state==1)printf("PUBLIC\n");column+=yyleng;if(parseState==1) return PUBLIC;}
"Integer.parseInt"  {if (state==1)printf("PARSEINT\n");column+=yyleng;if(parseState==1) return PARSEINT;}
"System.out.print"  {if (state==1)printf("PRINT\n");column+=yyleng;if(parseState==1) return PRINT;}
"int"               {if (state==1)printf("INT\n");column+=yyleng;if(parseState==1) return INT;}
"if"                {if (state==1)printf("IF\n");column+=yyleng;if(parseState==1) return IF;}
"else"              {if (state==1)printf("ELSE\n");column+=yyleng;if(parseState==1) return ELSE;}
"double"            {if (state==1)printf("DOUBLE\n");column+=yyleng;if(parseState==1) return DOUBLE;}
".length"           {if (state==1)printf("DOTLENGTH\n");column+=yyleng;if(parseState==1) return DOTLENGTH;}
"class"             {if (state==1)printf("CLASS\n");column+=yyleng;if(parseState==1) return CLASS;}
"boolean"           {if (state==1)printf("BOOL\n");column+=yyleng;if(parseState==1) return BOOL;}
"^"                 {if (state==1)printf("XOR\n");column+=yyleng;if(parseState==1) return XOR;}
">>"                {if (state==1)printf("RSHIFT\n");column+=yyleng;if(parseState==1) return RSHIFT;}
"<<"                {if (state==1)printf("LSHIFT\n");column+=yyleng;if(parseState==1) return LSHIFT;}
"->"                {if (state==1)printf("ARROW\n");column+=yyleng;if(parseState==1) return ARROW;}
";"                 {if (state==1)printf("SEMICOLON\n");column+=yyleng;if(parseState==1) return SEMICOLON;}
"]"                 {if (state==1)printf("RSQ\n");column+=yyleng;if(parseState==1) return RSQ;}
")"                 {if (state==1)printf("RPAR\n");column+=yyleng;if(parseState==1) return RPAR;}
"}"                 {if (state==1)printf("RBRACE\n");column+=yyleng;if(parseState==1) return RBRACE;}
"+"                 {if (state==1)printf("PLUS\n");column+=yyleng;if(parseState==1) return PLUS;}
"||"                {if (state==1)printf("OR\n");column+=yyleng;if(parseState==1) return OR;}
"!"                 {if (state==1)printf("NOT\n");column+=yyleng;if(parseState==1) return NOT;}
"!="                {if (state==1)printf("NE\n");column+=yyleng;if(parseState==1) return NE;}
"%"                 {if (state==1)printf("MOD\n");column+=yyleng;if(parseState==1) return MOD;}
"-"                 {if (state==1)printf("MINUS\n");column+=yyleng;if(parseState==1) return MINUS;}
"<"                 {if (state==1)printf("LT\n");column+=yyleng;if(parseState==1) return LT;}
"["                 {if (state==1)printf("LSQ\n");column+=yyleng;if(parseState==1) return LSQ;}
"("                 {if (state==1)printf("LPAR\n");column+=yyleng;if(parseState==1) return LPAR;}
"<="                {if (state==1)printf("LE\n");column+=yyleng;if(parseState==1) return LE;}
"{"                  {if (state==1)printf("LBRACE\n");column+=yyleng;if(parseState==1) return LBRACE;}
">"                 {if (state==1)printf("GT\n");column+=yyleng;if(parseState==1) return GT;}
">="                {if (state==1)printf("GE\n");column+=yyleng;if(parseState==1) return GE;}
"=="                {if (state==1)printf("EQ\n");column+=yyleng;if(parseState==1) return EQ;}
"/"                 {if (state==1)printf("DIV\n");column+=yyleng;if(parseState==1) return DIV;}
","                 {if (state==1)printf("COMMA\n");column+=yyleng;if(parseState==1) return COMMA;}
"*"                 {if (state==1)printf("STAR\n");column+=yyleng;if(parseState==1) return STAR;}
"="                 {if (state==1)printf("ASSIGN\n");column+=yyleng;if(parseState==1) return ASSIGN;}
"&&"                {if (state==1)printf("AND\n");column+=yyleng;if(parseState==1) return AND;}
"true"              {if (state==1)printf("BOOLLIT(true)\n");column+=yyleng;if(parseState==1) return TRUE;}
"false"             {if (state==1)printf("BOOLLIT(false)\n");column+=yyleng;if(parseState==1) return FALSE;}
{id}                {if (state==1)printf("ID(%s)\n",yytext);column+=yyleng;if(parseState==1){yylval.id=strdup(yytext); return ID;}}

<STRING><<EOF>>	                {if(parseState==1)column++;printf("Line %d, col %d: unterminated string literal\n",errol,erroc);yyterminate();}
\"                              {BEGIN(STRING);errors = 0;errol = nline;erroc = column;column+=yyleng;if(parseState==1)yymore();}
<STRING>\"                      {BEGIN 0; column+=1;if(errors == 0 && state == 1){printf("STRLIT(\"%s)\n",yytext);}if(parseState==1 && errors == 0){yylval.id=strdup(yytext);return STRLIT;}}
<STRING>\n|\r\n|\r              {printf("Line %d, col %d: unterminated string literal\n",errol,erroc);BEGIN 0;resetline();}
<STRING>\\[\\fnrt"]             {yymore();column+=2;}
<STRING>\\		                {printf("Line %d, col %d: invalid escape sequence (\\)\n",nline,column);errors = 1;column+=1;if(parseState==1)yymore();}
<STRING>\\[^\n\r]?		        {printf("Line %d, col %d: invalid escape sequence (\\%c)\n",nline,column,yytext[yyleng - 1]);errors = 1;column+=2;if(parseState==1)yymore();}
<STRING>.                       {yymore();column+=1;}

{STARTCOMMENT_1}				{BEGIN COMMENT_1;}
<COMMENT_1>{NEWLINE}				{BEGIN 0; resetline();}
<COMMENT_1>.					

<COMMENT><<EOF>>	    {if(parseState==1)column++;printf("Line %d, col %d: unterminated comment\n",errol, erroc);yyterminate();} 
"/*"                   {BEGIN COMMENT;errol = nline;erroc = column;column+=yyleng;}
<COMMENT>"*/"           {BEGIN INITIAL;column+=yyleng;}
<COMMENT>{NEWLINE}             {resetline();}
<COMMENT>.                      {column+=yyleng;}

{IGNORE}            {column+=yyleng;}
<<EOF>>             {column+=1;yyterminate();}
{NEWLINE}		    {resetline();}



.					{printf("Line %d, col %d: illegal character (%s)\n",nline,column,yytext);column+=yyleng;}

%%
void yyerror(char *msg) {
    printf("Line %d, col %d: %s: %s\n",nline,column-yyleng,msg, yytext);
}


int main(int argc, char *argv[ ]){
    if(argc==2){
        char *nStr = "-e1";
        char * str = "-l";
        char * parseStr = "-t";
        char * nParseStr = "-e2";
        if(strcmp(argv[1],str)==0){
			state=1;
			yylex();
			return 0;
        }
        else if(strcmp(argv[1],nStr)==0){
			state=0;
			yylex();
        }
        else if(strcmp(argv[1], parseStr)==0){
            parseState=1;
            if(yyparse() == 0) {
                if(error_yacc == 0){
                    printTree(programafinal);
                }
            }
        }
        else if(strcmp(argv[1], nParseStr)==0){
            parseState=1;
            yyparse();
        }
    }
    else{
        parseState=1;
        yyparse();
    }
    return 0;
}

int yywrap(){
    return 1;
}
