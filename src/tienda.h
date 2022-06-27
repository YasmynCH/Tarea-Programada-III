#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <iostream>
#include "producto.h"

#include <vector>

using namespace std;

namespace Tarea3 {

class Tienda {

    vector <Producto *> inventario;

    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[8];


    public:

    Tienda (string nombre, string direccionWeb, string direccionFisica, string telefono);
    ~Tienda();

    void AgregarProducto(Producto *producto);
    Producto BuscarProducto(int nombreProductoBuscado);
    void EliminarProducto(int idProductoAEliminar);
    void ModificarProducto();

    void GuardarEnStream(ostream *streamSalida);
    void CargarDesdeStream(istream *streamEntrada);

    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

}

#endif
