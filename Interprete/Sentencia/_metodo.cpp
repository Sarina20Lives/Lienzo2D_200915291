#include "Interprete/interprete.h"
#include "General/constantes.h"

Resultado *Interprete::ejecutarMtd(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Metodo mtd){
    Resultado *resultado = new Resultado();
    foreach (Nodo sentencia, *mtd.getSentencias()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            if(resultado->getTipo()!=mtd.getTipo()){
                ma->addErrorSemantico("Se obtuvo un retorno que no corresponde al tipo del metodo", mtd.getFila());
                return new Resultado();
            }
            return resultado;
        }
        if(resultado->getRol()==RN_SALIR){
            ma->addErrorSemantico("Break fuera de contexto", mtd.getFila());
            resultado = new Resultado();
        }
        if(resultado->getRol()==RN_CONTINUAR){
            ma->addErrorSemantico("Continue fuera de contexto", mtd.getFila());
            resultado = new Resultado();
        }
    }
    if(mtd.getTipo()!=TVOID){
        ma->addErrorSemantico("Se requeria un retorno y no fue encontrado", mtd.getFila());
    }
    return new Resultado();
}






