#include "contexto.h"
#include "Interprete/casteo.h"
#include "General/constantes.h"
#include "Interprete/resultado.h"
#include "Interprete/interprete.h"

Contexto::Contexto()
{
    this->contexto= new QList<Simbolo>();
    this->nivel = 0;
}

//Asumiendo que el contexto ya posee sus propias variables globales, ahora se desea hacer un merge con sus variables de los extendsC
void Contexto::agregarVariablesExtends(QString nombreL){
    QList<Lienzo> extends = Interprete::searchExtends(nombreL);
    Contexto *ctxTemp;
    foreach (Lienzo lienzo, extends) {
        ctxTemp=generarContextoGlobal(lienzo.getNombre());
        foreach (Simbolo var, *ctxTemp->getContexto()) {
            this->agregarVariable(var);
        }
    }
}

Contexto *Contexto::generarContextoGlobal(QString lienzo){
   Contexto *ctxG = new Contexto();
   Contexto *ctxL = new Contexto();
   Lienzo actual = Interprete::searchLienzo(lienzo);
   foreach (Nodo dec, *actual.getVariables()) {
       Interprete::ejecutarDeclaracion(lienzo, lienzo, ctxG, ctxL, dec, true);
   }
   return ctxG;
}


Contexto *Contexto::generarContextoLocal(QString padre, int acceso, QList<Nodo> params, QList<Resultado> valores){
    Contexto *temp = new Contexto();
    QList<Simbolo> *parametros = Simbolo::crearParams(padre, acceso, params);
    Resultado res = *new Resultado();
    int cont = 0;
    foreach (Simbolo nuevo, *parametros) {
        if(temp->existeVariable(nuevo.getNombre())){
            //TODO-ERROR-Duplicación de variables
            return new Contexto();
        }
        res = valores.at(cont);
        if(res.getTipo()!=ERR){
            nuevo.setInstancia("true");
            nuevo.setValor(res.getValor());
        }
        temp->contexto->append(nuevo);
    }
    return temp;
}

//Agregar una variable local o globales de un lienzo a partir de su nodo declaración y del resultado de su valor... en el contexto
//Global -> Lienzo = Padre
//Local ->Lienzo = nombre del lienzo actual, Padre = nombre del método donde se ha declarado
void Contexto::agregarVariables(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo declaracion){

    QList<Simbolo> *variables = Simbolo::crearVars(padre, declaracion);
    //Setear Valor
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, declaracion.getHijo(0) );
    valor = Casteo::toAsigVar(declaracion.getTipo(), valor);

    foreach (Simbolo sim, *variables) {
        if(existeVariable(sim.getNombre())){
           return;
        }
        if(valor.getTipo()!=ERR){
            sim.setValor(valor.getValor());
            sim.setInstancia(true);
        }
        sim.setNivel(this->getNivel());
        this->contexto->append(sim);
    }
}

void Contexto::agregarArreglos(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo declaracion){
    QList<Resultado> *dims = new QList<Resultado>();
    Resultado *unaDim;
    //Resolver Dimensiones de declaración, todas deben ser tipo entero
    foreach (Nodo dim, *declaracion.getHijo(0).getHijos()) {
        unaDim = Interprete::resolverExpresion(lienzo, ctxG, ctxL, dim);
        if(unaDim->getTipo()!=TENTERO){
            //TODO-ERROR-La dimensión que se quiere definir no es de tipo entero
            return;
        }
        dims->append(*unaDim);
    }

    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, declaracion.getHijo(1));
    if(valor.getTipo()!=ERR && dims->count()!=valor.getDimensiones().count()){
        //TODO-ERROR-La magnitud de los arreglos no corresponden
        return;
    }

    if(valor.getTipo()!=ERR){
        int pos = 0;
        QList<int> posiciones = valor.getDimensiones();
        foreach (Resultado dim, *dims) {
            if(posiciones.at(pos)<0 || posiciones.at(pos)>Casteo::strToInt(dim.getValor())){
                //TODO-ERROR-Indices fuera de la capacidad del arreglo
            }
            pos = pos+1;
        }
    }

    QList<Simbolo> *arreglos = Simbolo::crearArrs(padre, declaracion);
    foreach (Simbolo sim, *arreglos) {
        if(existeVariable(sim.getNombre())){
           return;
        }
        if(valor.getTipo()!=ERR){
            sim.setInstancia(true);
            sim.setValores(valor.getValores());
        }else{
            sim.setValores(Contexto::crearEspacios(*dims));
        }
        sim.setDims(*dims);
        sim.setNivel(this->getNivel());
        this->contexto->append(sim);
    }
}


QList<QString> Contexto::crearEspacios(QList<Resultado> dims){
    int capacidad = Contexto::obtenerCapacidad(dims);
    QList<QString> espacios = *new QList<QString>();
    for (int i = 0; i<capacidad; i++){
        espacios.append("");
    }
    return espacios;
}

int Contexto::obtenerCapacidad(QList<Resultado> dims){
    int capacidad = 1;
    foreach (Resultado dim, dims) {
        capacidad = capacidad * Casteo::strToInt(dim.getValor());
    }
    return capacidad;
}

int Contexto::obtenerCapacidad(QList<int> dims){
    int capacidad = 1;
    foreach (int dim, dims) {
        capacidad = capacidad * dim;
    }
    return capacidad;
}

int Contexto::obtenerPosicion(QList<Resultado> *posiciones, QList<int> dims){
    if(posiciones->count()==1){
        return Casteo::strToInt(posiciones->takeAt(0).getValor());
    }

    QList<int> poss = Contexto::obtenerPosiciones(posiciones);
    int capacidad = Contexto::obtenerCapacidad(dims);
    int pos = 0;
    int tempPos = 0;

    for (int i = 0; i< poss.count()-1; i++){
        capacidad = capacidad / dims.at(i);
        pos = tempPos + poss.at(i) * capacidad + poss.at(i+1);
        tempPos = pos - poss.at(i+1);
    }
    return pos;
}

QList<int> Contexto::obtenerPosiciones(QList<Resultado> *posiciones){
    QList<int> poss = *new QList<int>();
    foreach (Resultado ress, *posiciones) {
        poss.append(Casteo::strToInt(ress.getValor()));
    }
    return poss;
}

void Contexto::limpiarContexto()
{
    int cont = 0;
    foreach (Simbolo sim, *this->contexto) {
        if(sim.getNivel()==this->getNivel()){
            this->contexto->removeAt(cont);
        }
        cont = cont + 1;
    }
    this->disminuirNivel();
}

int Contexto::getNivel()
{
    return this->nivel;
}

QList<Simbolo> *Contexto::getContexto()
{
    return this->contexto;
}

void Contexto::setNivel(int nivel)
{
    this->nivel = nivel;
}

void Contexto::aumentarNivel()
{
    this->nivel = this->nivel + 1;
}

void Contexto::disminuirNivel()
{
    this->nivel = this->nivel-1;
}

Simbolo Contexto::getVariable(QString nombre)
{
    foreach (Simbolo sim, *this->contexto) {
        if(QString::compare(sim.getNombre(), nombre)){
            return sim;
        }
    }
    return *new Simbolo();
}


bool Contexto::existeVariable(QString nombre){
    foreach (Simbolo sim, *this->contexto) {
        if(QString::compare(sim.getNombre(), nombre)==0){
            //TODO-ERROR-Duplicación de variables
            return true;
        }
    }
    return false;
}

void Contexto::agregarVariable(Simbolo sim)
{
    int cont = 0;
    foreach (Simbolo var, *this->contexto) {
        if(var.getNombre() == sim.getNombre()){
            if(var.getAcceso()>A_PRI){
                //TODO:WARNING-LA VARIABLE PRESENTA DUPLICACION
                return;
            }
            if(sim.getAcceso()>A_PRI && sim.getAcceso()!=A_PRI_CON){
                this->contexto->replace(cont, sim);
                return;
            }else{
                //TODO:WARNING-LA VARIABLE PRESENTA DUPLICACION
                return;
            }
        }
        cont = cont + 1;
    }
    this->contexto->append(sim);
}






