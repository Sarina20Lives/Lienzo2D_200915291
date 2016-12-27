#include "manejoarchivos.h"
#include <QTextStream>
#include <QFile>

QString ManejoArchivos::abrirArchivo(QString dir){
    QByteArray ba = dir.toLatin1();
    char *acceso = ba.data();

    FILE* file = fopen(acceso, "r+t");
    if (file==NULL)
        return "";
    QString content = "";
    while (feof(file)==0){
        content = content + QChar(fgetc(file));
    }
    fclose(file);
    return content;
}

void ManejoArchivos::guardarArchivo(QString dir, QString contenido)
{
    QByteArray ba = dir.toLatin1();
    char *acceso = ba.data();

    FILE* f = fopen(acceso, "w+r");
    if(f!=NULL){
        fprintf(f, "%s", contenido.toUtf8().data());
        fclose(f);
    }
}
