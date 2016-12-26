#include "nodo.h"
#include "General/constantes.h"

Nodo::Nodo(int rol, int subrol, QString cadena, int tipo, QList<QString> *ids, QList<Nodo> *hijos, int fila){
    this->rol = rol;
    this->subrol = subrol;
    this->acceso = ERR;
    this->cadena = cadena;
    this->tipo = tipo;
    this->ids=ids;
    this->hijos= hijos;
    this->fila = fila;
}

Nodo::Nodo(int rol, int subrol, QString cadena, int tipo, int fila){
    this->rol = rol;
    this->subrol = subrol;
    this->acceso=ERR;
    this->cadena = cadena;
    this->tipo = tipo;
    this->ids=new QList<QString>;
    this->hijos= new QList<Nodo>;
    this->fila = fila;
}

Nodo::Nodo(){
    this->rol =  NOTHING;
    this->subrol = ERR;
    this->acceso = ERR;
    this->cadena = "";
    this->tipo = ERR;
    this->ids = new QList<QString>;
    this->hijos = new QList<Nodo>;
    this->fila = -1;
}

int Nodo::getRol(){
    return this->rol;
}
int Nodo::getSubRol(){
    return this->subrol;
}

int Nodo::getAcceso()
{
    return this->acceso;
}
QString Nodo::getCadena(){
    return this->cadena;
}
int Nodo::getTipo(){
    return this->tipo;
}
QList<Nodo> *Nodo::getHijos(){
    return this->hijos;
}

Nodo Nodo::getHijo(int indice)
{
    return this->getHijos()->at(indice);
}

QList<QString> *Nodo::getIds(){
    return this->ids;
}
int Nodo::getFila(){
    return this->fila;
}

QList<Nodo> *Nodo::iniciarHijos(Nodo hijo){
    QList<Nodo> *lista =  new QList<Nodo>();
    lista->append(hijo);
    return lista;
}

QList<Nodo> *Nodo::iniciarHijos(){
    QList<Nodo> *lista = new QList<Nodo>();
    return lista;
}

QList<Nodo> *Nodo::addHijo(QList<Nodo> *lista, Nodo hijo){
    lista->append(hijo);
    return lista;
}

QList<Nodo> *Nodo::preHijo(QList<Nodo> *lista, Nodo hijo){
    lista->prepend(hijo);
    return lista;
}

QList<QString> *Nodo::iniciarIds()
{
    QList<QString> *lista = new QList<QString>();
    return lista;
}

QList<QString> *Nodo::iniciarIds(QString id){
    QList<QString> *lista = new QList<QString>();
    lista->append(id);
    return lista;
}
QList<QString> *Nodo::addId(QList<QString> *lista, QString id){
    lista->append(id);
    return lista;
}
QList<QString> *Nodo::preId(QList<QString> *lista, QString id){
    lista->prepend(id);
    return lista;
}

