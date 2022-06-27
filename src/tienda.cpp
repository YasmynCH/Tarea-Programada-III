#include "tienda.h"
#include <iostream>
#include <string>
#include <cstring>

namespace Tarea3
{

    Tienda::Tienda(string nombre, string direccionWeb, string direccionFisica, string telefono)
    {

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

    void Tienda::AgregarProducto(Producto *productoNuevo)
    {

        this->inventario.push_back(productoNuevo);
    }

    /*void Tienda::GuardarEnStream(ostream *streamSalida){
    streamSalida->seekp(0, std::ios::end);
        int cantidadBytesEnArchivo = streamSalida->tellp();
        int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

        for (Producto *producto : this->inventario){

            streamSalida->write((char *)producto, sizeof(Producto));
        }
    }*/

    void Tienda::GuardarEnStream(ostream *streamSalida){       

 
            Tienda *tienda = new Tienda(this->nombre, this->direccionWeb, this->direccionFisica, this->telefono);
            streamSalida->write((char *)tienda, sizeof(Tienda));

            for (Producto *producto : this->inventario){

            streamSalida->write((char *)producto, sizeof(Producto));;
         }
        }
    
        void Tienda::CargarDesdeStream(istream * streamEntrada)
        {

            streamEntrada->seekg(0, std::ios::end);
            int cantidadBytesEnArchivo = streamEntrada->tellg();
            int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

            // Leer cada empleado
            streamEntrada->seekg(0, std::ios::beg); // Empezar desde el principio del archivo
            for (int indice = 0; indice < cantidadProductos; indice++)
            {
                Producto *producto = new Producto();
                streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

                this->AgregarProducto(producto);
            }
        }

        ostream &operator<<(ostream &o, const Tarea3::Tienda *tienda)
        {

            o << "Inventario: " << std::endl;

            for (Tarea3::Producto *producto : tienda->inventario)
            {
                o << producto << endl;
            }

            return o;
        }
    };