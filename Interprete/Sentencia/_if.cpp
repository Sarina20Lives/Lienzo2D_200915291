#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::ejecutarIf(QString lienzo, QString padre,  Contexto *ctxG, Contexto *ctxL, Nodo nodo){
    Resultado *resultado = new Resultado();
    Resultado *condicion = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo.getHijo(0));
    if(condicion->getTipo()!=TBOOLEAN){
        ManejoErrores::addErrorSemantico("Error al resolver la condicion para if", nodo.getHijo(0).getFila());
        return resultado;
    }

    ctxL->aumentarNivel();
    if(Casteo::strToBool(condicion->getValor())){
        foreach (Nodo sentencia, *nodo.getHijo(1).getHijos()) {
            resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
            if(resultado->getRol()==RN_RETORNA){
                break;
            }
            if(resultado->getRol()==RN_SALIR){
                break;
            }
            if(resultado->getRol()==RN_CONTINUAR){
                break;
            }
            resultado = new Resultado();
        }
        ctxL->limpiarContexto();
        return resultado;
    }

    foreach (Nodo sentencia, *nodo.getHijo(2).getHijos()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            break;
        }
        if(resultado->getRol()==RN_SALIR){
            break;
        }
        if(resultado->getRol()==RN_CONTINUAR){
            break;
        }
        resultado = new Resultado();
    }
    ctxL->limpiarContexto();
    return resultado;
}
