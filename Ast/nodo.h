#ifndef NODO_H
#define NODO_H
#include <QString>
#include <QList>

class Nodo
{
private:
    // Atributos
    int rol;
    int subrol;
    int acceso;
    QString cadena;
    int tipo;
    QList<QString> *ids;
    QList<Nodo> *hijos;
    int fila;

    // Constructores
    Nodo(int rol, int subrol, QString cadena, int tipo, QList<QString> *ids, QList<Nodo> *hijos, int fila);
    Nodo(int rol, int subrol, QString cadena, int tipo, int fila);

public:
    // Constructores
    Nodo();

    // Acceso a Atributos
    int getRol();
    int getSubRol();
    int getAcceso();
    QString getCadena();
    int getTipo();
    QList<Nodo> *getHijos();
    Nodo getHijo(int indice);
    QList<QString> *getIds();
    int getFila();

    // Agregando atributos
    static QList<Nodo> *iniciarHijos();
    static QList<Nodo> *iniciarHijos(Nodo hijo);
    static QList<Nodo> *addHijo(QList<Nodo> *lista, Nodo hijo);
    static QList<Nodo> *preHijo(QList<Nodo> *lista, Nodo hijo);
    static QList<QString> *iniciarIds();
    static QList<QString> *iniciarIds(QString id);
    static QList<QString> *addId(QList<QString> *lista, QString id);
    static QList<QString> *preId(QList<QString> *lista, QString id);

    //Expresiones
    static Nodo *crearOperando(QString cadena, int tipo, int fila);
    static Nodo *crearEntero(QString cadena, int fila);
    static Nodo *crearDoble(QString cadena, int fila);
    static Nodo *crearCadena(QString cadena, int fila);
    static Nodo *crearCaracter(QString cadena, int fila);
    static Nodo *crearBoolean(QString cadena, int fila);
    static Nodo *crearVar(QString cadena, int fila);
    static Nodo *crearArr(QString cadena, QList<Nodo> dimensiones, int fila);
    static Nodo *crearRefArr(QString cadena, int fila);
    static Nodo *crearRefArr(QList<Nodo> refs, int fila);


    static Nodo *crearAritmetica(int subrol, QString cadena, Nodo op1, Nodo op2, int fila);
    static Nodo *crearPow(Nodo op1, Nodo op2, int fila);
    static Nodo *crearDiv(Nodo op1, Nodo op2, int fila);
    static Nodo *crearMul(Nodo op1, Nodo op2, int fila);
    static Nodo *crearSub(Nodo op1, Nodo op2, int fila);
    static Nodo *crearSum(Nodo op1, Nodo op2, int fila);

    static Nodo *crearRelacional(int subrol, QString cadena, Nodo op1, Nodo op2, int fila);
    static Nodo *crearIgual(Nodo op1, Nodo op2, int fila);
    static Nodo *crearDiferente(Nodo op1, Nodo op2, int fila);
    static Nodo *crearMen(Nodo op1, Nodo op2, int fila);
    static Nodo *crearMenIgual(Nodo op1, Nodo op2, int fila);
    static Nodo *crearMay(Nodo op1, Nodo op2, int fila);
    static Nodo *crearMayIgual(Nodo op1, Nodo op2, int fila);
    static Nodo *crearNulo(QString cadena, int fila);

    static Nodo *crearLogica(int subrol, QString cadena, Nodo op1, Nodo op2, int fila);
    static Nodo *crearAnd(Nodo op1, Nodo op2, int fila);
    static Nodo *crearNand(Nodo op1, Nodo op2, int fila);
    static Nodo *crearOr(Nodo op1, Nodo op2, int fila);
    static Nodo *crearNor(Nodo op1, Nodo op2, int fila);
    static Nodo *crearXor(Nodo op1, Nodo op2, int fila);
    static Nodo *crearNot(Nodo op1, int fila);

    //Sentencias
    static Nodo *crearLlamada(QString cadena, QList<Nodo> params, int fila);
    static Nodo *crearSentencia(QList<Nodo> sentencias);
    static Nodo *crearDimensiones(QList<Nodo> *dims);
    static Nodo *crearOrdenar(QString cadena, int forma, int fila);
    static Nodo *crearSumarizar(Nodo refArr, int fila);
    static Nodo *crearPintarS(Nodo posX, Nodo posY, Nodo color, Nodo cadena, int fila);
    static Nodo *crearPintarOR(Nodo posX, Nodo posY, Nodo color, Nodo ancho, Nodo alto, Nodo figura, int fila);
    static Nodo *crearPintarP(Nodo posX, Nodo posY, Nodo color, Nodo diametro, int fila);
    static Nodo *crearPara(Nodo inicio, Nodo cond, Nodo variacion, QList<Nodo> sentencias, int fila);
    static Nodo *crearMientras(Nodo cond, QList<Nodo> sentencias, int fila);
    static Nodo *crearHacer(Nodo cond, QList<Nodo> sentencias, int fila);

    static Nodo *asigArr(int subrol, QString cadena, QList<Nodo> *dims, int fila);
    static Nodo *asigArrDir(QString cadena, QList<Nodo> *dims, Nodo exp, int fila);
    static Nodo *asigArrInc(QString cadena, QList<Nodo> *dims, int fila);
    static Nodo *asigArrDec(QString cadena, QList<Nodo> *dims, int fila);
    static Nodo *asigArrSumSimply(QString cadena, QList<Nodo> *dims, Nodo exp, int fila);
    static Nodo *asigArrSubSimply(QString cadena, QList<Nodo> *dims, Nodo exp, int fila);

    static Nodo *asigVar(int subrol, QString cadena, int fila);
    static Nodo *asigVarDir(QString cadena, Nodo exp, int fila);
    static Nodo *asigVarInc(QString cadena,int fila);
    static Nodo *asigVarDec(QString cadena, int fila);
    static Nodo *asigVarSumSimply(QString cadena, Nodo exp, int fila);
    static Nodo *asigVarSubSimply(QString cadena, Nodo exp, int fila);

    static QList<Nodo> *crearCasos(QList<Nodo> sentDefecto, int fila);
    static QList<Nodo> *crearCasos(Nodo cond, QList<Nodo> sentCaso, int fila);
    static QList<Nodo> *preCasos(QList<Nodo> *lista, Nodo cond, QList<Nodo> sentCaso, int fila);
    static Nodo *crearCaso(Nodo cond, QList<Nodo> sentencias, int fila);
    static Nodo *crearComprobar(Nodo cond, QList<Nodo> casos, int fila);
    static Nodo *crearSi( Nodo cond, QList<Nodo> sentSi, Nodo sentSino, int fila);
    static Nodo *decArr(int acceso, int tipo, QList<QString> *ids, QList<Nodo> *dims, Nodo iniArr, int fila);
    static Nodo *crearSalir(int fila);
    static Nodo *crearContinuar(int fila);
    static Nodo *crearRetorno(Nodo ret, int fila);
    static QList<Nodo> *agregarPausa(QList<Nodo> *lista, int fila);
    static Nodo *decVar(QString id, int tipo, Nodo exp, int fila);
    static Nodo *decVar(int acceso, QList<QString> *ids, int tipo, Nodo exp, int fila);
    static Nodo *decParam(QString id, int tipo, int fila);

};

#endif // NODO_H
