#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::ejecutarPara(QString lienzo, QString padre,  Contexto *ctxG, Contexto *ctxL, Nodo nodo){
    Resultado *resultado = new Resultado();
    Resultado *condicion;
    ctxL->aumentarNivel();
    //inicializacion
    Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, nodo.getHijo(0));

linicio:
    //condicion
    condicion = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo.getHijo(1));
    if(condicion->getTipo()!=TBOOLEAN){
        ctxL->limpiarContexto();
        return new Resultado();
    }
    if(!Casteo::strToBool(condicion->getValor())){
        ctxL->limpiarContexto();
        return new Resultado();
    }

    //sentencias
    foreach (Nodo sentencia, *nodo.getHijo(3).getHijos()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            ctxL->limpiarContexto();
            return resultado;
        }
        if(resultado->getRol()==RN_SALIR){
            ctxL->limpiarContexto();
            return new Resultado;
        }
        if(resultado->getRol()==RN_CONTINUAR){
            break;
        }
        resultado = new Resultado();
    }
    //Variacion
    Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, nodo.getHijo(2));
    goto linicio;



}
