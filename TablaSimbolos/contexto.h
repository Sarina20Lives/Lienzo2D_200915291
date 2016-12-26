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
};


#endif // CONTEXTO_H
