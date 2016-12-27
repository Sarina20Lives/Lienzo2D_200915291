#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"

Resultado *Interprete::resolverRelacional(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();

    if(exp.getSubRol() == SRN_NULO){
        return Interprete::resolverNulo(ctxGlobal, ctxLocal, exp);
    }

    Resultado *op1 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(0));
    Resultado *op2 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(1));
    if(op1->getTipo() == ERR || op2->getTipo() == ERR ){
        return resultado;
    }
    if(op1->getEsArr() || op2->getEsArr()){
        return resultado;
    }

    if(exp.getSubRol() == SRN_IGUAL){
        return Interprete::resolverIgual(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_DIFERENTE){
        return Interprete::resolverDiferente(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_MEN){
        return Interprete::resolverMen(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_MEN_IGUAL){
        return Interprete::resolverMenIgual(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_MAY){
        return Interprete::resolverMay(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_MAY_IGUAL){
        return Interprete::resolverMayIgual(*op1, *op2);
    }
    return resultado;
}


Resultado *Interprete::resolverNulo(Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();
    resultado = Interprete::buscarValVar(ctxGlobal, ctxLocal, exp.getCadena());
    resultado->setValor("true");
    if(resultado->getTipo()==ERR){
        resultado->setValor("true");
    }
    resultado->setTipo(TBOOLEAN);
    return resultado;
}

Resultado *Interprete::resolverIgual(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(op1.getTipo()==op2.getTipo() && op1.getValor()==op2.getValor()){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverDiferente(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("true");
    if(op1.getTipo()==op2.getTipo() && op1.getValor()==op2.getValor()){
        resultado->setValor("false");
    }
    return resultado;
}

Resultado *Interprete::resolverMen(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        if(QString::compare(op1.getValor(), op2.getValor())<0){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        if(Casteo::toDoble(op1)<Casteo::toDoble(op2)){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(Casteo::toInt(op1)<Casteo::toInt(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverMenIgual(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        if(QString::compare(op1.getValor(), op2.getValor())<=0){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        if(Casteo::toDoble(op1)<=Casteo::toDoble(op2)){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(Casteo::toInt(op1)<=Casteo::toInt(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverMay(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        if(QString::compare(op1.getValor(), op2.getValor())>0){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        if(Casteo::toDoble(op1)>Casteo::toDoble(op2)){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(Casteo::toInt(op1)>Casteo::toInt(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

Resultado *Interprete::resolverMayIgual(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TBOOLEAN);
    resultado->setValor("false");
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        if(QString::compare(op1.getValor(), op2.getValor())>=0){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        if(Casteo::toDoble(op1)>=Casteo::toDoble(op2)){
            resultado->setValor("true");
        }
        return resultado;
    }
    if(Casteo::toInt(op1)>=Casteo::toInt(op2)){
        resultado->setValor("true");
    }
    return resultado;
}

