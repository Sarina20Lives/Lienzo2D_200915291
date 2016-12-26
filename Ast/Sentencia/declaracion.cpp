#include "Ast/nodo.h"
#include "General/constantes.h"


Nodo *Nodo::decParam(QString id, int tipo, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_DECLARE;
    nodo->subrol = SRN_PARAM;
    nodo->cadena = id;
    nodo->acceso = A_PUB;
    nodo->tipo = tipo;
    nodo->fila = fila;
    return nodo;
}


Nodo *Nodo::decVar(QString id, int tipo, Nodo exp, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_DECLARE;
    nodo->subrol = SRN_VAR;
    nodo->acceso = A_PUB;
    nodo->tipo = tipo;
    nodo->fila = fila;
    nodo->ids->append(id);
    nodo->hijos->append(exp);
    return nodo;
}


Nodo *Nodo::decVar(int acceso, QList<QString> *ids, int tipo, Nodo exp, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_DECLARE;
    nodo->subrol = SRN_VAR;
    nodo->acceso = acceso;
    nodo->tipo = tipo;
    nodo->fila = fila;
    nodo->ids=ids;
    nodo->hijos->append(exp);
    return nodo;
}

Nodo *Nodo::decArr(int acceso, int tipo, QList<QString> *ids, QList<Nodo> *dims, Nodo iniArr, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_DECLARE;
    nodo->subrol = SRN_ARR;
    nodo->acceso = acceso;
    nodo->tipo = tipo;
    nodo->ids = ids;
    nodo->fila = fila;
    nodo->hijos->append(*Nodo::crearDimensiones(dims));
    nodo->hijos->append(iniArr);
    return nodo;
}
