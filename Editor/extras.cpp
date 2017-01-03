#include "principal.h"
#include "ui_principal.h"
#include "Editor/codeeditor.h"
#include "areagrafica.h"
#include "qfiledialog.h"
#include "qdesktopservices.h"
#include "qmessagebox.h"
#include "General/constantes.h"
#include "Errores/errores.h"
#include "manejoarchivos.h"

void Principal::analizarArchivo() {
    ManejoErrores::resetInstance();
    area->erase();
    int i = ui->tabArchivos->currentIndex();
    if(i < 1)  return;
    CodeEditor *editor = (CodeEditor*)ui->tabArchivos->currentWidget();
    QString entrada = editor->toPlainText();
    if(entrada==""){
        QMessageBox::critical(this, "Error en el análisis", "No se admite una cadena vacia.");
        return;
    }
    HiloDebug *hilo = new HiloDebug;
    hilo->setCadena(entrada);
    hilo->start();
}

void HiloDebug::setCadena(QString cadena) {
    this->cadena = cadena;
}

void HiloDebug::run() {
    Principal::analisis(cadena);
}


void Principal::nuevaPestania()
{
    CodeEditor *editor = new CodeEditor;
    connect(editor, SIGNAL(cursorPositionChanged()), this, SLOT(mostrarPosicion()));
    int i = ui->tabArchivos->addTab(editor, editor->getTitle());
    ui->tabArchivos->setCurrentIndex(i);
}

void Principal::abrirArchivo()
{
    int i = ui->tabArchivos->currentIndex();
    if(i < 1)  return;
    QString pathTemp = QFileDialog::getOpenFileName(this, "Seleccione el lienzo...", ManejoArchivos::RAIZ, "Archivos de Lienzos (*.lz)");
    if(pathTemp.isEmpty()) return;
    CodeEditor *editor = (CodeEditor*)ui->tabArchivos->currentWidget();
    editor->readFile(pathTemp);
    ui->tabArchivos->setTabText(i, editor->getTitle());
}

void Principal::guardarArchivo(bool guardarComo)
{
    int i = ui->tabArchivos->currentIndex();
    if(i < 1)  return;
    CodeEditor *editor = (CodeEditor*)ui->tabArchivos->currentWidget();
    QString pathTemp = editor->getPath();
    if(guardarComo || editor->getTitle().contains("*")){
         pathTemp = QFileDialog::getSaveFileName(this, "Seleccione el lienzo...", ManejoArchivos::RAIZ, "Archivos de Lienzos (*.lz)");
        if(pathTemp.isEmpty()) return;
    }
    editor->writeFile(pathTemp);
    ui->tabArchivos->setTabText(i, editor->getTitle());
}

void Principal::cerrarArchivo() {
    int i = ui->tabArchivos->currentIndex();
    if(i < 1)  return;
    ui->tabArchivos->removeTab(i);
}

void Principal::mostrarPosicion() {
    QTextCursor cursor = ((CodeEditor*)ui->tabArchivos->currentWidget())->textCursor();
    QString posicion = QString("Línea: %1   Columna: %2").arg(cursor.blockNumber()+1).arg(cursor.columnNumber()+1);
    ui->statusBar->showMessage(posicion);
}

void Principal::showInfo(QString mensaje) {
    ui->statusBar->showMessage(mensaje, 5000);
}

void Principal::abrirAreaGrafica() {
    if(area==NULL)
        area = new AreaGrafica();
    area->erase();
    area->show();    
}

void Principal::mostrarReporteErrores() {
    QDesktopServices::openUrl(QUrl(RUTA_ERR));
}

void Principal::mostrarReporteTablaSimbolos() {
    QDesktopServices::openUrl(QUrl(RUTA_TS));
}
