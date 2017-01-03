#ifndef INTERPRETE_H
#define INTERPRETE_H
#include <QString>
#include <QList>
#include "Ast/lienzo.h"
#include "Ast/metodo.h"
#include "Ast/nodo.h"
#include "Interprete/resultado.h"
#include "TablaSimbolos/contexto.h"
#include "Errores/errores.h"

class Interprete
{
private:
    static bool debuggeando;
    static bool pausa;
    static int tiempoPausa;
public:
    static void activarDebug() { debuggeando = true; }
    static void desactivarDebug() { debuggeando = false; pausa = false; tiempoPausa = 0; }
    static void setPausa(int tiempo) { tiempoPausa = tiempo; }
    static void triggerDebug() { pausa = debuggeando ? !pausa : pausa; }
    static QList<Lienzo> *lienzos;
    static Lienzo searchLienzo(QString nombre);
    static QList<Lienzo> searchExtends(QString nombre);
    static Metodo searchMetodoConservar(QList<Metodo> metds);
    static QList<Metodo> searchMetodoExtend(QString lienzoActual, QString nombre, QString paramsToStr);
    static Metodo searchMetodo(QString nombreL, QString nombre, QString paramsToStr);
    static Resultado searchVariable(QString nombreL, QString nombre, QString paramsToStr);

    static Resultado *resolverExpresion(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverOperando(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *buscarValVar(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre, int fila);
    static Resultado *resolverRefArr(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverValArr(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo valArr);
    static Resultado *buscarArr(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre, int fila);
    static QString getParamsToString(QList<Resultado> params);
    static Resultado *resolverLlamada(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverAritmetica(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverSum(Resultado op1, Resultado op2);
    static Resultado *resolverSub(Resultado op1, Resultado op2);
    static Resultado *resolverMul(Resultado op1, Resultado op2);
    static Resultado *resolverDiv(Resultado op1, Resultado op2, int fila);
    static Resultado *resolverPow(Resultado op1, Resultado op2);
    static Resultado *resolverLogica(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverNot(Resultado op1);
    static Resultado *resolverAnd(Resultado op1, Resultado op2);
    static Resultado *resolverNand(Resultado op1, Resultado op2);
    static Resultado *resolverOr(Resultado op1, Resultado op2);
    static Resultado *resolverNor(Resultado op1, Resultado op2);
    static Resultado *resolverXor(Resultado op1, Resultado op2);
    static Resultado *resolverRelacional(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverNulo(Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverIgual(Resultado op1, Resultado op2);
    static Resultado *resolverDiferente(Resultado op1, Resultado op2);
    static Resultado *resolverMen(Resultado op1, Resultado op2);
    static Resultado *resolverMenIgual(Resultado op1, Resultado op2);
    static Resultado *resolverMay(Resultado op1, Resultado op2);
    static Resultado *resolverMayIgual(Resultado op1, Resultado op2);

    static Resultado *ejecutarMtd(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Metodo mtd);
    static void ejecutarPrincipal(QString lienzo);
    static void ejecutarDeclaracion(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo dec, bool esGlobal);
    static Resultado *ejecutarSentencia(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo sentencia);
    static Simbolo buscarSimboloArr(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre);
    static Resultado *buscarValArr(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp);
    static Resultado *resolverAsigVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static void asigDecVar(Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static void asigIncVar(Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static void asigDirectaVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static void asigSumSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static void asigSubSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static Resultado *ejecutarWhile(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo);
    static Resultado *ejecutarIf(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo);
    static Resultado *resolverRetorna(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo sentencia);
    static Resultado *resolverSalir();
    static Resultado *resolverContinuar();
    static Resultado *ejecutarHacer(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo);
    static Resultado *ejecutarPara(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo);
    static Resultado *asigDirectaArr(QString nombre, int fila, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL);
    static Resultado *resolverAsigArr(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig);
    static Resultado *asigSumSimplyArr(QString nombre, int fila, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL);
    static Resultado *asigSubSimplyArr(QString nombre, int fila, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL);
    static Resultado *asigIncArr(QString nombre, int fila, QList<Resultado> *dims, Contexto *ctxG, Contexto *ctxL);
    static Resultado *asigDecArr(QString nombre, int fila, QList<Resultado> *dims, Contexto *ctxG, Contexto *ctxL);
    static void asigArrArr(Contexto *ctxG, Contexto *ctxL, QString nombre, int fila, Resultado arr);
    static QList<QString> ascValores(QList<QString> original, int tipo);
    static QList<QString> descValores(QList<QString> original, int tipo);
    static Resultado *resolverOrdenar(Contexto *ctxG, Contexto *ctxL, Nodo ordenar);
    static QList<QString> parImparValores(QList<QString> original, int tipo, int fila, bool parImpar);
    static QList<QString> primosValores(QList<QString> original, int tipo, int fila);
    static QString sumarizarValores(QList<QString> valores, int tipo);
    static Resultado *resolverSumarizar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo ordenar);
    static Resultado *ejectuarComprobar(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo);
    static void pintarS(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func);
    static void pintarOR(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func);
    static void pintarP(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func);
    static void ejecutarPrimitiva(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func);
};

#endif // INTERPRETE_Hpo
