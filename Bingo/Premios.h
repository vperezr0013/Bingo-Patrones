#ifndef PREMIOS_H
#define PREMIOS_H

#include <sstream>
#include "carton.h"

struct Premios
{


public:


    Premio()
    {

    }

    unsigned int Columnas;
    unsigned int Filas;
    unsigned int Valor;


    explicit Premio(unsigned int filas, unsigned int columnas, unsigned int valor) :
            Columnas(columnas),
            Filas(filas),
            Valor(valor)
    {

    }


    [[nodiscard]] std::string toString() const
    {
        std::stringstream ss;
        ss << "H" << Filas;
        ss << "V" << ColumnasS;
        ss << "C" << Valor;
        return ss.str();
    }

};



#endif // PREMIOS_H
