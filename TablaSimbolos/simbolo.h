#ifndef SIMBOLO_H
#define SIMBOLO_H
#include "Ast/nodo.h"
#include "Ast/metodo.h"
#include "Interprete/resultado.h"

class Simbolo
{
private:
    int rol;
    int acceso;
    int tipo;
    int nivel;
    QString nombre;
    QString valor;
    QString padre;
    QList<int> *dims;
    QList<QString> *valores;
    int contDims;
    bool esArr; //Usado para saber si el método retorna un arreglo
    bool instancia;
    QString paramsToString; //Usado para los métodos ;)

public:
    Simbolo();
    int getRol();
    int getAcceso();
    int getTipo();
    int getNivel();
    QString getNombre();
    QString getValor();
    QString getPadre();
    QList<int> *getDims();
    QList<QString> *getValores();
    int getContDims();
    bool getEsArr();
    bool getInstancia();
    QString getParamsToString();
    void setRol(int rol);
    void setAcceso(int acceso);
    void setTipo(int tipo);
    void setNivel(int nivel);
    void setNombre(QString nombre);
    void setValor(QString valor);
    void setPadre(QString padre);
    void setValores(QList<QString> *valores);
    void setContDims(int contDims);
    void setEsArr(bool esArr);
    void setDims(QList<Resultado> dims);
    void setInstancia(bool instancia);
    void setParamsToString(QString paramsToString);

    static QList<Simbolo> *crearArrs(QString padre, Nodo declaracion);
    static QList<Simbolo> *crearParams(QString padre, int acceso, QList<Nodo> params);
    static QList<Simbolo> *crearVars(QString padre, Nodo declaracion);
    //static QList<Simbolo> *crearMtd(QString padre, Metodo mtd);
    //static Simbolo *crearPrincipal(QString padre, int acceso);
    //static Simbolo *crearLienzo(QString nombre, int acceso);

};

#endif // SIMBOLO_H
