#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include "Interprete/casteo.h"

extern bool parselienzo();

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_pBanalizar_clicked()
{
    QString entrada = ui->pTEentrada->toPlainText();
    if(entrada==""){
        QMessageBox::critical(this, "Error en el análisis","No se admite una cadena vacia.");
        return;
    }
    Principal::analisis(entrada);
    QMessageBox::information(this, "Fin del análisis","El análisis ha sido exitoso.");

}

void Principal::on_pushButton_clicked()
{



}

void Principal::showInfo(QString mensaje)
{
    ui->statusBar->showMessage(mensaje, 5000);
}
