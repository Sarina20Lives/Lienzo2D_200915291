/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         lienzoparse
#define yylex           lienzolex
#define yyerror         lienzoerror
#define yydebug         lienzodebug
#define yynerrs         lienzonerrs

#define yylval          lienzolval
#define yychar          lienzochar

/* Copy the first part of user declarations.  */
#line 1 "sintactico_lienzo.y" /* yacc.c:339  */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>	
#include "lexico_lienzo.h"
#include "Ast/nodo.h"
#include "Ast/lienzo.h"
#include "Ast/metodo.h"
#include "General/constantes.h"
#include "TablaSimbolos/simbolo.h"
#include <QList>
#include <QString>
#include <QStack>
extern int lienzolex();
extern char * lienzotext;
extern int lienzoline;
void lienzoerror(char * s);

/*--------------------------------------------------------------------------
 *	Declaracion de variables globales
 *--------------------------------------------------------------------------*/
Lienzo *lienzoRaiz = new Lienzo();
QStack<int> *recorrido = new QStack<int>();
QStack<QString> *padre = new QStack<QString>();
QList<Simbolo> *ts = new QList<Simbolo>();
QString nombreLienzo = "";

/*--------------------------------------------------------------------------
 *	Declaracion de structs
 *--------------------------------------------------------------------------*/
struct AtributoNodo{
    Nodo *nodo = new Nodo();
};

struct AtributoLnodo{
    QList<Nodo> *lnodo = new QList<Nodo>();
};

struct AtributoLstring{
    QList<QString> *lstring = new QList<QString>();
};

struct AtributoMetodo{
    Metodo *metodo = new Metodo();
};

struct AtributoLienzo{
    Lienzo *lienzo = new Lienzo();
};





#line 129 "sintactico_lienzo.cpp" /* yacc.c:339  */

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
   by #include "sintactico_lienzo.h".  */
#ifndef YY_LIENZO_SINTACTICO_LIENZO_H_INCLUDED
# define YY_LIENZO_SINTACTICO_LIENZO_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int lienzodebug;
#endif
/* "%code requires" blocks.  */
#line 60 "sintactico_lienzo.y" /* yacc.c:355  */

	#include <QList>
    #include <QString>
    #include "Ast/lienzo.h"
    #include "TablaSimbolos/simbolo.h"

#line 166 "sintactico_lienzo.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LIENZO = 258,
    EXTIENDE = 259,
    PUBLICO = 260,
    PRIVADO = 261,
    PROTEGIDO = 262,
    VAR = 263,
    CONSERVAR = 264,
    ARR = 265,
    SI = 266,
    SINO = 267,
    COMPROBAR = 268,
    CASO = 269,
    DEFECTO = 270,
    SALIR = 271,
    CONTINUAR = 272,
    PARA = 273,
    MIENTRAS = 274,
    HACER = 275,
    RETORNA = 276,
    PINTAR_P = 277,
    PINTAR_OR = 278,
    PINTAR_S = 279,
    PRINCIPAL = 280,
    ORDENAR = 281,
    SUMARIZAR = 282,
    ASC = 283,
    DESC = 284,
    PAR = 285,
    IMPAR = 286,
    PRIMO = 287,
    FIN = 288,
    PYC = 289,
    COMA = 290,
    ASIG = 291,
    DANGOS = 292,
    OPEN = 293,
    CLOSE = 294,
    C_OPEN = 295,
    C_CLOSE = 296,
    LL_OPEN = 297,
    LL_CLOSE = 298,
    P_OPEN = 299,
    P_CLOSE = 300,
    SUM = 301,
    SUB = 302,
    MUL = 303,
    DIV = 304,
    POW = 305,
    INCREMENTO = 306,
    DECREMENTO = 307,
    SUM_SIMPLY = 308,
    SUB_SIMPLY = 309,
    OR = 310,
    AND = 311,
    NAND = 312,
    NOR = 313,
    XOR = 314,
    NOT = 315,
    IGUAL = 316,
    DIFERENTE = 317,
    MEN = 318,
    MAY = 319,
    MEN_IGUAL = 320,
    MAY_IGUAL = 321,
    NULO = 322,
    T_VOID = 323,
    T_ENTERO = 324,
    T_DOBLE = 325,
    T_CADENA = 326,
    T_BOOLEAN = 327,
    T_CARACTER = 328,
    TRUE = 329,
    FALSE = 330,
    ENTERO = 331,
    DOBLE = 332,
    CARACTER = 333,
    CADENA = 334,
    ID = 335
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 75 "sintactico_lienzo.y" /* yacc.c:355  */

    QString *CADENA;
    int INT;
    struct AtributoNodo *NODO;
    struct AtributoLnodo *LNODO;
    struct AtributoLstring *LSTRING;
    struct AtributoMetodo *METODO;
    struct AtributoLienzo *LIENZO;

#line 269 "sintactico_lienzo.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE lienzolval;

int lienzoparse (void);
/* "%code provides" blocks.  */
#line 66 "sintactico_lienzo.y" /* yacc.c:355  */
 
	Lienzo *parselienzo(QString *entrada);
	QList<Simbolo> *getTS();

#line 285 "sintactico_lienzo.cpp" /* yacc.c:355  */

#endif /* !YY_LIENZO_SINTACTICO_LIENZO_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "sintactico_lienzo.cpp" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  323

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   335

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   136,   135,   150,   151,   152,   154,   161,
     167,   172,   183,   189,   195,   202,   207,   213,   218,   230,
     229,   248,   253,   247,   264,   265,   267,   268,   270,   275,
     281,   286,   297,   303,   310,   315,   320,   325,   330,   335,
     340,   345,   350,   355,   360,   365,   370,   375,   380,   385,
     396,   403,   404,   405,   407,   412,   418,   419,   420,   421,
     422,   429,   434,   439,   444,   449,   460,   467,   472,   478,
     483,   488,   494,   499,   504,   510,   515,   526,   531,   536,
     541,   546,   557,   557,   563,   568,   579,   579,   585,   591,
     597,   608,   608,   614,   619,   630,   630,   641,   641,   652,
     657,   662,   673,   678,   684,   685,   686,   687,   688,   690,
     695,   706,   712,   717,   728,   734,   739,   744,   749,   754,
     759,   764,   770,   775,   780,   785,   790,   795,   800,   806,
     811,   816,   821,   826,   831,   837,   842,   847,   852,   857,
     862,   867,   872,   877,   882,   887,   893,   898,   903,   908
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LIENZO", "EXTIENDE", "PUBLICO",
  "PRIVADO", "PROTEGIDO", "VAR", "CONSERVAR", "ARR", "SI", "SINO",
  "COMPROBAR", "CASO", "DEFECTO", "SALIR", "CONTINUAR", "PARA", "MIENTRAS",
  "HACER", "RETORNA", "PINTAR_P", "PINTAR_OR", "PINTAR_S", "PRINCIPAL",
  "ORDENAR", "SUMARIZAR", "ASC", "DESC", "PAR", "IMPAR", "PRIMO", "FIN",
  "PYC", "COMA", "ASIG", "DANGOS", "OPEN", "CLOSE", "C_OPEN", "C_CLOSE",
  "LL_OPEN", "LL_CLOSE", "P_OPEN", "P_CLOSE", "SUM", "SUB", "MUL", "DIV",
  "POW", "INCREMENTO", "DECREMENTO", "SUM_SIMPLY", "SUB_SIMPLY", "OR",
  "AND", "NAND", "NOR", "XOR", "NOT", "IGUAL", "DIFERENTE", "MEN", "MAY",
  "MEN_IGUAL", "MAY_IGUAL", "NULO", "T_VOID", "T_ENTERO", "T_DOBLE",
  "T_CADENA", "T_BOOLEAN", "T_CARACTER", "TRUE", "FALSE", "ENTERO",
  "DOBLE", "CARACTER", "CADENA", "ID", "$accept", "inicio", "lienzo",
  "$@1", "visibilidad", "extends", "lid", "contenido", "decGlobal",
  "decFun", "fprincipal", "$@2", "funcion", "$@3", "$@4", "tipof", "esArr",
  "params", "lparam", "sentencias", "sentencia", "decVar", "acceso",
  "iniVar", "tipo", "asigVar", "decArr", "ldims", "iniArr", "valArr",
  "lexpresion", "asigArr", "fSi", "$@5", "fSino", "fComprobar", "$@6",
  "casos", "bpara", "$@7", "inicial", "bmientras", "$@8", "bhacer", "$@9",
  "funPrimitiva", "funArr", "forma", "refArr", "llamada", "paramsLL",
  "expresion", "logica", "relacional", "aritmetica", "unitario", "numero", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,  -144,  -144,  -144,    55,    15,  -144,  -144,    27,  -144,
    -144,   -10,    28,     8,    16,    69,  -144,  -144,     8,    50,
    -144,    76,    50,    50,  -144,  -144,  -144,     3,  -144,  -144,
    -144,  -144,   138,  -144,  -144,  -144,  -144,  -144,  -144,    36,
      81,     2,    79,    87,    83,  -144,     8,    84,    91,  -144,
    -144,    85,   271,   104,   101,   138,   271,   105,   110,   111,
     271,   -55,   271,    88,  -144,  -144,  -144,  -144,  -144,  -144,
      57,  -144,  -144,  -144,   120,  -144,    44,  -144,  -144,  -144,
      18,  -144,  -144,    92,   122,   205,   128,    93,   -33,   126,
    -144,  -144,  -144,  -144,   271,  -144,   271,   271,   271,   271,
     271,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   121,   123,   149,   151,   141,   144,  -144,   227,
     145,   150,   153,    94,   154,    18,  -144,   187,   165,  -144,
     166,  -144,  -144,  -144,  -144,  -144,  -144,   168,   170,   159,
     177,    85,   249,  -144,  -144,   179,   249,  -144,   160,  -144,
    -144,   171,   180,    21,  -144,  -144,    21,    21,    63,    63,
     173,   173,  -144,   293,   293,   293,   293,   293,   293,   271,
     271,  -144,  -144,    -1,   271,   183,  -144,   191,   271,   271,
     271,   271,  -144,  -144,   271,   271,    99,  -144,  -144,  -144,
    -144,  -144,  -144,   189,   138,  -144,   249,   182,  -144,   326,
     185,  -144,  -144,   271,   188,   190,   138,   198,   204,   199,
      18,  -144,   211,   213,   215,  -144,  -144,  -144,   271,  -144,
    -144,   271,   271,    18,  -144,   208,  -144,  -144,  -144,  -144,
    -144,  -144,   210,  -144,  -144,  -144,  -144,   176,   271,   271,
    -144,   219,   271,   271,   271,  -144,  -144,  -144,   220,   226,
    -144,   224,   225,   228,  -144,   232,   230,   250,   235,   238,
     242,  -144,   249,    18,    71,   271,   206,    18,   234,   271,
     271,   271,  -144,   251,   271,   252,   253,  -144,   106,   243,
     256,   271,   264,   265,   273,   298,   274,    18,  -144,  -144,
    -144,   269,   271,   271,   271,   279,  -144,    18,  -144,   281,
     287,   276,   297,   277,    18,    71,    18,  -144,   301,   271,
     302,   305,  -144,   313,  -144,   324,  -144,  -144,  -144,   271,
     291,   304,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      53,     5,     6,     7,     0,     0,     2,    52,     0,    51,
       1,     0,     9,     0,     0,    11,     8,     3,     0,    53,
      10,     0,    53,    53,    17,    18,    15,    25,    16,     4,
      12,    13,     0,    19,    56,    57,    60,    58,    59,     0,
      27,     0,     0,     0,     0,    24,     0,    55,     0,    21,
      26,     0,     0,     0,     0,    29,     0,    71,     0,     0,
       0,     0,     0,     0,   144,   145,   148,   149,   142,   143,
     140,   136,   137,    54,   114,   121,   128,   134,   141,    50,
      33,    22,    28,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   120,   139,   113,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,    33,    34,     0,     0,    36,
       0,    38,    39,    40,    41,    42,    47,     0,     0,     0,
      31,    68,     0,    70,    66,     0,     0,   109,     0,   135,
     112,     0,    76,   115,   118,   119,   116,   117,   129,   130,
     131,   132,   133,   122,   123,   125,   126,   124,   127,     0,
       0,    43,    44,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,    20,    32,    35,
      37,    48,    49,     0,     0,    67,     0,     0,    74,     0,
       0,   103,   111,     0,     0,     0,     0,     0,     0,     0,
      33,    45,     0,     0,     0,    61,    64,    65,     0,    78,
      79,     0,     0,    33,    30,     0,    69,   104,   105,   106,
     107,   108,     0,   110,    75,    82,    86,     0,     0,     0,
      95,     0,     0,     0,     0,    77,    80,    81,     0,    73,
     102,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,    23,     0,    33,     0,     0,     0,    33,     0,     0,
       0,     0,    72,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,    85,     0,    33,    87,    91,
      96,     0,     0,     0,     0,     0,    83,    33,    90,     0,
       0,     0,     0,     0,    33,    89,    33,    98,     0,     0,
       0,     0,    88,     0,    99,     0,   101,    84,    92,     0,
       0,     0,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,   374,  -144,    25,    73,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   186,  -123,
    -144,    61,    46,  -144,   -26,   113,    80,   -60,  -144,  -143,
     -89,  -144,  -144,  -144,  -144,  -144,  -144,    77,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   -67,  -144,  -144,   -61,
    -144,   -52,   -48,  -144,   266,  -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    19,     7,    14,    16,    21,    22,    23,
      24,    42,    25,    55,   139,    39,    45,    81,    82,   124,
     125,   126,   127,    53,    83,   128,   129,    57,    86,   197,
     198,   130,   131,   251,   296,   132,   252,   276,   133,   299,
     208,   134,   256,   135,   175,   136,    71,   232,   148,    72,
     151,   152,    74,    75,    76,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    40,   188,   200,    84,   150,    41,   206,    89,   146,
      95,    32,    46,   137,    92,    10,     1,     2,     3,   138,
       4,    90,    91,     1,     2,     3,   -53,     4,    33,   112,
      11,   113,    13,   143,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    20,    58,    59,     8,   147,   153,   154,
     155,   156,   157,   225,    17,     1,     2,     3,   137,     4,
       1,     2,     3,   186,   138,    27,    47,   177,    27,    27,
      12,    51,    34,    35,    36,    37,    38,    97,    98,   207,
      26,   195,    15,    26,    26,   274,   275,   241,    15,   -14,
     101,   102,   103,   104,   105,    30,    31,    56,   123,    28,
     248,    94,    28,    28,    18,   106,   107,   108,   109,   110,
     111,   103,   104,   105,   234,    29,    43,   204,   205,   272,
      52,    44,   209,    48,    50,    56,   212,   213,   214,   215,
     181,    49,   216,   217,    56,   218,    54,    79,    94,    80,
     273,    85,   181,   137,   280,   182,   183,   184,   185,   138,
     219,   220,   221,   222,    87,    88,   137,   182,   183,   184,
     185,   144,   138,   141,   298,   169,   245,   170,    93,   246,
     247,   149,   140,   145,   305,    96,    97,    98,    99,   100,
     237,   311,   171,   313,   172,   173,   254,   255,   174,   178,
     258,   259,   260,   187,   179,    32,   137,   180,   189,   190,
     137,   191,   138,   192,   193,   201,   138,    34,    35,    36,
      37,    38,   194,   277,   199,   203,   202,   282,   283,   284,
     137,   210,   286,   105,   211,   226,   138,   223,   233,   291,
     137,    58,    59,   235,   238,   236,   138,   137,   239,   137,
     301,   302,   303,   138,   240,   138,   242,   142,   243,    60,
     244,   249,    61,    58,    59,   250,   253,   315,   257,   261,
     176,   262,   263,   264,   265,    62,   266,   320,   267,   268,
     269,    60,    63,   270,    61,    58,    59,   271,   281,    64,
      65,    66,    67,    68,    69,    70,   278,    62,   289,   287,
     285,   196,   288,    60,    63,   290,    61,    58,    59,   292,
     293,    64,    65,    66,    67,    68,    69,    70,   294,    62,
     295,   297,    58,    59,   300,    60,    63,   304,    61,   306,
     307,   308,   310,    64,    65,    66,    67,    68,    69,    70,
      60,    62,   309,    61,   314,   316,   321,   322,    63,   101,
     102,   103,   104,   105,   317,    64,    65,    66,    67,    68,
      69,    70,   318,    63,   227,   228,   229,   230,   231,   319,
      64,    65,    66,    67,    68,    69,    70,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     9,   279,
     224,     0,   312
};

static const yytype_int16 yycheck[] =
{
      52,    27,   125,   146,    56,    94,    32,     8,    60,    42,
      70,     8,    10,    80,    62,     0,     5,     6,     7,    80,
       9,    76,    77,     5,     6,     7,     8,     9,    25,    11,
       3,    13,     4,    85,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    18,    26,    27,     0,    80,    96,    97,
      98,    99,   100,   196,    38,     5,     6,     7,   125,     9,
       5,     6,     7,   123,   125,    19,    41,   119,    22,    23,
      80,    46,    69,    70,    71,    72,    73,    56,    57,    80,
      19,   141,    80,    22,    23,    14,    15,   210,    80,    39,
      46,    47,    48,    49,    50,    22,    23,    40,    80,    19,
     223,    44,    22,    23,    35,    61,    62,    63,    64,    65,
      66,    48,    49,    50,   203,    39,    80,   169,   170,   262,
      36,    40,   174,    44,    41,    40,   178,   179,   180,   181,
      36,    44,   184,   185,    40,    36,    45,    33,    44,    38,
     263,    36,    36,   210,   267,    51,    52,    53,    54,   210,
      51,    52,    53,    54,    44,    44,   223,    51,    52,    53,
      54,    33,   223,    41,   287,    44,   218,    44,    80,   221,
     222,    45,    80,    80,   297,    55,    56,    57,    58,    59,
     206,   304,    33,   306,    33,    44,   238,   239,    44,    44,
     242,   243,   244,    39,    44,     8,   263,    44,    33,    33,
     267,    33,   263,    33,    45,    45,   267,    69,    70,    71,
      72,    73,    35,   265,    35,    35,    45,   269,   270,   271,
     287,    38,   274,    50,    33,    43,   287,    38,    43,   281,
     297,    26,    27,    45,    36,    45,   297,   304,    34,   306,
     292,   293,   294,   304,    45,   306,    35,    42,    35,    44,
      35,    43,    47,    26,    27,    45,    80,   309,    39,    39,
      33,    35,    38,    38,    36,    60,    34,   319,    38,    19,
      35,    44,    67,    35,    47,    26,    27,    35,    44,    74,
      75,    76,    77,    78,    79,    80,    80,    60,    45,    37,
      39,    42,    39,    44,    67,    39,    47,    26,    27,    35,
      35,    74,    75,    76,    77,    78,    79,    80,    35,    60,
      12,    37,    26,    27,    45,    44,    67,    38,    47,    38,
      33,    45,    45,    74,    75,    76,    77,    78,    79,    80,
      44,    60,    35,    47,    33,    33,    45,    33,    67,    46,
      47,    48,    49,    50,    39,    74,    75,    76,    77,    78,
      79,    80,    39,    67,    28,    29,    30,    31,    32,    35,
      74,    75,    76,    77,    78,    79,    80,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     4,   266,
     194,    -1,   305
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     9,    82,    83,    85,   103,    85,
       0,     3,    80,     4,    86,    80,    87,    38,    35,    84,
      87,    88,    89,    90,    91,    93,   102,   103,   107,    39,
      88,    88,     8,    25,    69,    70,    71,    72,    73,    96,
     105,   105,    92,    80,    40,    97,    10,    87,    44,    44,
      41,    87,    36,   104,    45,    94,    40,   108,    26,    27,
      44,    47,    60,    67,    74,    75,    76,    77,    78,    79,
      80,   127,   130,   132,   133,   134,   135,   136,   137,    33,
      38,    98,    99,   105,   132,    36,   109,    44,    44,   132,
      76,    77,   133,    80,    44,   108,    55,    56,    57,    58,
      59,    46,    47,    48,    49,    50,    61,    62,    63,    64,
      65,    66,    11,    13,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    80,   100,   101,   102,   103,   106,   107,
     112,   113,   116,   119,   122,   124,   126,   127,   130,    95,
      80,    41,    42,   132,    33,    80,    42,    80,   129,    45,
     111,   131,   132,   133,   133,   133,   133,   133,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,    44,
      44,    33,    33,    44,    44,   125,    33,   132,    44,    44,
      44,    36,    51,    52,    53,    54,   108,    39,   100,    33,
      33,    33,    33,    45,    35,   108,    42,   110,   111,    35,
     110,    45,    45,    35,   132,   132,     8,    80,   121,   132,
      38,    33,   132,   132,   132,   132,   132,   132,    36,    51,
      52,    53,    54,    38,    99,   110,    43,    28,    29,    30,
      31,    32,   128,    43,   111,    45,    45,   105,    36,    34,
      45,   100,    35,    35,    35,   132,   132,   132,   100,    43,
      45,   114,   117,    80,   132,   132,   123,    39,   132,   132,
     132,    39,    35,    38,    38,    36,    34,    38,    19,    35,
      35,    35,   110,   100,    14,    15,   118,   132,    80,   106,
     100,    44,   132,   132,   132,    39,   132,    37,    39,    45,
      39,   132,    35,    35,    35,    12,   115,    37,   100,   120,
      45,   132,   132,   132,    38,   100,    38,    33,    45,    35,
      45,   100,   118,   100,    33,   132,    33,    39,    39,    35,
     132,    45,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    84,    83,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    89,    89,    90,    90,    92,
      91,    94,    95,    93,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   107,   108,   108,   109,
     109,   109,   110,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   114,   113,   115,   115,   117,   116,   118,   118,
     118,   120,   119,   121,   121,   123,   122,   125,   124,   126,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   129,
     129,   130,   131,   131,   132,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     8,     1,     1,     1,     2,     0,
       3,     1,     2,     2,     0,     1,     1,     1,     1,     0,
       8,     0,     0,    11,     2,     0,     2,     0,     1,     0,
       4,     2,     2,     0,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     2,     2,
       6,     2,     1,     0,     2,     0,     1,     1,     1,     1,
       1,     3,     2,     2,     3,     3,     8,     4,     3,     4,
       2,     0,     5,     3,     1,     3,     1,     4,     3,     3,
       4,     4,     0,     9,     4,     0,     0,     8,     5,     4,
       3,     0,    12,     5,     3,     0,     8,     0,    10,    11,
      15,    11,     6,     4,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     0,     1,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1
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
        case 3:
#line 136 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline); 
 					padre->push(*(yyvsp[-2].CADENA)); 
 					ts=new QList<Simbolo>();
 					nombreLienzo = *(yyvsp[-2].CADENA);
 				}
#line 1619 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					lienzoRaiz = (yyvsp[-1].LIENZO->lienzo);
                    lienzoRaiz->setAtributos(*(yyvsp[-5].CADENA), (yyvsp[-7].INT), recorrido->pop(), (yyvsp[-4].LSTRING->lstring));
                    ts->append(*Simbolo::crearLienzo(padre->pop(), (yyvsp[-7].INT)));
 				}
#line 1629 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PUB; }
#line 1635 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 151 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PRI; }
#line 1641 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PRO; }
#line 1647 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				{
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = (yyvsp[0].LSTRING->lstring);
 				}				
 				}
#line 1658 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 162 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::iniciarIds();
 				}
#line 1667 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 168 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::preId((yyvsp[0].LSTRING->lstring), *(yyvsp[-2].CADENA));
 				}
#line 1676 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::iniciarIds(*(yyvsp[0].CADENA));
 				}
#line 1685 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = (yyvsp[0].LIENZO->lienzo);
 					(yyval.LIENZO->lienzo)->addVariable(*(yyvsp[-1].NODO->nodo));
				}
#line 1695 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = (yyvsp[0].LIENZO->lienzo);
 					(yyval.LIENZO->lienzo)->addMetodo(*(yyvsp[-1].METODO->metodo));
 				}
#line 1705 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = new Lienzo();
 				}
#line 1714 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 203 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
				}
#line 1723 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 208 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
				}
#line 1732 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = (yyvsp[0].METODO->metodo);
				}
#line 1741 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = (yyvsp[0].METODO->metodo);
				}
#line 1750 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline);
 					padre->push("Principal");
 				}
#line 1759 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 235 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = Metodo::crearPrincipal((yyvsp[-7].INT), recorrido->pop(), (yyvsp[-1].LNODO->lnodo));
					padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *(yyval.METODO->metodo)));
				}
#line 1770 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline);
 					padre->push(*(yyvsp[-1].CADENA));
 				}
#line 1779 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 253 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
				    ts->append(*Simbolo::crearParams(nombreLienzo, padre->top(), (yyvsp[-5].INT), *(yyvsp[0].LNODO->lnodo)));
 				}
#line 1787 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 257 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
                    (yyval.METODO->metodo) = Metodo::crearMetodo(*(yyvsp[-8].CADENA), (yyvsp[-10].INT), (yyvsp[-9].INT), recorrido->pop(), (yyvsp[-5].LNODO->lnodo), (yyvsp[-1].LNODO->lnodo));
                    padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *(yyval.METODO->metodo)));
				}
#line 1798 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 264 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[-1].INT) + (yyvsp[0].INT);}
#line 1804 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 265 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = T_VOID;}
#line 1810 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = 6; }
#line 1816 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 268 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = 0;}
#line 1822 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = (yyvsp[0].LNODO->lnodo);
 				}
#line 1831 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 276 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos();
 				}
#line 1840 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 282 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *Nodo::decParam(*(yyvsp[-2].CADENA), (yyvsp[-3].INT), lienzoline));
 				}
#line 1849 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*Nodo::decParam(*(yyvsp[0].CADENA), (yyvsp[-1].INT), lienzoline));
 				}
#line 1858 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 298 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *(yyvsp[-1].NODO->nodo));
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1868 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 304 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos();
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1878 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 311 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1887 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 316 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 1896 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 321 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1905 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 326 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 1914 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 331 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1923 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 336 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1932 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 341 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1941 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 346 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1950 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 351 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1959 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 356 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearSalir(lienzoline);
 				}
#line 1968 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 361 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearContinuar(lienzoline);
 				}
#line 1977 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 366 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRetorno(*(yyvsp[-1].NODO->nodo), lienzoline);
 				}
#line 1986 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 371 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRetorno(*new Nodo(), lienzoline);
 				}
#line 1995 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 376 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2004 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 381 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 2013 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 386 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 2022 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 397 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decVar((yyvsp[-5].INT), (yyvsp[-2].LSTRING->lstring), (yyvsp[-3].INT), *(yyvsp[-1].NODO->nodo), lienzoline);
                    ts->append(*Simbolo::crearVars(nombreLienzo, padre->top(), *(yyval.NODO->nodo)));
 				}
#line 2032 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 403 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[0].INT) + A_PRI; }
#line 2038 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 404 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[0].INT); }
#line 2044 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 405 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = A_PUB; }
#line 2050 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 408 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2059 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 413 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = new Nodo();
 				}
#line 2068 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 418 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TENTERO; }
#line 2074 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 419 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TDOBLE; }
#line 2080 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 420 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TBOOLEAN; }
#line 2086 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 421 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TCARACTER; }
#line 2092 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 422 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TCADENA; }
#line 2098 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 430 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDir(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2107 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 435 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarInc(*(yyvsp[-1].CADENA), lienzoline);  					
  				}
#line 2116 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 440 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDec(*(yyvsp[-1].CADENA), lienzoline);  					
  				}
#line 2125 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 445 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarSumSimply(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2134 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 450 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarSubSimply(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2143 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 461 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decArr((yyvsp[-7].INT), (yyvsp[-5].INT), (yyvsp[-3].LSTRING->lstring), (yyvsp[-2].LNODO->lnodo),  *(yyvsp[-1].NODO->nodo), lienzoline);
                    ts->append(*Simbolo::crearArrs(nombreLienzo, padre->top(), *(yyval.NODO->nodo)));
 				}
#line 2153 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 468 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *(yyvsp[-2].NODO->nodo));
 				}
#line 2162 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 473 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*(yyvsp[-1].NODO->nodo));
 				}
#line 2171 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 479 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2180 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 484 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2189 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 489 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = new Nodo();
 				}
#line 2198 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 495 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *Nodo::crearRefArr(*(yyvsp[-3].LNODO->lnodo), lienzoline));
 				}
#line 2207 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 500 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline));
 				}
#line 2216 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 505 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = (yyvsp[0].LNODO->lnodo);
 				}
#line 2225 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 511 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *(yyvsp[-2].NODO->nodo));
 				}
#line 2234 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 516 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*(yyvsp[0].NODO->nodo));
 				}
#line 2243 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 527 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrDir(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2252 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 532 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrInc(*(yyvsp[-2].CADENA), (yyvsp[-1].LNODO->lnodo), lienzoline);  					
  				}
#line 2261 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 537 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrDec(*(yyvsp[-2].CADENA), (yyvsp[-1].LNODO->lnodo), lienzoline);  					
  				}
#line 2270 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 542 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrSumSimply(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2279 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 547 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrSubSimply(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2288 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 557 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2294 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 558 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearSi(*(yyvsp[-6].NODO->nodo), *(yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), recorrido->pop());
 				}
#line 2303 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 564 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearSentencia(*(yyvsp[-1].LNODO->lnodo));
 				}
#line 2312 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 569 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = new Nodo();
 				}
#line 2321 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 579 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2327 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 580 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearComprobar(*(yyvsp[-5].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), recorrido->pop());
 				}
#line 2336 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 586 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preCasos((yyvsp[0].LNODO->lnodo), *(yyvsp[-3].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), lienzoline);

 				}
#line 2346 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 592 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::crearCasos(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].LNODO->lnodo), lienzoline);

 				}
#line 2356 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 598 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::crearCasos(*(yyvsp[0].LNODO->lnodo), lienzoline);

 				}
#line 2366 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 608 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2372 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 609 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearPara(*(yyvsp[-9].NODO->nodo), *(yyvsp[-7].NODO->nodo), *(yyvsp[-5].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), recorrido->pop());
 				}
#line 2381 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 615 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decVar(*(yyvsp[-2].CADENA), (yyvsp[-3].INT), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2390 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 620 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDir(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2399 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 630 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2405 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 631 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearMientras(*(yyvsp[-5].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), recorrido->pop());
 				}
#line 2414 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 641 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2420 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 642 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearHacer(*(yyvsp[-2].NODO->nodo), *(yyvsp[-6].LNODO->lnodo), recorrido->pop());
 				}
#line 2429 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 653 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarP(*(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2438 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 658 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarOR(*(yyvsp[-12].NODO->nodo), *(yyvsp[-10].NODO->nodo), *(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2447 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 663 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarS(*(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2456 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 674 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearOrdenar(*(yyvsp[-3].CADENA), (yyvsp[-1].INT), lienzoline);
 				}
#line 2465 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 679 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSumarizar(*(yyvsp[-1].NODO->nodo), lienzoline);
 				}
#line 2474 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 684 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_ASC; }
#line 2480 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 685 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_DESC; }
#line 2486 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 686 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_PAR; }
#line 2492 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 687 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_IMPAR; }
#line 2498 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 688 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_PRIMO; }
#line 2504 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 691 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2513 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 696 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2522 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 707 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearLlamada(*(yyvsp[-3].CADENA), *(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2531 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 713 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
					(yyval.LNODO) = (yyvsp[0].LNODO) ;
 				}
#line 2540 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 718 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
					(yyval.LNODO->lnodo) = Nodo::iniciarHijos();
 				}
#line 2549 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 729 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2558 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 735 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearOr(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2567 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 740 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNor(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2576 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 745 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearXor(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2585 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 750 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearAnd(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2594 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 755 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNand(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2603 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 760 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNot(*(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2612 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 765 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2621 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 771 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2630 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 776 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDiferente(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2639 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 781 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMenIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2648 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 786 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMen(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2657 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 791 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMay(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2666 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 796 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMayIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2675 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 801 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2684 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 807 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSum(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2693 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 812 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSub(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2702 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 817 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMul(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2711 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 822 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDiv(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2720 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 827 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPow(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2729 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 832 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2738 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 838 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[-1].NODO);
 				}
#line 2747 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 843 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2756 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 848 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2765 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 853 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearArr(*(yyvsp[-1].CADENA), *(yyvsp[0].LNODO->lnodo), lienzoline);
 				}
#line 2774 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 858 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNulo(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2783 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 863 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearVar(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2792 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 868 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2801 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 873 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearCaracter(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2810 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 878 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearCadena(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2819 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 883 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearBoolean(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2828 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 888 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearBoolean(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2837 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 894 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearEntero(QString("-").append(*(yyvsp[0].CADENA)), lienzoline);
 				}
#line 2846 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 899 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDoble(QString("-").append(*(yyvsp[0].CADENA)), lienzoline);
 				}
#line 2855 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 904 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearEntero(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2864 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 909 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDoble(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2873 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;


#line 2877 "sintactico_lienzo.cpp" /* yacc.c:1646  */
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
#line 915 "sintactico_lienzo.y" /* yacc.c:1906  */


void lienzoinit(){
	lienzoline = 1;
}

void lienzoerror(char *s)
{
  fprintf(stderr, "Error sintactico: %s", s);
}

QList<Simbolo> *getTS(){
	return ts;
}

Lienzo *parselienzo(QString *entrada){
	lienzoinit();
    YY_BUFFER_STATE bufferState = lienzo_scan_string(entrada->toUtf8().constData());
    int estado = lienzoparse();
    if(estado!=0){
        return NULL;
    }
    lienzo_delete_buffer(bufferState);
    return lienzoRaiz;
}
