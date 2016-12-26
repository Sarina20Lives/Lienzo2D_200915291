#ifndef LIENZO_H
#define LIENZO_H
#include <QString>
#include <QList>
#include "Ast/nodo.h"
#include "Ast/metodo.h"

class Lienzo
{
private:
    QString nombre;
    int acceso;
    int fila;
    bool esPrincipal;
    QList<QString> *extends;
    QList<Nodo> *variables;
    QList<Metodo> *metodos;

public:
    Lienzo();
    void setAtributos(QString nombre, int acceso, int fila, QList<QString> *extends);
    QString getNombre();
    int getAcceso();
    int getFila();
    QList<QString> *getExtends();
    QList<Nodo> *getVariables();
    QList<Metodo> *getMetodos();
    QList<Metodo> *getMetodos(QString nombre, QString paramsToStr);
    void setEsPrincipal(bool esPrincipal);
    void addMetodo(Metodo mtd);
    void addVariable(Nodo var);

};

#endif // LIENZO_H
