#include "areagrafica.h"
#include "ui_areagrafica.h"

AreaGrafica::AreaGrafica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AreaGrafica)
{
    ui->setupUi(this);
}

AreaGrafica::~AreaGrafica()
{
    delete ui;
}
