#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;


class Producto{

    int id;
    char nombre[20];
    int existencias; 
    //Tamaño total del empleado 28


    public:

    Producto(int id, string nombre, int existencias);
    Producto();

    int getId();
    std::string getNombre();
    int getExistencias();

    friend ostream& operator << (ostream &o, const Producto *producto);
};

#endif