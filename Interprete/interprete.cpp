#include "interprete.h"
#include "General/constantes.h"

QList<Lienzo> *Interprete::lienzos;
ManejoErrores *Interprete::ma = ManejoErrores::getInstance();

Lienzo Interprete::searchLienzo(QString nombre){
    foreach (Lienzo lienzo, *Interprete::lienzos) {
        if(QString::compare(lienzo.getNombre(), nombre)==0){
            return lienzo;
        }
    }
    return *new Lienzo();
}


void Interprete::ejecutarPrincipal(QString lienzo){
    //Buscar metodo en el lienzo actual
    Metodo encontrado = Interprete::searchMetodo(lienzo, "Principal", "");
    //Buscar y unir todos los metodos que correspondan al nombre
    QList<Metodo> allMtds = Interprete::searchMetodoExtend(lienzo, "Principal", "");
    //Agregar el del lienzo actual siempre que exista
    if(encontrado.getAcceso()!=ERR){
        allMtds.append(encontrado);
    }

    if(allMtds.count()==0){
        //TODO-ERROR-El metodo buscado no existe
        return;
    }

    Contexto *ctxG;
    Contexto *ctxL = new Contexto();

    //Buscar el metodo que tenga conservar
    Metodo conservar = Interprete::searchMetodoConservar(allMtds);
    if(conservar.getAcceso()!=ERR){
        //Crear contexto Global...
        ctxG = Contexto::generarContextoGlobal(conservar.getLienzoPadre());
        ctxG->agregarVariablesExtends(conservar.getLienzoPadre());
        //ejecutar el metodo conservar
        Interprete::ejecutarMtd(conservar.getLienzoPadre(), conservar.getNombre(), ctxG, ctxL, conservar);
        return;
    }

    //No existe un metodo que posea conservar y el metodo local si existe
    if(encontrado.getAcceso()!=ERR){
        //Crear contexto Global...
        ctxG = Contexto::generarContextoGlobal(encontrado.getLienzoPadre());
        ctxG->agregarVariablesExtends(encontrado.getLienzoPadre());
        //ejecutar el metodo conservar
        Interprete::ejecutarMtd(encontrado.getLienzoPadre(), encontrado.getNombre(), ctxG, ctxL, encontrado);
        return;
    }

    //No existe un metodo que posea conservar y el metodo local no existe
    Metodo seleccionado = allMtds.at(allMtds.count()-1);
    //Crear contexto Global...
    ctxG = Contexto::generarContextoGlobal(seleccionado.getLienzoPadre());
    ctxG->agregarVariablesExtends(seleccionado.getLienzoPadre());
    //ejecutar el metodo conservar
    Interprete::ejecutarMtd(seleccionado.getLienzoPadre(), seleccionado.getNombre(), ctxG, ctxL, seleccionado);
}


QList<Lienzo> Interprete::searchExtends(QString nombre){
    QList<Lienzo> extendidos = *new QList<Lienzo>();

    //Seleccionando el lienzo actual
    Lienzo actual = Interprete::searchLienzo(nombre);
    if(actual.getAcceso() == ERR){
        return extendidos;
    }

    //Buscando Extends
    Lienzo encontrado;
    foreach (QString extend, *actual.getExtends()) {
        encontrado = Interprete::searchLienzo(extend);
        if(encontrado.getAcceso()!=ERR){
            extendidos.append(encontrado);
        }
    }

    return extendidos;
}

//OBTENCION DE METODOS... DE LOS LIENZOS EXTEND
QList<Metodo> Interprete::searchMetodoExtend(QString lienzoActual, QString nombre, QString paramsToStr){
    QList<Lienzo> extendidos = Interprete::searchExtends(lienzoActual);
    QList<Metodo> metds = *new QList<Metodo>();

    Metodo encontrado = *new Metodo();
    foreach (Lienzo lienzo, extendidos) {
          encontrado = Interprete::searchMetodo(lienzo.getNombre(), nombre, paramsToStr);
          if(encontrado.getAcceso()!=ERR || encontrado.getAcceso()!=A_PRI || encontrado.getAcceso()!=A_PRI_CON){
              metds.append(encontrado);
          }
   }
    return metds;
}


//OBTENCION DE METODOS CONSERVAR DE UN GRUPO DE METODOS
Metodo Interprete::searchMetodoConservar(QList<Metodo> metds){
    QList<Metodo> encontrados = *new QList<Metodo>();
    foreach (Metodo mtd, metds) {
        if(mtd.getAcceso()>A_PRI){
            encontrados.append(mtd);
        }
    }
    if(encontrados.count()==1){
        return encontrados.at(0);
    }
    if(encontrados.count()>1){
        //TODO-ERROR-DUPLICACION DE METODOS, EXISTE MÁS DE UN MÉTODO CON EL ATRIBUTO CONSERVAR
    }
    return *new Metodo();
}


//OBTENCION DE METODOS POR NOMBRE Y PARAMETROS DE UN LIENZO DETERMINADO
Metodo Interprete::searchMetodo(QString nombreL, QString nombre, QString paramsToStr){
    Lienzo lienzo = Interprete::searchLienzo(nombreL);
    foreach (Metodo mtd, *lienzo.getMetodos()) {
        if(QString::compare(mtd.getNombre(), nombre)==0 && QString::compare(mtd.getParamsToStr(), paramsToStr)==0){
            mtd.setLienzoPadre(lienzo.getNombre());
            return mtd;
        }
    }
    return *new Metodo();
}

