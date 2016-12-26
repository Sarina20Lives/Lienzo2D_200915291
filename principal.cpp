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

void Principal::showInfo(QString mensaje)
{
    ui->statusBar->showMessage(mensaje, 5000);
}

void Principal::nuevaPestania()
{
    CodeEditor *editor = new CodeEditor;
    connect(editor, SIGNAL(cursorPositionChanged()), this, SLOT(mostrarPosicion()));
    ui->tabArchivos->addTab(editor, "Pestania nueva *");
}

void Principal::mostrarPosicion()
{
    QTextCursor cursor = ((CodeEditor*)ui->tabArchivos->currentWidget())->textCursor();
    QString posicion = QString("Línea: %1   Columna: %2").arg(cursor.blockNumber()+1).arg(cursor.columnNumber()+1);
    ui->statusBar->showMessage(posicion);
}
