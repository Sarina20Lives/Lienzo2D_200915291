#include "Ast/nodo.h"
#include "General/constantes.h"


Nodo *Nodo::asigVar(int subrol, QString cadena, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_ASIG_VAR;
    nodo->subrol = subrol;
    nodo->cadena = cadena;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::asigVarDir(QString cadena, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigVar(SRN_DIRECTO, cadena, fila);
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::asigVarInc(QString cadena, int fila){
    return Nodo::asigVar(SRN_INC, cadena,fila);
}

Nodo *Nodo::asigVarDec(QString cadena,  int fila){
    return Nodo::asigVar(SRN_DEC, cadena, fila);
}

Nodo *Nodo::asigVarSumSimply(QString cadena, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigVar(SRN_SUM_SIMPLY, cadena, fila);
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::asigVarSubSimply(QString cadena, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigVar(SRN_SUB_SIMPLY, cadena, fila);
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::asigArr(int subrol, QString cadena, QList<Nodo> *dims, int fila){
    Nodo *dim = Nodo::crearDimensiones(dims);
    Nodo *nodo = new Nodo();
    nodo->rol = RN_ASIG_ARR;
    nodo->subrol = subrol;
    nodo->cadena = cadena;
    nodo->fila = fila;
    nodo->hijos->append(*dim);
    return nodo;
}

Nodo *Nodo::asigArrDir(QString cadena, QList<Nodo> *dims, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigArr(SRN_DIRECTO, cadena, dims, fila);
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::asigArrInc(QString cadena, QList<Nodo> *dims, int fila){
    return Nodo::asigArr(SRN_INC, cadena, dims, fila);
}

Nodo *Nodo::asigArrDec(QString cadena, QList<Nodo> *dims, int fila){
    return Nodo::asigArr(SRN_INC, cadena, dims, fila);
}

Nodo *Nodo::asigArrSumSimply(QString cadena, QList<Nodo> *dims, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigArr(SRN_SUM_SIMPLY, cadena, dims, fila);
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::asigArrSubSimply(QString cadena, QList<Nodo> *dims, Nodo exp, int fila){
    Nodo *nodo = Nodo::asigArr(SRN_SUB_SIMPLY, cadena, dims, fila);
    nodo->hijos->append(exp);
    return nodo;
}
