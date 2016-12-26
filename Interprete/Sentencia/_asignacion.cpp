#include "Interprete/interprete.h"
#include "Interprete/casteo.h"
#include "General/constantes.h"


Resultado *Interprete::resolverAsigVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado *resultado = new Resultado();
    if(asig.getSubRol()==SRN_DIRECTO){
       Interprete::asigDirectaVar(lienzo, ctxG, ctxL, asig);
    }
    if(asig.getSubRol()==SRN_INC){
       Interprete::asigIncVar(ctxG, ctxL, asig);
    }
    if(asig.getSubRol()==SRN_DEC){
       Interprete::asigDecVar(ctxG, ctxL, asig);
    }
    if(asig.getSubRol()==SRN_SUM_SIMPLY){
       Interprete::asigSumSimplyVar(lienzo, ctxG, ctxL, asig);
    }
    if(asig.getSubRol()==SRN_SUB_SIMPLY){
       Interprete::asigSubSimplyVar(lienzo, ctxG, ctxL, asig);
    }
    return resultado;
}

void Interprete::asigDecVar(Contexto *ctxG, Contexto *ctxL, Nodo asig){

    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            if(simL->getTipo()==TENTERO){
                simL->setValor(Casteo::intToStr(Casteo::strToInt(simL->getValor()) - 1));
            }
            if(simL->getTipo()==TDOBLE){
                simL->setValor(Casteo::dobleToStr(Casteo::strToDoble(simL->getValor()) - 1.0));
            }
            if(simL->getTipo()==TCARACTER){
                simL->setValor(Casteo::intToChar(Casteo::charToInt(simL->getValor()) - 1));
            }
            return;
        }
    }


    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), asig.getCadena())==0 && !simG->getEsArr()){
            if(simG->getTipo()==TENTERO){
                simG->setValor(Casteo::intToStr(Casteo::strToInt(simG->getValor()) - 1));
            }
            if(simG->getTipo()==TDOBLE){
                simG->setValor(Casteo::dobleToStr(Casteo::strToDoble(simG->getValor()) - 1.0));
            }
            if(simG->getTipo()==TCARACTER){
                simG->setValor(Casteo::intToChar(Casteo::charToInt(simG->getValor()) - 1));
            }
            return;
        }
    }

    //TODO-ERROR-La variable no existe

}

void Interprete::asigIncVar(Contexto *ctxG, Contexto *ctxL, Nodo asig){

    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            if(simL->getTipo()==TENTERO){
                simL->setValor(Casteo::intToStr(Casteo::strToInt(simL->getValor()) + 1));
            }
            if(simL->getTipo()==TDOBLE){
                simL->setValor(Casteo::dobleToStr(Casteo::strToDoble(simL->getValor()) + 1.0));
            }
            if(simL->getTipo()==TCARACTER){
                simL->setValor(Casteo::intToChar(Casteo::charToInt(simL->getValor())+1));
            }
            return;
        }
    }

    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), asig.getCadena())==0 && !simG->getEsArr()){
            if(simG->getTipo()==TENTERO){
                simG->setValor(Casteo::intToStr(Casteo::strToInt(simG->getValor()) + 1));
            }
            if(simG->getTipo()==TDOBLE){
                simG->setValor(Casteo::dobleToStr(Casteo::strToDoble(simG->getValor()) + 1.0));
            }
            if(simG->getTipo()==TCARACTER){
                simG->setValor(Casteo::intToChar(Casteo::charToInt(simG->getValor())+1));
            }
            return;
        }
    }

    //TODO-ERROR-La variable no existe
}

void Interprete::asigDirectaVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR || valor.getEsArr()){
        //TODO-ERROR-La asignación no es posible
        return;
    }

    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simL->setValor(valor.getValor());
            simL->setInstancia(true);
            return;
        }
    }

    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), asig.getCadena())==0 && !simG->getEsArr()){
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }

    //TODO-ERROR-La variable no existe
}

void Interprete::asigSumSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR || valor.getEsArr()){
        //TODO-ERROR-La asignación no es posible
        return;
    }

    Resultado *tempL = new Resultado();
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            tempL->setTipo(simL->getTipo());
            tempL->setValor(simL->getValor());
            valor = *Interprete::resolverSum(*tempL, valor);
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simL->setValor(valor.getValor());
            simL->setInstancia(true);
            return;
        }
    }


    Resultado *tempG = new Resultado();
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), asig.getCadena())==0 && !simG->getEsArr()){
            tempG->setTipo(simG->getTipo());
            tempG->setValor(simG->getValor());
            valor = *Interprete::resolverSum(*tempG, valor);
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }

    //TODO-ERROR-La variable no existe
}

void Interprete::asigSubSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR || valor.getEsArr()){
        //TODO-ERROR-La asignación no es posible
        return;
    }

    Resultado *tempL = new Resultado();
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            tempL->setTipo(simL->getTipo());
            tempL->setValor(simL->getValor());
            valor = *Interprete::resolverSub(*tempL, valor);
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simL->setValor(valor.getValor());
            simL->setInstancia(true);
            return;
        }
    }

    Resultado *tempG = new Resultado();
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), asig.getCadena())==0 && !simG->getEsArr()){
            tempG->setTipo(simG->getTipo());
            tempG->setValor(simG->getValor());
            valor = *Interprete::resolverSub(*tempG, valor);
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                //TODO-ERROR-Los tipos de asignación no son permitidos
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }

    //TODO-ERROR-La variable no existe
}
