#include "Interprete/interprete.h"
#include "General/constantes.h"

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
        return buscarValVar(ctxGlobal, ctxLocal, exp.getCadena());
    }
    if(exp.getSubRol()==SRN_ARR){
        //FALTA IMPLEMENTAR
        return resultado;
    }
    return resultado;
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
    if(exp.getSubRol()==SRN_ARR){
        //FALTA IMPLEMENTAR
        return resultado;
    }
    if(exp.getSubRol()==SRN_VAL_ARR){
        return Interprete::resolverValArr(lienzo, ctxGlobal, ctxLocal, exp);
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
        hijos = temp->getValores()->count();
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
        if(resultado.getValores()->count()!=hijos){
            //TODO-ERROR-las dimensiones no son de igual magnitud..
            return new Resultado();
        }
        unnion->addValores(*resultado.getValores());
        dims = resultado.getDimensiones();
    }
    unnion->getDimensiones().prepend(cont);
    return unnion;
}


