#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::resolverExpresion(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    if(exp.getRol() == RN_ARITMETICA){
        return Interprete::resolverAritmetica(lienzo, ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_RELACIONAL){
        return Interprete::resolverRelacional(lienzo, ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_LOGICA){
        return Interprete::resolverLogica(lienzo, ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_OPERANDO){
        return Interprete::resolverOperando(lienzo, ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_REF_ARR){
        return Interprete::resolverRefArr(lienzo, ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_LLAMADA){
        return Interprete::resolverLlamada(lienzo, ctxGlobal, ctxLocal, exp);
    }
    return new Resultado();
}

Resultado *Interprete::resolverOperando(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();
    if(exp.getSubRol()==SRN_OPERANDO){
        resultado->setTipo(exp.getTipo());
        resultado->setValor(exp.getCadena());
        return resultado;
    }
    if(exp.getSubRol()==SRN_VAR){
        resultado = Interprete::resolverRefArr(lienzo, ctxGlobal, ctxLocal, exp);
        if(resultado->getTipo()==ERR){
            return buscarValVar(ctxGlobal, ctxLocal, exp.getCadena());
        }
    }
    if(exp.getSubRol()==SRN_ARR){
        return buscarValArr(lienzo, ctxGlobal, ctxLocal, exp);
    }
    return resultado;
}


Resultado *Interprete::buscarValArr(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    //Resolver dimensiones...
    QList<Resultado> *dims = new QList<Resultado>();
    Resultado *dim;
    foreach (Nodo nodo, *exp.getHijos()) {
        dim = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, nodo);
        if(dim->getTipo()!=TENTERO){
            //TODO-ERROR-Error al querer obtener los valores de las dimensiones
            return new Resultado();
        }
        dims->append(*dim);
    }

    //Buscar arreglo:
    Simbolo arreglo = Interprete::buscarSimboloArr(ctxGlobal, ctxLocal, exp.getCadena());
    if(arreglo.getTipo()==ERR){
        //TODO-ERROR-El arreglo no existe ;)
        return new Resultado();
    }

    //Comprobar la cantidad de dimensiones:
    if(arreglo.getDims().count()!=dims->count()){
        //TODO-ERROR-Las dimensiones no corresponden al arreglo
        return new Resultado();
    }
    int cont = 0;
    foreach (Resultado res, *dims) {
        if(Casteo::strToInt(res.getValor())<0 || Casteo::strToInt(res.getValor())>arreglo.getDims().at(cont)){
            //TODO-ERROR-Los indices se encuentran fuera de los limites permitidos
            return new Resultado();
        }
        cont = cont + 1;
    }
    int pos= Contexto::obtenerPosicion(dims, arreglo.getDims());
    if(!arreglo.getInstancia() && QString::compare(arreglo.getValores().at(pos),"")==0){
        //TODO-ERROR-Se hace referencia a una posición de arreglo no definida
        return new Resultado();
    }

    Resultado *resultado = new Resultado();
    resultado->setTipo(arreglo.getTipo());
    resultado->setValor(arreglo.getValores().at(pos));
    return resultado;
}


Simbolo Interprete::buscarSimboloArr(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre){
    Simbolo arreglo = *new Simbolo();
    foreach (Simbolo simbolo, *ctxLocal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && simbolo.getEsArr()){
            return simbolo;
        }
    }
    foreach (Simbolo simbolo, *ctxGlobal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && simbolo.getEsArr()){
                return simbolo;
        }
    }
    return arreglo;
}

Resultado *Interprete::buscarValVar(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre){
    Resultado *resultado = new Resultado();
    foreach (Simbolo simbolo, *ctxLocal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && !simbolo.getEsArr()){
            if(!simbolo.getInstancia()){
                //TODO-ERROR-La variable no ha sido instanciada previamente
                return resultado;
            }
            resultado->setTipo(simbolo.getTipo());
            resultado->setValor(simbolo.getValor());
            return resultado;
        }
    }

    foreach (Simbolo simbolo, *ctxGlobal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && !simbolo.getEsArr()){
            if(!simbolo.getInstancia()){
                //TODO-ERROR-La variable no ha sido instanciada previamente
                return resultado;
            }
            resultado->setTipo(simbolo.getTipo());
            resultado->setValor(simbolo.getValor());
            return resultado;
        }
    }
    return resultado;
}

Resultado *Interprete::resolverRefArr(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();
    if(exp.getSubRol()==SRN_ARR || exp.getSubRol()==SRN_VAR){
        return Interprete::buscarArr(ctxGlobal, ctxLocal, exp.getCadena());
    }
    if(exp.getSubRol()==SRN_VAL_ARR){
        return Interprete::resolverValArr(lienzo, ctxGlobal, ctxLocal, exp);
    }
    return resultado;
}

Resultado *Interprete::buscarArr(Contexto *ctxGlobal, Contexto *ctxLocal, QString nombre){
    Resultado *resultado = new Resultado();
    foreach (Simbolo simbolo, *ctxLocal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && simbolo.getEsArr()){
            if(!simbolo.getInstancia()){
                //TODO-WARNING-El arreglo puede contener valores no instanciados
            }
            resultado->setTipo(simbolo.getTipo());
            resultado->setEsArr(true);
            resultado->setValores(simbolo.getValores());
            return resultado;
        }
    }

    foreach (Simbolo simbolo, *ctxGlobal->getContexto()) {
        if(QString::compare(simbolo.getNombre(), nombre)==0 && simbolo.getEsArr()){
            if(!simbolo.getInstancia()){
                //TODO-WARNING-El arreglo puede contener valores no instanciados
            }
            resultado->setTipo(simbolo.getTipo());
            resultado->setEsArr(true);
            resultado->setValores(simbolo.getValores());
            return resultado;
        }
    }
    return resultado;
}

Resultado *Interprete::resolverValArr(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo valArr){
    Resultado *unnion = new Resultado();
    QList<Resultado> *resultados = new QList<Resultado>();
    Resultado *temp;
    int tipo;
    int hijos;
    foreach (Nodo nodo, *valArr.getHijos()) {
        temp = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo);
        tipo = temp->getTipo();
        hijos = temp->getValores().count();
        resultados->append(*temp);
    }

    int cont = 0;
    QList<int> dims = *new QList<int>();
    foreach (Resultado resultado, *resultados) {
        cont = cont + 1;
        if(resultado.getTipo()!=tipo){
            //TODO-ERROR-los tipos no corresponden...
            return new Resultado();
        }
        if(resultado.getValores().count()!=hijos){
            //TODO-ERROR-las dimensiones no son de igual magnitud..
            return new Resultado();
        }
        if(hijos==0){
            unnion->addValor(resultado.getValor());
        }else{
            unnion->addValores(resultado.getValores());
        }
        dims = resultado.getDimensiones();
    }
    unnion->setTipo(tipo);
    unnion->setEsArr(true);
    unnion->setDimensiones(dims);
    unnion->preDimension(cont);
    return unnion;
}


