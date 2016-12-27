#ifndef CANVAS_H
#define CANVAS_H
#include <QList>
#include <QWidget>
#include <QRect>
#include <QPainter>
#include "elemento.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    static Canvas *getInstance();
    static Canvas *resetInstance();
    void addElemento(Elemento *elem);

private:
    static Canvas *singleton;
    Canvas(QWidget *parent = 0);
    QList<Elemento> *elementos;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#endif // CANVAS_H
