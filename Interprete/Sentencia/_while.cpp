#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::ejecutarWhile(QString lienzo, QString padre,  Contexto *ctxG, Contexto *ctxL, Nodo nodo){
    Resultado *resultado = new Resultado();
    ctxL->aumentarNivel();
    linicio:
    Resultado *condicion = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo.getHijo(0));
    if(condicion->getTipo()!=TBOOLEAN){
        ManejoErrores::addErrorSemantico("Error al resolver la condicion para mientras", nodo.getHijo(0).getFila());
        return resultado;
    }
    if(!Casteo::strToBool(condicion->getValor())){
        return resultado;
    }
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
            goto linicio;
        }
        resultado = new Resultado();
    }
    goto linicio;
}
