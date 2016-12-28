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
        ma->addErrorSemantico("Se requiere que el parametro para la posición x sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para la posición y sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(diametro->getTipo()!=TENTERO || diametro->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el diametro sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el color sea de tipo cadena", func.getFila());
        parametrosCorrectos = false;
    }

    QColor color = QColor(colorH->getValor());

    if(!color.isValid()){
        ma->addErrorSemantico("La definición del color no es valida", func.getFila());
        parametrosCorrectos = false;
    }

    if(!parametrosCorrectos)
        return;

    int x = Casteo::strToInt(posX->getValor())+Casteo::dobleToInt(Casteo::strToDoble(diametro->getValor())/2);
    int y = Casteo::strToInt(posY->getValor())+Casteo::dobleToInt(Casteo::strToDoble(diametro->getValor())/2);
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
        ma->addErrorSemantico("Se requiere que el parametro para la posición x sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para la posición y sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(ancho->getTipo()!=TENTERO || ancho->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el ancho sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(alto->getTipo()!=TENTERO || alto->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el alto sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el color sea de tipo cadena", func.getFila());
        parametrosCorrectos = false;
    }

    QColor color = QColor(colorH->getValor());

    if(!color.isValid()){
        ma->addErrorSemantico("El color no está escrito en un formato valido", func.getFila());
        parametrosCorrectos = false;
    }

    if(figura->getTipo()!=TCARACTER || figura->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para la figura sea de tipo caracter", func.getFila());
        parametrosCorrectos = false;
    }

    if(!parametrosCorrectos)
        return;

    int x = Casteo::strToInt(posX->getValor())+Casteo::dobleToInt(Casteo::strToDoble(ancho->getValor())/2);
    int y = Casteo::strToInt(posY->getValor()+Casteo::dobleToInt(Casteo::strToDoble(alto->getValor())/2));
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
    ma->addErrorSemantico("El parametro figura no es valido", func.getFila());

}

void Interprete::pintarS(QString lienzo, Contexto *ctxG, Contexto *ctxL, Nodo func){
    Resultado *posX = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(0));
    Resultado *posY = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(1));
    Resultado *colorH = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(2));
    Resultado *texto = Interprete::resolverExpresion(lienzo, ctxG, ctxL, func.getHijo(3));
    bool parametrosCorrectos = true;
    if(posX->getTipo()!=TENTERO || posX->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para la posición x sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(posY->getTipo()!=TENTERO || posY->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para la posición y sea de tipo entero", func.getFila());
        parametrosCorrectos = false;
    }

    if(colorH->getTipo()!=TCADENA || colorH->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el color sea de tipo cadena", func.getFila());
        parametrosCorrectos = false;
    } QColor color = QColor(colorH->getValor());
    if(!color.isValid()){
        ma->addErrorSemantico("El color no está escrito en un formato valido", func.getFila());
        parametrosCorrectos = false;
    }
    if(texto->getTipo()!=TCADENA || texto->getEsArr()){
        ma->addErrorSemantico("Se requiere que el parametro para el texto sea de tipo cadena", func.getFila());
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
