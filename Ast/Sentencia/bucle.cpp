#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearPara(Nodo inicio, Nodo cond, Nodo variacion, QList<Nodo> sentencias, int fila){
    Nodo *sentencia = Nodo::crearSentencia(sentencias);
    Nodo *nodo = new Nodo();
    nodo->rol = RN_PARA;
    nodo->hijos->append(inicio);
    nodo->hijos->append(cond);
    nodo->hijos->append(variacion);
    nodo->hijos->append(*sentencia);
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearMientras(Nodo cond, QList<Nodo> sentencias, int fila){
    Nodo *sentencia = Nodo::crearSentencia(sentencias);
    Nodo *nodo = new Nodo();
    nodo->rol = RN_MIENTRAS;
    nodo->hijos->append(cond);
    nodo->hijos->append(*sentencia);
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearHacer(Nodo cond, QList<Nodo> sentencias, int fila){
    Nodo *sentencia = Nodo::crearSentencia(sentencias);
    Nodo *nodo = new Nodo();
    nodo->rol = RN_HACER;
    nodo->hijos->append(cond);
    nodo->hijos->append(*sentencia);
    nodo->fila = fila;
    return nodo;
}
