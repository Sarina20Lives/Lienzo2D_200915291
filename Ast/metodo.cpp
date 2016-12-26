#include "metodo.h"
#include "General/constantes.h"

Metodo::Metodo()
{
    this->nombre="";
    this->acceso=ERR;
    this->tipo = ERR;
    this->esArr = false;
    this->esPrincipal = false;
    this->fila = ERR;
    this->parametros= new QList<Nodo>();
    this->sentencias= new QList<Nodo>();
    this->paramsToStr="";
}

QString Metodo::getNombre()
{
    return this->nombre;
}

int Metodo::getAcceso()
{
    return this->acceso;
}

int Metodo::getTipo()
{
    return this->tipo;
}

bool Metodo::getEsArr()
{
    return this->esArr;
}

bool Metodo::getEsPrincipal()
{
    return this->getEsPrincipal();
}

int Metodo::getFila()
{
    return this->fila;
}

QString Metodo::getLienzoPadre()
{
    return this->lienzoPadre;
}

QList<Nodo> *Metodo::getParametros()
{
    return this->parametros;
}

QList<Nodo> *Metodo::getSentencias()
{
    return this->sentencias;
}

QString Metodo::getParamsToStr()
{
    return this->paramsToStr;
}

void Metodo::setLienzoPadre(QString lienzo)
{
    this->lienzoPadre = lienzo;
}

Metodo::Metodo(QString nombre, int acceso, int tipo, bool esArr, int fila, QList<Nodo> *parametros, QList<Nodo> *sentencias, QString paramsToStr)
{
    this->nombre=nombre;
    this->acceso=acceso;
    this->tipo = tipo;
    this->esArr = esArr;
    this->esPrincipal = false;
    this->fila =fila;
    this->parametros=parametros;
    this->sentencias=sentencias;
    this->paramsToStr=paramsToStr;
}

QString Metodo::getParamsToStr(QList<Nodo> *parametros)
{
    QString params = "";
    QString tempParams = "";
    foreach (Nodo nodo, *parametros) {
        params = tempParams +  TIPOS[nodo.getTipo()];
        tempParams = params + "-";
    }
    return params;
}

Metodo *Metodo::crearMetodo(QString nombre, int acceso, int tipof, int fila, QList<Nodo> *parametros, QList<Nodo> *sentencias)
{
    QString params = Metodo::getParamsToStr(parametros);
    bool esArr = false;
    int tipo = tipof;
    if(tipof>=6){
        esArr = true;
        tipo = tipof-6;
    }
    Metodo *metodo = new Metodo(nombre, acceso, tipo, esArr, fila, parametros, sentencias, params);
    return metodo;
}

Metodo *Metodo::crearPrincipal(int acceso, int fila, QList<Nodo> *sentencias)
{
    Metodo *metodo = new Metodo();
    metodo->nombre = "Principal";
    metodo->acceso= acceso;
    metodo->fila = fila;
    metodo->esPrincipal = true;
    metodo->sentencias = sentencias;
    return metodo;
}


