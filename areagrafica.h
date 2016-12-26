#ifndef AREAGRAFICA_H
#define AREAGRAFICA_H

#include <QWidget>

namespace Ui {
class AreaGrafica;
}

class AreaGrafica : public QWidget
{
    Q_OBJECT

public:
    explicit AreaGrafica(QWidget *parent = 0);
    ~AreaGrafica();

private:
    Ui::AreaGrafica *ui;
};

#endif // AREAGRAFICA_H
