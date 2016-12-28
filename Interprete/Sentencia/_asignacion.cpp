#include "Interprete/interprete.h"
#include "Interprete/casteo.h"
#include "General/constantes.h"


Resultado *Interprete::resolverAsigArr(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig ){
    Resultado *resultado = new Resultado();
    ma->getInstance(lienzo);
    //Resolviendo valor
    Resultado *valor = new Resultado();
    if(asig.getSubRol()==SRN_DIRECTO || asig.getSubRol()==SRN_SUM_SIMPLY || asig.getSubRol()==SRN_SUB_SIMPLY){
       valor = Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(1));
       if(valor->getTipo()==ERR || valor->getEsArr()){
           ma->addErrorSemantico("La asignación no puede ser posible", asig.getFila());
           return resultado;
       }
    }

    //Resolviendo las dimensiones
    QList<Resultado> *dims = new QList<Resultado>();
    Resultado *temp;
    foreach (Nodo nodo, *asig.getHijo(0).getHijos()) {
        temp = Interprete::resolverExpresion(lienzo, ctxG, ctxL, nodo);
        if(temp->getTipo()!=TENTERO || temp->getEsArr()){
            ma->addErrorSemantico("Se esperaba tipo Entero para las dimensiones", asig.getFila());
            return resultado;
        }
        dims->append(*temp);
    }

    if(asig.getSubRol()==SRN_DIRECTO){
        return Interprete::asigDirectaArr(asig.getCadena(), dims, *valor, ctxG, ctxL);
    }
    if(asig.getSubRol()==SRN_SUM_SIMPLY){
        return Interprete::asigSumSimplyArr(asig.getCadena(), dims, *valor, ctxG, ctxL);
    }
    if(asig.getSubRol()==SRN_SUB_SIMPLY){
        return Interprete::asigSubSimplyArr(asig.getCadena(), dims, *valor, ctxG, ctxL);
    }
    if(asig.getSubRol()==SRN_INC){
        return Interprete::asigIncArr(asig.getCadena(), dims, ctxG, ctxL);
    }
    if(asig.getSubRol()==SRN_DEC){
        return Interprete::asigDecArr(asig.getCadena(), dims, ctxG, ctxL);
    }

    return resultado;
}

Resultado *Interprete::asigDirectaArr(QString nombre, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL){
    Resultado *resultado = new Resultado();
    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simL->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simL->getDims());
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("La asignación no es posible");
                return resultado;
            }
            simL->setValor(pos, valor.getValor());
            return resultado;
        }
    }
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simG->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simG->getDims());
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("La asignación no es posible");
                return resultado;
            }
            simG->setValor(pos, valor.getValor());
            return resultado;
        }
    }

    return resultado;
}

Resultado *Interprete::asigSumSimplyArr(QString nombre, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL){
    Resultado *resultado = new Resultado();
    Resultado *tempL = new Resultado();
    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simL->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simL->getDims());

            tempL->setTipo(simL->getTipo());
            tempL->setValor(simL->getValor(pos));
            valor = *Interprete::resolverSum(*tempL, valor);
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("Los tipos de asignación no son permitidos");
                return resultado;
            }
            simL->setValor(pos, valor.getValor());
            return resultado;
        }
    }
    Resultado *tempG = new Resultado();
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simG->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simG->getDims());

            tempG->setTipo(simG->getTipo());
            tempG->setValor(simG->getValor(pos));
            valor = *Interprete::resolverSum(*tempG, valor);
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("Los tipos de asignación no son permitidos");
                return resultado;
            }
            simG->setValor(pos, valor.getValor());
            return resultado;
        }
    }
    return resultado;
}

Resultado *Interprete::asigSubSimplyArr(QString nombre, QList<Resultado> *dims, Resultado valor, Contexto *ctxG, Contexto *ctxL){
    Resultado *resultado = new Resultado();
    Resultado *tempL = new Resultado();
    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simL->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simL->getDims());

            tempL->setTipo(simL->getTipo());
            tempL->setValor(simL->getValor(pos));
            valor = *Interprete::resolverSub(*tempL, valor);
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("Los tipos de asignación no son permitidos");
                return resultado;
            }
            simL->setValor(pos, valor.getValor());
            return resultado;
        }
    }
    Resultado *tempG = new Resultado();
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simG->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simG->getDims());

            tempG->setTipo(simG->getTipo());
            tempG->setValor(simG->getValor(pos));
            valor = *Interprete::resolverSub(*tempG, valor);
            valor = Casteo::toAsigVar(simG->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addError("Los tipos de asignación no son permitidos");
                return resultado;
            }
            simG->setValor(pos, valor.getValor());
            return resultado;
        }
    }
    return resultado;
}

Resultado *Interprete::asigIncArr(QString nombre, QList<Resultado> *dims, Contexto *ctxG, Contexto *ctxL){
    Resultado *resultado = new Resultado();
    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simL->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simL->getDims());

            if(simL->getValor(pos) == "" && !simL->getInstancia()){
                ma->addError("Se requiere una instancia previa para realizar un incremento");
                return resultado;
            }

            if(simL->getTipo()==TENTERO){
                simL->setValor(pos, Casteo::intToStr(Casteo::strToInt(simL->getValor(pos)) + 1));
            }
            if(simL->getTipo()==TDOBLE){
                simL->setValor(pos, Casteo::intToStr(Casteo::dobleToInt(simL->getValor(pos)) + 1));

            }
            if(simL->getTipo()==TCARACTER){
                simL->setValor(pos, Casteo::intToStr(Casteo::charToInt(simL->getValor(pos)) + 1));

            }
            ma->addError("El tipo de arreglo no es valido para realizar un incremento");
            return resultado;
        }
    }
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simG->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simG->getDims());

            if(simG->getValor(pos) == "" && !simG->getInstancia()){
                ma->addError("Se requiere una instancia previa para realizar un incremento");
                return resultado;
            }

            if(simG->getTipo()==TENTERO){
                simG->setValor(pos, Casteo::intToStr(Casteo::strToInt(simG->getValor(pos)) + 1));
            }
            if(simG->getTipo()==TDOBLE){
                simG->setValor(pos, Casteo::intToStr(Casteo::dobleToInt(simG->getValor(pos)) + 1));

            }
            if(simG->getTipo()==TCARACTER){
                simG->setValor(pos, Casteo::intToStr(Casteo::charToInt(simG->getValor(pos)) + 1));

            }
            ma->addError("El tipo de arreglo no es valido para realizar un incremento");
            return resultado;
        }
    }
    return resultado;
}

Resultado *Interprete::asigDecArr(QString nombre, QList<Resultado> *dims, Contexto *ctxG, Contexto *ctxL){
    Resultado *resultado = new Resultado();
    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simL->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simL->getDims());

            if(simL->getValor(pos) == "" && !simL->getInstancia()){
                ma->addError("Se requiere una instancia previa para realizar un decremento");
                return resultado;
            }

            if(simL->getTipo()==TENTERO){
                simL->setValor(pos, Casteo::intToStr(Casteo::strToInt(simL->getValor(pos)) - 1));
            }
            if(simL->getTipo()==TDOBLE){
                simL->setValor(pos, Casteo::intToStr(Casteo::dobleToInt(simL->getValor(pos)) - 1));

            }
            if(simL->getTipo()==TCARACTER){
                simL->setValor(pos, Casteo::intToStr(Casteo::charToInt(simL->getValor(pos)) - 1));

            }
            ma->addError("El tipo de arreglo no es valido para realizar un decremento");
            return resultado;
        }
    }
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            //Verificar que las dimensiones concuerdan
            if(!Contexto::verificarDims(dims, simG->getDims())){
                ma->addError("Las dimensiones no corresponden al arreglo");
                return resultado;
            }
            int pos = Contexto::obtenerPosicion(dims, simG->getDims());

            if(simG->getValor(pos) == "" && !simG->getInstancia()){
                ma->addError("Se requiere una instancia previa para realizar un decremento");
                return resultado;
            }

            if(simG->getTipo()==TENTERO){
                simG->setValor(pos, Casteo::intToStr(Casteo::strToInt(simG->getValor(pos)) - 1));
            }
            if(simG->getTipo()==TDOBLE){
                simG->setValor(pos, Casteo::intToStr(Casteo::dobleToInt(simG->getValor(pos)) - 1));

            }
            if(simG->getTipo()==TCARACTER){
                simG->setValor(pos, Casteo::intToStr(Casteo::charToInt(simG->getValor(pos)) - 1));

            }
            ma->addError("El tipo de arreglo no es valido para realizar un decremento");
            return resultado;
        }
    }
    return resultado;
}

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

    ma->addError("La variable no existe");
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

    ma->addError("La variable no existe");
}

void Interprete::asigArrArr(Contexto *ctxG, Contexto *ctxL, QString nombre, Resultado arr){

    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), nombre)==0 && simL->getEsArr()){
            if(arr.getTipo()!=simL->getTipo()){
                ma->addError("Los tipos de asignación no son permitidos");
                return;
            }
            simL->setValores(arr.getValores());
            simL->setInstancia(true);
            return;
        }
    }

    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), nombre)==0 && simG->getEsArr()){
            if(arr.getTipo()!=simG->getTipo()){
                ma->addError("Los tipos de asignación no son permitidos");
                return;
            }
            simG->setValores(arr.getValores());
            simG->setInstancia(true);
            return;
        }
    }
}



void Interprete::asigDirectaVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR){
        ma->addErrorSemantico("La asignación no es posible", asig.getFila());
        return;
    }
    if(valor.getEsArr()){
        Interprete::asigArrArr(ctxG, ctxL, asig.getCadena(), valor);
        return;
    }

    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), asig.getCadena())==0 && !simL->getEsArr()){
            valor = Casteo::toAsigVar(simL->getTipo(), valor);
            if(valor.getTipo()==ERR){
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
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
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }
    ma->addErrorSemantico("La variable no existe", asig.getFila());
}

void Interprete::asigSumSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR || valor.getEsArr()){
        ma->addErrorSemantico("La asignación no es posible", asig.getFila());
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
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
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
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }
    ma->addErrorSemantico("La variable no existe", asig.getFila());

}

void Interprete::asigSubSimplyVar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo asig){
    Resultado valor = *Interprete::resolverExpresion(lienzo, ctxG, ctxL, asig.getHijo(0));
    if(valor.getTipo()==ERR || valor.getEsArr()){
        ma->addErrorSemantico("La asignación no es posible", asig.getFila());
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
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
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
                ma->addErrorSemantico("Los tipos de asignación no son permitidos", asig.getFila());
                return;
            }
            simG->setValor(valor.getValor());
            simG->setInstancia(true);
            return;
        }
    }
    ma->addErrorSemantico("La variable no existe", asig.getFila());
}
