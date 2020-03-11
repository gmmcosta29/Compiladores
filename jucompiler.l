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

SEQESCAPE	\\n|\\\\|\\t|\\f|\\r|\\\"
INVALIDESCAPE	\\[^ntfr\"]
STARTCOMMENT_1	(\/)(\/)
INITSTRING            \"
UNDERSCORE          "_"
numero				([0-9|_]+)
numeroall           [0-9|_]*
numerof             [0-9]+
semzero             [1-9]+
expoente           ([Ee]?[+-]?)
escape              [A-z][^n][^r][^f][^t]
id                  [A-Za-z_$][A-Za-z_$0-9]*
reserved            "++"|"--"|"null"|"System"|"Integer"|"abstract"|"continue"|"for"|"new"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"implements"|"protected"|"import"|"enum"|"instanceof"|"extends"|"short"|"final"|"interface"|"finally"|"long"|"strictfp"|"float"|"native"|"super"|"switch"|"throw"|"throws"|"assert"|"this"|"break"|"byte"|"case"|"transient"|"catch"|"try"|"char"|"volatile"|"const"
IGNORE		[" "|"\t"|"\v"|"\f"|"\r"]


%X STRING COMMENT COMMENT_1
%%
{reserved}          {if (state==1)printf("RESERVED(%s)\n",yytext);column+=yyleng;}

"0"                                                                         {if (state==1)printf("INTLIT(0)\n");column+=yyleng;}
{semzero}{numeroall}{numerof}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;}
{semzero}                                                        {if (state==1)printf("INTLIT(%s)\n",yytext);column+=yyleng;}


{numero}"."                                                                 {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}{semzero}{numeroall}{numerof}                          {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}{semzero}                          {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}{numeroall}{numerof}            {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}{semzero}{numeroall}{numerof}                               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}{semzero}{numeroall}"."{numero}{numerof}               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}{expoente}"0"?"."{numero}{numerof}                               {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{numerof}                                                             {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numerof}                                                             {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}{semzero}{numeroall}"."{numero}{numerof} {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}{semzero}{numeroall}"."{numero}{numerof}                    {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
{semzero}{numeroall}"."{numeroall}{expoente}"0"?"."{numero}{numerof}                 {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}
"0"?"."{numero}{expoente}"0"?"."{numero}{numerof}                                    {if (state==1)printf("REALLIT(%s)\n",yytext);column+=yyleng;}



{STARTCOMMENT_1}				{BEGIN COMMENT_1;}
<COMMENT_1>.					
<COMMENT_1>\n?				{BEGIN 0; resetline();}


"/*"                 BEGIN COMMENT;errol = nline;erroc = column;column+=yyleng;
<COMMENT>"*/"           BEGIN INITIAL;column+=yyleng;          //Finaliza o comentario
<COMMENT><<EOF>>	    {BEGIN 0;printf("Line %d, col %d: unterminated comment\n",errol, erroc);}
<COMMENT>.              column+=yyleng;
<COMMENT>\n           resetline();


\"                              BEGIN(STRING);errors = 0;errol = nline;erroc = column;column+=yyleng;
<STRING>[^\\\n"]*               yymore();
<STRING>{INVALIDESCAPE}			{yymore();printf("Line %d, column %d: invalid escape sequence (\\%c)\n",nline,column,yytext[yyleng-1]);}
<STRING>\n                      printf("Unterminated string."); BEGIN(INITIAL);
<STRING>{SEQESCAPE}             yymore();column+=yyleng;
<STRING>\"                      {yytext[yyleng-1] = '\0'; printf("STRLIT(\"%s\")\n",yytext); BEGIN(INITIAL);column+=yyleng;}


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

{IGNORE}            {column+=yyleng;}
\n				    {resetline();}
.					{printf("Line %d, column %d: illegal character (%s)\n",nline,column,yytext);column+=yyleng;}

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
