#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearOrdenar(QString cadena, int forma, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol= RN_ORDENAR;
    nodo->subrol = forma;
    nodo->cadena= cadena;
    nodo->fila =fila;
    return nodo;
}

Nodo *Nodo::crearSumarizar(Nodo refArr, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol= RN_SUMARIZAR;
    nodo->fila =fila;
    nodo->hijos->append(refArr);
    return nodo;
}



