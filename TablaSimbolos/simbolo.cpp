#include "simbolo.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"
#include "Editor/manejoarchivos.h"
#include <QDateTime>

Simbolo::Simbolo()
{
    this->rol = ERR;
    this->acceso = ERR;
    this->tipo = ERR;
    this->nombre = "";
    this->valor = "";
    this->padre = "";
    this->dims = *new QList<int>();
    this->valores = *new QList<QString>();
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

QString Simbolo::getLienzo()
{
    return this->lienzo;
}

QString Simbolo::getPadre(){
    return this->padre;
}

QList<int> Simbolo::getDims(){
    return this->dims;
}

QList<QString> Simbolo::getValores(){
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

void Simbolo::setLienzo(QString lienzo)
{
    this->lienzo = lienzo;
}

void Simbolo::setValor(int pos, QString valor)
{
    this->valores.replace(pos, valor);
}

QString Simbolo::getValor(int pos)
{
    return this->valores.at(pos);
}


void Simbolo::setPadre(QString padre){
    this->padre = padre;
}

void Simbolo::setValores(QList<QString> valores){
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
        this->dims.append(Casteo::strToInt(dim.getValor()));
    }
}

void Simbolo::setInstancia(bool instancia){
    this->instancia = instancia;
}

void Simbolo::setParamsToString(QString paramsToString){
    this->paramsToString = paramsToString;
}

Simbolo *Simbolo::crearLienzo(QString lienzo, int acceso){
    Simbolo *lz = new Simbolo();
    lz->setNombre(lienzo);
    lz->setRol(RS_LIENZO);
    lz->setAcceso(acceso);
    return lz;
}

Simbolo *Simbolo::crearMtd(QString lienzo, QString padre, Metodo mtd)
{
    Simbolo *metodo = new Simbolo();
    metodo->setNombre(mtd.getNombre());
    metodo->setRol(RS_METODO);
    metodo->setAcceso(mtd.getAcceso());
    metodo->setPadre(padre);
    metodo->setLienzo(lienzo);
    metodo->setEsArr(mtd.getEsArr());
    metodo->setTipo(mtd.getTipo());
    metodo->setParamsToString(mtd.getParamsToStr());
    return metodo;
}


QList<Simbolo> *Simbolo::crearArrs(QString lienzo, QString padre, Nodo declaracion)
{
    QList<Simbolo> *arreglos = new QList<Simbolo>();
    Simbolo *arreglo;
    foreach (QString id, *declaracion.getIds()) {
        arreglo = new Simbolo();
        arreglo->setNombre(id);
        arreglo->setRol(RS_ARREGLO);
        arreglo->setLienzo(lienzo);
        arreglo->setAcceso(declaracion.getAcceso());
        arreglo->setPadre(padre);
        arreglo->setTipo(declaracion.getTipo());
        arreglo->setEsArr(true);
        arreglos->append(*arreglo);
    }
    return arreglos;
}


QList<Simbolo> *Simbolo::crearVars(QString lienzo, QString padre, Nodo declaracion)
{
    QList<Simbolo> *variables = new QList<Simbolo>();
    Simbolo *variable;
    foreach (QString id, *declaracion.getIds()) {
        variable = new Simbolo();
        variable->setNombre(id);
        variable->setLienzo(lienzo);
        variable->setRol(RS_VAR);
        variable->setAcceso(declaracion.getAcceso());
        variable->setPadre(padre);
        variable->setTipo(declaracion.getTipo());
        variables->append(*variable);
    }
    return variables;
}

QList<Simbolo> *Simbolo::crearParams(QString lienzo, QString padre, int acceso, QList<Nodo> params)
{
    QList<Simbolo> *parametros = new QList<Simbolo>();
    Simbolo *parametro;
    foreach (Nodo nodo, params) {
        parametro = new Simbolo();
        parametro->setNombre(nodo.getCadena());
        parametro->setRol(RS_PARAMETRO);
        parametro->setLienzo(lienzo);
        parametro->setAcceso(acceso);
        parametro->setPadre(padre);
        parametro->setTipo(nodo.getTipo());
        parametros->append(*parametro);
    }
    return parametros;
}


QString Simbolo::getHTML()
{
    if(this->tipo <=0){
        this->tipo = 0;
    }

    QString html = "<tr>\n";
    html = html + "\t<td>" + this->lienzo+ "</td>\n";
    html = html + "\t<td>" + this->padre + "</td>\n";
    html = html + "\t<td>" + ROLES[this->rol] + "</td>\n";
    html = html + "\t<td>" + ACCESOS[this->acceso] + "</td>\n";
    html = html + "\t<td>" + TIPOS[this->tipo] + "</td>\n";
    html = html + "\t<td>" + Casteo::boolToStr(this->esArr) + "</td>\n";
    html = html + "\t<td>" + this->nombre + "</td>\n";
    html = html + "\t<td>" + this->paramsToString + "</td>\n";
    return html + "</tr>\n";
}

void Simbolo::reporte(QList<Simbolo> ts, QString principal)
{
    QString contenido = ManejoArchivos::abrirArchivo(RUTA_PLANTILLA_TS);
    QString body  = "";
    foreach (Simbolo sim, ts) {
        body.append(sim.getHTML());
    }
    contenido = contenido.replace("__BODY__", body);
    contenido = contenido.replace("__FILE__", principal);
    contenido = contenido.replace("__DATE__", QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    ManejoArchivos::guardarArchivo(RUTA_TS, contenido);

}
