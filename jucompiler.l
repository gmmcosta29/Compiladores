%{
#include <stdio.h>
#include <stdlib.h>
    int nline = 1;
    int column = 1;
    int errors = 0;
    int state = 0;

    char buffer[128] = "";
    char *s;


  void resetline(){
  	nline++;
	column=1;
}
void updatecol(int n){
    column +=n;
}  
    
%}

SEQESCAPE	\\n|\\\\|\\t|\\f|\\r|\\\"
INVALIDESCAPE	(\\[^n|t|f|r|\\|"""])
STARTCOMMENT_1	(\/)(\/)
INITSTRING            \"
numero				([0-9|_]+)
numeroall           [0-9|_]*
semzero             [1-9]+
expoente           ([Ee]?[+-]?)
escape              [A-z][^n][^r][^f][^t]
id                  [A-Za-z_$][A-Za-z_$0-9]*
reserved            "++"|"--"|"null"|"System"|"Integer"|"abstract"|"continue"|"for"|"new"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"implements"|"protected"|"import"|"enum"|"instanceof"|"extends"|"short"|"final"|"interface"|"finally"|"long"|"strictfp"|"float"|"native"|"super"|"switch"|"throw"|"throws"|"assert"|"this"|"break"|"byte"|"case"|"transient"|"catch"|"try"|"char"|"volatile"|"const"|"_"
IGNORE		\ |\\t


%X STRING COMMENT COMMENT_1
%%

"0"                                                                         {if (state==1)printf("INTLIT(0)\n");column+=yyleng;}
{semzero}{numeroall}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;}

{numero}"."                                                                 {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}{semzero}{numeroall}                          {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}{numeroall}            {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}{semzero}{numeroall}                               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}{semzero}{numeroall}"."{numero}               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}"0"?"."{numero}                               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}                                                             {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}{semzero}{numeroall}"."{numero} {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}{semzero}{numeroall}"."{numero}                    {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}"0"?"."{numero}                 {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}"0"?"."{numero}                                    {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}




"/*"                BEGIN COMMENT;
<COMMENT>[^*\n]*        resetline();
<COMMENT>"*/"           BEGIN INITIAL;          //Finaliza o comentario
<COMMENT>"*"            //ignora
<COMMENT><<EOF>>				        {printf("Line %d, column %d: unterminated comment\n",nline, column);BEGIN 0;}

{STARTCOMMENT_1}				{BEGIN COMMENT_1;}
<COMMENT_1>.					
<COMMENT_1>(\n)					{BEGIN 0; resetline();}

{INITSTRING}                    {BEGIN STRING;s = buffer;errors = 0;}
<STRING>([^\n\"])			        {*s ++= *yytext; column+=yyleng;}
<STRING>{INVALIDESCAPE}         {errors = 1;printf("Line %d, col %d: invalid escape sequence (%s)\n",nline,column,yytext);column+=yyleng;}
<STRING>{INITSTRING}            {BEGIN 0;*s = 0;if(errors == 0)printf("STRLIT(\"%s\")\n",buffer);}
<STRING>\n                    {BEGIN 0;printf("Line %d,col %d:unterminated string literal\n",nline,column);resetline();}


"while"             {if (state==1)printf("WHILE\n");}
"void"              {if (state==1)printf("VOID\n");}
"String"            {if (state==1)printf("STRING\n");}
"static"            {if (state==1)printf("STATIC\n");}
"return"            {if (state==1)printf("RETURN\n");}
"public"            {if (state==1)printf("PUBLIC\n");}
"Integer.parseInt"  {if (state==1)printf("PARSEINT\n");}
"System.out.print"  {if (state==1)printf("PRINT\n");}
"int"               {if (state==1)printf("INT\n");}
"if"                {if (state==1)printf("IF\n");}
"else"              {if (state==1)printf("ELSE\n");}
"double"            {if (state==1)printf("DOUBLE\n");}
".length"           {if (state==1)printf("DOTLENGTH\n");}
"class"             {if (state==1)printf("CLASS\n");}
"boolean"           {if (state==1)printf("BOOL\n");}
"^"                 {if (state==1)printf("XOR\n");}
">>"                {if (state==1)printf("RSHIFT\n");}
"<<"                {if (state==1)printf("LSHIFT\n");}
"->"                {if (state==1)printf("ARROW\n");}
";"                 {if (state==1)printf("SEMICOLON\n");}
"]"                 {if (state==1)printf("RSQ\n");}
")"                 {if (state==1)printf("RPAR\n");}
"}"                 {if (state==1)printf("RBRACE\n");}
"+"                 {if (state==1)printf("PLUS\n");}
"||"                {if (state==1)printf("OR\n");}
"!"                 {if (state==1)printf("NOT\n");}
"!="                {if (state==1)printf("NE\n");}
"%"                 {if (state==1)printf("MOD\n");}
"-"                 {if (state==1)printf("MINUS\n");}
"<"                 {if (state==1)printf("LT\n");}
"["                 {if (state==1)printf("LSQ\n");}
"("                 {if (state==1)printf("LPAR\n");}
"<="                {if (state==1)printf("LE\n");}
"{"                 {if (state==1)printf("LBRACE\n");}
">"                 {if (state==1)printf("GT\n");}
">="                {if (state==1)printf("GE\n");}
"=="                {if (state==1)printf("EQ\n");}
"/"                 {if (state==1)printf("DIV\n");}
","                 {if (state==1)printf("COMMA\n");}
"*"                 {if (state==1)printf("STAR\n");}
"="                 {if (state==1)printf("ASSIGN\n");}
"&&"                {if (state==1)printf("AND\n");}
"true"              {if (state==1)printf("BOOLLIT\n");}
"false"             {if (state==1)printf("BOOLLIT\n");}
{reserved}          {if (state==1)printf("RESERVED\n");}
{id}                {if (state==1)printf("ID(%s)\n",yytext);}

{IGNORE}            {updatecol(yyleng);}
\n						{resetline();}
.					{printf("Line %d, column %d: illegal character (%s)\n",nline,column,yytext);updatecol(yyleng);}

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
