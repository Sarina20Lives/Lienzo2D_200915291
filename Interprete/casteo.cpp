#include "casteo.h"
#include "General/constantes.h"

int Casteo::strToInt(QString valor){
    int casteo = valor.toInt();
    return casteo;
}

QString Casteo::intToStr(int valor){
    return QString::number(valor);
}

double Casteo::strToDoble(QString valor){
    double casteo = valor.toDouble();
    return casteo;
}

QString Casteo::dobleToStr(double valor){
    return QString::number(valor);
}

bool Casteo::strToBool(QString valor){
    if(valor=="0" || valor =="false"){
        return false;
    }
    return true;
}

QString Casteo::boolToStr(bool valor){
    if(valor){
        return "true";
    }
    return "false";
}

int Casteo::boolToInt(QString valor){
    if(valor == "true" || valor == "1"){
        return 1;
    }
    return 0;
}

int Casteo::charToInt(QString valor){
    QByteArray array = valor.toLocal8Bit();
    char* buffer = array.data();
    int casteo = (int)buffer[0];
    return casteo;
}

QString Casteo::intToChar(int valor){
    QString casteo = QChar((char)valor);
    return casteo;
}

QString Casteo::intToChar(QString valor){
    int valint = Casteo::strToInt(valor);
    if(valint < 32 || valint > 126){
        //TODO-ERROR-Conversion de char fuera de los limites...
        return "";
    }
    return Casteo::intToChar(valint);
}

double Casteo::intToDoble(int valor){
    return (double)valor;
}

double Casteo::intToDoble(QString valor){
    return (double)(Casteo::strToInt(valor));
}

int Casteo::dobleToInt(double valor){
    return (int)valor;
}

int Casteo::dobleToInt(QString valor){
    double val = Casteo::strToDoble(valor);
    return Casteo::dobleToInt(val);
}

int Casteo::toInt(Resultado resultado)
{
    if(resultado.getTipo()==TENTERO){
        return strToInt(resultado.getValor());
    }
    if(resultado.getTipo()==TDOBLE){
        return dobleToInt(resultado.getValor());
    }
    if(resultado.getTipo()==TCARACTER){
        return charToInt(resultado.getValor());
    }
    if(resultado.getTipo()==TBOOLEAN){
        return boolToInt(resultado.getValor());
    }

}

double Casteo::toDoble(Resultado resultado)
{
    if(resultado.getTipo()==TENTERO){
        return intToDoble(resultado.getValor());
    }
    if(resultado.getTipo()==TDOBLE){
        return strToDoble(resultado.getValor());
    }
    if(resultado.getTipo()==TCARACTER){
        return intToDoble(charToInt(resultado.getValor()));
    }
    if(resultado.getTipo()==TBOOLEAN){
        return intToDoble(boolToInt(resultado.getValor()));
    }
}


bool Casteo::toBool(Resultado resultado)
{
    if(resultado.getTipo()==TBOOLEAN){
        return strToBool(resultado.getValor());
    }
}

Resultado Casteo::toAsigVar(int tipo, Resultado resultado){
    if(resultado.getTipo()==ERR || resultado.getEsArr()){
        return resultado;
    }
    if(tipo==TCADENA){
        resultado.setTipo(TCADENA);
        return resultado;
    }
    if(tipo==TENTERO){
        resultado.setTipo(TENTERO);
        resultado.setValor(intToStr(toInt(resultado)));
        return resultado;
    }
    if(tipo==TBOOLEAN && resultado.getTipo()==TBOOLEAN){
        return resultado;
    }
    if(tipo==TDOBLE && resultado.getTipo()!=TBOOLEAN){
        resultado.setTipo(TDOBLE);
        resultado.setValor(dobleToStr(toDoble(resultado)));
        return resultado;
    }
    if(tipo==TCARACTER && resultado.getTipo()!=TBOOLEAN){
        resultado.setTipo(TCARACTER);
        resultado.setValor(intToChar(toInt(resultado)));
        return resultado;
    }
}

bool Casteo::EsPrimo(int valor){
    if(valor % 2 == 0){
        return false;
    }
    for (int divisor=3; divisor<valor; divisor+=2){
        if(valor % divisor == 0){
            return false;
        }
    }
    return true;
}


