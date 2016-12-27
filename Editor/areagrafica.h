#ifndef AREAGRAFICA_H
#define AREAGRAFICA_H
#include <QWidget>
#include "lienzografico.h"

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
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::AreaGrafica *ui;
    int x;
    int y;
    int diametro;
    QColor color;
    LienzoGrafico *lienzo;

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // AREAGRAFICA_H
