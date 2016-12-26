#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::resolverLogica(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();

    Resultado *op1 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(0));
    if(op1->getTipo() == ERR || op1->getEsArr()){
        return resultado;
    }

    if(exp.getSubRol() == SRN_NOT){
        return Interprete::resolverNot(*op1);
    }

    Resultado *op2 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(1));
    if(op2->getTipo() == ERR || op2->getEsArr()){
        return resultado;
    }

    if(exp.getSubRol() == SRN_AND){
        return Interprete::resolverAnd(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_NAND){
        return Interprete::resolverNand(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_OR){
        return Interprete::resolverOr(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_NOR){
        return Interprete::resolverNor(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_XOR){
        return Interprete::resolverXor(*op1, *op2);
    }
    return resultado;
}


Resultado *Interprete::resolverNot(Resultado op1){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("true");
    if(Casteo::toBool(op1)){
        resultado->setValor("false");
    }
    return resultado;
}

Resultado *Interprete::resolverAnd(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN || op2.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(Casteo::toBool(op1) && Casteo::toBool(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverNand(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN || op2.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("true");
    if(Casteo::toBool(op1) && Casteo::toBool(op2)){
        resultado->setValor("false");
    }
    return resultado;
}

Resultado *Interprete::resolverOr(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN || op2.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(Casteo::toBool(op1) || Casteo::toBool(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverNor(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN || op2.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("true");
    if(Casteo::toBool(op1) || Casteo::toBool(op2)){
        resultado->setValor("false");
    }
    return resultado;
}

Resultado *Interprete::resolverXor(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()!=TBOOLEAN || op2.getTipo()!=TBOOLEAN){
        return resultado;
    }
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(Casteo::toBool(op1) != Casteo::toBool(op2)){
        resultado->setValor("true");
    }
    return resultado;
}


