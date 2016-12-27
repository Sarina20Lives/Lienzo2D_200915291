#ifndef CASTEO_H
#define CASTEO_H
#include <QString>
#include "Interprete/resultado.h"

class Casteo
{
public:
    static int strToInt(QString valor);
    static QString intToStr(int valor);

    static double strToDoble(QString valor);
    static QString dobleToStr(double valor);

    static bool strToBool(QString valor);
    static int boolToInt(QString valor);
    static QString boolToStr(bool valor);


    static int charToInt(QString valor);
    static QString intToChar(int valor);
    static QString intToChar(QString valor);

    static double intToDoble(int valor);
    static double intToDoble(QString valor);
    static int dobleToInt(double valor);
    static int dobleToInt(QString valor);

    static int toInt(Resultado resultado);
    static double toDoble(Resultado resultado);
    static bool toBool(Resultado resultado);

    static Resultado toAsigVar(int tipo, Resultado resultado);


    static bool EsPrimo(int valor);
};

#endif // CASTEO_H
