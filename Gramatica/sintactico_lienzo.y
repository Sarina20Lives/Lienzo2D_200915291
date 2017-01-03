%{
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

%}

/*--------------------------------------------------------------------------
 *	Declaracion de métodos 
 *--------------------------------------------------------------------------*/
%code requires {
	#include <QList>
    #include <QString>
    #include "Ast/lienzo.h"
    #include "TablaSimbolos/simbolo.h"
}
%code provides { 
	Lienzo *parselienzo(QString *entrada);
	QList<Simbolo> *getTS();
}

/*--------------------------------------------------------------------------
 *	Declaracion de tipos
 *--------------------------------------------------------------------------*/

%union{
    QString *CADENA;
    int INT;
    struct AtributoNodo *NODO;
    struct AtributoLnodo *LNODO;
    struct AtributoLstring *LSTRING;
    struct AtributoMetodo *METODO;
    struct AtributoLienzo *LIENZO;
}

/*--------------------------------------------------------------------------
 *	Tokens
 *--------------------------------------------------------------------------*/
//	Palabras reservadas:
	%token LIENZO EXTIENDE PUBLICO PRIVADO PROTEGIDO VAR CONSERVAR ARR SI SINO COMPROBAR CASO DEFECTO SALIR CONTINUAR PARA MIENTRAS HACER RETORNA PINTAR_P PINTAR_OR PINTAR_S PRINCIPAL ORDENAR SUMARIZAR ASC DESC PAR IMPAR PRIMO
 
//	Simbolos de puntuación:
	%token FIN PYC COMA ASIG DANGOS 

//	Simbolos de agrupación:
	%token OPEN CLOSE C_OPEN C_CLOSE LL_OPEN LL_CLOSE P_OPEN P_CLOSE

//	Operadores aritmeticos:
	%token SUM SUB MUL DIV POW INCREMENTO DECREMENTO SUM_SIMPLY SUB_SIMPLY

//	Operadores logicos:
	%token OR AND NAND NOR XOR NOT

//	Operadores relacionales:
	%token IGUAL DIFERENTE MEN MAY MEN_IGUAL MAY_IGUAL NULO

//	Tipos:
	%token T_VOID T_ENTERO T_DOBLE T_CADENA T_BOOLEAN T_CARACTER

//	Terminales:
	%token<CADENA> TRUE FALSE ENTERO DOBLE CARACTER CADENA ID


/*--------------------------------------------------------------------------
 *	No terminales
 *--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 *	Asociatividad y precedencia
 *--------------------------------------------------------------------------*/
%left OR XOR NOR
%left AND NAND
%precedence NOT
%left SUM SUB
%left MUL DIV
%left POW

%%

/*--------------------------------------------------------------------------
 *	Inicio >>> Grámatica
 *--------------------------------------------------------------------------*/

 inicio 		: lienzo
 ;
 lienzo 		: acceso LIENZO ID extends OPEN 
 				{
 					recorrido->push(lienzoline); 
 					padre->push(*$<CADENA>3); 
 					ManejoErrores::getInstance(*$<CADENA>3);
 					ts=new QList<Simbolo>();
 					nombreLienzo = *$<CADENA>3;
 				} 
 				contenido CLOSE
 				{
 					lienzoRaiz = $<LIENZO->lienzo>7;
                    lienzoRaiz->setAtributos(*$<CADENA>3, $<INT>1, recorrido->pop(), $<LSTRING->lstring>4);
                    ts->append(*Simbolo::crearLienzo(padre->pop(), $<INT>1));
 				}

 ;
 visibilidad 	: PUBLICO 		{ $<INT>$ = V_PUB; }
 				| PRIVADO		{ $<INT>$ = V_PRI; }
 				| PROTEGIDO		{ $<INT>$ = V_PRO; }
 ;
 extends 		: EXTIENDE lid
 				{
 				{
 					$<LSTRING>$ = new AtributoLstring();
 					$<LSTRING->lstring>$ = $<LSTRING->lstring>2;
 				}				
 				}
 				| %empty
 				{
 					$<LSTRING>$ = new AtributoLstring();
 					$<LSTRING->lstring>$ = Nodo::iniciarIds();
 				}
 ;
 lid 			: ID COMA lid
 				{
 					$<LSTRING>$ = new AtributoLstring();
 					$<LSTRING->lstring>$ = Nodo::preId($<LSTRING->lstring>3, *$<CADENA>1);
 				}
 				| ID
 				{
 					$<LSTRING>$ = new AtributoLstring();
 					$<LSTRING->lstring>$ = Nodo::iniciarIds(*$<CADENA>1);
 				}
 ;

/*--------------------------------------------------------------------------
 *	Instrucciones
 *--------------------------------------------------------------------------*/

 contenido		: decGlobal contenido
 				{
 					$<LIENZO>$ = new AtributoLienzo();
 					$<LIENZO->lienzo>$ = $<LIENZO->lienzo>2;
 					$<LIENZO->lienzo>$->addVariable(*$<NODO->nodo>1);
				}
 				| decFun contenido
 				{
 					$<LIENZO>$ = new AtributoLienzo();
 					$<LIENZO->lienzo>$ = $<LIENZO->lienzo>2;
 					$<LIENZO->lienzo>$->addMetodo(*$<METODO->metodo>1);
 				}
 				| %empty
 				{
 					$<LIENZO>$ = new AtributoLienzo();
 					$<LIENZO->lienzo>$ = new Lienzo();
 				}

 ;
 decGlobal 		: decVar
 				{
					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = $<NODO->nodo>1;
				}
 				| decArr
 				{
					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = $<NODO->nodo>1;
				}
 ;
 decFun			: fprincipal
 				{
					$<METODO>$ = new AtributoMetodo();
					$<METODO->metodo>$ = $<METODO->metodo>1;
				}
 				| funcion
 				{
					$<METODO>$ = new AtributoMetodo();
					$<METODO->metodo>$ = $<METODO->metodo>1;
				}
 ;

/*--------------------------------------------------------------------------
 *	Principal
 *--------------------------------------------------------------------------*/

 fprincipal 	: acceso PRINCIPAL 
 				{
 					recorrido->push(lienzoline);
 					padre->push("Principal");
 				} 
 				P_OPEN P_CLOSE cuerpo	
 				{
					$<METODO>$ = new AtributoMetodo();
					$<METODO->metodo>$ = Metodo::crearPrincipal($<INT>1, recorrido->pop(), $<LNODO->lnodo>6);
					padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *$<METODO->metodo>$));
				}	
 ;

/*--------------------------------------------------------------------------
 *	Funciones y procedimientos
 *--------------------------------------------------------------------------*/

 funcion 		: acceso tipof ID P_OPEN 
 				{
 					recorrido->push(lienzoline);
 					padre->push(*$<CADENA>3);
 				} 
 				params 
 				{
				    ts->append(*Simbolo::crearParams(nombreLienzo, padre->top(), $<INT>1, *$<LNODO->lnodo>6));
 				}
 				P_CLOSE cuerpo
				{
					$<METODO>$ = new AtributoMetodo();
                    $<METODO->metodo>$ = Metodo::crearMetodo(*$<CADENA>3, $<INT>1, $<INT>2, recorrido->pop(), $<LNODO->lnodo>6, $<LNODO->lnodo>9);
                    padre->pop();
	                ts->append(*Simbolo::crearMtd(nombreLienzo, padre->top(), *$<METODO->metodo>$));
				}
 ;
 tipof 			: tipo esArr		{ $<INT>$ = $<INT>1 + $<INT>2;}
 				| %empty			{ $<INT>$ = T_VOID;}
 ;
 esArr 			: C_OPEN C_CLOSE 	{ $<INT>$ = 6; }
 				| %empty			{ $<INT>$ = 0;}
 ;
 params 		: lparam
				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = $<LNODO->lnodo>1;
 				}
 				| %empty
				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos();
 				}
 ;
 lparam 		: tipo ID COMA lparam
				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::preHijo($<LNODO->lnodo>4, *Nodo::decParam(*$<CADENA>2, $<INT>1, lienzoline));
 				}
 				| tipo ID
				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(*Nodo::decParam(*$<CADENA>2, $<INT>1, lienzoline));
 				}
 ;

/*--------------------------------------------------------------------------
 *	Sentencias
 *--------------------------------------------------------------------------*/

 cuerpo			: OPEN sentencias CLOSE
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = $<LNODO->lnodo>2; 					
 				}
 				| OPEN CLOSE
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(); 					
 					$<LNODO->lnodo>$ = Nodo::agregarPausa($<LNODO->lnodo>$, lienzoline);
 				}
 				| OPEN error CLOSE
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(); 					
 					$<LNODO->lnodo>$ = Nodo::agregarPausa($<LNODO->lnodo>$, lienzoline);
 				}

 sentencias 	: sentencias sentencia
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::addHijo($<LNODO->lnodo>1, *$<NODO->nodo>2);
 					$<LNODO->lnodo>$ = Nodo::agregarPausa($<LNODO->lnodo>$, lienzoline);
 				}
 				| sentencia
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(*$<NODO->nodo>1);
 					$<LNODO->lnodo>$ = Nodo::agregarPausa($<LNODO->lnodo>$, lienzoline);
 				}
 ;
 sentencia 		: decVar
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| asigVar FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| decArr
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| asigArr FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| fSi
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| fComprobar
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| bpara
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| bmientras
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| bhacer
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| SALIR FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = Nodo::crearSalir(lienzoline);
 				}
 				| CONTINUAR FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = Nodo::crearContinuar(lienzoline);
 				}
 				| RETORNA expresion FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = Nodo::crearRetorno(*$<NODO->nodo>2, lienzoline);
 				}
 				| RETORNA FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = Nodo::crearRetorno(*new Nodo(), lienzoline);
 				}
 				| funPrimitiva
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| funArr FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| llamada FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
 				| error FIN
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = new Nodo(); 					
 				}
 ;

 /*--------------------------------------------------------------------------
 *	Declaración de variables
 *--------------------------------------------------------------------------*/

 decVar 		: acceso VAR tipo lid iniVar FIN 
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::decVar($<INT>1, $<LSTRING->lstring>4, $<INT>3, *$<NODO->nodo>5, lienzoline);
                    ts->append(*Simbolo::crearVars(nombreLienzo, padre->top(), *$<NODO->nodo>$));
 				}
 ;
 acceso			: CONSERVAR visibilidad 	{ $<INT>$ = $<INT>2 + A_PRI; }
 				| visibilidad				{ $<INT>$ = $<INT>1; }
 				| %empty					{ $<INT>$ = A_PUB; }
 ;
 iniVar 		: ASIG expresion
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>2;
 				}
 				| %empty
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = new Nodo();
 				}
 ;
 tipo 			: T_ENTERO		{ $<INT>$ = TENTERO; }
 				| T_DOBLE		{ $<INT>$ = TDOBLE; }
 				| T_BOOLEAN		{ $<INT>$ = TBOOLEAN; }
 				| T_CARACTER	{ $<INT>$ = TCARACTER; }
 				| T_CADENA		{ $<INT>$ = TCADENA; }
 ;

 /*--------------------------------------------------------------------------
 *	Asignación de variables
 *--------------------------------------------------------------------------*/
 
 asigVar 		: ID ASIG expresion 
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarDir(*$<CADENA>1, *$<NODO->nodo>3, lienzoline);  					
  				}
  				| ID INCREMENTO
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarInc(*$<CADENA>1, lienzoline);  					
  				}
  				| ID DECREMENTO
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarDec(*$<CADENA>1, lienzoline);  					
  				}
  				| ID SUM_SIMPLY expresion
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarSumSimply(*$<CADENA>1, *$<NODO->nodo>3, lienzoline);  					
  				}
  				| ID SUB_SIMPLY expresion
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarSubSimply(*$<CADENA>1, *$<NODO->nodo>3, lienzoline);  					
  				}
 ;

 /*--------------------------------------------------------------------------
 *	Declaración de arreglos
 *--------------------------------------------------------------------------*/

 decArr 		: acceso VAR tipo ARR lid ldims iniArr FIN
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::decArr($<INT>1, $<INT>3, $<LSTRING->lstring>5, $<LNODO->lnodo>6,  *$<NODO->nodo>7, lienzoline);
                    ts->append(*Simbolo::crearArrs(nombreLienzo, padre->top(), *$<NODO->nodo>$));
 				}
 ;
 ldims 			: C_OPEN expresion C_CLOSE ldims
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::preHijo($<LNODO->lnodo>4, *$<NODO->nodo>2);
 				}
 				| C_OPEN expresion C_CLOSE
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(*$<NODO->nodo>2);
 				}
 ;
 iniArr 		: ASIG LL_OPEN valArr LL_CLOSE
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = Nodo::crearRefArr(*$<LNODO->lnodo>3, lienzoline);
 				}
 				| ASIG expresion
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = $<NODO->nodo>2;
 				}
 				| %empty
 				{
 				 	$<NODO>$ = new AtributoNodo();
 				 	$<NODO->nodo>$ = new Nodo();
 				}
 ;
 valArr			: LL_OPEN valArr LL_CLOSE COMA valArr
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::preHijo($<LNODO->lnodo>5, *Nodo::crearRefArr(*$<LNODO->lnodo>2, lienzoline));
 				}
 				| LL_OPEN valArr LL_CLOSE
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(*Nodo::crearRefArr(*$<LNODO->lnodo>2, lienzoline));
 				}
 				| lexpresion
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = $<LNODO->lnodo>1;
 				}
 ;
 lexpresion  	: expresion COMA lexpresion
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::preHijo($<LNODO->lnodo>3, *$<NODO->nodo>1);
 				}
 				| expresion
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::iniciarHijos(*$<NODO->nodo>1);
 				}
 ;

 /*--------------------------------------------------------------------------
 *	Asignación de arreglos
 *--------------------------------------------------------------------------*/

 asigArr 		: ID ldims ASIG expresion
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigArrDir(*$<CADENA>1, $<LNODO->lnodo>2, *$<NODO->nodo>4, lienzoline);  					
  				}
				| ID ldims INCREMENTO
				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigArrInc(*$<CADENA>1, $<LNODO->lnodo>2, lienzoline);  					
  				}
  				| ID ldims DECREMENTO
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigArrDec(*$<CADENA>1, $<LNODO->lnodo>2, lienzoline);  					
  				}
  				| ID ldims SUM_SIMPLY expresion
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigArrSumSimply(*$<CADENA>1, $<LNODO->lnodo>2, *$<NODO->nodo>4, lienzoline);  					
  				}
  				| ID ldims SUB_SIMPLY expresion
  				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigArrSubSimply(*$<CADENA>1, $<LNODO->lnodo>2, *$<NODO->nodo>4, lienzoline);  					
  				}
 ;

 /*--------------------------------------------------------------------------
 *	Flujo Si
 *--------------------------------------------------------------------------*/

 fSi 			: SI P_OPEN expresion P_CLOSE  {recorrido->push(lienzoline);} cuerpo fSino
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearSi(*$<NODO->nodo>3, *$<LNODO->lnodo>6, *$<NODO->nodo>7, recorrido->pop());
 				} 				
 ;
 fSino 			: SINO cuerpo
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearSentencia(*$<LNODO->lnodo>2);
 				}
 				| %empty
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = new Nodo();
 				}
 ;

/*--------------------------------------------------------------------------
 *	Flujo Comprobar
 *--------------------------------------------------------------------------*/
 
 fComprobar 	: COMPROBAR P_OPEN expresion P_CLOSE  {recorrido->push(lienzoline);} OPEN casos CLOSE
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearComprobar(*$<NODO->nodo>3, *$<LNODO->lnodo>7, recorrido->pop());
 				}
 ;
 casos 			: CASO expresion DANGOS sentencias casos
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::preCasos($<LNODO->lnodo>5, *$<NODO->nodo>2, *$<LNODO->lnodo>4, lienzoline);

 				}
 				| CASO expresion DANGOS sentencias
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::crearCasos(*$<NODO->nodo>2, *$<LNODO->lnodo>4, lienzoline);

 				}
 				| DEFECTO DANGOS sentencias
 				{
 					$<LNODO>$ = new AtributoLnodo();
 					$<LNODO->lnodo>$ = Nodo::crearCasos(*$<LNODO->lnodo>3, lienzoline);

 				}
 ;

/*--------------------------------------------------------------------------
 *	Bucle para
 *--------------------------------------------------------------------------*/
 bpara 			: PARA P_OPEN inicial PYC expresion PYC asigVar P_CLOSE {recorrido->push(lienzoline);} cuerpo
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearPara(*$<NODO->nodo>3, *$<NODO->nodo>5, *$<NODO->nodo>7, *$<LNODO->lnodo>10, recorrido->pop());
 				}
 ;
 inicial 		: VAR tipo ID ASIG expresion
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::decVar(*$<CADENA>3, $<INT>2, *$<NODO->nodo>5, lienzoline);
 				}
 				| ID ASIG expresion
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::asigVarDir(*$<CADENA>1, *$<NODO->nodo>3, lienzoline);
 				}
 ;

/*--------------------------------------------------------------------------
 *	Bucle mientras
 *--------------------------------------------------------------------------*/

 bmientras 		: MIENTRAS P_OPEN expresion P_CLOSE {recorrido->push(lienzoline);} cuerpo
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearMientras(*$<NODO->nodo>3, *$<LNODO->lnodo>6, recorrido->pop());
 				}
 ;

/*--------------------------------------------------------------------------
 *	Bucle hacer mientras
 *--------------------------------------------------------------------------*/

 bhacer 		: HACER {recorrido->push(lienzoline);} cuerpo MIENTRAS P_OPEN expresion P_CLOSE FIN
 				{
 					$<NODO>$ = new AtributoNodo();
 					$<NODO->nodo>$ = Nodo::crearHacer(*$<NODO->nodo>6, *$<LNODO->lnodo>3, recorrido->pop());
 				}
 ;

/*--------------------------------------------------------------------------
 *	Funciones primitivas
 *--------------------------------------------------------------------------*/

 funPrimitiva 	: PINTAR_P P_OPEN expresion COMA expresion COMA expresion COMA expresion P_CLOSE FIN
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearPintarP(*$<NODO->nodo>3, *$<NODO->nodo>5, *$<NODO->nodo>7, *$<NODO->nodo>9, lienzoline);
 				}  			
 				| PINTAR_OR P_OPEN expresion COMA expresion COMA expresion COMA expresion COMA expresion COMA expresion P_CLOSE FIN
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearPintarOR(*$<NODO->nodo>3, *$<NODO->nodo>5, *$<NODO->nodo>7, *$<NODO->nodo>9, *$<NODO->nodo>11, *$<NODO->nodo>13, lienzoline);
 				}  			
 				| PINTAR_S P_OPEN expresion COMA expresion COMA expresion COMA expresion P_CLOSE FIN
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearPintarS(*$<NODO->nodo>3, *$<NODO->nodo>5, *$<NODO->nodo>7, *$<NODO->nodo>9, lienzoline);
 				}  			
 ;

/*--------------------------------------------------------------------------
 *	Funciones de arreglos
 *--------------------------------------------------------------------------*/
 
 funArr 		: ORDENAR P_OPEN ID COMA forma P_CLOSE
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearOrdenar(*$<CADENA>3, $<INT>5, lienzoline);
 				}  			
 				| SUMARIZAR P_OPEN refArr P_CLOSE 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearSumarizar(*$<NODO->nodo>3, lienzoline);
 				}  			
 ;
 forma 			: ASC 		{ $<INT>$ = SRN_ASC; }
 				| DESC		{ $<INT>$ = SRN_DESC; }
 			  	| PAR 		{ $<INT>$ = SRN_PAR; }
 			  	| IMPAR 	{ $<INT>$ = SRN_IMPAR; }
 			  	| PRIMO 	{ $<INT>$ = SRN_PRIMO; }
 ;
 refArr 		: ID
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearRefArr(*$<CADENA>1, lienzoline);
 				}  			
 				| LL_OPEN valArr LL_CLOSE
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearRefArr(*$<LNODO->lnodo>2, lienzoline);
 				}  
 ;

 /*--------------------------------------------------------------------------
 *	Llamadas
 *--------------------------------------------------------------------------*/

 llamada 		: ID P_OPEN paramsLL P_CLOSE 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearLlamada(*$<CADENA>1, *$<LNODO->lnodo>3, lienzoline);
 				} 
 ;
 paramsLL		: lexpresion
 				{
 					$<LNODO>$ = new AtributoLnodo();
					$<LNODO>$ = $<LNODO>1 ;
 				}
 				| %empty
 				{
 					$<LNODO>$ = new AtributoLnodo();
					$<LNODO->lnodo>$ = Nodo::iniciarHijos();
 				}
 ;

 /*--------------------------------------------------------------------------
 *	Expresion
 *--------------------------------------------------------------------------*/

 expresion 		: logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}
 ;
 logica 		: logica OR logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearOr(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | logica NOR logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearNor(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | logica XOR logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearXor(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | logica AND logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearAnd(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | logica NAND logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearNand(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | NOT logica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearNot(*$<NODO->nodo>2, lienzoline);
 				} 
                | relacional 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}
 ;
 relacional 	: aritmetica IGUAL aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearIgual(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | aritmetica DIFERENTE aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearDiferente(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | aritmetica MEN_IGUAL aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearMenIgual(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | aritmetica MEN aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearMen(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
                | aritmetica MAY aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearMay(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				} 
 				| aritmetica MAY_IGUAL aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearMayIgual(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | aritmetica 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}
 ;
 aritmetica 	: aritmetica SUM aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearSum(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | aritmetica SUB aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearSub(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | aritmetica MUL aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearMul(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | aritmetica DIV aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearDiv(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | aritmetica POW aritmetica
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearPow(*$<NODO->nodo>1, *$<NODO->nodo>3, lienzoline);
 				}
                | unitario 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}
 ;
 unitario 		: P_OPEN expresion P_CLOSE  
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>2;
 				}
                | funArr 	 
				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}
                | llamada 		 
				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO>$ = $<NODO>1;
 				}                
                | ID ldims 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearArr(*$<CADENA>1, *$<LNODO->lnodo>2, lienzoline);
 				}
				| NULO ID
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearNulo(*$<CADENA>2, lienzoline);
 				}
				| ID
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearVar(*$<CADENA>1, lienzoline);
 				}
 				| numero 		
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = $<NODO->nodo>1;
 				}
                | CARACTER		
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearCaracter(*$<CADENA>1, lienzoline);
 				}
                | CADENA 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearCadena(*$<CADENA>1, lienzoline);
 				}
                | TRUE
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearBoolean(*$<CADENA>1, lienzoline);
 				}
                | FALSE 		
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearBoolean(*$<CADENA>1, lienzoline);
 				}
 ;
 numero 		: SUB ENTERO
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearEntero(QString("-").append(*$<CADENA>2), lienzoline);
 				}
 				| SUB DOBLE
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearDoble(QString("-").append(*$<CADENA>2), lienzoline);
 				}
 				| ENTERO 
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearEntero(*$<CADENA>1, lienzoline);
 				}
 				| DOBLE
 				{
 					$<NODO>$ = new AtributoNodo();
					$<NODO->nodo>$ = Nodo::crearDoble(*$<CADENA>1, lienzoline);
 				}
 ;				

%%

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
