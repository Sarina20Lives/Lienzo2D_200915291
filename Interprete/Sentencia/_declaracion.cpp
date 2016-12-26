#include "Interprete/interprete.h"
#include "General/constantes.h"

void Interprete::ejecutarDeclaracion(QString lienzo, QString padre, Contexto *ctxG, Contexto *ctxL, Nodo dec, bool esGlobal){
    if(dec.getSubRol()==SRN_VAR){
        if(esGlobal){
            ctxG->agregarVariables(lienzo, padre, ctxG, ctxL, dec);
            return;
        }
        ctxL->agregarVariables(lienzo, padre, ctxG, ctxL, dec);
        return;
    }

}
