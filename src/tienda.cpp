#include "tienda.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "excepcionProductoInexistente.h"

using namespace std; 

namespace Tarea3{


    Tienda::Tienda(string nombre, string direccionWeb, string direccionFisica, string telefono){

        strcpy(this->nombre, nombre.c_str());
        strcpy(this->direccionWeb, direccionWeb.c_str());
        strcpy(this->direccionFisica, direccionFisica.c_str());
        strcpy(this->telefono, telefono.c_str());
    }


}
