#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <iostream>
#include "producto.h"

#include <vector>

using namespace std;

namespace Tarea3{


class Tienda {

    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[8];

    //Tamaño total del la tienda 71

    public:

    Tienda (string nombre, string direccionWeb, string direccionFisica, string telefono);
    Tienda();
   
    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

}

#endif
