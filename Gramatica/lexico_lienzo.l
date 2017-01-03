%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "sintactico_lienzo.h"
#include "Errores/errores.h"
int lienzoline = 1;
%}

/*--------------------------------------------------------------------------
 *	Tokens definidos por ER
 *--------------------------------------------------------------------------*/
ENTERO 		[0-9]+
DOBLE 		{ENTERO}"."{ENTERO}
CARACTER 	\'([^\n\']|\\\')\'
CADENA   	\"(([^\n\"]|\\\\|\\\/|\\\"|\\b|\\f|\\n|\\r|\\t)*)\"
ID 			[A-Za-z][A-Za-z0-9_]*

%%

"Lienzo"		{ return(LIENZO); };
"extiende"		{ return(EXTIENDE); };
"publico"		{ return(PUBLICO); };
"privado"		{ return(PRIVADO); };
"protegido"		{ return(PROTEGIDO); };
"var"			{ return(VAR); };
"Conservar"		{ return(CONSERVAR); };
"arreglo"		{ return(ARR); };
"si"			{ return(SI); };
"sino"			{ return(SINO); };
"comprobar"		{ return(COMPROBAR); };
"caso"			{ return(CASO); };
"defecto"		{ return(DEFECTO); };
"salir"			{ return(SALIR); };
"continuar"		{ return(CONTINUAR); };
"para"			{ return(PARA); };
"mientras"		{ return(MIENTRAS); };
"hacer"			{ return(HACER); };
"retorna"		{ return(RETORNA); };
"Pintar_P"		{ return(PINTAR_P); };
"Pintar_OR"		{ return(PINTAR_OR); };
"Pintar_S"		{ return(PINTAR_S); };
"Principal"		{ return(PRINCIPAL); };
"Ordenar"		{ return(ORDENAR); };
"ascendente"	{ return(ASC); };
"descendente"	{ return(DESC); };
"pares"			{ return(PAR); };
"impares"		{ return(IMPAR); };
"primos"		{ return(PRIMO); };
"Sumarizar"		{ return(SUMARIZAR); };

"$"			{ return(FIN); };
";"			{ return(PYC); };
"¿"			{ return(OPEN); };
"?"			{ return(CLOSE); };
","			{ return(COMA); };
"="			{ return(ASIG); };
"["			{ return(C_OPEN); };
"]"			{ return(C_CLOSE); };
"{"			{ return(LL_OPEN); };
"}"			{ return(LL_CLOSE); };
"("			{ return(P_OPEN); };
")"			{ return(P_CLOSE); };
":"			{ return(DANGOS); };

"=="		{ return(IGUAL); };
"!="		{ return(DIFERENTE); };
"<"			{ return(MEN); };
">"			{ return(MAY); };
"<="		{ return(MEN_IGUAL); };
">="		{ return(MAY_IGUAL); };
"!&¡"		{ return(NULO); };

"||"		{ return(OR); };
"&&"		{ return(AND); };
"!&&"		{ return(NAND); };
"!||"		{ return(NOR); };
"&|"		{ return(XOR); };
"!"			{ return(NOT); };

"+"			{ return(SUM); };
"-"			{ return(SUB); };
"*"			{ return(MUL); };
"/"			{ return(DIV); };
"^"			{ return(POW); };
"++"		{ return(INCREMENTO); };
"--"		{ return(DECREMENTO); };
"+="		{ return(SUM_SIMPLY); };
"-="		{ return(SUB_SIMPLY); };

"Void"		{ return(T_VOID); };
"Entero"	{ return(T_ENTERO); };
"Doble"		{ return(T_DOBLE); };
"Cadena"	{ return(T_CADENA); };
"Boolean"	{ return(T_BOOLEAN); };
"Caracter"	{ return(T_CARACTER); };

"true"	{
    lienzolval.CADENA = new QString(lienzotext);
    return(TRUE);
};

"false"	{
    lienzolval.CADENA = new QString(lienzotext);
    return(FALSE);
};

{ENTERO} {
    lienzolval.CADENA = new QString(lienzotext);
    return(ENTERO);
};

{DOBLE} {
    lienzolval.CADENA = new QString(lienzotext);
    return(DOBLE);
};

{CARACTER} 	{
    QString aux = QString(lienzotext);
    lienzolval.CADENA = new QString(aux.mid(1,aux.length()-2));
    return(CARACTER);
};

{CADENA} {
    QString aux = QString(lienzotext);
    aux = aux.replace("\\n","\n");
    aux = aux.replace("\\t","\t");
    lienzolval.CADENA = new QString(aux.mid(1,aux.length()-2));
    return(CADENA);
};

{ID} {
    lienzolval.CADENA = new QString(lienzotext);
    return(ID);
};

">>"[^\n]*     				{ /* comentario de una línea */ } ;
"<-"[^(\-!!)]*"->"   		{ /* comentarios multilínea*/ }; 
[\t ]+						{ /* espacios en blanco */ }
\n       			    	{ lienzoline++; }; 

.		{ ManejoErrores::addErrorLexico("Caracter no válido '" + QString(lienzotext)+  "'", lienzoline); fprintf(stderr, "Error léxico '%s' en la línea %d\n", lienzotext, lienzoline); };

%%

