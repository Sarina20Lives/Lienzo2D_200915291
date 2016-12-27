#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <QColor>
#include <QRect>

class Elemento
{
public:
    enum Figura { Rectangulo, Ovalo, Circulo, Texto };
    Elemento(){ }
    Elemento(int x, int y, int diametro, int ancho, int alto, QColor color, QString cadena);
    bool es(Figura figura);
    static Elemento *creaOvalo(int x, int y, int ancho, int alto, QColor color);
    static Elemento *creaCirculo(int x, int y, int diametro, QColor color);
    static Elemento *creaRectangulo(int x, int y, int ancho, int alto, QColor color);
    static Elemento *creaTexto(int x, int y, QColor color, QString cadena);
    int getX() { return x; }
    int getY() { return y; }
    int getDiam() { return diametro; }
    int getAlto() { return alto; }
    int getAncho() { return ancho; }
    QColor getColor() { return color; }
    QString getCadena() { return cadena; }
    QRect rect() { QRect r(x, y, ancho, alto); return r; }
    QRect circ() { QRect c(x, y, diametro, diametro); return c; }
private:
    Figura figura;
    int x, y;
    int diametro, ancho, alto;
    QColor color;
    QString cadena;
};

#endif // ELEMENTO_H
