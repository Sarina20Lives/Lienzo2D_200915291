#include "areagrafica.h"
#include "ui_areagrafica.h"
#include "QMouseEvent"
#include "QPainter"
#include "QColorDialog"
#include "QJsonObject"
#include "QJsonDocument"
#include "QDateTime"
#include <QtNetwork>

AreaGrafica::AreaGrafica(QWidget *parent) : QWidget(parent), ui(new Ui::AreaGrafica) {
    ui->setupUi(this);
    x = 0;
    y = 0;
    diametro = 20;
    color = QColor("#000");
    lienzo = Canvas::resetInstance();
    lienzo->setStyleSheet("background-color:#FFFFFF;");
    ui->verticalLayout_3->addWidget(lienzo);
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

void AreaGrafica::on_pushBtn_Publicar_clicked() {
    Canvas *l = Canvas::getInstance();
    QImage img(l->size(), QImage::Format_ARGB32);
    QPainter painter(&img);
    l->render(&painter);
    img.save("/home/esvux/inicio.png");
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    img.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer
    QString imageBase64(byteArray.toBase64().data());
    QNetworkAccessManager *networkManager = new QNetworkAccessManager;
    QByteArray datos;
    QJsonObject jsonObject;
    jsonObject["titulo"] = ui->txt_Titulo->text();
    jsonObject["descripcion"] = ui->txt_Descripcion->toPlainText();
    jsonObject["fecha"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    jsonObject["imagen"] = imageBase64;
    QJsonDocument doc(jsonObject);
    datos.append("json="+doc.toJson());
    networkManager->post(QNetworkRequest(QUrl("http://127.0.0.1:5000/publica")), datos);
}

