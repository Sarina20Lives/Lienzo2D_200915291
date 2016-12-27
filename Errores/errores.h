#ifndef ERRORES_H
#define ERRORES_H
#include "qlist.h"

class ErrorCompilador
{
    private:
        int tipo;
        int fila;
        QString ubicacion;
        QString descripcion;

    public:
        ErrorCompilador(QString descripcion, int fila, int tipo, QString ubicacion = "No disponible");
        QString getHTML();
};

class ManejoErrores
{

public:
    static ManejoErrores *getInstance();
    static ManejoErrores *getInstance(QString ubicacion);
    static ManejoErrores *resetInstance();
    static ManejoErrores *resetInstance(QString ubicacion);
    static ManejoErrores *singleton;
    void addError(QString descripcion);
    void addErrorLexico(QString descripcion, int fila);
    void addErrorSintactico(QString descripcion, int fila);
    void addErrorSemantico(QString descripcion, int fila);

private:
    ManejoErrores(QString ubicacion = "No disponible");
    QList<ErrorCompilador> *errores;
    QString ubicacion;

};

#endif // ERRORES_H
