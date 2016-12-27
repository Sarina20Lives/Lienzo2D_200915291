#include "lienzografico.h"
#include "elemento.h"
#include "qpainter.h"

LienzoGrafico::LienzoGrafico(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
    setAutoFillBackground(true);
    elementos = new QList<Elemento>;
}

void LienzoGrafico::addElemento(Elemento *elem) {
    elementos->append(*elem);
}

void LienzoGrafico::paintEvent(QPaintEvent * /* event */){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), QBrush(Qt::white));
    painter.setPen(QPen(QColor(0,0,0,0)));
    foreach (Elemento elem , *this->elementos){
        if(elem.es(Elemento::Rectangulo)){
            painter.setBrush(QBrush(elem.getColor()));
            QRect r = elem.rect();
            painter.drawRect(r);
        }else if(elem.es(Elemento::Circulo)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.drawEllipse(elem.circ());
        }else if(elem.es(Elemento::Ovalo)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.drawEllipse(elem.rect());
        }else if(elem.es(Elemento::Texto)){
            painter.setBrush(QBrush(elem.getColor()));
            painter.drawText(elem.getX(), elem.getY(), elem.getCadena());
        }
    }
}


