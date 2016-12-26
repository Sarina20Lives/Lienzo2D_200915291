#ifndef CONTEXTO_H
#define CONTEXTO_H
#include "TablaSimbolos/simbolo.h"
#include "Interprete/resultado.h"
#include <QList>

class Contexto
{
private:
    QList<Simbolo> *contexto;
    int nivel;
public:
    Contexto();
    void agregarVariablesExtends(QString nombreL);
    static Contexto *generarContextoGlobal(QString lienzo);
    static Contexto *generarContextoLocal(QString padre, int acceso, QList<Nodo> params, QList<Resultado> valores);
    void agregarVariables(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo declaracion);
    void limpiarContexto();
    int getNivel();
    QList<Simbolo> *getContexto();
    void setNivel(int nivel);
    void aumentarNivel();
    void disminuirNivel();
    Simbolo getVariable(QString nombre);
    bool existeVariable(QString nombre);
    void agregarVariable(Simbolo sim);
    void agregarArreglos(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo declaracion);
    static QList<QString> crearEspacios(QList<Resultado> dims);
    static int obtenerCapacidad(QList<Resultado> dims);
    static int obtenerCapacidad(QList<int> dims);
    static int obtenerPosicion(QList<Resultado> *posiciones, QList<int> dims);
    static QList<int> obtenerPosiciones(QList<Resultado> *posiciones);
};


#endif // CONTEXTO_H
