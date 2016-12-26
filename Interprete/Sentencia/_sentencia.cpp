#include "Interprete/interprete.h"
#include "General/constantes.h"


Resultado *Interprete::ejecutarSentencia(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo sentencia){

    if(sentencia.getRol()==RN_DECLARE){
        Interprete::ejecutarDeclaracion(lienzo, padre, ctxG, ctxL, sentencia, false);
        return new Resultado();

    }
    if(sentencia.getRol()==RN_LLAMADA){
        return Interprete::resolverLlamada(lienzo, ctxG, ctxL, sentencia);
    }

    return new Resultado();
}
