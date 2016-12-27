#include "canvas.h"

Canvas *Canvas::singleton = NULL;

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
    setAutoFillBackground(true);
    elementos = new QList<Elemento>;
}

Canvas *Canvas::getInstance() {
    if(singleton==NULL){
        singleton = new Canvas();
    }
    return singleton;
}

Canvas *Canvas::resetInstance() {
    singleton = new Canvas();
    return singleton;
}

void Canvas::addElemento(Elemento *elem) {
    elementos->append(*elem);
}

void Canvas::paintEvent(QPaintEvent * /* event */){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), QBrush(Qt::white));
    painter.setPen(QPen(QColor(0,0,0,0)));
    foreach (Elemento elem , *this->elementos){
        if(elem.es(Elemento::Rectangulo)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.setPen(QPen(QColor(0,0,0,0)));
            painter.drawRect(elem.rect());
        }else if(elem.es(Elemento::Circulo)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.setPen(QPen(QColor(0,0,0,0)));
            painter.drawEllipse(elem.circ());
        }else if(elem.es(Elemento::Ovalo)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.setPen(QPen(QColor(0,0,0,0)));
            painter.drawEllipse(elem.rect());
        }else if(elem.es(Elemento::Texto)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.setPen(QPen(elem.getColor()));
            painter.drawText(elem.getX(), elem.getY(), elem.getCadena());
        }
    }
}


