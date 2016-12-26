#include "Ast/nodo.h"
#include "General/constantes.h"

Nodo *Nodo::crearPintarP(Nodo posX, Nodo posY, Nodo color, Nodo diametro, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_PRIMITIVA;
    nodo->subrol = SRN_PINTAR_P;
    nodo->fila=fila;
    nodo->hijos->append(posX);
    nodo->hijos->append(posY);
    nodo->hijos->append(color);
    nodo->hijos->append(diametro);
    return nodo;
}

Nodo *Nodo::crearPintarOR(Nodo posX, Nodo posY, Nodo color, Nodo ancho, Nodo alto, Nodo figura, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_PRIMITIVA;
    nodo->subrol = SRN_PINTAR_OR;
    nodo->fila=fila;
    nodo->hijos->append(posX);
    nodo->hijos->append(posY);
    nodo->hijos->append(color);
    nodo->hijos->append(ancho);
    nodo->hijos->append(alto);
    nodo->hijos->append(figura);
    return nodo;
}

Nodo *Nodo::crearPintarS(Nodo posX, Nodo posY, Nodo color, Nodo cadena, int fila){
    Nodo *nodo = new Nodo();
    nodo->rol = RN_PRIMITIVA;
    nodo->subrol = SRN_PINTAR_S;
    nodo->fila=fila;
    nodo->hijos->append(posX);
    nodo->hijos->append(posY);
    nodo->hijos->append(color);
    nodo->hijos->append(cadena);
    return nodo;
}
