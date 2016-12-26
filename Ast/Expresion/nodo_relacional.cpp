#include "Ast/nodo.h"
#include "General/constantes.h"


Nodo *Nodo::crearRelacional(int subrol, QString cadena, Nodo op1, Nodo op2, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_RELACIONAL;
    nodo->subrol =subrol;
    nodo->cadena = cadena;
    nodo->fila = fila;
    nodo->hijos->append(op1);
    nodo->hijos->append(op2);
    return nodo;
}
Nodo *Nodo::crearIgual(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_IGUAL, "==", op1, op2, fila);
}
Nodo *Nodo::crearDiferente(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_DIFERENTE, "!=", op1, op2, fila);
}
Nodo *Nodo::crearMen(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_MEN, "<", op1, op2, fila);
}
Nodo *Nodo::crearMenIgual(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_MEN_IGUAL, "<=", op1, op2, fila);
}
Nodo *Nodo::crearMay(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_MAY, ">", op1, op2, fila);
}
Nodo *Nodo::crearMayIgual(Nodo op1, Nodo op2, int fila){
    return Nodo::crearRelacional(SRN_MAY_IGUAL, ">=", op1, op2, fila);
}
Nodo *Nodo::crearNulo(QString cadena, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_RELACIONAL;
    nodo->subrol=SRN_NULO;
    nodo->cadena = cadena;
    nodo->fila=fila;
    return nodo;
}
