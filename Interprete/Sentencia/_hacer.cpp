#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::ejecutarHacer(QString lienzo, QString padre,  Contexto *ctxG, Contexto *ctxL, Nodo nodo){
    Resultado *resultado = new Resultado();
    Resultado *condicion;
    ctxL->aumentarNivel();
linicio:
    foreach (Nodo sentencia, *nodo.getHijo(1).getHijos()) {
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

    condicion = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo.getHijo(0));
    if(condicion->getTipo()!=TBOOLEAN){
        ctxL->limpiarContexto();
        ManejoErrores::addErrorSemantico("Error al resolver la condicion para hacer-mientras", nodo.getHijo(0).getFila());
        return new Resultado();
    }
    if(Casteo::strToBool(condicion->getValor())){
        ctxL->limpiarContexto();
        return new Resultado();
    }
    goto linicio;
}
