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
}

AreaGrafica::~AreaGrafica() {
    delete ui;
}

void AreaGrafica::erase(){
    QLayoutItem* child;
    while(ui->verticalLayout->count()!=0){
        child = ui->verticalLayout->takeAt(0);
        if(child->widget() != 0) {
            delete child->widget();
        }
        delete child;
    }
    lienzo = Canvas::resetInstance();
    lienzo->setStyleSheet("background-color:#FFFFFF;");
    ui->verticalLayout->addWidget(lienzo);
}

void AreaGrafica::on_pushBtn_Publicar_clicked() {
    Canvas *l = Canvas::getInstance();
    QImage img(l->size(), QImage::Format_ARGB32);
    QPainter painter(&img);
    l->render(&painter);
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    img.save(&buffer, "PNG");
    QString encoded = QString(byteArray.toBase64());

    QJsonObject jsonObject;
    jsonObject["titulo"] = ui->txt_Titulo->text();
    jsonObject["descripcion"] = ui->txt_Descripcion->toPlainText();
    jsonObject["fecha"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    jsonObject["imagen"] = encoded;
    QJsonDocument doc(jsonObject);

    QNetworkAccessManager *networkManager = new QNetworkAccessManager;
    QNetworkRequest req(QUrl("http://localhost:5000/publica"));
    req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    QByteArray datos;
    datos.append("json=");
    datos.append(escaparDatos(QString(doc.toJson())));
    networkManager->post(req, datos);
}

QString AreaGrafica::escaparDatos(QString data){
    data = data.replace("%", "%25");
    data = data.replace("\n", "%0A");
    data = data.replace("\\", "%5C");
    data = data.replace(" ", "%20");
    data = data.replace("<", "%3C");
    data = data.replace(">", "%3E");
    data = data.replace("#", "%23");
    data = data.replace("{", "%7B");
    data = data.replace("}", "%7D");
    data = data.replace("|", "%7C");
    data = data.replace("^", "%5E");
    data = data.replace("~", "%7E");
    data = data.replace("[", "%5B");
    data = data.replace("]", "%5D");
    data = data.replace("`", "%60");
    data = data.replace(";", "%3B");
    data = data.replace("/", "%2F");
    data = data.replace("?", "%3F");
    data = data.replace(":", "%3A");
    data = data.replace("@", "%40");
    data = data.replace("=", "%3D");
    data = data.replace("&", "%26");
    data = data.replace("+", "%2B");
    data = data.replace("*", "%2A");
    return data.replace("$", "%24");
}
