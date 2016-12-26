#include "resultado.h"
#include "General/constantes.h"


Resultado::Resultado()
{
    this->rol = NOTHING;
    this->valor = "";
    this->valores = new QList<QString>();
    this->esArr = false;
    this->dimensiones = *new QList<int>();
    this->tipo = ERR;
}



int Resultado::getRol()
{
    return this->rol;
}

int Resultado::getTipo(){
    return this->tipo;
}

QString Resultado::getValor()
{
    return this->valor;
}

QList<QString> *Resultado::getValores()
{
    return this->valores;
}

void Resultado::addValores(QList<QString> valores){
    this->valores->append(valores);
}

bool Resultado::getEsArr()
{
    return this->esArr;
}

QList<int> Resultado::getDimensiones()
{
    return this->dimensiones;
}

void Resultado::setRol(int rol)
{
    this->rol = rol;
}

void Resultado::setTipo(int tipo)
{
    this->tipo = tipo;
}

void Resultado::setValor(QString valor)
{
    this->valor = valor;
}

void Resultado::setValores(QList<QString> *valores)
{
    this->valores = valores;
}

void Resultado::setEsArr(bool esArr)
{
    this->esArr = esArr;
}

void Resultado::setDimensiones(QList<int> dimensiones)
{
    this->dimensiones = dimensiones;
}


