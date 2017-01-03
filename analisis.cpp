#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include "General/constantes.h"
#include "Gramatica/sintactico_lienzo.h"
#include "Gramatica/lexico_lienzo.h"
#include "Editor/manejoarchivos.h"
#include "Interprete/interprete.h"

//INICIO DE ANALISIS
void Principal::analisis(QString contenido){
    Lienzo *prin = parselienzo(&contenido);
    if (prin == NULL){
        ManejoErrores::addErrorSemantico("El lienzo no se pudo generar.", 0);
        return;
    }
    QList<Simbolo> *ts = new QList<Simbolo>();
    QList<Lienzo> * lnzs = new QList<Lienzo>();
    ts->append(*getTS());
    prin->setEsPrincipal(true);
    lnzs->append(*prin);
    Principal::agregarExtends(ts, lnzs, *prin->getExtends());
    Interprete::lienzos = lnzs;
    Interprete::ejecutarPrincipal(prin->getNombre());
    Simbolo::reporte(*ts, prin->getNombre());
}


//AGREGAR EXTEND AL QLIST DE LIENZOS
void Principal::agregarExtends(QList<Simbolo> *ts, QList<Lienzo> *lienzos, QList<QString> extends){
    QString direccion = "";
    QString contenido = "";
    Lienzo *lienzo;
    foreach (QString nombre, extends) {
        direccion = ManejoArchivos::RAIZ + nombre + EXT;
        contenido = ManejoArchivos::abrirArchivo(direccion);
        lienzo = parselienzo(&contenido);
        if(lienzo==NULL){
            ManejoErrores::addErrorSemantico("El lienzo no se pudo generar, comprobar la existencia de los archivos.", 0);
            return;
        }
        if(Principal::existeUnLienzo(lienzos, nombre)){
            ManejoErrores::addErrorSemantico("Referencia de extends redudante.", 0);
            return;
        }
        ts->append(*getTS());
        lienzos->append(*lienzo);
        Principal::agregarExtends(ts, lienzos, *lienzo->getExtends());
    }
}

//VERIFICANDO QUE EXISTA UN LIENZO CON NOMBRE ESPECIFICO
bool Principal::existeUnLienzo(QList<Lienzo> *lienzos, QString nombre){
    foreach (Lienzo lienzo, *lienzos) {
        if(QString::compare(lienzo.getNombre(), nombre)==0){
            return true;
        }
    }
    return false;
}

