#include "principal.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal *w = new Principal;
    w->show();
    return a.exec();
}
