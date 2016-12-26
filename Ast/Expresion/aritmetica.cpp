#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearAritmetica(int subrol, QString cadena, Nodo op1, Nodo op2, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_ARITMETICA;
    nodo->subrol =subrol;
    nodo->cadena = cadena;
    nodo->fila = fila;
    nodo->hijos->append(op1);
    nodo->hijos->append(op2);
    return nodo;
}
Nodo *Nodo::crearPow(Nodo op1, Nodo op2, int fila){
    return Nodo::crearAritmetica(SRN_POW, "^", op1, op2, fila);
}
Nodo *Nodo::crearDiv(Nodo op1, Nodo op2, int fila){
    return Nodo::crearAritmetica(SRN_DIV, "/", op1, op2, fila);
}
Nodo *Nodo::crearMul(Nodo op1, Nodo op2, int fila){
    return Nodo::crearAritmetica(SRN_MUL, "*", op1, op2, fila);
}
Nodo *Nodo::crearSub(Nodo op1, Nodo op2, int fila){
    return Nodo::crearAritmetica(SRN_SUB, "-", op1, op2, fila);
}
Nodo *Nodo::crearSum(Nodo op1, Nodo op2, int fila){
    return Nodo::crearAritmetica(SRN_SUM, "+", op1, op2, fila);
}
