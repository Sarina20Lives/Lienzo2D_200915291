#include "Interprete/interprete.h"
#include "General/constantes.h"

Resultado *Interprete::resolverLlamada(QString lienzo, Contexto *ctxGlobal, Contexto *ctxLocal, Nodo exp){
    Resultado *resultado = new Resultado();

    QList<Resultado> *params = new QList<Resultado>();

    //RESOLVER PARAMETROS...
    Resultado *parametro = new Resultado();
    foreach (Nodo param, *exp.getHijos()) {
        parametro =Interprete::resolverExpresion(lienzo, ctxGlobal, ctxLocal, param);
        if(parametro->getTipo()==ERR || parametro->getRol() != NOTHING){
            //TODO-ERROR-Los parametros no son validos
            return resultado;
        }
        params->append(*parametro);
    }

    QString paramsToString = Interprete::getParamsToString(*params);

    //Buscar metodo en el lienzo actual
    Metodo encontrado = Interprete::searchMetodo(lienzo, exp.getCadena(), paramsToString);
    //Buscar y unir todos los metodos que correspondan al nombre
    QList<Metodo> allMtds = Interprete::searchMetodoExtend(lienzo, exp.getCadena(), paramsToString);
    //Agregar el del lienzo actual siempre que exista
    if(encontrado.getAcceso()!=ERR){
        allMtds.append(encontrado);
    }

    if(allMtds.count()==0){
        //TODO-ERROR-El metodo buscado no existe
        return resultado;
    }

    Contexto *ctxG2;
    Contexto *ctxL2;

    //Buscar el metodo que tenga conservar
    Metodo conservar = Interprete::searchMetodoConservar(allMtds);
    if(conservar.getAcceso()!=ERR){
        //Crear contexto Global...
        ctxG2 = Contexto::generarContextoGlobal(conservar.getLienzoPadre());
        ctxG2->agregarVariablesExtends(conservar.getLienzoPadre());
        //Crear contexto Local...
        ctxL2 = Contexto::generarContextoLocal(lienzo, conservar.getNombre(), conservar.getAcceso(), *conservar.getParametros(), *params);
        //ejecutar el metodo conservar
        return resultado = Interprete::ejecutarMtd(conservar.getLienzoPadre(), conservar.getNombre(), ctxG2, ctxL2, conservar);
    }

    //No existe un metodo que posea conservar y el metodo local si existe
    if(encontrado.getAcceso()!=ERR){
        //Crear contexto Global...
        ctxG2 = Contexto::generarContextoGlobal(encontrado.getLienzoPadre());
        ctxG2->agregarVariablesExtends(encontrado.getLienzoPadre());
        //Crear contexto Local...
        ctxL2 = Contexto::generarContextoLocal(lienzo, encontrado.getNombre(), encontrado.getAcceso(), *encontrado.getParametros(), *params);
        //ejecutar el metodo conservar
        return Interprete::ejecutarMtd(encontrado.getLienzoPadre(), encontrado.getNombre(), ctxG2, ctxL2, encontrado);

    }

    //No existe un metodo que posea conservar y el metodo local no existe
    Metodo seleccionado = allMtds.at(allMtds.count()-1);
    //Crear contexto Global...
    ctxG2 = Contexto::generarContextoGlobal(seleccionado.getLienzoPadre());
    ctxG2->agregarVariablesExtends(seleccionado.getLienzoPadre());
    //Crear contexto Local...
    ctxL2 = Contexto::generarContextoLocal(lienzo, seleccionado.getNombre(), seleccionado.getAcceso(), *seleccionado.getParametros(), *params);
    //ejecutar el metodo conservar
    return Interprete::ejecutarMtd(seleccionado.getLienzoPadre(), seleccionado.getNombre(), ctxG2, ctxL2, seleccionado);
}


QString Interprete::getParamsToString(QList<Resultado> params){
    QString paramsToString = "";
    QString temp = "";
    foreach (Resultado resultado, params) {
        paramsToString = temp + TIPOS[resultado.getTipo()];
        temp = paramsToString + "-";
    }
    return paramsToString;
}
