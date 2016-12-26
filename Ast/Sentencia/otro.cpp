#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearLlamada(QString cadena, QList<Nodo> params, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_LLAMADA;
    nodo->cadena = cadena;
    nodo->hijos->append(params);
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearSentencia(QList<Nodo> sentencias){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_SENTENCIAS;
    nodo->hijos->append(sentencias);
    return nodo;
}

Nodo *Nodo::crearDimensiones(QList<Nodo> *dims){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_DIMENCIONES;
    nodo->hijos->append(*dims);
    return nodo;
}

Nodo *Nodo::crearSalir(int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_SALIR;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearContinuar(int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_CONTINUAR;
    nodo->fila = fila;
    return nodo;
}

Nodo *Nodo::crearRetorno(Nodo ret, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_RETORNA;
    nodo->fila = fila;
    nodo->hijos->append(ret);
    return nodo;
}

QList<Nodo> *Nodo::agregarPausa(QList<Nodo> *lista, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_PAUSA;
    nodo->fila = fila;
    lista->prepend(*nodo);
    return lista;
}
