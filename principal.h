#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QThread>
#include "Ast/lienzo.h"
#include "TablaSimbolos/simbolo.h"
#include "Editor/areagrafica.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();
    static bool existeUnLienzo(QList<Lienzo> *lienzos, QString nombre);    
    static void agregarExtends(QList<Simbolo> *ts, QList<Lienzo> *lienzos, QList<QString> extends, int fila);
    static void analisis(QString contenido);

private slots:
    void mostrarPosicion();
    void on_pBanalizar_clicked();
    void on_pushButton_clicked();
    void on_pushBtn_Nuevo_clicked();
    void on_pushBtn_Abrir_clicked();
    void on_pushBtn_Guardar_clicked();
    void on_pushBtn_GuardarComo_clicked();
    void on_pushBtn_Cerrar_clicked();
    void on_pushBtn_AreaGrafica_clicked();
    void on_pushBtn_Ejecutar_clicked();
    void on_pushBtn_Debuggear_clicked();
    void on_pushBtn_Errores_clicked();
    void on_pushBtn_TablaSimbolos_clicked();
    void on_vertSlider_Velocidad_valueChanged(int value);
    void on_actionTerminar_triggered();
    void on_actionDetenerReanudar_triggered();

private:
    Ui::Principal *ui;
    AreaGrafica *area;
    void nuevaPestania();
    void abrirAreaGrafica();
    void showInfo(QString mensaje);
    void abrirArchivo();
    void guardarArchivo(){ guardarArchivo(false); }
    void guardarArchivoComo(){ guardarArchivo(true); }
    void guardarArchivo(bool guardarComo);
    void cerrarArchivo();
    void analizarArchivo();
    void mostrarReporteErrores();
    void mostrarReporteTablaSimbolos();
};


class HiloDebug : public QThread{
private:
    QString cadena;
public:
    void setCadena(QString cadena);
protected:
    void run();
};


#endif // PRINCIPAL_H
