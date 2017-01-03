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
    void erase();

private slots:
    void on_pushBtn_Publicar_clicked();

private:
    Ui::AreaGrafica *ui;
    Canvas *lienzo;    
    QString escaparDatos(QString data);
};

#endif // AREAGRAFICA_H
