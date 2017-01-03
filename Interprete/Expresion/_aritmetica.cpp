#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"


Resultado *Interprete::resolverAritmetica(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();
    Resultado *op1 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(0));
    Resultado *op2 = Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, exp.getHijo(1));
    if(op1->getTipo() == ERR || op2->getTipo() == ERR ){
        return resultado;
    }
    if(op1->getEsArr() || op2->getEsArr()){
        return resultado;
    }

    if(exp.getSubRol() == SRN_SUM){
        return Interprete::resolverSum(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_SUB){
        return Interprete::resolverSub(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_MUL){
        return Interprete::resolverMul(*op1, *op2);
    }
    if(exp.getSubRol() == SRN_DIV){
        return Interprete::resolverDiv(*op1, *op2, exp.getFila());
    }
    if(exp.getSubRol() == SRN_POW){
        return Interprete::resolverPow(*op1, *op2);
    }
    return new Resultado();
}

Resultado *Interprete::resolverSum(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        if(op2.getTipo() == TBOOLEAN || op2.getTipo() == TBOOLEAN){
            return resultado;
        }
        resultado->setTipo(TCADENA);
        resultado->setValor(op1.getValor() + op2.getValor());
        return resultado;
    }

    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(Casteo::toDoble(op1) + Casteo::toDoble(op2)));
        return resultado;
    }

    if(op1.getTipo()==TENTERO || op2.getTipo()==TENTERO){
        resultado->setTipo(TENTERO);
        resultado->setValor(Casteo::intToStr(Casteo::toInt(op1) + Casteo::toInt(op2)));
        return resultado;
    }

    if(op1.getTipo()==TBOOLEAN && op2.getTipo()==TBOOLEAN){
        resultado->setTipo(TBOOLEAN);
        resultado->setValor("false");
        if(Casteo::toBool(op1) || Casteo::toBool(op2)){
            resultado->setValor("true");
        }
    }
    return resultado;
}

Resultado *Interprete::resolverSub(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        return resultado;
    }
    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(Casteo::toDoble(op1)-Casteo::toDoble(op2)));
        return resultado;
    }
    if(op1.getTipo()==TENTERO || op2.getTipo()==TENTERO){
        resultado->setTipo(TENTERO);
        resultado->setValor(Casteo::intToStr(Casteo::toInt(op1)-Casteo::toInt(op2)));
        return resultado;
    }
    return resultado;
}

Resultado *Interprete::resolverMul(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        return resultado;
    }

    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(Casteo::toDoble(op1) * Casteo::toDoble(op2)));
        return resultado;
    }

    if(op1.getTipo()==TENTERO || op2.getTipo()==TENTERO){
        resultado->setTipo(TENTERO);
        resultado->setValor(Casteo::intToStr(Casteo::toInt(op1) * Casteo::toInt(op2)));
        return resultado;
    }

    if(op1.getTipo()==TBOOLEAN && op2.getTipo()==TBOOLEAN){
        resultado->setTipo(TBOOLEAN);
        resultado->setValor("false");
        if(Casteo::toBool(op1) && Casteo::toBool(op2)){
            resultado->setValor("true");
        }
    }
    return resultado;
}

Resultado *Interprete::resolverDiv(Resultado op1, Resultado op2, int fila){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        return resultado;
    }

    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        double divisor = Casteo::toDoble(op2);
        if(divisor==0){
            ManejoErrores::addErrorSemantico("División dentro de cero", fila);
            return resultado;
        }
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(Casteo::toDoble(op1) / divisor));
        return resultado;
    }

    if(op1.getTipo()==TENTERO || op2.getTipo()==TENTERO){
        double divisor = Casteo::toDoble(op2);
        if(divisor==0){
            ManejoErrores::addErrorSemantico("División dentro de cero", fila);
            return resultado;
        }
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(Casteo::toDoble(op1) / divisor));
        return resultado;
    }
    return resultado;
}

Resultado *Interprete::resolverPow(Resultado op1, Resultado op2){
    Resultado *resultado = new Resultado();
    if(op1.getTipo()==TCADENA || op2.getTipo()==TCADENA){
        return resultado;
    }

    if(op1.getTipo()==TDOBLE || op2.getTipo()==TDOBLE){
        resultado->setTipo(TDOBLE);
        resultado->setValor(Casteo::dobleToStr(pow(Casteo::toDoble(op1),Casteo::toDoble(op2))));
        return resultado;
    }

    if(op1.getTipo()==TENTERO || op2.getTipo()==TENTERO){
        resultado->setTipo(TENTERO);
        resultado->setValor(Casteo::intToStr(pow(Casteo::toInt(op1),Casteo::toInt(op2))));
        return resultado;
    }

    return resultado;
}
