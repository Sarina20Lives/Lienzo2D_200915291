#ifndef METODO_H
#define METODO_H
#include <QString>
#include <QList>
#include "Ast/nodo.h"

class Metodo
{
private:
    // Atributos
    QString nombre;
    int acceso;
    int tipo;
    bool esArr;
    bool esPrincipal;
    int fila;
    QList<Nodo> *parametros;
    QList<Nodo> *sentencias;
    QString paramsToStr;
    QString lienzoPadre;

public:
    Metodo();
    QString getNombre();
    int getAcceso();
    int getTipo();
    bool getEsArr();
    bool getEsPrincipal();
    int getFila();
    QString getLienzoPadre();
    QList<Nodo> *getParametros();
    QList<Nodo> *getSentencias();
    QString getParamsToStr();

    void setLienzoPadre(QString lienzo);

    Metodo(QString nombre, int acceso, int tipo, bool esArr, int fila, QList<Nodo> *parametros, QList<Nodo> *sentencias, QString paramsToStr);
    static QString getParamsToStr(QList<Nodo> *parametros);
    static Metodo *crearMetodo(QString nombre, int acceso, int tipof, int fila, QList<Nodo> *parametros, QList<Nodo> *sentencias);
    static Metodo *crearPrincipal(int acceso, int fila, QList<Nodo> *sentencias);




};

#endif // METODO_H
