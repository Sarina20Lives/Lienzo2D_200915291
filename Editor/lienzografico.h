#ifndef LIENZOGRAFICO_H
#define LIENZOGRAFICO_H
#include <QList>
#include <QWidget>
#include <QRect>
#include "elemento.h"

class LienzoGrafico : public QWidget
{
    Q_OBJECT
public:
    LienzoGrafico(QWidget *parent = 0);
    void addElemento(Elemento *elem);
private:
    QList<Elemento> *elementos;
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#endif // LIENZOGRAFICO_H
