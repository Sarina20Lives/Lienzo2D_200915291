#include "Interprete/interprete.h"
#include "General/constantes.h"
#include "Interprete/casteo.h"


Resultado *Interprete::resolverSumarizar(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo ordenar){
    Resultado *resultado = new Resultado();
    Resultado *temp = Interprete::resolverRefArr(lienzo, ctxG, ctxL, ordenar.getHijo(0));
    if(temp->getTipo()==ERR){
        return resultado;
    }
    resultado->setTipo(TCADENA);
    resultado->setValor(Interprete::sumarizarValores(temp->getValores(), temp->getTipo()));
    return resultado;
}


QString Interprete::sumarizarValores(QList<QString> valores, int tipo){
    QString resultado = "";
    foreach (QString val, valores) {
        if(tipo ==TCARACTER){
            resultado = Casteo::intToChar(Casteo::intToStr(Casteo::charToInt(resultado)+Casteo::charToInt(val)));
        }
        if(tipo ==TENTERO){
            resultado = Casteo::intToStr(Casteo::strToInt(resultado)+Casteo::strToInt(val));
        }
        if(tipo ==TDOBLE){
            resultado = Casteo::dobleToStr(Casteo::strToDoble(resultado)+Casteo::strToDoble(val));
        }
        if(tipo ==TCADENA){
            resultado = resultado + val;
        }
    }
    return resultado;
}


Resultado *Interprete::resolverOrdenar(Contexto *ctxG, Contexto *ctxL, Nodo ordenar){
    Resultado *resultado = new Resultado();
    resultado->setTipo(TENTERO);
    resultado->setValor("0");


    //Buscando el arreglo en el contexto local
    QList<Simbolo>::iterator simL;
    for(simL = (ctxL->getContexto())->begin(); simL!=(ctxL->getContexto())->end(); ++simL){
        if(QString::compare(simL->getNombre(), ordenar.getCadena())==0 && simL->getEsArr()){
            if(!simL->getInstancia()){
                ManejoErrores::addErrorSemantico("El arreglo no posee una instancia inicial", ordenar.getFila());
            }
            if(ordenar.getSubRol()==SRN_ASC){
                simL->setValores(Interprete::ascValores(simL->getValores(), simL->getTipo()));
            }
            if(ordenar.getSubRol()==SRN_DESC){
                simL->setValores(Interprete::descValores(simL->getValores(), simL->getTipo()));
            }
            if(ordenar.getSubRol()==SRN_PAR){
                simL->setValores(Interprete::parImparValores(simL->getValores(), simL->getTipo(), true));
            }
            if(ordenar.getSubRol()==SRN_IMPAR){
                simL->setValores(Interprete::parImparValores(simL->getValores(), simL->getTipo(), false));
            }
            if(ordenar.getSubRol()==SRN_PRIMO){
                simL->setValores(Interprete::primosValores(simL->getValores(), simL->getTipo()));
            }
            resultado->setValor("1");
            return resultado;
        }
    }
    //Buscando el arreglo en el contexto global
    QList<Simbolo>::iterator simG;
    for(simG = (ctxG->getContexto())->begin(); simG!=(ctxG->getContexto())->end(); ++simG){
        if(QString::compare(simG->getNombre(), ordenar.getCadena())==0 && simG->getEsArr()){
            if(!simL->getInstancia()){
                ManejoErrores::addErrorSemantico("El arreglo no posee una instancia inicial", ordenar.getFila());
            }
            if(ordenar.getSubRol()==SRN_ASC){
                simG->setValores(Interprete::ascValores(simG->getValores(), simG->getTipo()));
            }
            if(ordenar.getSubRol()==SRN_DESC){
                simG->setValores(Interprete::descValores(simG->getValores(), simG->getTipo()));
            }
            if(ordenar.getSubRol()==SRN_PAR){
                simG->setValores(Interprete::parImparValores(simG->getValores(), simG->getTipo(), ordenar.getFila(), true));
            }
            if(ordenar.getSubRol()==SRN_IMPAR){
                simG->setValores(Interprete::parImparValores(simG->getValores(), simG->getTipo(), ordenar.getFila(), false));
            }
            if(ordenar.getSubRol()==SRN_PRIMO){
                simG->setValores(Interprete::primosValores(simG->getValores(), simG->getTipo(), ordenar.getFila(),));
            }
            resultado->setValor("1");
            return resultado;
        }
    }

    return resultado;
}

QList<QString> Interprete::ascValores(QList<QString> original, int tipo){
    QList<QString> nueva = *new QList<QString>();
    bool ubicado = false;
    int cont = 0;
    foreach (QString val, original) {
        ubicado = false;
        cont = 0;
        foreach (QString temp, nueva) {
            if((tipo==TCADENA || tipo ==TCARACTER) && QString::compare(val, temp)<0){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            if(tipo==TENTERO && Casteo::strToInt(val)<Casteo::strToInt(temp)){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            if(tipo==TDOBLE && Casteo::strToDoble(val)<Casteo::strToDoble(temp)){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            cont = cont+1;
        }
        if(!ubicado){
            nueva.append(val);
        }
    }
    return nueva;
}

QList<QString> Interprete::descValores(QList<QString> original, int tipo){
    QList<QString> nueva = *new QList<QString>();
    bool ubicado = false;
    int cont = 0;
    foreach (QString val, original) {
        ubicado = false;
        cont = 0;
        foreach (QString temp, nueva) {
            if((tipo==TCADENA || tipo ==TCARACTER) && QString::compare(val, temp)<0){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            if(tipo==TENTERO && Casteo::strToInt(val)<Casteo::strToInt(temp)){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            if(tipo==TDOBLE && Casteo::strToDoble(val)<Casteo::strToDoble(temp)){
                nueva.insert(cont, val);
                ubicado = true;
                break;
            }
            cont = cont+1;
        }
        if(!ubicado){
            nueva.append(val);
        }
    }
    original = *new QList<QString>();
    foreach (QString val, nueva) {
        original.prepend(val);
    }
    return original;
}


QList<QString> Interprete::parImparValores(QList<QString> original, int tipo, int fila, bool parImpar){
    if(tipo==TCADENA){
        ManejoErrores::addErrorSemantico("No es posible ordenar por impar o par un arreglo de tipo cadena", fila);
        return original;
    }
    QList<QString> nueva = *new QList<QString>();
    QList<QString> pares = *new QList<QString>();
    QList<QString> impares = *new QList<QString>();

    int valor;
    foreach (QString val, original) {
        if(tipo ==TCARACTER){
            valor = Casteo::charToInt(val);
        }
        if(tipo ==TENTERO){
            valor = Casteo::strToInt(val);
        }
        if(tipo ==TDOBLE){
            valor = Casteo::dobleToInt(Casteo::strToDoble(val));
        }
        if(valor % 2 == 0){
            pares.append(val);
        }else{
            impares.append(val);
        }
    }
    if(parImpar){
        nueva.append(pares);
        nueva.append(impares);
    }else{
        nueva.append(impares);
        nueva.append(pares);
    }
    return nueva;
}

QList<QString> Interprete::primosValores(QList<QString> original, int tipo, int fila){
    if(tipo==TCADENA){
        ManejoErrores::addErrorSemantico("No es posible ordenar por primos una arreglo de tipo cadena", fila);
        return original;
    }
    QList<QString> nueva = *new QList<QString>();
    QList<QString> primos = *new QList<QString>();
    QList<QString> noprimos = *new QList<QString>();

    int valor;
    foreach (QString val, original) {
        if(tipo ==TCARACTER){
            valor = Casteo::charToInt(val);
        }
        if(tipo ==TENTERO){
            valor = Casteo::strToInt(val);
        }
        if(tipo ==TDOBLE){
            valor = Casteo::dobleToInt(Casteo::strToDoble(val));
        }
        if(Casteo::EsPrimo(valor)){
            primos.append(val);
        }else{
            noprimos.append(val);
        }
    }
    nueva.append(primos);
    nueva.append(noprimos);
    return nueva;
}



