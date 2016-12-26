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
    if(sentencia.getRol() ==RN_ASIG_VAR){
        return Interprete::resolverAsigVar(lienzo, ctxG, ctxL, sentencia);
    }
    if(sentencia.getRol() == RN_HACER){
        return Interprete::ejecutarHacer(lienzo, padre, ctxG, ctxL, sentencia);
    }
    if(sentencia.getRol() == RN_MIENTRAS){
        return Interprete::ejecutarWhile(lienzo, padre, ctxG, ctxL, sentencia);
    }
    if(sentencia.getRol() == RN_RETORNA){
        return Interprete::resolverRetorna(lienzo, ctxG, ctxL, sentencia);
    }
    if(sentencia.getRol() == RN_SALIR){
        return Interprete::resolverSalir();
    }
    if(sentencia.getRol() == RN_RETORNA){
        return Interprete::resolverContinuar();
    }
    if(sentencia.getRol() == RN_SI){
        return Interprete::ejecutarIf(lienzo, padre, ctxG, ctxL, sentencia);
    }

    return new Resultado();
}

Resultado *Interprete::resolverRetorna(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo sentencia){
    Resultado *resultado;
    Nodo exp = sentencia.getHijo(0);
    //Verificar si viene vacio
    if(exp.getRol()==NOTHING){
        resultado = new Resultado();
        resultado->setTipo(TVOID);
        resultado->setRol(RN_RETORNA);
        return resultado;
    }
    resultado = Interprete::resolverExpresion(lienzo, ctxG, ctxL, sentencia.getHijo(0));
    resultado->setRol(RN_RETORNA);
    return resultado;
}

Resultado *Interprete::resolverSalir(){
    Resultado *resultado = new Resultado();
    resultado->setRol(RN_SALIR);
    return resultado;
}

Resultado *Interprete::resolverContinuar(){
    Resultado *resultado = new Resultado();
    resultado->setRol(RN_CONTINUAR);
    return resultado;
}
