#include "tienda.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "./excepcionNoSePuedeLeerArchivo.h"
#include "./excepcionProductoInexistente.h"

/*Tienda::Tienda(){

        strcpy(this->nombre, "");
        strcpy(this->direccionWeb, "");
        strcpy(this->direccionFisica, "");
        strcpy(this->telefono, "");

}*/

Tienda::Tienda(string nombre, string direccionWeb, string direccionFisica, string telefono){

        strcpy(this->nombre, nombre.c_str());
        strcpy(this->direccionWeb, direccionWeb.c_str());
        strcpy(this->direccionFisica, direccionFisica.c_str());
        strcpy(this->telefono, telefono.c_str());
}

Tienda::~Tienda()
{
    for (Producto *producto : this->inventario)
    {
        delete producto;
    }
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->inventario.push_back(nuevoProducto);
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{

    Tienda *infoTienda = new Tienda(this->nombre, this->direccionWeb, this->direccionFisica, this->telefono);
    
    streamSalida->write((char *)infoTienda, sizeof(Tienda));
    
    for (Producto *producto : this->inventario)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::BuscarProducto(istream *streamEntrada, int posicionProducto)
{
    streamEntrada->seekg(sizeof(Producto) * posicionProducto +71);

    Producto *producto = new Producto();
    streamEntrada->read((char *)producto, sizeof(Producto));

    this->AgregarProducto(producto);
}

void Tienda::CargarDesdeStream(istream *streamEntrada){

    streamEntrada->seekg(0, ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = 71+(cantidadBytesEnArchivo / sizeof(Producto));

    // Leer cada empleado
    streamEntrada->seekg(0, ios::beg); // Empezar desde el principio del archivo
    Tienda *tienda = new Tienda(this->nombre, this->direccionWeb, this->direccionFisica, this->telefono);
    streamEntrada->read((char *)tienda, sizeof(Tienda));

    for (int indice = 71; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }
}

Producto Tienda::ModificarNombreProducto(int idProductoAModificar, string nombreModificado){

        ifstream streamEntrada;
        streamEntrada.open("archivo_test.dat", ios::in | ios::binary);

        if (!streamEntrada.is_open()){

            throw ExcepcionNoSePuedeLeerArchivo();
        }

        Producto productoEncontrado;

        int posicion = sizeof(Tienda) + (sizeof(Producto) * idProductoAModificar);
        streamEntrada.seekg(0, ios::beg);

        int tamanoStream = streamEntrada.tellg();

        if (posicion < tamanoStream){

            throw ExcepcionProductoInexistente();
        }

        if (productoEncontrado.getId() == idProductoAModificar){
      
            streamEntrada.seekg(posicion);
            streamEntrada.read((char *) &productoEncontrado, sizeof(Producto));
             
            productoEncontrado.getNombre() = nombreModificado;

     
        }
         return  productoEncontrado;
 }
        
 void Tienda::EliminarProducto(int idProductoBuscado){

        for (int indice= 0; indice<inventario.size(); indice++){

            if (inventario[indice]->getId() == idProductoBuscado){

                inventario.erase(inventario.begin()+ indice);
            }
        }

 }

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "Inventario: " << std::endl;

    for (Producto *producto : tienda->inventario)
    {
        o << producto << endl;
    }
    
    return o;
}