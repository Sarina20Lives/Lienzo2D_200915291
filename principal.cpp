#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include "Interprete/casteo.h"
#include "Editor/codeeditor.h"

extern bool parselienzo();

Principal::Principal(QWidget *parent) : QMainWindow(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);
    nuevaPestania();
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

void Principal::on_pushBtn_Nuevo_clicked() {
    nuevaPestania();
}

void Principal::on_pushBtn_Abrir_clicked() {
    abrirArchivo();
}

void Principal::on_pushBtn_Guardar_clicked() {
    guardarArchivo();
}

void Principal::on_pushBtn_GuardarComo_clicked() {
    guardarArchivoComo();
}

void Principal::on_pushBtn_Cerrar_clicked() {
    cerrarArchivo();
}

void Principal::on_pushBtn_AreaGrafica_clicked()
{
    abrirAreaGrafica();
}

void Principal::on_pushBtn_Ejecutar_clicked()
{
    QString entrada = ui->pTEentrada->toPlainText();
    if(entrada==""){
        QMessageBox::critical(this, "Error en el análisis","No se admite una cadena vacia.");
        return;
    }
    Principal::analisis(entrada);
    QMessageBox::information(this, "Fin del análisis","El análisis ha sido exitoso.");
}

void Principal::on_pushBtn_Debuggear_clicked()
{

}

void Principal::on_pushBtn_Errores_clicked()
{

}

void Principal::on_pushBtn_TablaSimbolos_clicked()
{

}
