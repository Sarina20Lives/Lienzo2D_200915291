#include "Interprete/interprete.h"
#include "Interprete/casteo.h"
#include "General/constantes.h"
#include "Editor/canvas.h"
#include <QColor>

void Interprete::ejecutarPrimitiva(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    if(func.getSubRol()==SRN_PINTAR_P){
        Interprete::pintarP(lienzo, ctxG, ctxL, func);
    }else if(func.getSubRol()==SRN_PINTAR_OR){
        Interprete::pintarOR(lienzo, ctxG, ctxL, func);
    }else if(func.getSubRol()==SRN_PINTAR_S){
        Interprete::pintarS(lienzo, ctxG, ctxL, func);
    }
}

void Interprete::pintarP(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *diametro = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    bool parametrosCorrectos = true;

    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(diametro->getTipo()!=TENTERO || diametro->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el diametro sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        parametrosCorrectos = false;
    }

    QColor color = QColor(colorH->getValor());

    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        parametrosCorrectos = false;
    }

    if(!parametrosCorrectos)
        return;

    int x = Casteo::strToInt(posX->getValor());
    int y = Casteo::strToInt(posY->getValor());
    int diam = Casteo::strToInt(diametro->getValor());
    Canvas *canvas = Canvas::getInstance();
    Elemento *elemento = Elemento::creaCirculo(x,y,diam, color);
    canvas->addElemento(elemento);
    canvas->update();
}

void Interprete::pintarOR(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *ancho = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    Resultado *alto = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(4));
    Resultado *figura = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(5));
    bool parametrosCorrectos = true;

    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(ancho->getTipo()!=TENTERO || ancho->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el ancho sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(alto->getTipo()!=TENTERO || alto->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el alto sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        parametrosCorrectos = false;
    }

    QColor color = QColor(colorH->getValor());

    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        parametrosCorrectos = false;
    }

    if(figura->getTipo()!=TCARACTER || figura->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la figura sea de tipo caracter.
        parametrosCorrectos = false;
    }

    if(!parametrosCorrectos)
        return;

    int x = Casteo::strToInt(posX->getValor());
    int y = Casteo::strToInt(posY->getValor());
    int w = Casteo::strToInt(ancho->getValor());
    int h = Casteo::strToInt(alto->getValor());
    Canvas *canvas = Canvas::getInstance();
    if(QString::compare(figura->getValor(), "r")==0){
        Elemento *elemento = Elemento::creaRectangulo(x,y,w,h,color);
        canvas->addElemento(elemento);
        canvas->update();
        return;
    }
    if(QString::compare(figura->getValor(), "o")==0){
        Elemento *elemento = Elemento::creaOvalo(x,y,w,h,color);
        canvas->addElemento(elemento);
        canvas->update();
        return;
    }
    //TODO-ERROR-El parametro de figura no es valido
}

void Interprete::pintarS(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *texto = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    bool parametrosCorrectos = true;
    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en X sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para la posicion en Y sea de tipo entero.
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el color sea de tipo cadena.
        parametrosCorrectos = false;
    } QColor color = QColor(colorH->getValor());
    if(!color.isValid()){
        //TODO-ERROR-El color no está escrito en un formato valido
        parametrosCorrectos = false;
    }
    if(texto->getTipo()!=TCADENA || texto->getEsArr()){
        //TODO-ERROR-Se requiere que el parametro para el texto sea de tipo cadena.
        parametrosCorrectos = false;
    }
    if(!parametrosCorrectos)
        return;
    int x = Casteo::strToInt(posX->getValor());
    int y =  Casteo::strToInt(posY->getValor());
    Canvas *canvas = Canvas::getInstance();
    Elemento *elemento = Elemento::creaTexto(x,y, color, texto->getValor());
    canvas->addElemento(elemento);
    canvas->update();
}
