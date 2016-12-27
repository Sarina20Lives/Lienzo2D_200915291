#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H
#include <QString>

class ManejoArchivos
{
public:
    static QString abrirArchivo(QString dir);
    static void guardarArchivo(QString path, QString content);
};

#endif // MANEJOARCHIVOS_H
