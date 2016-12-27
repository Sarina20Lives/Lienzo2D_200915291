#include "areagrafica.h"
#include "ui_areagrafica.h"
#include "QMouseEvent"
#include "QPainter"
#include "QColorDialog"
#include "stdio.h"

AreaGrafica::AreaGrafica(QWidget *parent) : QWidget(parent), ui(new Ui::AreaGrafica) {
    ui->setupUi(this);
    x = 0;
    y = 0;
    diametro = 20;
    color = QColor("#0F0");
    lienzo = new LienzoGrafico();
    lienzo->setStyleSheet("background-color:#FFFFFF;");
    ui->verticalLayout->addWidget(lienzo);
}

AreaGrafica::~AreaGrafica() {
    delete ui;
}

void AreaGrafica::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->x = event->x()-12;
        this->y = event->y()-57;
    }
}

void AreaGrafica::on_pushButton_clicked()
{
    Elemento *e = Elemento::creaRectangulo(x, y, 100, 60, color);
    lienzo->addElemento(e);
    lienzo->update();
}

void AreaGrafica::on_pushButton_2_clicked()
{
    Elemento *e = Elemento::creaOvalo(x, y, 20, 60, QColor("#FF0"));
    lienzo->addElemento(e);
    lienzo->update();
}

void AreaGrafica::on_pushButton_3_clicked()
{

}

void AreaGrafica::on_pushButton_4_clicked()
{

}

void AreaGrafica::on_pushButton_5_clicked()
{
    QColor temp = QColorDialog::getColor();
    if(temp.isValid()){
        color = temp;
    }
}
