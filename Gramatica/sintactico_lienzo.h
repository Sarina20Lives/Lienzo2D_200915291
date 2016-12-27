/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 60 "sintactico_lienzo.y" /* yacc.c:1909  */

	#include <QList>
    #include <QString>
    #include "Ast/lienzo.h"
    #include "TablaSimbolos/simbolo.h"

#line 51 "sintactico_lienzo.h" /* yacc.c:1909  */

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
#line 75 "sintactico_lienzo.y" /* yacc.c:1909  */

    QString *CADENA;
    int INT;
    struct AtributoNodo *NODO;
    struct AtributoLnodo *LNODO;
    struct AtributoLstring *LSTRING;
    struct AtributoMetodo *METODO;
    struct AtributoLienzo *LIENZO;

#line 154 "sintactico_lienzo.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE lienzolval;

int lienzoparse (void);
/* "%code provides" blocks.  */
#line 66 "sintactico_lienzo.y" /* yacc.c:1909  */
 
	Lienzo *parselienzo(QString *entrada);
	QList<Simbolo> *getTS();

#line 170 "sintactico_lienzo.h" /* yacc.c:1909  */

#endif /* !YY_LIENZO_SINTACTICO_LIENZO_H_INCLUDED  */
