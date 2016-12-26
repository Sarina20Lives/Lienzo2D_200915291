#include "Ast/nodo.h"
#include "General/constantes.h"

QList<Nodo> *Nodo::crearCasos(QList<Nodo> sentDefecto, int fila){
    Nodo *nodo = Nodo::crearSentencia(sentDefecto);
    nodo->fila = fila;
    QList<Nodo> *lista = new QList<Nodo>();
    lista->append(*nodo);
    return lista;
}

QList<Nodo> *Nodo::crearCasos(Nodo cond, QList<Nodo> sentCaso, int fila){
    Nodo *caso = Nodo::crearCaso(cond, sentCaso, fila);
    Nodo *defecto = new Nodo();
    QList<Nodo> *lista = new QList<Nodo>();
    lista->append(*caso);
    lista->append(*defecto);
    return lista;
}

QList<Nodo> *Nodo::preCasos(QList<Nodo> *lista, Nodo cond, QList<Nodo> sentCaso, int fila){
    Nodo *caso = Nodo::crearCaso(cond, sentCaso, fila);
    lista->prepend(*caso);
    return lista;
}

Nodo *Nodo::crearCaso(Nodo cond, QList<Nodo> sentencias, int fila){
    Nodo *caso = new Nodo();
    Nodo *sent = Nodo::crearSentencia(sentencias);
    caso->rol = RN_CASO;
    caso->fila = fila;
    caso->hijos->append(cond);
    caso->hijos->append(*sent);
    return caso;
}

Nodo *Nodo::crearComprobar(Nodo cond, QList<Nodo> casos, int fila){
    Nodo *comprobar = new Nodo();
    comprobar->rol = RN_COMPROBAR;
    comprobar->fila = fila;
    comprobar->hijos->append(cond);
    comprobar->hijos->append(casos);
    return comprobar;
}

Nodo *Nodo::crearSi( Nodo cond, QList<Nodo> sentSi, Nodo sentSino, int fila){
    Nodo *sent = Nodo::crearSentencia(sentSi);
    Nodo *nodo = new Nodo();
    nodo->rol = RN_SI;
    nodo->hijos->append(cond);
    nodo->hijos->append(*sent);
    nodo->hijos->append(sentSino);
    nodo->fila = fila;
    return nodo;
}

