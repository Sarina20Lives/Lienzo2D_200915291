#ifndef RESULTADO_H
#define RESULTADO_H
#include <QString>
#include <QList>
#include "Ast/lienzo.h"


class Resultado
{
private:
    int rol;
    int tipo;
    QString valor;
    QList<QString> valores;
    bool esArr;
    QList<int> dimensiones;

    
public:
    Resultado();
    static QList<Lienzo> *lienzos;
    int getRol();
    int getTipo();
    QString getValor();
    QList<QString> getValores();
    bool getEsArr();
    QList<int> getDimensiones();
    void setRol(int rol);
    void setTipo(int tipo);
    void setValor(QString valor);
    void setValores(QList<QString> valores);
    void setEsArr(bool esArr);
    void setDimensiones(QList<int> dimensiones);


    //Expresion

    
    void addValores(QList<QString> valores);
    void addValor(QString valor);
    void preDimension(int dim);
};

#endif // RESULTADO_H
