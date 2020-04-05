/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "strutcs.h"
#include "y.tab.h"

int yylex (void);
void yyerror(char *s);
int error_yacc=0;

program *programafinal;

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 62 "jucompiler.y" /* yacc.c:355  */

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

#line 248 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 265 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    85,    86,    87,    88,    90,    92,    93,
      95,    97,    98,   100,   101,   102,   104,   105,   107,   108,
     109,   111,   112,   114,   116,   117,   118,   120,   123,   125,
     126,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   142,   143,   145,   146,   148,   149,
     151,   152,   154,   156,   157,   159,   160,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTLIT", "REALLIT", "STRLIT", "ESTRING",
  "ID", "WHILE", "VOID", "STRING1", "STATIC", "RETURN", "PUBLIC",
  "PARSEINT", "PRINT", "ARROW", "RESERVED", "INT", "IF", "ELSE", "DOUBLE",
  "DOTLENGTH", "BOOL", "CLASS", "XOR", "RSHIFT", "LSHIFT", "SEMICOLON",
  "RSQ", "RPAR", "RBRACE", "LSQ", "LPAR", "LBRACE", "PLUS", "STAR",
  "MINUS", "DIV", "MOD", "LT", "GT", "EQ", "NE", "LE", "GE", "OR", "AND",
  "NOT", "COMMA", "ASSIGN", "TRUE", "FALSE", "LOWER_THAN_ELSE", "$accept",
  "Program", "ProgramAux", "MethodDecl", "FieldDecl", "FieldIdAux",
  "FieldCommaIdAux", "Type", "MethodHeader", "FormalParams",
  "FormalParamsAux", "MethodBody", "MethodBodyAux", "VarDecl", "VarIdAux",
  "VarCommaIdAux", "Statement", "StatementAux", "AuxExprComma", "AuxExpr",
  "MethodInvocation", "Assignment", "ParseArgs", "Expression", "Expr",
  "TextExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -50

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,     8,    18,     0,   -77,   -77,    28,    -5,    27,   -77,
     -77,   -77,   -77,   -77,    45,    35,   -77,   -77,   -77,    37,
      14,    16,    20,    29,   -77,   -77,    54,    54,    11,   -77,
     213,    38,    66,    49,    52,    83,    65,   -23,    64,    82,
      67,    76,    79,   -77,   -77,   -77,   106,   -77,   -77,    90,
      92,    93,    94,   -77,   -77,   -77,   -77,   -77,    10,   158,
     158,   -77,   -77,   -13,   -77,    32,   178,   178,   178,   -77,
     -77,   -77,   -77,   -77,    99,   242,   -77,    15,   153,   158,
      80,   -77,   100,   -77,   -77,   -77,   115,    86,   101,   102,
     -77,   -77,   129,   -77,   133,   134,    -1,    -8,    -8,   -77,
     -77,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   136,    97,   139,
     140,   141,   -77,   -77,    87,   -77,   -77,    53,   -77,   -77,
     119,   238,   -77,   -77,   287,   138,   138,    -8,   -77,    -8,
     -77,   -77,   345,   345,   329,   329,   345,   345,   265,   309,
     -77,   158,   150,   151,   238,   173,   176,   158,   -77,   155,
     -77,   -77,   167,   -77,   -77,   -77,   159,   238,   -77,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     0,     0,     0,     5,
       2,     3,     4,     9,     0,     0,    14,    15,    13,     0,
       0,     0,    12,     0,    26,     7,    20,    20,    10,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    23,    45,     0,    25,    24,     0,
       0,     0,     0,    22,    17,    16,    11,    43,     0,     0,
       0,    82,    85,    81,    36,     0,     0,     0,     0,    83,
      84,    78,    56,    79,     0,    55,    57,     0,     0,     0,
       0,    30,     0,    38,    39,    40,     0,    18,     0,     0,
      47,    52,     0,    80,     0,     0,    81,    74,    75,    76,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    44,    28,    27,    19,     0,    51,    50,
      48,     0,    86,    77,    71,    73,    72,    66,    68,    67,
      69,    70,    60,    61,    62,    63,    64,    65,    58,    59,
      54,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      42,    41,    32,    29,    21,    46,     0,     0,    53,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -11,   -77,   169,
     -77,   -77,   -77,   -77,   -77,   -77,   -76,   -77,   -77,   -77,
     -30,   -29,   -28,   -53,    39,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    11,    12,    23,    28,    32,    20,    33,
      87,    25,    30,    47,    82,   124,    48,    80,   130,    89,
      71,    72,    73,    74,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    51,    19,   123,    90,    91,    92,     1,    93,
      58,    88,    95,    61,    62,     3,   117,    63,     4,    46,
      58,    93,   118,    13,    40,   120,   121,    59,   105,     7,
     107,   108,    58,    94,     5,    61,    62,    59,    14,    63,
     -49,     8,    21,    65,    22,    66,    40,    67,    24,    26,
      49,    50,    51,    27,    15,   158,     9,    29,    68,    10,
      35,    69,    70,    16,    31,    65,    17,    66,    18,    67,
      52,    16,    16,    53,    17,    17,    18,    18,   162,    54,
      68,    36,    55,    69,    70,    61,    62,    37,    38,    63,
      56,   169,    39,    57,    40,    41,    40,    60,   159,    42,
      77,    49,    50,    51,   165,    97,    98,    99,    43,    78,
      64,   122,    79,    81,    45,    65,   156,    66,    83,    67,
      84,    85,   126,    86,    49,    50,    51,   100,   125,   151,
      68,   128,   129,    69,    70,   127,   155,    49,    50,    51,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    61,    62,   119,   131,
      63,    61,    62,   132,   133,    63,   150,    40,   157,   152,
     153,   154,    40,   104,   105,   106,   107,   108,   160,   161,
     163,    61,    62,   164,   166,    96,    65,   167,    66,   168,
      67,    65,    40,    66,     0,    67,    34,     0,     0,     0,
       0,    68,     0,     0,    69,    70,    68,     0,     0,    69,
      70,    65,     0,    66,    36,    67,     0,     0,     0,     0,
      37,    38,     0,     0,     0,    39,    68,    40,    41,    69,
      70,    16,    42,     0,    17,     0,    18,     0,     0,    36,
       0,    43,     0,     0,    44,    37,    38,    45,     0,     0,
      39,     0,    40,    41,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    43,   101,   102,   103,
       0,     0,    45,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   116,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,   116,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   102,   103,   113,   114,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
      30,    30,    30,    14,    80,    58,    59,    60,    24,    22,
      33,     1,    65,     3,     4,     7,     1,     7,     0,    30,
      33,    22,     7,    28,    14,    78,    79,    50,    36,     1,
      38,    39,    33,     1,    34,     3,     4,    50,    11,     7,
      30,    13,     7,    33,     7,    35,    14,    37,    34,    33,
      80,    80,    80,    33,     9,   131,    28,    28,    48,    31,
      49,    51,    52,    18,    10,    33,    21,    35,    23,    37,
      32,    18,    18,     7,    21,    21,    23,    23,   154,    30,
      48,     1,    30,    51,    52,     3,     4,     7,     8,     7,
       7,   167,    12,    28,    14,    15,    14,    33,   151,    19,
      33,   131,   131,   131,   157,    66,    67,    68,    28,    33,
      28,    31,    33,     7,    34,    33,   127,    35,    28,    37,
      28,    28,     7,    29,   154,   154,   154,    28,    28,    32,
      48,    30,    30,    51,    52,    49,    49,   167,   167,   167,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     3,     4,     5,    30,
       7,     3,     4,    30,    30,     7,    30,    14,    49,    30,
      30,    30,    14,    35,    36,    37,    38,    39,    28,    28,
       7,     3,     4,     7,    29,     7,    33,    20,    35,    30,
      37,    33,    14,    35,    -1,    37,    27,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    48,    -1,    -1,    51,
      52,    33,    -1,    35,     1,    37,    -1,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    12,    48,    14,    15,    51,
      52,    18,    19,    -1,    21,    -1,    23,    -1,    -1,     1,
      -1,    28,    -1,    -1,    31,     7,     8,    34,    -1,    -1,
      12,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    25,    26,    27,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    26,    27,    44,    45,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    55,     7,     0,    34,    56,     1,    13,    28,
      31,    57,    58,    28,    11,     9,    18,    21,    23,    61,
      62,     7,     7,    59,    34,    65,    33,    33,    60,    28,
      66,    10,    61,    63,    63,    49,     1,     7,     8,    12,
      14,    15,    19,    28,    31,    34,    61,    67,    70,    74,
      75,    76,    32,     7,    30,    30,     7,    28,    33,    50,
      33,     3,     4,     7,    28,    33,    35,    37,    48,    51,
      52,    74,    75,    76,    77,    78,    79,    33,    33,    33,
      71,     7,    68,    28,    28,    28,    29,    64,     1,    73,
      77,    77,    77,    22,     1,    77,     7,    78,    78,    78,
      28,    25,    26,    27,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     1,     7,     5,
      77,    77,    31,    70,    69,    28,     7,    49,    30,    30,
      72,    30,    30,    30,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      30,    32,    30,    30,    30,    49,    61,    49,    70,    77,
      28,    28,    70,     7,     7,    77,    29,    20,    30,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    65,    66,    66,    66,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     5,     2,
       2,     3,     0,     1,     1,     1,     5,     5,     3,     4,
       0,     4,     0,     3,     2,     2,     0,     3,     2,     3,
       0,     3,     5,     7,     5,     3,     2,     1,     2,     2,
       2,     5,     5,     2,     2,     0,     3,     0,     2,     0,
       4,     4,     3,     7,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 83 "jucompiler.y" /* yacc.c:1646  */
    { (yyval.programVar) = programafinal = insertProgram((yyvsp[-3].id),(yyvsp[-1].declarationsVar));}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.declarationsVar) = insertDeclarationList((yyvsp[-1].declarationsVar),(yyvsp[0].methodDecVar),NULL,0);}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.declarationsVar) = insertDeclarationList((yyvsp[-1].declarationsVar),NULL,(yyvsp[0].fieldDecVar),0);}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.declarationsVar) = insertDeclarationList((yyvsp[-1].declarationsVar),NULL,NULL,1);}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.declarationsVar) = NULL;}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodDecVar) = insertMethodDec((yyvsp[0].methodBodyVar),(yyvsp[-1].methodHeaderVar));}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.fieldDecVar) = insertFieldDec((yyvsp[-2].id),(yyvsp[-1].listFieldDecVar));}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "jucompiler.y" /* yacc.c:1646  */
    {error_yacc = 1;(yyval.fieldDecVar) = NULL;}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listFieldDecVar) = insertListFieldDec((yyvsp[0].listFieldDecVar),(yyvsp[-1].id));}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 97 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listFieldDecVar) = insertListFieldDec((yyvsp[-2].listFieldDecVar),(yyvsp[0].id));}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listFieldDecVar) = NULL;}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id) = "Bool";}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id) = "Int";}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id) = "Double";}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodHeaderVar) = insertMethodHeader((yyvsp[-4].id),(yyvsp[-3].id),(yyvsp[-1].paramsVar));}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodHeaderVar) = insertMethodHeader("Void",(yyvsp[-3].id),(yyvsp[-1].paramsVar));}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 107 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.paramsVar) = insertParams((yyvsp[0].paramsVar),(yyvsp[-1].id),(yyvsp[-2].id));}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.paramsVar) = insertParams(NULL,(yyvsp[0].id),"StringArray");}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.paramsVar) = NULL;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.paramsVar) = insertParams((yyvsp[-3].paramsVar),(yyvsp[0].id),(yyvsp[-1].id));}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 112 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.paramsVar) = NULL;}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodBodyVar) = (yyvsp[-1].methodBodyVar);}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 116 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodBodyVar) = insertMethodBody((yyvsp[-1].methodBodyVar),NULL,(yyvsp[0].statementVar));}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 117 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodBodyVar) = insertMethodBody((yyvsp[-1].methodBodyVar),(yyvsp[0].varDecVar),NULL);}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodBodyVar) = NULL;}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 120 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.varDecVar) = insertVarDec((yyvsp[-2].id),(yyvsp[-1].listVarDecVar));}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listVarDecVar) = insertListVarDec((yyvsp[0].listVarDecVar),(yyvsp[-1].id));}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 125 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listVarDecVar) = insertListVarDec((yyvsp[-2].listVarDecVar),(yyvsp[0].id));}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 126 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listVarDecVar) = NULL;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "jucompiler.y" /* yacc.c:1646  */
    { (yyval.statementVar) = insertListStatement((yyvsp[-1].listStatementVar));}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertIfElse((yyvsp[-2].expressionVar),(yyvsp[0].statementVar),NULL);}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertIfElse((yyvsp[-4].expressionVar),(yyvsp[-2].statementVar),(yyvsp[0].statementVar));}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertWhile((yyvsp[-2].expressionVar),(yyvsp[0].statementVar));}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertReturn((yyvsp[-1].expressionVar));}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertReturn(NULL);}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = NULL;}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 135 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertMethodInvocationStatement((yyvsp[-1].methodInvocationVar));}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 136 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertAssignStatement((yyvsp[-1].assignmentVar));}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 137 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertParseArgsStatement((yyvsp[-1].parseArgsVar));}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 138 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertPrint((yyvsp[-2].expressionVar),NULL);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 139 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.statementVar) = insertPrint(NULL,(yyvsp[-2].id));}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 140 "jucompiler.y" /* yacc.c:1646  */
    {error_yacc = 1;(yyval.statementVar) = NULL;}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 142 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listStatementVar) = insertMultipleStatement((yyvsp[-1].listStatementVar),(yyvsp[0].statementVar));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listStatementVar) = NULL;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 145 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listExpressionVar) = insertListExpression((yyvsp[-2].listExpressionVar), (yyvsp[0].expressionVar));}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 146 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listExpressionVar) = NULL;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 148 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listExpressionVar) = insertListExpression((yyvsp[0].listExpressionVar), (yyvsp[-1].expressionVar));}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.listExpressionVar) = NULL;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.methodInvocationVar) = insertMethodInvocation((yyvsp[-3].id), (yyvsp[-1].listExpressionVar));}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 152 "jucompiler.y" /* yacc.c:1646  */
    {error_yacc = 1; (yyval.methodInvocationVar) = NULL;}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.assignmentVar) = insertAssign((yyvsp[-2].id), (yyvsp[0].expressionVar));}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 156 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.parseArgsVar) = insertParseArgs((yyvsp[-4].id), (yyvsp[-2].expressionVar));}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 157 "jucompiler.y" /* yacc.c:1646  */
    {error_yacc = 1; (yyval.parseArgsVar) = NULL;}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 159 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = (yyvsp[0].expressionVar);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 160 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertAssignment((yyvsp[0].assignmentVar));}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 162 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = (yyvsp[0].expressionVar);}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 163 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Or", (yyvsp[0].expressionVar));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 164 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "And", (yyvsp[0].expressionVar));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 165 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Lt", (yyvsp[0].expressionVar));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 166 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Gt", (yyvsp[0].expressionVar));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 167 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Eq", (yyvsp[0].expressionVar));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 168 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Ne", (yyvsp[0].expressionVar));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 169 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Le", (yyvsp[0].expressionVar));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 170 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Ge", (yyvsp[0].expressionVar));}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 171 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Plus", (yyvsp[0].expressionVar));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 172 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Minus", (yyvsp[0].expressionVar));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 173 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Star", (yyvsp[0].expressionVar));}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 174 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Div", (yyvsp[0].expressionVar));}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 175 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Mod", (yyvsp[0].expressionVar));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 176 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Xor", (yyvsp[0].expressionVar));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 177 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Lshift", (yyvsp[0].expressionVar));}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 178 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertOperator((yyvsp[-2].expressionVar), "Rshift", (yyvsp[0].expressionVar));}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 179 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertUnitary("Plus", (yyvsp[0].expressionVar));}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 180 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertUnitary("Minus", (yyvsp[0].expressionVar));}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 181 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertUnitary("Not", (yyvsp[0].expressionVar));}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 184 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertMultipleExpression((yyvsp[-1].expressionVar));}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 185 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression((yyvsp[0].methodInvocationVar), NULL, 0, NULL, NULL, NULL, NULL);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 186 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, (yyvsp[0].parseArgsVar), 0, NULL, NULL, NULL, NULL);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 187 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 1, (yyvsp[-1].id), NULL, NULL, NULL);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 188 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 0, (yyvsp[0].id), NULL, NULL, NULL);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 189 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 0, NULL, (yyvsp[0].id), NULL, NULL);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 190 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 0, NULL, NULL, "True", NULL);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 191 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 0, NULL, NULL, "False", NULL);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 192 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.expressionVar) = insertExpression(NULL, NULL, 0, NULL, NULL, NULL, (yyvsp[0].id));}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 193 "jucompiler.y" /* yacc.c:1646  */
    {error_yacc = 1; (yyval.expressionVar) = NULL;}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2011 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 195 "jucompiler.y" /* yacc.c:1906  */



