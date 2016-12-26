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
        //TODO-ERROR-Lienzo no se pudo generar
        //QMessageBox::critical(this, "Error en el análisis","El lienzo no se puede generar.");
        return;
    }
    prin->setEsPrincipal(true);
    QList<Lienzo> * lnzs = new QList<Lienzo>();
    lnzs->append(*prin);
    Principal::agregarExtends(lnzs, *prin->getExtends());
    Interprete::lienzos = lnzs;
    Interprete::ejecutarPrincipal(prin->getNombre());

}


//AGREGAR EXTEND AL QLIST DE LIENZOS
void Principal::agregarExtends(QList<Lienzo> *lienzos, QList<QString> extends){
    QString direccion = "";
    QString contenido = "";
    Lienzo *lienzo;
    foreach (QString nombre, extends) {
        direccion = RAIZ + nombre + EXT;
        contenido = ManejoArchivos::abrirArchivo(direccion);
        lienzo = parselienzo(&contenido);
        if(lienzo==NULL){
            //TODO-ERROR-El lienzo no se pudo generar, comprobar archivos
            //QMessageBox::critical(this, "Error en el análisis","El lienzo "+nombre+" no se puede generar, comprobar Archivos.");
            return;
        }
        if(Principal::existeUnLienzo(lienzos, nombre)){
            //TODO-ERROR-Referencia redundante
            //QMessageBox::critical(this, "Error en el análisis","El lienzo "+nombre+" hace una referencia redundante.");
            return;
        }
        lienzos->append(*lienzo);
        Principal::agregarExtends(lienzos, *lienzo->getExtends());
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

