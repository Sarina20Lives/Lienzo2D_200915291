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
#include "Errores/errores.h"
#include <QList>
#include <QString>
#include <QStack>
#define YYDEBUG 1
#define YYERROR_VERBOSE 5
extern int lienzolex();
extern char * lienzotext;
extern int lienzoline;
void lienzoerror(const char * s);

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
# define YYERROR_VERBOSE 5
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
#line 59 "sintactico_lienzo.y" /* yacc.c:355  */

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
#line 74 "sintactico_lienzo.y" /* yacc.c:355  */

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
#line 65 "sintactico_lienzo.y" /* yacc.c:355  */
 
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
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  317

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
       0,   132,   132,   135,   134,   150,   151,   152,   154,   161,
     167,   172,   183,   189,   195,   202,   207,   213,   218,   230,
     229,   248,   253,   247,   264,   265,   267,   268,   270,   275,
     281,   286,   297,   302,   308,   315,   321,   328,   333,   338,
     343,   348,   353,   358,   363,   368,   373,   378,   383,   388,
     393,   398,   403,   408,   419,   426,   427,   428,   429,   431,
     436,   442,   443,   444,   445,   446,   453,   458,   463,   468,
     473,   484,   491,   496,   502,   507,   512,   518,   523,   528,
     534,   539,   550,   555,   560,   565,   570,   581,   581,   587,
     592,   603,   603,   609,   615,   621,   632,   632,   638,   643,
     654,   654,   665,   665,   676,   681,   686,   697,   702,   708,
     709,   710,   711,   712,   714,   719,   730,   736,   741,   752,
     758,   763,   768,   773,   778,   783,   788,   794,   799,   804,
     809,   814,   819,   824,   830,   835,   840,   845,   850,   855,
     861,   866,   871,   876,   881,   886,   891,   896,   901,   906,
     911,   917,   922,   927,   932
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
  "params", "lparam", "cuerpo", "sentencias", "sentencia", "decVar",
  "acceso", "iniVar", "tipo", "asigVar", "decArr", "ldims", "iniArr",
  "valArr", "lexpresion", "asigArr", "fSi", "$@5", "fSino", "fComprobar",
  "$@6", "casos", "bpara", "$@7", "inicial", "bmientras", "$@8", "bhacer",
  "$@9", "funPrimitiva", "funArr", "forma", "refArr", "llamada",
  "paramsLL", "expresion", "logica", "relacional", "aritmetica",
  "unitario", "numero", YY_NULLPTR
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

#define YYPACT_NINF -275

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-275)))

#define YYTABLE_NINF -96

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,  -275,  -275,  -275,    88,    33,  -275,  -275,    35,  -275,
    -275,   -22,    57,   -14,    36,    51,  -275,  -275,   -14,    23,
    -275,    41,    23,    23,  -275,  -275,  -275,     6,  -275,  -275,
    -275,  -275,   169,  -275,  -275,  -275,  -275,  -275,  -275,    21,
      76,     1,    75,    77,    84,  -275,   -14,    92,    99,  -275,
    -275,    89,   391,   103,   108,   169,   391,   113,   115,   118,
     391,   -55,   391,    87,  -275,  -275,  -275,  -275,  -275,  -275,
     -17,  -275,  -275,  -275,   191,  -275,   413,  -275,  -275,  -275,
     134,  -275,  -275,  -275,    90,   128,   306,   141,   101,   -23,
     143,  -275,  -275,  -275,  -275,   391,  -275,   391,   391,   391,
     391,   391,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   -13,   145,   146,   158,   161,   151,   167,
    -275,   330,   171,   172,   174,  -275,    19,   251,  -275,  -275,
     205,   193,  -275,   195,  -275,  -275,  -275,  -275,  -275,  -275,
     196,   197,   188,   199,    89,   369,  -275,  -275,   200,   369,
    -275,   206,  -275,  -275,   208,   201,   -21,  -275,  -275,   -21,
     -21,   130,   130,   204,   204,  -275,   288,   288,   288,   288,
     288,   288,  -275,  -275,   391,   391,  -275,  -275,     4,   391,
     108,  -275,   230,   391,   391,   391,   391,  -275,  -275,   391,
     391,   112,   232,  -275,  -275,  -275,  -275,  -275,  -275,   108,
     169,  -275,   369,   223,  -275,   311,   236,  -275,  -275,   391,
     240,   242,   169,   253,   269,   264,   292,  -275,   278,   289,
     293,  -275,  -275,  -275,   391,  -275,  -275,   391,   391,  -275,
    -275,   284,  -275,  -275,  -275,  -275,  -275,  -275,   285,  -275,
    -275,  -275,  -275,   249,   391,   391,  -275,   300,   391,   391,
     391,  -275,  -275,  -275,   310,  -275,   108,   308,   313,  -275,
     317,   108,   391,   312,   319,   323,   369,   340,    28,   391,
     279,  -275,   315,   391,   391,   391,  -275,   108,  -275,   391,
     324,   325,  -275,   132,   320,   329,   332,   333,   334,  -275,
     338,   299,  -275,  -275,  -275,   391,   391,   391,   299,   275,
     108,   331,   335,   342,    91,  -275,   355,   391,   358,  -275,
    -275,   343,  -275,   391,   348,   361,  -275
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      58,     5,     6,     7,    57,     0,     2,    56,     0,    55,
       1,     0,     9,     0,     0,    11,     8,     3,     0,    58,
      10,     0,    58,    58,    17,    18,    15,    25,    16,     4,
      12,    13,     0,    19,    61,    62,    65,    63,    64,     0,
      27,     0,     0,     0,     0,    24,     0,    60,     0,    21,
      26,     0,     0,     0,     0,    29,     0,    76,     0,     0,
       0,     0,     0,     0,   149,   150,   153,   154,   147,   148,
     145,   141,   142,    59,   119,   126,   133,   139,   146,    54,
       0,    20,    22,    28,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   125,   144,   118,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,    33,     0,     0,    36,    37,
       0,     0,    39,     0,    41,    42,    43,    44,    45,    50,
       0,     0,     0,    31,    73,     0,    75,    71,     0,     0,
     114,     0,   140,   117,     0,    81,   120,   123,   124,   121,
     122,   134,   135,   136,   137,   138,   127,   128,   130,   131,
     129,   132,    53,    34,     0,     0,    46,    47,     0,     0,
       0,    49,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,     0,    32,    35,    38,    40,    51,    52,     0,
       0,    72,     0,     0,    79,     0,     0,   108,   116,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,    66,    69,    70,     0,    83,    84,     0,     0,    23,
      30,     0,    74,   109,   110,   111,   112,   113,     0,   115,
      80,    87,    91,     0,     0,     0,   100,     0,     0,     0,
       0,    82,    85,    86,    78,   107,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,   101,     0,     0,     0,     0,    77,     0,    88,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,    89,
       0,     0,    92,    96,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,    93,
     104,     0,   106,     0,     0,     0,   105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -275,  -275,  -275,  -275,   394,  -275,    -2,    68,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,   202,  -174,
    -274,  -122,    45,    18,  -275,   -25,   129,    66,   -61,  -275,
    -146,   -85,  -275,  -275,  -275,  -275,  -275,  -275,    96,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,   -79,  -275,  -275,
     -67,  -275,   -52,   -47,  -275,    97,  -275,  -275
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    19,     7,    14,    16,    21,    22,    23,
      24,    42,    25,    55,   142,    39,    45,    82,    83,    81,
     127,   128,   129,   130,    53,    84,   131,   132,    57,    87,
     203,   204,   133,   134,   256,   278,   135,   257,   281,   136,
     300,   214,   137,   261,   138,   180,   139,    71,   238,   151,
      72,   154,   155,    74,    75,    76,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   140,    40,   206,    85,   194,   216,    41,    90,    96,
     153,    46,   212,   141,    32,    93,    20,   299,     8,   149,
     172,    91,    92,    56,   304,   229,   173,    95,     1,     2,
       3,    33,     4,    10,   146,    98,    99,    27,    11,    47,
      27,    27,   279,   280,    51,     1,     2,     3,   140,     4,
     156,   157,   158,   159,   160,   186,   231,   150,    12,    56,
     141,    13,   -14,    95,    26,   191,    15,    26,    26,   182,
     187,   188,   189,   190,    17,    34,    35,    36,    37,    38,
      29,    15,   267,   201,   213,    28,    18,   271,    28,    28,
      30,    31,   192,     1,     2,     3,     1,     2,     3,   -58,
       4,    43,   114,   289,   115,   279,   280,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    44,    58,    59,    48,
     276,    49,   210,   211,   240,    50,   305,   215,    52,    56,
     -94,   218,   219,   220,   221,   113,    79,   222,   223,     1,
       2,     3,   -58,     4,    54,   114,    80,   115,   224,    86,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    88,
      58,    59,    89,   225,   226,   227,   228,    94,   186,   144,
     143,   126,   251,   125,   147,   252,   253,   194,   104,   105,
     106,   148,   194,   187,   188,   189,   190,   243,   152,   174,
     175,   176,   259,   260,   177,   178,   263,   264,   265,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     272,   179,   140,    32,   126,   183,   184,   282,   185,   140,
     140,   286,   287,   288,   141,   140,   195,   290,   196,   197,
     198,   141,   141,   199,   200,   205,   209,   141,    34,    35,
      36,    37,    38,   301,   302,   303,    97,    98,    99,   100,
     101,   207,   192,   208,   106,   311,     1,     2,     3,   -58,
       4,   314,   114,   217,   115,   172,   232,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   192,    58,    59,   239,
       1,     2,     3,   -58,     4,   241,   114,   242,   115,   244,
     193,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     192,    58,    59,   245,     1,     2,     3,   -58,     4,   246,
     114,   247,   115,   248,   -95,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   249,    58,    59,   254,   250,   258,
     255,   126,    58,    59,   102,   103,   104,   105,   106,   233,
     234,   235,   236,   237,   262,   266,   268,   273,   145,   269,
      60,   270,   277,    61,   274,   126,    58,    59,   275,   283,
     285,   291,   294,   181,   292,   293,    62,   295,   296,   297,
     307,    58,    59,    63,    60,   298,   306,    61,   313,   126,
      64,    65,    66,    67,    68,    69,    70,   308,   310,    60,
      62,   312,    61,   315,   316,    58,    59,    63,     9,   284,
     309,     0,   230,     0,    64,    65,    66,    67,    68,    69,
      70,   202,    63,    60,     0,     0,    61,    58,    59,    64,
      65,    66,    67,    68,    69,    70,     0,     0,     0,    62,
       0,     0,     0,     0,     0,    60,    63,     0,    61,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
       0,    62,     0,     0,     0,     0,     0,     0,    63,   102,
     103,   104,   105,   106,     0,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   107,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      52,    80,    27,   149,    56,   127,   180,    32,    60,    70,
      95,    10,     8,    80,     8,    62,    18,   291,     0,    42,
      33,    76,    77,    40,   298,   199,    39,    44,     5,     6,
       7,    25,     9,     0,    86,    56,    57,    19,     3,    41,
      22,    23,    14,    15,    46,     5,     6,     7,   127,     9,
      97,    98,    99,   100,   101,    36,   202,    80,    80,    40,
     127,     4,    39,    44,    19,   126,    80,    22,    23,   121,
      51,    52,    53,    54,    38,    69,    70,    71,    72,    73,
      39,    80,   256,   144,    80,    19,    35,   261,    22,    23,
      22,    23,     1,     5,     6,     7,     5,     6,     7,     8,
       9,    80,    11,   277,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    40,    26,    27,    44,
     266,    44,   174,   175,   209,    41,   300,   179,    36,    40,
      39,   183,   184,   185,   186,     1,    33,   189,   190,     5,
       6,     7,     8,     9,    45,    11,    38,    13,    36,    36,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    44,
      26,    27,    44,    51,    52,    53,    54,    80,    36,    41,
      80,    80,   224,    39,    33,   227,   228,   299,    48,    49,
      50,    80,   304,    51,    52,    53,    54,   212,    45,    44,
      44,    33,   244,   245,    33,    44,   248,   249,   250,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     262,    44,   291,     8,    80,    44,    44,   269,    44,   298,
     299,   273,   274,   275,   291,   304,    33,   279,    33,    33,
      33,   298,   299,    45,    35,    35,    35,   304,    69,    70,
      71,    72,    73,   295,   296,   297,    55,    56,    57,    58,
      59,    45,     1,    45,    50,   307,     5,     6,     7,     8,
       9,   313,    11,    33,    13,    33,    43,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     1,    26,    27,    43,
       5,     6,     7,     8,     9,    45,    11,    45,    13,    36,
      39,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       1,    26,    27,    34,     5,     6,     7,     8,     9,    45,
      11,    19,    13,    35,    39,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    35,    26,    27,    43,    35,    80,
      45,    80,    26,    27,    46,    47,    48,    49,    50,    28,
      29,    30,    31,    32,    44,    35,    38,    35,    42,    36,
      44,    34,    12,    47,    35,    80,    26,    27,    35,    80,
      45,    37,    33,    33,    39,    45,    60,    35,    35,    35,
      35,    26,    27,    67,    44,    37,    45,    47,    35,    80,
      74,    75,    76,    77,    78,    79,    80,    45,    33,    44,
      60,    33,    47,    45,    33,    26,    27,    67,     4,   270,
     304,    -1,   200,    -1,    74,    75,    76,    77,    78,    79,
      80,    42,    67,    44,    -1,    -1,    47,    26,    27,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    44,    67,    -1,    47,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    46,
      47,    48,    49,    50,    -1,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    61,    62,    63,    64,    65,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     9,    82,    83,    85,   104,    85,
       0,     3,    80,     4,    86,    80,    87,    38,    35,    84,
      87,    88,    89,    90,    91,    93,   103,   104,   108,    39,
      88,    88,     8,    25,    69,    70,    71,    72,    73,    96,
     106,   106,    92,    80,    40,    97,    10,    87,    44,    44,
      41,    87,    36,   105,    45,    94,    40,   109,    26,    27,
      44,    47,    60,    67,    74,    75,    76,    77,    78,    79,
      80,   128,   131,   133,   134,   135,   136,   137,   138,    33,
      38,   100,    98,    99,   106,   133,    36,   110,    44,    44,
     133,    76,    77,   134,    80,    44,   109,    55,    56,    57,
      58,    59,    46,    47,    48,    49,    50,    61,    62,    63,
      64,    65,    66,     1,    11,    13,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    39,    80,   101,   102,   103,
     104,   107,   108,   113,   114,   117,   120,   123,   125,   127,
     128,   131,    95,    80,    41,    42,   133,    33,    80,    42,
      80,   130,    45,   112,   132,   133,   134,   134,   134,   134,
     134,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,    33,    39,    44,    44,    33,    33,    44,    44,
     126,    33,   133,    44,    44,    44,    36,    51,    52,    53,
      54,   109,     1,    39,   102,    33,    33,    33,    33,    45,
      35,   109,    42,   111,   112,    35,   111,    45,    45,    35,
     133,   133,     8,    80,   122,   133,   100,    33,   133,   133,
     133,   133,   133,   133,    36,    51,    52,    53,    54,   100,
      99,   111,    43,    28,    29,    30,    31,    32,   129,    43,
     112,    45,    45,   106,    36,    34,    45,    19,    35,    35,
      35,   133,   133,   133,    43,    45,   115,   118,    80,   133,
     133,   124,    44,   133,   133,   133,    35,   100,    38,    36,
      34,   100,   133,    35,    35,    35,   111,    12,   116,    14,
      15,   119,   133,    80,   107,    45,   133,   133,   133,   100,
     133,    37,    39,    45,    33,    35,    35,    35,    37,   101,
     121,   133,   133,   133,   101,   100,    45,    35,    45,   119,
      33,   133,    33,    35,   133,    45,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    84,    83,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    89,    89,    90,    90,    92,
      91,    94,    95,    93,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   104,   104,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   108,   109,   109,   110,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   115,   114,   116,
     116,   118,   117,   119,   119,   119,   121,   120,   122,   122,
     124,   123,   126,   125,   127,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   130,   130,   131,   132,   132,   133,
     134,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     8,     1,     1,     1,     2,     0,
       3,     1,     2,     2,     0,     1,     1,     1,     1,     0,
       6,     0,     0,     9,     2,     0,     2,     0,     1,     0,
       4,     2,     3,     2,     3,     2,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       1,     2,     2,     2,     6,     2,     1,     1,     0,     2,
       0,     1,     1,     1,     1,     1,     3,     2,     2,     3,
       3,     8,     4,     3,     4,     2,     0,     5,     3,     1,
       3,     1,     4,     3,     3,     4,     4,     0,     7,     2,
       0,     0,     8,     5,     4,     3,     0,    10,     5,     3,
       0,     6,     0,     8,    11,    15,    11,     6,     4,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     0,     1,
       3,     3,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1
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
  YYCASE_(0, YY_(""));
  YYCASE_(1, YY_("Se detectó el token inesperado %s"));
  YYCASE_(2, YY_("Se detectó el token inesperado %s, y se esperaba %s"));
  YYCASE_(3, YY_("Se detectó el token inesperado %s, y se esperaba %s o %s"));
  YYCASE_(4, YY_("Se detectó el token inesperado %s, y se esperaba %s o %s o %s"));
  YYCASE_(5, YY_("Se detectó el token inesperado %s, y se esperaba %s o %s o %s o %s"));
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
#line 135 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline); 
 					padre->push(*(yyvsp[-2].CADENA)); 
 					ManejoErrores::getInstance(*(yyvsp[-2].CADENA));
 					ts=new QList<Simbolo>();
 					nombreLienzo = *(yyvsp[-2].CADENA);
 				}
#line 1639 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					lienzoRaiz = (yyvsp[-1].LIENZO->lienzo);
                    lienzoRaiz->setAtributos(*(yyvsp[-5].CADENA), (yyvsp[-7].INT), recorrido->pop(), (yyvsp[-4].LSTRING->lstring));
                    ts->append(*Simbolo::crearLienzo(padre->pop(), (yyvsp[-7].INT)));
 				}
#line 1649 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PUB; }
#line 1655 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 151 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PRI; }
#line 1661 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = V_PRO; }
#line 1667 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				{
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = (yyvsp[0].LSTRING->lstring);
 				}				
 				}
#line 1678 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 162 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::iniciarIds();
 				}
#line 1687 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 168 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::preId((yyvsp[0].LSTRING->lstring), *(yyvsp[-2].CADENA));
 				}
#line 1696 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LSTRING) = new AtributoLstring();
 					(yyval.LSTRING->lstring) = Nodo::iniciarIds(*(yyvsp[0].CADENA));
 				}
#line 1705 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = (yyvsp[0].LIENZO->lienzo);
 					(yyval.LIENZO->lienzo)->addVariable(*(yyvsp[-1].NODO->nodo));
				}
#line 1715 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = (yyvsp[0].LIENZO->lienzo);
 					(yyval.LIENZO->lienzo)->addMetodo(*(yyvsp[-1].METODO->metodo));
 				}
#line 1725 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LIENZO) = new AtributoLienzo();
 					(yyval.LIENZO->lienzo) = new Lienzo();
 				}
#line 1734 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 203 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
				}
#line 1743 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 208 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
				}
#line 1752 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = (yyvsp[0].METODO->metodo);
				}
#line 1761 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = (yyvsp[0].METODO->metodo);
				}
#line 1770 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline);
 					padre->push("Principal");
 				}
#line 1779 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 235 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
					(yyval.METODO->metodo) = Metodo::crearPrincipal((yyvsp[-5].INT), recorrido->pop(), (yyvsp[0].LNODO->lnodo));
					padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *(yyval.METODO->metodo)));
				}
#line 1790 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					recorrido->push(lienzoline);
 					padre->push(*(yyvsp[-1].CADENA));
 				}
#line 1799 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 253 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
				    ts->append(*Simbolo::crearParams(nombreLienzo, padre->top(), (yyvsp[-5].INT), *(yyvsp[0].LNODO->lnodo)));
 				}
#line 1807 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 257 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
					(yyval.METODO) = new AtributoMetodo();
                    (yyval.METODO->metodo) = Metodo::crearMetodo(*(yyvsp[-6].CADENA), (yyvsp[-8].INT), (yyvsp[-7].INT), recorrido->pop(), (yyvsp[-3].LNODO->lnodo), (yyvsp[0].LNODO->lnodo));
                    padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *(yyval.METODO->metodo)));
				}
#line 1818 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 264 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[-1].INT) + (yyvsp[0].INT);}
#line 1824 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 265 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TVOID;}
#line 1830 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = 6; }
#line 1836 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 268 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = 0;}
#line 1842 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = (yyvsp[0].LNODO->lnodo);
 				}
#line 1851 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 276 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos();
 				}
#line 1860 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 282 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *Nodo::decParam(*(yyvsp[-2].CADENA), (yyvsp[-3].INT), lienzoline));
 				}
#line 1869 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*Nodo::decParam(*(yyvsp[0].CADENA), (yyvsp[-1].INT), lienzoline));
 				}
#line 1878 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 298 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = (yyvsp[-1].LNODO->lnodo); 					
 				}
#line 1887 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 303 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(); 					
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1897 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 309 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(); 					
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1907 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 316 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::addHijo((yyvsp[-1].LNODO->lnodo), *(yyvsp[0].NODO->nodo));
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1917 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 322 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*(yyvsp[0].NODO->nodo));
 					(yyval.LNODO->lnodo) = Nodo::agregarPausa((yyval.LNODO->lnodo), lienzoline);
 				}
#line 1927 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 329 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1936 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 334 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 1945 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 339 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1954 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 344 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 1963 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 349 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1972 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 354 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1981 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 359 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1990 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 364 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 1999 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 369 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2008 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 374 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearSalir(lienzoline);
 				}
#line 2017 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 379 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearContinuar(lienzoline);
 				}
#line 2026 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 384 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRetorno(*(yyvsp[-1].NODO->nodo), lienzoline);
 				}
#line 2035 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 389 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRetorno(*new Nodo(), lienzoline);
 				}
#line 2044 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 394 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2053 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 399 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 2062 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 404 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[-1].NODO->nodo);
 				}
#line 2071 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 409 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = new Nodo(); 					
 				}
#line 2080 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 420 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decVar((yyvsp[-5].INT), (yyvsp[-2].LSTRING->lstring), (yyvsp[-3].INT), *(yyvsp[-1].NODO->nodo), lienzoline);
                    ts->append(*Simbolo::crearVars(nombreLienzo, padre->top(), *(yyval.NODO->nodo)));
 				}
#line 2090 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 426 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[0].INT) + A_PRI; }
#line 2096 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 427 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = (yyvsp[0].INT); }
#line 2102 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 428 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = A_PUB_CON; }
#line 2108 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 429 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = A_PUB; }
#line 2114 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 432 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2123 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 437 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = new Nodo();
 				}
#line 2132 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 442 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TENTERO; }
#line 2138 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 443 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TDOBLE; }
#line 2144 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 444 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TBOOLEAN; }
#line 2150 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 445 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TCARACTER; }
#line 2156 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 446 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = TCADENA; }
#line 2162 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 454 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDir(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2171 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 459 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarInc(*(yyvsp[-1].CADENA), lienzoline);  					
  				}
#line 2180 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 464 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDec(*(yyvsp[-1].CADENA), lienzoline);  					
  				}
#line 2189 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 469 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarSumSimply(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2198 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 474 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarSubSimply(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2207 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 485 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decArr((yyvsp[-7].INT), (yyvsp[-5].INT), (yyvsp[-3].LSTRING->lstring), (yyvsp[-2].LNODO->lnodo),  *(yyvsp[-1].NODO->nodo), lienzoline);
                    ts->append(*Simbolo::crearArrs(nombreLienzo, padre->top(), *(yyval.NODO->nodo)));
 				}
#line 2217 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 492 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *(yyvsp[-2].NODO->nodo));
 				}
#line 2226 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 497 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*(yyvsp[-1].NODO->nodo));
 				}
#line 2235 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 503 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2244 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 508 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2253 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 513 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 				 	(yyval.NODO) = new AtributoNodo();
 				 	(yyval.NODO->nodo) = new Nodo();
 				}
#line 2262 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 519 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *Nodo::crearRefArr(*(yyvsp[-3].LNODO->lnodo), lienzoline));
 				}
#line 2271 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 524 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline));
 				}
#line 2280 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 529 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = (yyvsp[0].LNODO->lnodo);
 				}
#line 2289 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 535 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preHijo((yyvsp[0].LNODO->lnodo), *(yyvsp[-2].NODO->nodo));
 				}
#line 2298 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 540 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::iniciarHijos(*(yyvsp[0].NODO->nodo));
 				}
#line 2307 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 551 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrDir(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2316 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 556 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrInc(*(yyvsp[-2].CADENA), (yyvsp[-1].LNODO->lnodo), lienzoline);  					
  				}
#line 2325 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 561 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrDec(*(yyvsp[-2].CADENA), (yyvsp[-1].LNODO->lnodo), lienzoline);  					
  				}
#line 2334 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 566 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrSumSimply(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2343 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 571 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigArrSubSimply(*(yyvsp[-3].CADENA), (yyvsp[-2].LNODO->lnodo), *(yyvsp[0].NODO->nodo), lienzoline);  					
  				}
#line 2352 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 581 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2358 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 582 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearSi(*(yyvsp[-4].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), *(yyvsp[0].NODO->nodo), recorrido->pop());
 				}
#line 2367 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 588 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearSentencia(*(yyvsp[0].LNODO->lnodo));
 				}
#line 2376 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 593 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = new Nodo();
 				}
#line 2385 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 603 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2391 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 604 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearComprobar(*(yyvsp[-5].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), recorrido->pop());
 				}
#line 2400 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 610 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::preCasos((yyvsp[0].LNODO->lnodo), *(yyvsp[-3].NODO->nodo), *(yyvsp[-1].LNODO->lnodo), lienzoline);

 				}
#line 2410 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 616 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::crearCasos(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].LNODO->lnodo), lienzoline);

 				}
#line 2420 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 622 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
 					(yyval.LNODO->lnodo) = Nodo::crearCasos(*(yyvsp[0].LNODO->lnodo), lienzoline);

 				}
#line 2430 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 632 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2436 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 633 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearPara(*(yyvsp[-7].NODO->nodo), *(yyvsp[-5].NODO->nodo), *(yyvsp[-3].NODO->nodo), *(yyvsp[0].LNODO->lnodo), recorrido->pop());
 				}
#line 2445 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 639 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::decVar(*(yyvsp[-2].CADENA), (yyvsp[-3].INT), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2454 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 644 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::asigVarDir(*(yyvsp[-2].CADENA), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2463 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 654 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2469 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 655 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearMientras(*(yyvsp[-3].NODO->nodo), *(yyvsp[0].LNODO->lnodo), recorrido->pop());
 				}
#line 2478 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 665 "sintactico_lienzo.y" /* yacc.c:1646  */
    {recorrido->push(lienzoline);}
#line 2484 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 666 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
 					(yyval.NODO->nodo) = Nodo::crearHacer(*(yyvsp[-2].NODO->nodo), *(yyvsp[-5].LNODO->lnodo), recorrido->pop());
 				}
#line 2493 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 677 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarP(*(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2502 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 682 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarOR(*(yyvsp[-12].NODO->nodo), *(yyvsp[-10].NODO->nodo), *(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2511 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 687 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPintarS(*(yyvsp[-8].NODO->nodo), *(yyvsp[-6].NODO->nodo), *(yyvsp[-4].NODO->nodo), *(yyvsp[-2].NODO->nodo), lienzoline);
 				}
#line 2520 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 698 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearOrdenar(*(yyvsp[-3].CADENA), (yyvsp[-1].INT), lienzoline);
 				}
#line 2529 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 703 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSumarizar(*(yyvsp[-1].NODO->nodo), lienzoline);
 				}
#line 2538 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 708 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_ASC; }
#line 2544 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 709 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_DESC; }
#line 2550 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 710 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_PAR; }
#line 2556 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 711 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_IMPAR; }
#line 2562 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 712 "sintactico_lienzo.y" /* yacc.c:1646  */
    { (yyval.INT) = SRN_PRIMO; }
#line 2568 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 715 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2577 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 720 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearRefArr(*(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2586 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 731 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearLlamada(*(yyvsp[-3].CADENA), *(yyvsp[-1].LNODO->lnodo), lienzoline);
 				}
#line 2595 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 737 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
					(yyval.LNODO) = (yyvsp[0].LNODO) ;
 				}
#line 2604 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 742 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.LNODO) = new AtributoLnodo();
					(yyval.LNODO->lnodo) = Nodo::iniciarHijos();
 				}
#line 2613 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 753 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2622 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 759 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearOr(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2631 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 764 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNor(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2640 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 769 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearXor(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2649 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 774 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearAnd(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2658 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 779 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNand(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2667 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 784 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNot(*(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2676 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 789 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2685 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 795 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2694 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 800 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDiferente(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2703 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 805 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMenIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2712 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 810 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMen(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2721 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 815 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMay(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2730 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 820 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMayIgual(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2739 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 825 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2748 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 831 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSum(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2757 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 836 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearSub(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2766 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 841 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearMul(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2775 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 846 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDiv(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2784 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 851 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearPow(*(yyvsp[-2].NODO->nodo), *(yyvsp[0].NODO->nodo), lienzoline);
 				}
#line 2793 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 856 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2802 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 862 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[-1].NODO);
 				}
#line 2811 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 867 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2820 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 872 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO) = (yyvsp[0].NODO);
 				}
#line 2829 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 877 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearArr(*(yyvsp[-1].CADENA), *(yyvsp[0].LNODO->lnodo), lienzoline);
 				}
#line 2838 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 882 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearNulo(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2847 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 887 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearVar(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2856 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 892 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = (yyvsp[0].NODO->nodo);
 				}
#line 2865 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 897 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearCaracter(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2874 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 902 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearCadena(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2883 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 907 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearBoolean(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2892 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 912 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearBoolean(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2901 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 918 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearEntero(QString("-").append(*(yyvsp[0].CADENA)), lienzoline);
 				}
#line 2910 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 923 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDoble(QString("-").append(*(yyvsp[0].CADENA)), lienzoline);
 				}
#line 2919 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 928 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearEntero(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2928 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 933 "sintactico_lienzo.y" /* yacc.c:1646  */
    {
 					(yyval.NODO) = new AtributoNodo();
					(yyval.NODO->nodo) = Nodo::crearDoble(*(yyvsp[0].CADENA), lienzoline);
 				}
#line 2937 "sintactico_lienzo.cpp" /* yacc.c:1646  */
    break;


#line 2941 "sintactico_lienzo.cpp" /* yacc.c:1646  */
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
#line 939 "sintactico_lienzo.y" /* yacc.c:1906  */


void lienzoinit(){
	lienzoline = 1;
}

void lienzoerror(const char *s)
{
	ManejoErrores::addErrorSintactico(QString(s), lienzoline);
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
