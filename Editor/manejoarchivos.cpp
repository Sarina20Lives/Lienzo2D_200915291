#include "manejoarchivos.h"
#include <QTextStream>

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
