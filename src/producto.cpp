#include "producto.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace Tarea3{


Producto::Producto(int id, string nombre, int existencias){


        this->id = id;
        strcpy(this->nombre, nombre.c_str());
        this->existencias = existencias;
    }

    Producto::Producto(){

        this->id = 0;
        strcpy(this->nombre, "");
        this->existencias = 0;

    }

    int Producto::getId(){

        return this->id;
    }

    string Producto::getNombre(){

        return this->nombre;
    }

    int Producto::getExistencias(){

        return this->existencias;
    }

    ostream &operator<<(ostream &o, const Producto *producto){
        o << "[" << producto->id << "] - " << producto->nombre << " " << producto->existencias;
        return o;
    
    }
    
};

