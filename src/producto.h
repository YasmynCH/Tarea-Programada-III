#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

namespace Tarea3 {

class Producto{

    int id;
    char nombre[20];
    int exitencias; 
    //Tamaño total del empleado 28


    public:

    Producto(int id, string nombre, int existencias);
    Producto();
    
    int getId();
    string getNombre();

    friend ostream& operator << (ostream &o, const Producto *producto);
};

}

#endif
