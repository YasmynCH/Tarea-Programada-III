#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <iostream>
#include <fstream>
#include "producto.h"

#include <vector>

using namespace std;

namespace Tarea3{


class Tienda {


   vector <Producto *> inventario;

    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[8];

    ifstream archivoBinarioSalida;

    //Tamaño total del la tienda 71

    public:

    Tienda (string nombre, string direccionWeb, string direccionFisica, string telefono);
    Tienda(string nombreArchivoBinario);
    Tienda();

    ~Tienda();

    void AgregarProducto(Producto *productoNuevo);
    
    Producto BuscarProducto(int nombreProductoBuscado);
    
    void ModificarNombreProducto(int idProductoAModificar, string nombreModificado);
    
    void EliminarProducto(int idProductoAEliminar);
    
    void GuardarEnStream(ostream *streamSalida);
    
    void CargarDesdeStream(istream *streamEntrada);
    
    void CerrarArchivoBinario();
   
    friend ostream& operator << (ostream &o, const Tienda *tienda);
};

}

#endif
