#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <iostream>
#include "producto.h"

#include <vector>

using namespace std;

class Tienda {

    vector <Producto *> inventario;

    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[9];
    //Tamaño total del la tienda 71


    public:

    Tienda (string nombre, string direccionWeb, string direccionFisica, string telefono);
    Tienda ();
    ~Tienda();

    void AgregarProducto(Producto *producto);
    void BuscarProducto(istream *streamEntrada, int idProductoBuscado);
    void EliminarProducto(int idProductoAEliminar);
    Producto ModificarNombreProducto(int idProductoAModificar, string nombreModificado);
    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStream(istream *streamEntrada);

    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

#endif