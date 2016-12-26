#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearLogica(int subrol, QString cadena, Nodo op1, Nodo op2, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_LOGICA;
    nodo->subrol =subrol;
    nodo->cadena = cadena;
    nodo->fila = fila;
    nodo->hijos->append(op1);
    nodo->hijos->append(op2);
    return nodo;
}
Nodo *Nodo::crearAnd(Nodo op1, Nodo op2, int fila){
    return Nodo::crearLogica(SRN_AND, "&&", op1, op2, fila);
}
Nodo *Nodo::crearNand(Nodo op1, Nodo op2, int fila){
    return Nodo::crearLogica(SRN_NAND, "!&&", op1, op2, fila);
}
Nodo *Nodo::crearOr(Nodo op1, Nodo op2, int fila){
    return Nodo::crearLogica(SRN_OR, "||", op1, op2, fila);
}
Nodo *Nodo::crearNor(Nodo op1, Nodo op2, int fila){
    return Nodo::crearLogica(SRN_NOR, "!||", op1, op2, fila);
}
Nodo *Nodo::crearXor(Nodo op1, Nodo op2, int fila){
    return Nodo::crearLogica(SRN_XOR, "&|", op1, op2, fila);
}

Nodo *Nodo::crearNot(Nodo op1, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_LOGICA;
    nodo->subrol=SRN_NULO;
    nodo->cadena = "!";
    nodo->fila=fila;
    nodo->hijos->append(op1);
    return nodo;
}
