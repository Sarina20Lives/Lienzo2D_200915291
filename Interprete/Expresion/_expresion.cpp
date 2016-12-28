#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"


Resultado *Interprete::resolverExpresion(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    ma = ManejoErrores::getInstance(lienzo);
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
    if(exp.getRol() == RN_ORDENAR){
        return Interprete::resolverOrdenar(ctxGlobal, ctxLocal, exp);
    }
    if(exp.getRol() == RN_SUMARIZAR){
        return Interprete::resolverSumarizar(lienzo, ctxGlobal, ctxLocal, exp);
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
    ma->getInstance(lienzo);
    //Resolver dimensiones...
    QList<Resultado> *dims = new QList<Resultado>();
    Resultado *dim;
    foreach (Nodo nodo, *exp.getHijos()) {
        dim = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, nodo);
        if(dim->getTipo()!=TENTERO){
            ma->addErrorSemantico("Error al querer obtener los valores de las dimensiones", exp.getFila());
            return new Resultado();
        }
        dims->append(*dim);
    }

    //Buscar arreglo:
    Simbolo arreglo = Interprete::buscarSimboloArr(ctxGlobal, ctxLocal, exp.getCadena());
    if(arreglo.getTipo()==ERR){
        ma->addErrorSemantico("El arreglo no existe", exp.getFila());
        return new Resultado();
    }

    //Comprobar la cantidad de dimensiones:
    if(arreglo.getDims().count()!=dims->count()){
        ma->addErrorSemantico("Las dimensiones no corresponden al arreglo", exp.getFila());
        return new Resultado();
    }
    int cont = 0;
    foreach (Resultado res, *dims) {
        if(Casteo::strToInt(res.getValor())<0 || Casteo::strToInt(res.getValor())>arreglo.getDims().at(cont)){
            ma->addErrorSemantico("Los indices se encuentran fuera de los limites permitidos", exp.getFila());
            return new Resultado();
        }
        cont = cont + 1;
    }
    int pos= Contexto::obtenerPosicion(dims, arreglo.getDims());
    if(!arreglo.getInstancia() && QString::compare(arreglo.getValores().at(pos),"")==0){
        ma->addErrorSemantico("Se hace referencia a una posición de arreglo no definida", exp.getFila());
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
                ma->addError("La variable no ha sido instanciada previamente");
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
                ma->addError("La variable no ha sido instanciada previamente");
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
                ma->addError("El arreglo puede contener valores no instanciados");
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
                ma->addError("El arreglo puede contener valores no instanciados");
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
    ma->getInstance(lienzo);
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
            ma->addErrorSemantico("Los tipos no corresponden", valArr.getFila());
            return new Resultado();
        }
        if(resultado.getValores().count()!=hijos){
            ma->addErrorSemantico("Las dimensiones no son de igual magnitud", valArr.getFila());
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


