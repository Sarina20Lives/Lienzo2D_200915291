#include "qlist.h"
#include "qfile.h"
#include "qtextstream.h"
#include "errores.h"
#include "General/constantes.h"
#include "Editor/manejoarchivos.h"

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Patrón de diseño singleton
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

ManejoErrores *ManejoErrores::singleton = NULL;

ManejoErrores *ManejoErrores::getInstance()
{
    if(singleton == NULL)
    {
        singleton = new ManejoErrores;
    }
    return singleton;
}

ManejoErrores *ManejoErrores::resetInstance()
{
    singleton = new ManejoErrores;
    return singleton;
}

ManejoErrores *ManejoErrores::getInstance(QString ubicacion)
{
    singleton = getInstance();
    singleton->ubicacion = ubicacion;
    return singleton;
}

ManejoErrores *ManejoErrores::resetInstance(QString ubicacion)
{
    singleton = new ManejoErrores(ubicacion);
    return singleton;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Definición de la clase ManejoErrores
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

ManejoErrores::ManejoErrores(QString ubicacion)
{
    this->errores = new QList<ErrorCompilador>;
    this->ubicacion = ubicacion;
}

void ManejoErrores::addError(QString descripcion, QString ubicacion)
{
    ErrorCompilador nuevo = ErrorCompilador(descripcion, -1, ERR_GENERAL, ubicacion);
    singleton->addError(nuevo);
}

void ManejoErrores::addErrorLexico(QString descripcion, int fila, QString ubicacion)
{
    ErrorCompilador nuevo = ErrorCompilador(descripcion, fila, ERR_LEXICO, ubicacion);
    singleton->addError(nuevo);
}

void ManejoErrores::addErrorSintactico(QString descripcion, int fila, QString ubicacion)
{
    ErrorCompilador nuevo = ErrorCompilador(descripcion, fila, ERR_SINTACTICO, ubicacion);
    singleton->addError(nuevo);
}

void ManejoErrores::addErrorSemantico(QString descripcion, int fila, QString ubicacion)
{
    ErrorCompilador nuevo = ErrorCompilador(descripcion, fila, ERR_SEMANTICO, ubicacion);
    singleton->addError(nuevo);
}

void ManejoErrores::addError(ErrorCompilador err)
{
    this->errores->append(err);
}

void ManejoErrores::generarReporte()
{
    QString *contenido = ManejoArchivos::abrirArchivo(RUTA_PLANTILLA_ERR);
    QString c(contenido->toUtf8());
    QString body = "";
    foreach (ErrorCompilador err, *this->errores) {
        body.append(err.getHTML());
    }
    c = c.replace("__BODY__", body);
    ManejoArchivos::guardarArchivo(RUTA_ERR, c);
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Definición de la clase ErrorCompilador
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

ErrorCompilador::ErrorCompilador(QString descripcion, int fila, int tipo, QString ubicacion)
{
    this->descripcion = descripcion;
    this->fila = fila;
    this->tipo = tipo;
    this->ubicacion = ubicacion;
}

QString ErrorCompilador::getHTML()
{
    QString html = "<tr>\n";
    html = html + "\t<td>" + ERRORES[this->tipo] + "</td>\n";
    html = html + "\t<td>" + this->descripcion + "</td>\n";
    html = html + "\t<td>" + this->ubicacion + "</td>\n";
    if(this->fila==-1)
        html = html + "\t<td> No aplica </td>\n";
    else
        html = html + "\t<td>" + QString::number(this->fila) + "</td>\n";
    return html + "</tr>\n";
}
