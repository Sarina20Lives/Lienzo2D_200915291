#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::ejectuarComprobar(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo nodo){
    ctxL->aumentarNivel();
    //Resolver valor:
    Resultado *ini = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo.getHijo(0));
    if(ini->getTipo()==ERR || ini->getEsArr()){
        ManejoErrores::addErrorSemantico("El valor inicial no es valido", nodo.getFila());
        return new Resultado();
    }
    bool esPrimero = true;
    Resultado *cond;
    Resultado *resultado = new Resultado();
    bool encontrado = false;
    linicio:
    esPrimero = true;
    foreach (Nodo caso, *nodo.getHijos()) {
        if(!esPrimero){
            if(caso.getRol()==RN_CASO){
                cond = Interprete::resolverExpresion(lienzo, ctxG, ctxL, caso.getHijo(0));
                if(cond->getTipo()!=ini->getTipo()){
                    ManejoErrores::addErrorSemantico("Los valores no se pueden igualar, no son del mismo tipo", nodo.getFila());
                    ctxL->limpiarContexto();
                    return new Resultado();
                }
                if(encontrado || cond->getValor()==ini->getValor()){
                    encontrado = true;
                    foreach (Nodo sentencia, *caso.getHijo(1).getHijos()) {
                        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
                        if(resultado->getRol()==RN_RETORNA){
                            ctxL->limpiarContexto();
                            return resultado;
                        }
                        if(resultado->getRol()==RN_SALIR){
                            ctxL->limpiarContexto();
                            return new Resultado();
                        }
                        if(resultado->getRol()==RN_CONTINUAR){
                            goto linicio;
                        }
                        resultado = new Resultado();
                    }
                }
            }else{
                foreach (Nodo sentencia, *caso.getHijos()) {
                    resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
                    if(resultado->getRol()==RN_RETORNA){
                        ctxL->limpiarContexto();
                        return resultado;
                    }
                    if(resultado->getRol()==RN_SALIR){
                        ctxL->limpiarContexto();
                        return new Resultado();
                    }
                    if(resultado->getRol()==RN_CONTINUAR){
                        goto linicio;
                    }
                    resultado = new Resultado();
                }
                ctxL->limpiarContexto();
                return resultado;
            }
        }
        esPrimero = false;
    }
    return new Resultado();
}
