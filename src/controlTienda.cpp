#include "controlTienda.h"
#include "tienda.h"
#include "./excepcionNoSePuedeLeerArchivo.h"
#include "./excepcionProductoInexistente.h"


using namespace Tarea3;

ControlTienda::ControlTienda(string nombreArchivoBinario)
{

    archivoBinarioSalida.open(nombreArchivoBinario, ios::out | ios::binary);

    if (!archivoBinarioSalida.is_open())
    {

        throw ExcepcionNoSePuedeLeerArchivo();
    }
}

ControlTienda::~ControlTienda()
{

    for (Producto *producto : this->inventario){

        delete producto;
    }
}



void ControlTienda::AgregarProducto(Producto *productoNuevo)
{

    this->inventario.push_back(productoNuevo);
}


void ControlTienda::GuardarEnStream(ostream *streamSalida)
{

    Tienda *tienda = new Tienda();

    streamSalida->write((char *)tienda, sizeof(Tienda));

    for (Producto *producto : this->inventario)
    {

        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void ControlTienda::CargarDesdeStream(istream *streamEntrada)
{

    streamEntrada->seekg(0, ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

    // Leer cada empleado
    streamEntrada->seekg(0, ios::beg); // Empezar desde el principio del archivo

    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }
}

 Producto ControlTienda::BuscarProducto(int idProductoBuscado){

        ifstream streamEntrada;
        streamEntrada.open("archivo_test.dat", ios::in | ios::binary);

        if (!streamEntrada.is_open()){

            cerr << "No se pudo abrir archivo planilla.dat para leer los datos";
        }

        Producto productoEncontrado;

        int posicion = sizeof(Tienda) + (sizeof(Producto) * idProductoBuscado) ;
        streamEntrada.seekg(0, ios::beg);

        int tamanoStream = streamEntrada.tellg();

        if (posicion > tamanoStream){

            throw ExcepcionProductoInexistente();
        }

        streamEntrada.seekg(posicion);
        streamEntrada.read((char *) &productoEncontrado, sizeof(Producto));

        return productoEncontrado;
    }


 void ControlTienda::ModificarNombreProducto(int idProductoAModificar, string nombreModificado){

        ifstream streamEntrada;
        streamEntrada.open("archivo_test.dat", ios::in | ios::binary);

        if (!streamEntrada.is_open()){

            cerr << "No se pudo abrir archivo planilla.dat para leer los datos";
        }

        Producto productoEncontrado;

        int posicion = sizeof(Tienda) + (sizeof(Producto) * idProductoAModificar);
        streamEntrada.seekg(71, ios::beg);

        int tamanoStream = streamEntrada.tellg();

        if (posicion > tamanoStream){

            throw ExcepcionProductoInexistente();
        }

        if (productoEncontrado.getId() == idProductoAModificar){
      
            streamEntrada.seekg(posicion);
            streamEntrada.read((char *) &productoEncontrado, sizeof(Producto));
             
            productoEncontrado.getNombre() = nombreModificado;

        }

        
    }

 void ControlTienda::EliminarProducto(int idProductoBuscado){

        for (int indice= 0; indice<inventario.size(); indice++){

            if (inventario[indice]->getId() == idProductoBuscado){

                inventario.erase(inventario.begin()+ indice);
            }
        }

 }


ostream &operator<<(ostream &o, const ControlTienda *controlTienda)
{

    o << "Inventario: " << std::endl;

    for (Producto *producto : controlTienda->inventario)
    {
        o << producto << endl;
    }

    return o;
};


void ControlTienda::CerrarArchivoBinario(){

    archivoBinarioSalida.close();
}