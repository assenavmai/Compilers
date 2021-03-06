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
#line 8 "cm.y" /* yacc.c:339  */

    #define YYPARSER

    #include "globals.h"
    #include "util.h"
    #include "scan.h"
    #include "parse.h"
    #include "symlist.h"

    #define YYSTYPE tokenTypes

    extern FILE * yyin;
    static struct TreeNode * syntaxTree; /* save the syntax tree to be returned */
    static char * savedName; /* for use in assignments */
    static int savedLineNo;  /* ditto */
    static int lineFunc;
    struct symhash * checkOne, *checkTwo;
    static int invalidVoid = -1;
    static int returnValue = -1;
    static int varLoc = 0;
    static int amountParam = 0;
    static int amountArgs = 0;

    struct symlist * tempHead;
    enum StmtKind stmtCheck = -1;
    int inScope = -1;

    static int ofpLocation = 0;
    static int initLocation = -2;
    static int declOffset = 0;

    extern yychar;

    typedef union tokenTypes
    {
        struct TreeNode * tnode;
        enum ExpType type;
        char * str;
        int op;
    }tokenTypes;


    void yyerror()
    {
           //fprintf(stderr,"line %d: error: \t",lineno);
            fprintf(stderr, "\nline %d: syntax error at: current token: \t%s\n", lineno, currLine);
            //printToken(yychar, tokenString);

    }

    int yywrap()
    {
            return 1;
    } 

   static int yylex(void)
    { return getToken(); }

    struct TreeNode * parse(void) { 

        yyparse();
        return syntaxTree;
    }



#line 133 "y.tab.c" /* yacc.c:339  */

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
    IF = 258,
    ELSE = 259,
    INT = 260,
    RETURN = 261,
    VOID = 262,
    WHILE = 263,
    ID = 264,
    NUM = 265,
    PLUS = 266,
    MINUS = 267,
    MULT = 268,
    DIV = 269,
    LT = 270,
    GT = 271,
    LTEQ = 272,
    GTEQ = 273,
    DOUBEQ = 274,
    NEQ = 275,
    EQ = 276,
    SEMI = 277,
    COMMA = 278,
    LPAREN = 279,
    RPAREN = 280,
    LBRAC = 281,
    RBRAC = 282,
    LCURL = 283,
    RCURL = 284,
    ERROR = 285,
    NO_ELSE = 286
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define ID 264
#define NUM 265
#define PLUS 266
#define MINUS 267
#define MULT 268
#define DIV 269
#define LT 270
#define GT 271
#define LTEQ 272
#define GTEQ 273
#define DOUBEQ 274
#define NEQ 275
#define EQ 276
#define SEMI 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LBRAC 281
#define RBRAC 282
#define LCURL 283
#define RCURL 284
#define ERROR 285
#define NO_ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    94,   114,   118,   120,   122,   125,   125,
     146,   146,   175,   177,   182,   182,   222,   225,   227,   231,
     254,   256,   259,   281,   281,   305,   305,   326,   329,   350,
     353,   373,   376,   378,   380,   382,   384,   388,   390,   394,
     406,   419,   422,   435,   438,   444,   450,   454,   468,   472,
     500,   500,   538,   545,   550,   552,   554,   556,   558,   560,
     564,   571,   575,   577,   581,   588,   592,   594,   598,   602,
     604,   606,   614,   614,   636,   638,   641,   663,   667
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "INT", "RETURN", "VOID",
  "WHILE", "ID", "NUM", "PLUS", "MINUS", "MULT", "DIV", "LT", "GT", "LTEQ",
  "GTEQ", "DOUBEQ", "NEQ", "EQ", "SEMI", "COMMA", "LPAREN", "RPAREN",
  "LBRAC", "RBRAC", "LCURL", "RCURL", "ERROR", "NO_ELSE", "$accept",
  "program", "decl_list", "decl", "var_decl", "$@1", "$@2", "type_spec",
  "fun_decl", "@3", "params", "param_list", "param", "$@4",
  "compound_stmt", "$@5", "local_decl", "stmt_list", "stmt", "expr_stmt",
  "select_stmt", "iter_stmt", "return_stmt", "expr", "var", "$@6",
  "simple_expr", "relop", "additive_expr", "addop", "term", "mulop",
  "factor", "call", "$@7", "args", "arg_list", "epsilon", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      30,   -51,   -51,   -51,     3,    28,     2,   -51,   -51,    23,
     -51,    15,   -51,   -51,    77,    21,    31,    39,    33,     5,
     -51,   -51,    64,    81,    48,   -51,    58,   -51,    68,    98,
      86,    89,   -51,   -51,    97,   -51,    67,    79,    21,    97,
     -51,   104,    14,   -51,   -51,    88,   -51,   -51,    90,    91,
      49,    93,    82,   -51,   -51,    70,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,    99,   101,   -51,    80,    96,   -51,   -51,
      92,    54,   102,   -51,   103,    66,    94,   105,   106,   -51,
      70,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    70,
      70,   -51,   -51,    70,   -51,   107,   108,   -51,   -51,   109,
     110,    70,    70,   -51,   -51,   -51,     7,    96,   -51,   -51,
      38,   -51,    38,   100,   -51,   111,    95,   -51,   119,   -51,
     -51,   -51,    70,    38,   -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,    12,    13,     0,     0,     0,     4,     5,     0,
       6,     0,     1,     3,     8,     0,     0,     0,     0,     0,
      16,     9,     0,     0,     0,    78,     0,    21,    13,     0,
       0,    17,    20,    27,    78,    29,     0,    22,     0,     0,
      28,     0,     0,    31,    11,     0,    15,    19,     8,     0,
       0,     0,    49,    71,    38,     0,    26,    33,    30,    32,
      34,    35,    36,     0,    69,    48,    53,    61,    65,    70,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    37,
       0,    62,    63,    55,    56,    54,    57,    58,    59,     0,
       0,    66,    67,     0,    24,     0,     0,    46,    45,     0,
       0,     0,    78,    68,    47,    69,    52,    60,    64,    41,
       0,    43,     0,     0,    77,     0,    74,    75,    39,    42,
      51,    73,     0,     0,    76,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   120,   112,   -51,   -51,    22,   -51,   -51,
     -51,   -51,   113,   -51,     1,   -51,   -51,   -51,   -42,   -51,
     -51,   -51,   -51,   -50,    -6,   -51,   -51,   -51,    41,   -51,
      47,   -51,    35,   -51,   -51,   -51,   -51,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    16,    17,     9,    10,    18,
      30,    31,    32,    45,    57,    25,    34,    42,    58,    59,
      60,    61,    62,    63,    64,    76,    65,    89,    66,    90,
      67,    93,    68,    69,    77,   115,   116,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      74,    43,    -2,     1,    11,    78,    24,     2,   -25,     3,
     -25,   -25,   -25,   -25,   -25,   -25,    20,    49,    81,    82,
      50,    96,    51,    52,    53,   100,     4,   -25,    12,   -25,
     104,     1,    14,   -25,   -25,     2,    54,     3,    55,    46,
      15,    49,    19,    56,    50,    29,    51,    52,    53,    19,
      72,   113,   114,    21,     4,    95,    41,    23,    52,    53,
      54,    29,    55,    52,    53,    22,    19,    99,   118,   117,
     119,    73,   124,    55,    26,    52,    53,    33,    55,    52,
      53,   125,    27,   105,   105,    36,     2,   105,    28,    44,
      55,    81,    82,   -18,    55,    83,    84,    85,    86,    87,
      88,   -14,     2,   -10,     3,   -23,   -72,    37,   -50,    91,
      92,    38,    39,    48,    70,    71,   -10,    75,   122,    94,
     101,    79,    80,   123,    97,    98,    13,   120,   108,   102,
     106,   103,   109,   110,   111,   112,   121,   107,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,    47
};

static const yytype_int8 yycheck[] =
{
      50,    34,     0,     1,     1,    55,     1,     5,     3,     7,
       5,     6,     7,     8,     9,    10,    15,     3,    11,    12,
       6,    71,     8,     9,    10,    75,    24,    22,     0,    24,
      80,     1,     9,    28,    29,     5,    22,     7,    24,    38,
      25,     3,    28,    29,     6,    23,     8,     9,    10,    28,
       1,   101,   102,    22,    24,     1,    34,    24,     9,    10,
      22,    39,    24,     9,    10,    26,    28,     1,   110,   102,
     112,    22,   122,    24,    10,     9,    10,    29,    24,     9,
      10,   123,     1,    89,    90,    27,     5,    93,     7,    22,
      24,    11,    12,    25,    24,    15,    16,    17,    18,    19,
      20,    24,     5,    26,     7,    26,    24,     9,    26,    13,
      14,    25,    23,     9,    26,    24,    26,    24,    23,    27,
      26,    22,    21,     4,    22,    22,     6,    27,    93,    24,
      89,    25,    25,    25,    25,    25,    25,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     7,    24,    33,    34,    35,    36,    39,
      40,     1,     0,    35,     9,    25,    37,    38,    41,    28,
      46,    22,    26,    24,     1,    47,    10,     1,     7,    39,
      42,    43,    44,    29,    48,    69,    27,     9,    25,    23,
      36,    39,    49,    69,    22,    45,    46,    44,     9,     3,
       6,     8,     9,    10,    22,    24,    29,    46,    50,    51,
      52,    53,    54,    55,    56,    58,    60,    62,    64,    65,
      26,    24,     1,    22,    55,    24,    57,    66,    55,    22,
      21,    11,    12,    15,    16,    17,    18,    19,    20,    59,
      61,    13,    14,    63,    27,     1,    55,    22,    22,     1,
      55,    26,    24,    25,    55,    56,    60,    62,    64,    25,
      25,    25,    25,    55,    55,    67,    68,    69,    50,    50,
      27,    25,    23,     4,    55,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    37,    36,
      38,    36,    39,    39,    41,    40,    40,    42,    42,    43,
      43,    43,    44,    45,    44,    47,    46,    46,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    56,
      57,    56,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    66,    65,    67,    67,    68,    68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     4,
       0,     7,     1,     1,     0,     7,     4,     1,     1,     3,
       1,     1,     2,     0,     5,     0,     5,     3,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     4,     5,     4,     2,     3,     3,     3,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     0,     5,     1,     1,     3,     1,     0
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
#line 91 "cm.y" /* yacc.c:1646  */
    { syntaxTree = (yyvsp[0]).tnode; }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "cm.y" /* yacc.c:1646  */
    {
                        struct TreeNode * temp;
                        temp = (yyvsp[-1]).tnode; 

                        if(temp)
                        {
                            while(temp->sibling) // find the node without a sibling
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = (yyvsp[0]).tnode; // make the sibling the 
                            (yyval).tnode = (yyvsp[-1]).tnode;
                        }
                        else
                        {
                            (yyval).tnode = (yyvsp[0]).tnode;
                        }
                    }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "cm.y" /* yacc.c:1646  */
    {  (yyval).tnode = (yyvsp[0]).tnode; }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "cm.y" /* yacc.c:1646  */
    { fprintf(stderr, "Error in declaration\n");}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 125 "cm.y" /* yacc.c:1646  */
    {    savedName = copyString(idString); 
                                    savedLineNo = lineno; }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "cm.y" /* yacc.c:1646  */
    { 
                        (yyval).tnode = newDeclNode(VarK);
                        (yyval).tnode->name = savedName;
                        (yyval).tnode->etype = (yyvsp[-3]).type;
                        (yyval).tnode->pos = savedLineNo;
                        (yyval).tnode->memoryLocation = ++varLoc;
                        //printf("var decl param %s %d\n", savedName,$$.tnode->memoryLocation);

                        if(searchList(globalList, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, (yyvsp[-3]).type, 0, savedLineNo, (yyval).tnode->memoryLocation);
                            stack->table = addToTable(stack->table, savedName, (yyvsp[-3]).type, 0, savedLineNo, (yyval).tnode->memoryLocation);
                        }
                    }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 146 "cm.y" /* yacc.c:1646  */
    {    savedName = copyString(idString); 
                                    savedLineNo = lineno; }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "cm.y" /* yacc.c:1646  */
    { 
                        (yyval).tnode = newDeclNode(VarK);
                        (yyval).tnode->name = savedName;
                        (yyval).tnode->etype = Array;
                        (yyval).tnode->val = atoi(numString);
                        (yyval).tnode->pos = savedLineNo;
                        (yyval).tnode->memoryLocation = ++varLoc;

                        if((yyval).tnode->val < 0)
                        {
                            fprintf(stderr, "line: %d: error: array %s has a index which is out of bounds\n", savedLineNo, savedName);
                        }

                        if(lookup(globalList->table, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, Array, (yyval).tnode->val, savedLineNo, (yyval).tnode->memoryLocation);
                            stack->table = addToTable(stack->table, savedName, (yyvsp[-6]).type, 0, savedLineNo, (yyval).tnode->memoryLocation);
                        }
                    }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "cm.y" /* yacc.c:1646  */
    { (yyval).type = Integer; }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 178 "cm.y" /* yacc.c:1646  */
    { (yyval).type = Void; }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "cm.y" /* yacc.c:1646  */
    { (yyval).str = copyString(idString);
                                lineFunc = lineno; }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 185 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newDeclNode(FunK);

                        (yyval).tnode->name = (yyvsp[-4]).str;
                        (yyval).tnode->etype = (yyvsp[-6]).type;
                        (yyval).tnode->pos = lineFunc;
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;
                        (yyval).tnode->params = amountParam;
                        (yyval).tnode->memoryLocation = ++varLoc + 1;

                        //printf("func decl location %d\n", varLoc);

                        if(lookup(globalList->table, (yyvsp[-4]).str))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, (yyvsp[-4]).str);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, (yyvsp[-4]).str, (yyvsp[-6]).type, 0, lineFunc, (yyval).tnode->memoryLocation);
                            stack->table = addToTable(stack->table, (yyvsp[-4]).str, (yyvsp[-6]).type, 0, lineFunc, (yyval).tnode->memoryLocation);
                        }

                        if(returnValue == 1 && (yyvsp[-6]).type == 0)
                        {
                            fprintf(stderr, "line: %d: error: void function '%s' cannot have a return of a value\n", savedLineNo, (yyvsp[-4]).str);
                        }
                        else if(returnValue != 1 && (yyvsp[-6]).type == 1)
                        {
                            //fprintf(stderr, "line: %d: error: int function '%s' needs to have a return value\n", savedLineNo, $3.str);
                        }
                        returnValue = -1;
                        //printSymbolTable(globalList);
                        //globalList = deleteNode(globalList);


                    }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 222 "cm.y" /* yacc.c:1646  */
    { fprintf(stderr, "Error in function declaration statement\n"); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 228 "cm.y" /* yacc.c:1646  */
    {}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 232 "cm.y" /* yacc.c:1646  */
    {
                        /* sibling stuff */
                        struct TreeNode * temp;
                        temp = (yyvsp[-2]).tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = (yyvsp[0]).tnode;
                            (yyval).tnode = (yyvsp[-2]).tnode;
                        }
                        else
                        {
                            (yyval).tnode = (yyvsp[0]).tnode;
                        }

                         amountParam++;

                    }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 255 "cm.y" /* yacc.c:1646  */
    {  amountParam++; (yyval).tnode = (yyvsp[0]).tnode; }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 256 "cm.y" /* yacc.c:1646  */
    { yyerrok; yyclearin; fprintf(stderr, "\tError in the parameter list:\n");}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "cm.y" /* yacc.c:1646  */
    {
                        varLoc = amountParam + 1;
                        //printf("param %d\n", varLoc);
                        (yyval).tnode = newDeclNode(ParamK);
                        (yyval).tnode->pos = lineno;
                        (yyval).tnode->name = copyString(idString);
                        (yyval).tnode->etype = (yyvsp[-1]).type;
                        (yyval).tnode->memoryLocation = varLoc;

                        //printf("%d memLoc param\n", $$.tnode->memoryLocation);

                        if(lookup(globalList->table, idString))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", lineno, idString);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, idString, (yyvsp[-1]).type, 0, lineno, varLoc);
                            stack->table = addToTable(stack->table, idString, (yyvsp[-1]).type, 0, lineno, varLoc);
                        }
                    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 281 "cm.y" /* yacc.c:1646  */
    {    savedName = copyString(idString);
                                    savedLineNo = lineno; }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 284 "cm.y" /* yacc.c:1646  */
    {
                        varLoc = amountParam + 1;
                        (yyval).tnode = newDeclNode(ParamK);
                        (yyval).tnode->pos = savedLineNo;
                        (yyval).tnode->name = savedName;
                        (yyval).tnode->etype = Array;
                        (yyval).tnode->memoryLocation = varLoc;


                        if(lookup(globalList->table, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is previously declared\n", savedLineNo, savedName);
                        }
                        else
                        {
                            globalList->table = addToTable(globalList->table, savedName, (yyvsp[-4]).type, 0, savedLineNo, varLoc);
                            stack->table = addToTable(stack->table, savedName, (yyvsp[-4]).type, 0, savedLineNo, varLoc);
                        }
                    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 305 "cm.y" /* yacc.c:1646  */
    {
                            position++;
                            sPos++;
                            symtable[position] = createTable();
                            stackTable[sPos] = createTable();

                            globalList = addToList(globalList, symtable[position]);
                            stack = addToList(stack, stackTable[sPos]);
                        }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 315 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(CmpdK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->child[1] = (yyvsp[-1]).tnode;

                        struct symlist * t;

                        globalList = deleteNode(globalList);

                        position--;
                    }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "cm.y" /* yacc.c:1646  */
    { yyerrok; fprintf(stderr, "Error in compound statement\n"); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "cm.y" /* yacc.c:1646  */
    {
                        /*sibling stuff */
                        struct TreeNode * temp;
                        temp = (yyvsp[-1]).tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = (yyvsp[0]).tnode;
                            (yyval).tnode = (yyvsp[-1]).tnode;

                        }
                        else
                        {
                            (yyval).tnode = (yyvsp[0]).tnode;
                        }
                    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 350 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = NULL; }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 354 "cm.y" /* yacc.c:1646  */
    {
                        /* sibling stuff */
                        struct TreeNode * temp;
                        temp = (yyvsp[-1]).tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = (yyvsp[0]).tnode;
                            (yyval).tnode = (yyvsp[-1]).tnode;
                        }
                        else
                        {
                            (yyval).tnode = (yyvsp[0]).tnode;
                        }
                    }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 373 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = NULL; }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 377 "cm.y" /* yacc.c:1646  */
    { }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 379 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 381 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 383 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 385 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 389 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[-1]).tnode; }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 391 "cm.y" /* yacc.c:1646  */
    {}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 395 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(IfK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: if statement condition must be of type int\n", lineno);
                        }
                        invalidVoid = -1;
                    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 407 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(IfK);
                        (yyval).tnode->child[0] = (yyvsp[-4]).tnode;
                        (yyval).tnode->child[1] = (yyvsp[-2]).tnode;
                        (yyval).tnode->child[2] = (yyvsp[0]).tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: if-else statement condition must be of type int\n", lineno);
                        }
                        invalidVoid = -1;
                    }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 419 "cm.y" /* yacc.c:1646  */
    { yyerrok; fprintf(stderr, "Error in selection (if) statement\n"); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 423 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(WhileK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: while statement condition must be of type int\n", lineno);
                        }

                        invalidVoid = -1;
                    }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 435 "cm.y" /* yacc.c:1646  */
    { yyerrok; fprintf(stderr, "Error in iteration (while) statement\n"); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 439 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(ReturnK);
                        (yyval).tnode->child[0] = NULL;
                        returnValue = 0;
                    }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 445 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(ReturnK);
                        (yyval).tnode->child[0] = (yyvsp[-1]).tnode;
                        returnValue = 1;
                    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 450 "cm.y" /* yacc.c:1646  */
    { yyerrok; fprintf(stderr, "Error in return statement\n"); }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 455 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(AssignK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->op = EQ;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;

                        if(invalidVoid == 1)
                        {
                            fprintf(stderr, "line: %d: error: type of left-hand size of expression does not match type of right-hand side\n", lineno);
                        }
                        invalidVoid = -1;

                    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 469 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 473 "cm.y" /* yacc.c:1646  */
    { 
                        /* check if undeclared */
                        (yyval).tnode = newExpNode(IdK);
                        (yyval).tnode->name = copyString(idString);
                        (yyval).tnode->memoryLocation = findMemoryLocation(globalList, savedName);

                        /*int l = findMemoryLocation(globalList, savedName);*/
                        //printf("OK BOYS %s %d\n", idString, $$.tnode->memoryLocation);

                        if(!searchList(globalList, idString))
                        {

                            fprintf(stderr, "line: %d: error: '%s' is undeclared\n", lineno, idString);
                            globalList->table = addToTable(globalList->table, idString, Undeclared, 0, lineno, (yyval).tnode->memoryLocation);
                            
                        }

                        // check if the type being used is valid for the variable
                       // checkOne = lookup(globalList->table, idString);
                       checkOne = searchList(globalList, idString);

                        if(checkOne->type == 0)
                        {
                            invalidVoid = 1;
                        }

                    }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 500 "cm.y" /* yacc.c:1646  */
    {  savedName = copyString(idString);
                        savedLineNo = lineno; }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 503 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newExpNode(IdK);
                        (yyval).tnode->name = savedName;
                        (yyval).tnode->pos = savedLineNo;
                        (yyval).tnode->isArr = 1;
                        (yyval).tnode->child[0] = (yyvsp[-1]).tnode;
                        (yyval).tnode->memoryLocation = findMemoryLocation(globalList, savedName);

                        if(!searchList(globalList, savedName))
                        {
                            fprintf(stderr, "line: %d: error: '%s' is undeclared\n", savedLineNo, savedName);
                            globalList->table = addToTable(globalList->table, savedName, Undeclared, 0, savedLineNo, -1000);
                        }

                        // check if the index being used for the array is of type int
                        //checkOne = lookup(globalList->table, $4.tnode->name);

                        checkOne = searchList(globalList, (yyvsp[-1]).tnode->name);
                        if(checkOne->type != 1)
                        {
                            fprintf(stderr, "line: %d: error: array '%s' needs an index of type int\n", savedLineNo, savedName);
                        }

                        // check if the type being used is valid for the variable
                       // checkOne = lookup(globalList->table, idString);

                       checkOne = searchList(globalList, idString);
                        if(checkOne->type == 0)
                        {
                            invalidVoid = 1;
                            //printf("%s is of type void\n", checkOne->key);
                        }
                    }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 539 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newExpNode(OpK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->op = (yyvsp[-1]).op;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;
                    }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 546 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 551 "cm.y" /* yacc.c:1646  */
    { (yyval).op = LTEQ; }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 553 "cm.y" /* yacc.c:1646  */
    { (yyval).op = LT; }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 555 "cm.y" /* yacc.c:1646  */
    { (yyval).op = GT; }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 557 "cm.y" /* yacc.c:1646  */
    { (yyval).op = GTEQ; }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 559 "cm.y" /* yacc.c:1646  */
    { (yyval).op = DOUBEQ; }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 561 "cm.y" /* yacc.c:1646  */
    { (yyval).op = NEQ; }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 565 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newExpNode(OpK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->op = (yyvsp[-1]).op;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;
                    }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 572 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 576 "cm.y" /* yacc.c:1646  */
    { (yyval).op = PLUS; }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 578 "cm.y" /* yacc.c:1646  */
    { (yyval).op = MINUS; }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 582 "cm.y" /* yacc.c:1646  */
    { 
                        (yyval).tnode = newExpNode(OpK);
                        (yyval).tnode->child[0] = (yyvsp[-2]).tnode;
                        (yyval).tnode->op = (yyvsp[-1]).op;
                        (yyval).tnode->child[1] = (yyvsp[0]).tnode;
                    }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 589 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 593 "cm.y" /* yacc.c:1646  */
    { (yyval).op = MULT; }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 595 "cm.y" /* yacc.c:1646  */
    { (yyval).op = DIV; }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 599 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = (yyvsp[-1]).tnode;
                    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 603 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 605 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 607 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newExpNode(ConstK);
                        (yyval).tnode->val = atoi(numString);
                    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 614 "cm.y" /* yacc.c:1646  */
    {  savedName = copyString(idString);
                        savedLineNo = lineno; }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 617 "cm.y" /* yacc.c:1646  */
    {
                        (yyval).tnode = newStmtNode(CallK);
                        (yyval).tnode->name = savedName;
                        (yyval).tnode->child[0] = (yyvsp[-1]).tnode;
                        (yyval).tnode->pos = savedLineNo;
                        //printf("Call %s\n", savedName);

                        // check arguments match with amount of parameters for function
                        // add input and output to sym table
                        // check is $$..params = args, if not error msg
                        if(strcmp(savedName, "output") == 0)
                        {
                            
                        }
                        //printf("amount args %s %d params %d\n", savedName, amountArgs, amountParam);

                    }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 637 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = (yyvsp[0]).tnode; }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 638 "cm.y" /* yacc.c:1646  */
    { (yyval).tnode = NULL; }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 642 "cm.y" /* yacc.c:1646  */
    {
                        /* siblng stuff */
                        struct TreeNode * temp;
                        temp = (yyvsp[-2]).tnode;

                        if(temp)
                        {
                            while(temp->sibling)
                            {
                                temp = temp->sibling;
                            }
                            temp->sibling = (yyvsp[0]).tnode;
                            (yyval).tnode = (yyvsp[-2]).tnode;
                        }
                        else
                        {
                            (yyval).tnode = (yyvsp[0]).tnode;
                        }

                        amountArgs++;
                    }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 664 "cm.y" /* yacc.c:1646  */
    { amountArgs++; (yyval).tnode = (yyvsp[0]).tnode; }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2250 "y.tab.c" /* yacc.c:1646  */
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
#line 668 "cm.y" /* yacc.c:1906  */


