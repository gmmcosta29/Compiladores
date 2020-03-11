%{
#include <stdio.h>
#include <stdlib.h>
    int nline = 1;
    int column = 1;

    char buffer[128];
    char *s;


  void resetline(){
  	nline++;
	column=1;
}
void updatecol(int n){
    column +=n;
}  
    
%}

SEQESCAPE	(\\n|\\\\|\\t|\\f|\\r)
INVALIDESCAPE	\\[^ntfr\"]
STARTCOMMENT_1	(\/)(\/)
INITSTRING            \"
numero				([0-9 | _]+)
numeroall           [0-9 |_]*
semzero             [1-9]+
expoente           ([Ee]?[+-]?)
escape              [A-z][^n][^r][^f][^t]
id                  [A-Za-z_$][A-Za-z_$0-9]*
reserved            "++"|"--"|"null"|"System"|"Integer"|"abstract"|"continue"|"for"|"new"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"implements"|"protected"|"import"|"enum"|"instanceof"|"extends"|"short"|"final"|"interface"|"finally"|"long"|"strictfp"|"float"|"native"|"super"|"switch"|"throw"|"throws"|"assert"|"this"|"break"|"byte"|"case"|"transient"|"catch"|"try"|"char"|"volatile"|"const"|"_"
IGNORE		\ |\t


%X STRING COMMENT COMMENT_1
%%
{numero}"."                                                                 {printf("REALLIT(%s)\n",yytext);}

{semzero}{numeroall}{expoente}{semzero}{numeroall}                          {printf("REALLIT(%s)\n",yytext);}
{semzero}{numeroall}"."{numeroall}{expoente}{numeroall}            {printf("REALLIT(%s)\n",yytext);}
"0"?"."{numero}{expoente}{semzero}{numeroall}                               {printf("REALLIT(%s)\n",yytext);}
{semzero}{numeroall}{expoente}{semzero}{numeroall}"."{numero}               {printf("REALLIT(%s)\n",yytext);}
{semzero}{numeroall}{expoente}"0"?"."{numero}                               {printf("REALLIT(%s)\n",yytext);}
"0"?"."{numero}                                                             {printf("REALLIT(%s)\n",yytext);}
{semzero}{numeroall}"."{numeroall}{expoente}{semzero}{numeroall}"."{numero} {printf("REALLIT(%s)\n",yytext);}
"0"?"."{numero}{expoente}{semzero}{numeroall}"."{numero}                    {printf("REALLIT(%s)\n",yytext);}
{semzero}{numeroall}"."{numeroall}{expoente}"0"?"."{numero}                 {printf("REALLIT(%s)\n",yytext);}
"0"?"."{numero}{expoente}"0"?"."{numero}                                    {printf("REALLIT(%s)\n",yytext);}

"0"                                                                         {printf("INTLIT(0)\n");}
{semzero}{numeroall}                                                        {printf("INTLIT(%s)\n",yytext);}


"/*"                BEGIN COMMENT;
<COMMENT>[^*\n]*        nline++;
<COMMENT>"*/"           BEGIN INITIAL;          //Finaliza o comentario
<COMMENT>"*"            //ignora
<COMMENT><<EOF>>				        {printf("Line %d, column %d: unterminated comment\n",nline, column);BEGIN 0;}

{STARTCOMMENT_1}				{BEGIN COMMENT_1;}
<COMMENT_1>.					
<COMMENT_1>(\n)					{BEGIN 0; resetline();}

{INITSTRING}                    {BEGIN STRING;s = buffer;}
<STRING>[^\n\"]			    {*s ++ = *yytext; column+=yyleng;}
<STRING>{INITSTRING}            {BEGIN 0;*s = 0;printf("STRLIT(\"%s\")\n",buffer);}
<STRING>\n                    {BEGIN 0;printf("Line %d,col %d:unterminated string literal\n",nline,column);}
<STRING>{INVALIDESCAPE}         {*s = 0;printf("Line %d, col %d: invalid escape sequence (%s)\n",nline,column,yytext);}


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

{IGNORE}            {updatecol(yyleng);}
\n						{resetline();}
.					{printf("Line %d, column %d: illegal character (%s)\n",nline,column,yytext);updatecol(yyleng);}

%%
int main(int argc, char *argv[ ]){
    if(argc==2){
        char * str = "-l";
        if(strcmp(argv[1],str)==0){
            //state=1;
        }
    }
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
