#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "qstring.h"

const QString RAIZ                = "/home/sarina/QtProjects/Lienzo2D_200915291/Lienzo2D_200915291/Recursos/Lienzos/";
const QString EXT                 = ".lz";
const QString RUTA_PLANTILLA_TS   = RAIZ + "PlantillaTS.html";
const QString RUTA_TS             = RAIZ + "TS.html";

const int ERR                     =  -2;
const int NOTHING                 =  -1;

/* ------------------------------------------------------------------------------------------------------------ *
 *  Roles para nodos
 * ------------------------------------------------------------------------------------------------------------ */
const int RN_ARITMETICA           =   0;
const int RN_RELACIONAL           =   2;
const int RN_LOGICA               =   4;
const int RN_LLAMADA              =   6;
const int RN_VAR                  =   8;
const int RN_ARR                  =  10;
const int RN_OPERANDO             =  12;
const int RN_PAUSA                =  14;
const int RN_SI                   =  16;
const int RN_CASO                 =  18;
const int RN_COMPROBAR            =  20;
const int RN_PARA                 =  22;
const int RN_MIENTRAS             =  24;
const int RN_HACER                =  26;
const int RN_SALIR                =  28;
const int RN_CONTINUAR            =  29;
const int RN_RETORNA              =  30;
const int RN_DECLARE              =  32;
const int RN_PRIMITIVA            =  36;
const int RN_ORDENAR              =  38;
const int RN_SUMARIZAR            =  40;
const int RN_REF_ARR              =  42;
const int RN_ASIG_VAR             =  44;
const int RN_ASIG_ARR             =  46;
const int RN_SENTENCIAS           =  48;
const int RN_DIMENCIONES          =  50;

/* ------------------------------------------------------------------------------------------------------------ *
 *  SubRol para Nodos
 * ------------------------------------------------------------------------------------------------------------ */
const int SRN_SUM                 =   0;
const int SRN_SUB                 =   2;
const int SRN_MUL                 =   4;
const int SRN_DIV                 =   6;
const int SRN_POW                 =   8;
const int SRN_DIRECTO             =  10;
const int SRN_INC                 =  12;
const int SRN_DEC                 =  14;
const int SRN_SUM_SIMPLY          =  16;
const int SRN_SUB_SIMPLY          =  18;

const int SRN_MAY                 =  20;
const int SRN_MEN                 =  22;
const int SRN_MAY_IGUAL           =  24;
const int SRN_MEN_IGUAL           =  26;
const int SRN_IGUAL               =  28;
const int SRN_DIFERENTE           =  30;
const int SRN_NULO                =  32;

const int SRN_XOR                 =  34;
const int SRN_OR                  =  36;
const int SRN_NOR                 =  38;
const int SRN_AND                 =  40;
const int SRN_NAND                =  42;
const int SRN_NOT                 =  44;

const int SRN_VAR                 =  46;
const int SRN_ARR                 =  48;
const int SRN_PARAM               =  50;
const int SRN_PINTAR_P            =  52;
const int SRN_PINTAR_OR           =  54;
const int SRN_PINTAR_S            =  56;

const int SRN_OPERANDO            =  62;
const int SRN_VAL_ARR             =  64;

const int SRN_ASC                =   66;
const int SRN_DESC               =   68;
const int SRN_PAR                =   70;
const int SRN_IMPAR              =   72;
const int SRN_PRIMO              =   74;


/* ------------------------------------------------------------------------------------------------------------ *
 *  Roles para simbolos
 * ------------------------------------------------------------------------------------------------------------ */
const int RS_METODO           =   0;
const int RS_VAR              =   1;
const int RS_PARAMETRO        =   2;
const int RS_ARREGLO          =   3;
const int RS_LIENZO           =   4;
const QString ROLES[]     = {"Metodo", "Variable", "Parametro", "Arreglo", "Lienzo"};

/* ------------------------------------------------------------------------------------------------------------ *
 *  Tipos
 * ------------------------------------------------------------------------------------------------------------ */
const int TVOID              =   0;
const int TENTERO            =   1;
const int TDOBLE             =   2;
const int TCARACTER          =   3;
const int TCADENA            =   4;
const int TBOOLEAN           =   5;
const QString TIPOS[]     = {"Void", "Entero", "Doble", "Caracter", "Cadena", "Boolean"};


/* ------------------------------------------------------------------------------------------------------------ *
 *  Visualizacion
 * ------------------------------------------------------------------------------------------------------------ */
const int V_PUB               =   1;
const int V_PRO               =   2;
const int V_PRI               =   3;

/* ------------------------------------------------------------------------------------------------------------ *
 *  Acceso
 * ------------------------------------------------------------------------------------------------------------ */
const int A_PUB               =   1;
const int A_PRO               =   2;
const int A_PRI               =   3;
const int A_PUB_CON           =   4;
const int A_PRO_CON           =   5;
const int A_PRI_CON           =   6;
const QString ACCESOS[]     = {"Publico", "Publico", "Protegido", "Privado", "Conservar Publico", "Conservar Protegido", "Conservar Privado"};


#endif // CONSTANTES_H
