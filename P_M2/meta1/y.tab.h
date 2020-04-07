/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTLIT = 258,
    REALLIT = 259,
    STRLIT = 260,
    ID = 261,
    WHILE = 262,
    VOID = 263,
    STRING1 = 264,
    STATIC = 265,
    RETURN = 266,
    PUBLIC = 267,
    PARSEINT = 268,
    PRINT = 269,
    ARROW = 270,
    RESERVED = 271,
    INT = 272,
    IF = 273,
    ELSE = 274,
    DOUBLE = 275,
    DOTLENGTH = 276,
    BOOL = 277,
    CLASS = 278,
    XOR = 279,
    RSHIFT = 280,
    LSHIFT = 281,
    SEMICOLON = 282,
    RSQ = 283,
    RPAR = 284,
    RBRACE = 285,
    LSQ = 286,
    LPAR = 287,
    LBRACE = 288,
    PLUS = 289,
    STAR = 290,
    MINUS = 291,
    DIV = 292,
    MOD = 293,
    LT = 294,
    GT = 295,
    EQ = 296,
    NE = 297,
    LE = 298,
    GE = 299,
    OR = 300,
    AND = 301,
    NOT = 302,
    COMMA = 303,
    ASSIGN = 304,
    TRUE = 305,
    FALSE = 306,
    UNITARY = 307,
    LOWER_THAN_ELSE = 308
  };
#endif
/* Tokens.  */
#define INTLIT 258
#define REALLIT 259
#define STRLIT 260
#define ID 261
#define WHILE 262
#define VOID 263
#define STRING1 264
#define STATIC 265
#define RETURN 266
#define PUBLIC 267
#define PARSEINT 268
#define PRINT 269
#define ARROW 270
#define RESERVED 271
#define INT 272
#define IF 273
#define ELSE 274
#define DOUBLE 275
#define DOTLENGTH 276
#define BOOL 277
#define CLASS 278
#define XOR 279
#define RSHIFT 280
#define LSHIFT 281
#define SEMICOLON 282
#define RSQ 283
#define RPAR 284
#define RBRACE 285
#define LSQ 286
#define LPAR 287
#define LBRACE 288
#define PLUS 289
#define STAR 290
#define MINUS 291
#define DIV 292
#define MOD 293
#define LT 294
#define GT 295
#define EQ 296
#define NE 297
#define LE 298
#define GE 299
#define OR 300
#define AND 301
#define NOT 302
#define COMMA 303
#define ASSIGN 304
#define TRUE 305
#define FALSE 306
#define UNITARY 307
#define LOWER_THAN_ELSE 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 62 "jucompiler.y" /* yacc.c:1909  */

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

#line 181 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
