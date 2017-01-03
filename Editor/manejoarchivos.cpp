#include "manejoarchivos.h"
#include <QTextStream>
#include <QFile>

QString ManejoArchivos::RAIZ = "/home/sarina/QtProjects/Lienzo2D_200915291/Lienzo2D_200915291/Recursos/Lienzos/";

QString *ManejoArchivos::abrirArchivo(QString dir){
    QFile file(dir);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return NULL;
    QTextStream in(&file);
    QString *content = new QString("");
    while (!in.atEnd()) {
        QString line = in.readLine();
        content->append(line + "\n");
    }
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
