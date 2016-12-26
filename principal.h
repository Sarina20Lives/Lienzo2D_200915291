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

    void showInfo(QString mensaje);
private slots:
    void mostrarPosicion();
    void on_pBanalizar_clicked();
    void on_pushButton_clicked();

private:
    Ui::Principal *ui;
    void nuevaPestania();
};

#endif // PRINCIPAL_H
