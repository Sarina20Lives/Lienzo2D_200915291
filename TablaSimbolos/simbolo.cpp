#include "simbolo.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Simbolo::Simbolo()
{
    this->rol = ERR;
    this->acceso = ERR;
    this->tipo = ERR;
    this->nombre = "";
    this->valor = "";
    this->padre = "";
    this->dims = new QList<int>();
    this->valores = new QList<QString>();
    this->contDims = 0;
    this->esArr = false;
    this->instancia = false;
    this->paramsToString = "";
}

int Simbolo::getRol(){
    return this->rol;
}

int Simbolo::getAcceso(){
    return this->acceso;
}

int Simbolo::getTipo(){
    return this->tipo;
}

int Simbolo::getNivel()
{
    return this->nivel;
}

QString Simbolo::getNombre(){
    return this->nombre;
}

QString Simbolo::getValor(){
    return this->valor;
}

QString Simbolo::getPadre(){
    return this->padre;
}

QList<int> *Simbolo::getDims(){
    return this->dims;
}

QList<QString> *Simbolo::getValores(){
    return this->valores;
}

int Simbolo::getContDims(){
    return this->contDims;
}

bool Simbolo::getEsArr(){
    return this->esArr;
}

bool Simbolo::getInstancia(){
    return this->instancia;
}

QString Simbolo::getParamsToString(){
    return this->paramsToString;
}

void Simbolo::setRol(int rol){
    this->rol = rol;
}

void Simbolo::setAcceso(int acceso){
    this->acceso = acceso;
}

void Simbolo::setTipo(int tipo){
    this->tipo = tipo;
}

void Simbolo::setNivel(int nivel)
{
    this->nivel = nivel;
}

void Simbolo::setNombre(QString nombre){
    this->nombre = nombre;
}

void Simbolo::setValor(QString valor){
    this->valor = valor;
}

void Simbolo::setPadre(QString padre){
    this->padre = padre;
}

void Simbolo::setValores(QList<QString> *valores){
    this->valores = valores;
}

void Simbolo::setContDims(int contDims){
    this->contDims = contDims;
}

void Simbolo::setEsArr(bool esArr){
    this->esArr = esArr;
}

void Simbolo::setDims(QList<Resultado> dims)
{
    foreach (Resultado dim, dims) {
        this->dims->append(Casteo::strToInt(dim.getValor()));
    }
}

void Simbolo::setInstancia(bool instancia){
    this->instancia = instancia;
}

void Simbolo::setParamsToString(QString paramsToString){
    this->paramsToString = paramsToString;
}

QList<Simbolo> *Simbolo::crearArrs(QString padre, Nodo declaracion)
{
    QList<Simbolo> *arreglos = new QList<Simbolo>();
    Simbolo *arreglo;
    foreach (QString id, *declaracion.getIds()) {
        arreglo = new Simbolo();
        arreglo->setNombre(id);
        arreglo->setRol(RN_ARR);
        arreglo->setAcceso(declaracion.getAcceso());
        arreglo->setPadre(padre);
        arreglo->setTipo(declaracion.getTipo());
        arreglo->setEsArr(true);
        arreglos->append(*arreglo);
    }
    return arreglos;
}


QList<Simbolo> *Simbolo::crearVars(QString padre, Nodo declaracion)
{
    QList<Simbolo> *variables = new QList<Simbolo>();
    Simbolo *variable;
    foreach (QString id, *declaracion.getIds()) {
        variable = new Simbolo();
        variable->setNombre(id);
        variable->setRol(RN_VAR);
        variable->setAcceso(declaracion.getAcceso());
        variable->setPadre(padre);
        variable->setTipo(declaracion.getTipo());
        variables->append(*variable);
    }
    return variables;
}

QList<Simbolo> *Simbolo::crearParams(QString padre, int acceso, QList<Nodo> params)
{
    QList<Simbolo> *parametros = new QList<Simbolo>();
    Simbolo *parametro;
    foreach (Nodo nodo, params) {
        parametro = new Simbolo();
        parametro->setNombre(nodo.getCadena());
        parametro->setRol(SRN_PARAM);
        parametro->setAcceso(acceso);
        parametro->setPadre(padre);
        parametro->setTipo(nodo.getTipo());
        parametros->append(*parametro);
    }
    return parametros;
}
