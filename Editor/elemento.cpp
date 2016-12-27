#include "elemento.h"

Elemento::Elemento(int x, int y, int diametro, int ancho, int alto, QColor color, QString cadena) {
    this->x = x;
    this->y = y;
    this->diametro = diametro;
    this->ancho = ancho;
    this->alto = alto;
    this->color = color;
    this->cadena = cadena;
    this->figura = Rectangulo;
}

bool Elemento::es(Figura figura) {
    return this->figura == figura;
}

Elemento *Elemento::creaOvalo(int x, int y, int ancho, int alto, QColor color) {
    Elemento *elem = new Elemento(x, y, 0, ancho, alto, color, "");
    elem->figura = Ovalo;
    return elem;
}

Elemento *Elemento::creaCirculo(int x, int y, int diametro, QColor color) {
    Elemento *elem = new Elemento(x, y, diametro, 0, 0, color, "");
    elem->figura = Circulo;
    return elem;
}

Elemento *Elemento::creaRectangulo(int x, int y, int ancho, int alto, QColor color) {
    Elemento *elem = new Elemento(x, y, 0, ancho, alto, color, "");
    elem->figura = Rectangulo;
    return elem;
}

Elemento *Elemento::creaTexto(int x, int y, QColor color, QString cadena) {
    Elemento *elem = new Elemento(x, y, 0, 0, 0, color, cadena);
    elem->figura = Texto;
    return elem;
}
