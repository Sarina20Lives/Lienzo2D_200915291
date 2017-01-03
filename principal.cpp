#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include "Interprete/casteo.h"
#include "Editor/codeeditor.h"
#include "Interprete/interprete.h"

extern bool parselienzo();

Principal::Principal(QWidget *parent) : QMainWindow(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->actionNuevo, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Nuevo_clicked()));
    connect(ui->actionAbrir, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Abrir_clicked()));
    connect(ui->actionGuardar, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Guardar_clicked()));
    connect(ui->actionGuardarComo, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_GuardarComo_clicked()));
    connect(ui->actionCerrar, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Cerrar_clicked()));
    connect(ui->actionEjecutar, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Ejecutar_clicked()));
    connect(ui->actionIniciar, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Debuggear_clicked()));
    connect(ui->actionErrores, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_Errores_clicked()));
    connect(ui->actionTablaSimbolos, SIGNAL(triggered(bool)), this, SLOT(on_pushBtn_TablaSimbolos_clicked()));
    nuevaPestania();
    area = NULL;
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

void Principal::on_pushBtn_AreaGrafica_clicked() {
    abrirAreaGrafica();
}

void Principal::on_pushBtn_Ejecutar_clicked() {
    Interprete::desactivarDebug();
    analizarArchivo();
}

void Principal::on_pushBtn_Debuggear_clicked() {
    Interprete::activarDebug();
    analizarArchivo();
}

void Principal::on_pushBtn_Errores_clicked() {
    mostrarReporteErrores();
}

void Principal::on_pushBtn_TablaSimbolos_clicked() {
    mostrarReporteTablaSimbolos();
}

void Principal::on_vertSlider_Velocidad_valueChanged(int value) {
    Interprete::setPausa(value);
}

void Principal::on_actionDetener_Reanudar_triggered() {
    Interprete::triggerDebug();
}

void Principal::on_actionTerminar_triggered() {
    Interprete::desactivarDebug();
}
