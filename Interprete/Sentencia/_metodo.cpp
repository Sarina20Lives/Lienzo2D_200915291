#include "Interprete/interprete.h"
#include "General/constantes.h"

Resultado *Interprete::ejecutarMtd(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Metodo mtd){
    Resultado *resultado = new Resultado();
    foreach (Nodo sentencia, *mtd.getSentencias()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            if(resultado->getTipo()!=mtd.getTipo()){
                ManejoErrores::addErrorSemantico("Se obtuvo un retorno que no corresponde al tipo del metodo", mtd.getFila(), mtd.getLienzoPadre());
                return new Resultado();
            }
            return resultado;
        }
        if(resultado->getRol()==RN_SALIR){
            ManejoErrores::addErrorSemantico("Break fuera de contexto", mtd.getFila(), mtd.getLienzoPadre());
            resultado = new Resultado();
        }
        if(resultado->getRol()==RN_CONTINUAR){
            ManejoErrores::addErrorSemantico("Continue fuera de contexto", mtd.getFila(), mtd.getLienzoPadre());
            resultado = new Resultado();
        }
    }
    if(mtd.getTipo()!=TVOID){
        ManejoErrores::addErrorSemantico("Se requeria un retorno y no fue encontrado", mtd.getFila(), mtd.getLienzoPadre());
    }
    return new Resultado();
}






