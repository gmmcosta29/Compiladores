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
    ESTRING = 261,
    ID = 262,
    WHILE = 263,
    VOID = 264,
    STRING1 = 265,
    STATIC = 266,
    RETURN = 267,
    PUBLIC = 268,
    PARSEINT = 269,
    PRINT = 270,
    ARROW = 271,
    RESERVED = 272,
    INT = 273,
    IF = 274,
    ELSE = 275,
    DOUBLE = 276,
    DOTLENGTH = 277,
    BOOL = 278,
    CLASS = 279,
    XOR = 280,
    RSHIFT = 281,
    LSHIFT = 282,
    SEMICOLON = 283,
    RSQ = 284,
    RPAR = 285,
    RBRACE = 286,
    LSQ = 287,
    LPAR = 288,
    LBRACE = 289,
    PLUS = 290,
    STAR = 291,
    MINUS = 292,
    DIV = 293,
    MOD = 294,
    LT = 295,
    GT = 296,
    EQ = 297,
    NE = 298,
    LE = 299,
    GE = 300,
    OR = 301,
    AND = 302,
    NOT = 303,
    COMMA = 304,
    ASSIGN = 305,
    TRUE = 306,
    FALSE = 307,
    LOWER_THAN_ELSE = 308
  };
#endif
/* Tokens.  */
#define INTLIT 258
#define REALLIT 259
#define STRLIT 260
#define ESTRING 261
#define ID 262
#define WHILE 263
#define VOID 264
#define STRING1 265
#define STATIC 266
#define RETURN 267
#define PUBLIC 268
#define PARSEINT 269
#define PRINT 270
#define ARROW 271
#define RESERVED 272
#define INT 273
#define IF 274
#define ELSE 275
#define DOUBLE 276
#define DOTLENGTH 277
#define BOOL 278
#define CLASS 279
#define XOR 280
#define RSHIFT 281
#define LSHIFT 282
#define SEMICOLON 283
#define RSQ 284
#define RPAR 285
#define RBRACE 286
#define LSQ 287
#define LPAR 288
#define LBRACE 289
#define PLUS 290
#define STAR 291
#define MINUS 292
#define DIV 293
#define MOD 294
#define LT 295
#define GT 296
#define EQ 297
#define NE 298
#define LE 299
#define GE 300
#define OR 301
#define AND 302
#define NOT 303
#define COMMA 304
#define ASSIGN 305
#define TRUE 306
#define FALSE 307
#define LOWER_THAN_ELSE 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "jucompiler.y" /* yacc.c:1909  */

    char *id;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
