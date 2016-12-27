#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T17:31:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lienzo2D_200915291
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    Gramatica/lexico_lienzo.cpp \
    Gramatica/sintactico_lienzo.cpp \
    Ast/lienzo.cpp \
    Ast/metodo.cpp \
    Ast/nodo.cpp \
    TablaSimbolos/simbolo.cpp \
    Editor/manejoarchivos.cpp \
    Interprete/resultado.cpp \
    Interprete/casteo.cpp \
    Interprete/interprete.cpp \
    analisis.cpp \
    Ast/Expresion/nodo_relacional.cpp \
    TablaSimbolos/contexto.cpp \
    Interprete/Sentencia/_metodo.cpp \
    Interprete/Sentencia/_declaracion.cpp \
    Interprete/Sentencia/_for.cpp \
    Interprete/Sentencia/_while.cpp \
    Interprete/Expresion/_aritmetica.cpp \
    Interprete/Expresion/_expresion.cpp \
    Interprete/Expresion/_llamada.cpp \
    Interprete/Expresion/_logica.cpp \
    Interprete/Expresion/_relacional.cpp \
    Ast/Expresion/aritmetica.cpp \
    Ast/Expresion/logica.cpp \
    Ast/Expresion/operando.cpp \
    Ast/Sentencia/asignacion.cpp \
    Ast/Sentencia/bucle.cpp \
    Ast/Sentencia/declaracion.cpp \
    Ast/Sentencia/flujo.cpp \
    Ast/Sentencia/funarreglo.cpp \
    Ast/Sentencia/funprimitiva.cpp \
    Ast/Sentencia/otro.cpp \
    Interprete/Sentencia/_sentencia.cpp \
    Interprete/Sentencia/_asignacion.cpp \
    Interprete/Sentencia/_if.cpp \
    Interprete/Sentencia/_hacer.cpp \
    Interprete/Sentencia/_comprobar.cpp \
    Interprete/Sentencia/_funarreglo.cpp \
    Interprete/Sentencia/_funprimitiva.cpp \
    Editor/codeeditor.cpp \
    Editor/extras.cpp \
    Editor/areagrafica.cpp \
    Editor/lienzografico.cpp \
    Editor/elemento.cpp

HEADERS  += principal.h \
    Gramatica/lexico_lienzo.h \
    Gramatica/lexico_lienzo.l \
    Gramatica/sintactico_lienzo.h \
    Gramatica/sintactico_lienzo.y \
    Ast/lienzo.h \
    Ast/metodo.h \
    Ast/nodo.h \
    TablaSimbolos/simbolo.h \
    General/constantes.h \
    Editor/manejoarchivos.h \
    Interprete/resultado.h \
    Interprete/casteo.h \
    Interprete/interprete.h \
    TablaSimbolos/contexto.h \
    Editor/codeeditor.h \
    Editor/areagrafica.h \
    Editor/lienzografico.h \
    Editor/elemento.h

FORMS    += principal.ui \
    Editor/areagrafica.ui

DISTFILES += \
    Recursos/Lienzos/Mouse.lz \
    Recursos/Lienzos/PlantillaTS.html \
    Recursos/Lienzos/TS.html \
    TablaSimbolos/PlantillaTS.html \
    Recursos/Lienzos/Mouse.txt

RESOURCES += \
    Recursos/recursos.qrc
