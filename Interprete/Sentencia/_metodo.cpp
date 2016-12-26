#include "Interprete/interprete.h"
#include "General/constantes.h"

Resultado *Interprete::ejecutarMtd(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Metodo mtd){
    Resultado *resultado = new Resultado();
    foreach (Nodo sentencia, *mtd.getSentencias()) {
        resultado = Interprete::ejecutarSentencia(lienzo, padre, ctxG, ctxL, sentencia);
        if(resultado->getRol()==RN_RETORNA){
            return resultado;
        }
    }
    if(mtd.getTipo()!=TVOID){
        //TODO-ERROR-No se ha encontrado ningún retorno
    }
    return new Resultado();
}






