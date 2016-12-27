#include "Interprete/interprete.h"
#include "General/constantes.h"

Resultado *Interprete::ejecutarMtd(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Metodo mtd){
    Resultado *resultado = new Resultado();
    foreach (Nodo sentencia, *mtd.getSentencias()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            if(resultado->getTipo()!=mtd.getTipo()){
                //TODO-ERROR-Se ha obtenido un retorno que no corresponde al tipo del metodo
                return new Resultado();
            }
            return resultado;
        }
        if(resultado->getRol()==RN_SALIR){
            //TODO-ERROR-Salir fuera de contexto
            return new Resultado();
        }
        if(resultado->getRol()==RN_CONTINUAR){
            //TODO-ERROR-Continuar fuera de contexto
            return new Resultado();
        }
    }
    if(mtd.getTipo()!=TVOID){
        //TODO-ERROR-No se ha encontrado ningún retorno
    }
    return new Resultado();
}






