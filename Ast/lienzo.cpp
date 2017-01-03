#include "lienzo.h"
#include "General/constantes.h"
#include "Errores/errores.h"

Lienzo::Lienzo()
{
    this->nombre="";
    this->acceso = ERR;
    this->fila = ERR;
    this->esPrincipal = false;
    this->extends = new QList<QString>();
    this->variables = new QList<Nodo>();
    this->metodos = new QList<Metodo>();
}


void Lienzo::setAtributos(QString nombre, int acceso, int fila, QList<QString> *extends){
    this->nombre = nombre;
    this->acceso = acceso;
    this->fila = fila;
    this->extends = extends;
}

QString Lienzo::getNombre()
{
    return this->nombre;
}

int Lienzo::getAcceso()
{
    return this->acceso;
}

int Lienzo::getFila()
{
    return this->fila;
}

QList<QString> *Lienzo::getExtends()
{
    return this->extends;
}

QList<Nodo> *Lienzo::getVariables()
{
    return this->variables;
}

QList<Metodo> *Lienzo::getMetodos()
{
    return this->metodos;
}

QList<Metodo> *Lienzo::getMetodos(QString nombre, QString paramsToStr)
{
    QList<Metodo> *seleccionados = new QList<Metodo>();
    foreach (Metodo metodo, *this->metodos) {
        if(QString::compare(nombre,metodo.getNombre())==0 && QString::compare(paramsToStr,metodo.getParamsToStr())==0){
            seleccionados->append(metodo);
        }
    }
    return seleccionados;
}

void Lienzo::setEsPrincipal(bool esPrincipal)
{
    this->esPrincipal=esPrincipal;
}

void Lienzo::addMetodo(Metodo mtd)
{
    foreach (Metodo metodo, *this->metodos) {
        if(QString::compare(mtd.getNombre(), metodo.getNombre())==0 && QString::compare(metodo.getParamsToStr(), mtd.getParamsToStr())==0){
            ManejoErrores::addErrorSemantico("Metodo duplicado en la declaración de lienzo.", metodo.getFila());
            return;
        }
    }
    this->metodos->prepend(mtd);
}

void Lienzo::addVariable(Nodo var)
{
    foreach (Nodo variable, *this->variables){
        foreach (QString variableN, *variable.getIds()) {
            foreach (QString varN, *var.getIds()) {
                if(QString::compare(variableN, varN)==0){
                    ManejoErrores::addErrorSemantico("La variable '"+varN+"' ya ha sido declarada previamente, variable duplicada.", var.getFila());
                    var.getIds()->removeOne(varN);
                    if(var.getIds()->count() == 0){
                        return;
                    }
                }
            }
        }
    }
    this->variables->prepend(var);
}
