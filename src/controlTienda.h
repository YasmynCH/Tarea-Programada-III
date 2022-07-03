#ifndef CONTROLTIENDA_H
#define CONTROLTIENDA_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>


#include "tienda.h"

using namespace Tarea3;

class ControlTienda{

    vector <Producto *> inventario;

    ofstream archivoBinarioSalida;

public:
    
    ControlTienda(string nombreDeArchivoBinario);
    ~ControlTienda();

    void AgregarProducto(Producto *productoNuevo);
    
    Producto BuscarProducto(int nombreProductoBuscado);
    
    void ModificarNombreProducto(int idProductoAModificar, string nombreModificado);
    
    void EliminarProducto(int idProductoAEliminar);
    
    void GuardarEnStream(ostream *streamSalida);
    
    void CargarDesdeStream(istream *streamEntrada);
    
    void CerrarArchivoBinario();

    
    friend ostream& operator << (ostream &o, const ControlTienda *controlTienda);

};

#endif