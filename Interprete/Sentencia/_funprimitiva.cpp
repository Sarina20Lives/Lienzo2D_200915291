#include "Interprete/interprete.h"
#include "Interprete/casteo.h"
#include "General/constantes.h"
#include <QColor>

void Interprete::ejecutarPrimitiva(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    if(func.getSubRol()==SRN_PINTAR_P){
        Interprete::pintarP(lienzo, ctxG, ctxL, func);
    }
    if(func.getSubRol()==SRN_PINTAR_OR){
        Interprete::pintarOR(lienzo, ctxG, ctxL, func);
    }
    if(func.getSubRol()==SRN_PINTAR_S){
        Interprete::pintarS(lienzo, ctxG, ctxL, func);
    }
}

void Interprete::pintarP(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *diametro = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        return;
    }
    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        return;
    }
    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        return;
    }
    if(diametro->getTipo()!=TENTERO || diametro->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el diametro sea de tipo entero.
        return;
    }
    QColor color = QColor(colorH->getValor());
    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        return;
    }
    //punto(Casteo::strToInt(posX->getValor()), Casteo::strToInt(posY->getValor()), color, Casteo::strToInt(diametro->getValor())/2);
}

void Interprete::pintarOR(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *ancho = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    Resultado *alto = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(4));
    Resultado *figura = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(5));
    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        return;
    }
    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        return;
    }
    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        return;
    }
    if(ancho->getTipo()!=TENTERO || ancho->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el ancho sea de tipo entero.
        return;
    }
    if(alto->getTipo()!=TENTERO || alto->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el alto sea de tipo entero.
        return;
    }
    if(figura->getTipo()!=TCARACTER || figura->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la figura sea de tipo caracter.
        return;
    }

    QColor color = QColor(colorH->getValor());
    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        return;
    }

    if(QString::compare(figura->getValor(), "r")==0){
       //cuadro(Casteo::strToInt(posX->getValor()), Casteo::strToInt(posY->getValor()), color, Casteo::strToInt(ancho->getValor()), Casteo::strToInt(alto->getValor()));
       return;
    }
    if(QString::compare(figura->getValor(), "o")==0){
       //ovalo(Casteo::strToInt(posX->getValor()), Casteo::strToInt(posY->getValor()), color, Casteo::strToInt(ancho->getValor()), Casteo::strToInt(alto->getValor()));
       return;
    }

    //TODO-ERROR-El parametro de figura no es valido
}

void Interprete::pintarS(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *texto = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        return;
    }
    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        return;
    }
    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        return;
    }
    if(texto->getTipo()!=TCADENA || texto->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el texto sea de tipo cadena.
        return;
    }

    QColor color = QColor(colorH->getValor());
    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        return;
    }

    //print(Casteo::strToInt(posX->getValor()), Casteo::strToInt(posY->getValor()), color, texto);
}
