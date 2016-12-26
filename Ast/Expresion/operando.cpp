#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearOperando(QString cadena, int tipo, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_OPERANDO;
    nodo->subrol = SRN_OPERANDO;
    nodo->cadena= cadena;
    nodo->tipo = tipo;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearEntero(QString cadena, int fila){
    return Nodo::crearOperando(cadena, TENTERO, fila);
}
Nodo *Nodo::crearDoble(QString cadena, int fila){
    return Nodo::crearOperando(cadena, TDOBLE, fila);
}
Nodo *Nodo::crearCaracter(QString cadena, int fila){
    return Nodo::crearOperando(cadena, TCARACTER, fila);
}
Nodo *Nodo::crearCadena(QString cadena, int fila){
    return Nodo::crearOperando(cadena, TCADENA, fila);
}
Nodo *Nodo::crearBoolean(QString cadena, int fila){
    return Nodo::crearOperando(cadena, TBOOLEAN, fila);
}

Nodo *Nodo::crearVar(QString cadena, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_OPERANDO;
    nodo->subrol = SRN_VAR;
    nodo->cadena = cadena;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearArr(QString cadena, QList<Nodo> dimensiones, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_OPERANDO;
    nodo->subrol = SRN_ARR;
    nodo->cadena = cadena;
    nodo->hijos->append(dimensiones);
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearRefArr(QString cadena, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_REF_ARR;
    nodo->subrol = SRN_ARR;
    nodo->cadena = cadena;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearRefArr(QList<Nodo> refs, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_REF_ARR;
    nodo->subrol = SRN_VAL_ARR;
    nodo->cadena = "{}";
    nodo->hijos->append(refs);
    nodo->fila = fila;
    return nodo;
}

