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
        ErrorCompilador(){}
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
    static void addError(QString descripcion, QString ubicacion = singleton->ubicacion);
    static void addErrorLexico(QString descripcion, int fila, QString ubicacion = singleton->ubicacion);
    static void addErrorSintactico(QString descripcion, int fila, QString ubicacion = singleton->ubicacion);
    static void addErrorSemantico(QString descripcion, int fila, QString ubicacion = singleton->ubicacion);
    void generarReporte();

private:
    ManejoErrores(QString ubicacion = "No disponible");
    QList<ErrorCompilador> *errores;
    QString ubicacion;
    void addError(ErrorCompilador err);

};

#endif // ERRORES_H
