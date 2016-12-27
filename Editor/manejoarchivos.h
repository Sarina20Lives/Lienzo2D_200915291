#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H
#include <QString>

class ManejoArchivos
{
public:
    static QString abrirArchivo(QString dir);
    static void guardarArchivo(QString dir, QString contenido);
};

#endif // MANEJOARCHIVOS_H
