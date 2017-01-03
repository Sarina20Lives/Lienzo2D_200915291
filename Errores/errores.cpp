#include "qlist.h"
#include "qfile.h"
#include "qtextstream.h"
#include "errores.h"
#include "General/constantes.h"

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
    QFile file("/home/esvux/errores.html");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       return;
    QTextStream out(&file);
    out << "<!DOCTYPE html>";
    out << "<html>";
    out << "<head>";
    out << "	<meta charset='utf-8'>";
    out << "	<title>Reporte de errores</title>";
    out << "</head>";
    out << "<body>";
    out << "	<div class='container'>";
    out << "		<table>";
    out << "			<thead>";
    out << "				<tr>";
    out << "					<th>Tipo</th>";
    out << "					<th>Descripción</th>";
    out << "					<th>Lienzo</th>";
    out << "					<th>Fila</th>";
    out << "				</tr>";
    out << "			</thead>";
    out << "            <tbody>";
    foreach (ErrorCompilador err, *this->errores) {
        out << err.getHTML();
    }
    out << "            </tbody>";
    out << "		</table>";
    out << "	</div>";
    out << "</body>";
    out << "</html>";
    file.close();
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
        html = html + "\t<td>" + this->fila+ "</td>\n";
    return html + "</tr>\n";
}
