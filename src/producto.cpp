#include "producto.h"
#include <iostream>
#include <string>
#include <cstring>


namespace Tarea3{

    Producto::Producto(int id, string nombre, int existencias){

        this->id = id;
        strcpy(this->nombre, nombre.c_str());
        this->exitencias = existencias;
    }

    Producto::Producto(){

        this->id = 0;
        strcpy(this->nombre, "");
        this->exitencias = 0;

    }

    ostream &operator<<(ostream &o, const Producto *producto){
        o << "[" << producto->id << "] - " << producto->nombre << " " << producto->exitencias;
        return o;
    }
}