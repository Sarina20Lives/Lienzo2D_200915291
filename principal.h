#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include "Ast/lienzo.h"

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
    static void agregarExtends(QList<Lienzo> *lienzos, QList<QString> extends);
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

private:
    Ui::Principal *ui;
    void nuevaPestania();
    void abrirAreaGrafica();
    void showInfo(QString mensaje);
    void abrirArchivo();
    void guardarArchivo(){ guardarArchivo(false); }
    void guardarArchivoComo(){ guardarArchivo(true); }
    void guardarArchivo(bool guardarComo);
    void cerrarArchivo();
};

#endif // PRINCIPAL_H
