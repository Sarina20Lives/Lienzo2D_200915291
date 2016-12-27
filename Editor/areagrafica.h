#ifndef AREAGRAFICA_H
#define AREAGRAFICA_H
#include <QWidget>
#include "canvas.h"

namespace Ui {
class AreaGrafica;
}

class AreaGrafica : public QWidget
{
    Q_OBJECT

public:
    explicit AreaGrafica(QWidget *parent = 0);
    ~AreaGrafica();

private slots:
    void on_pushBtn_Publicar_clicked();

private:
    Ui::AreaGrafica *ui;
    int x;
    int y;
    int diametro;
    QColor color;
    Canvas *lienzo;

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // AREAGRAFICA_H
