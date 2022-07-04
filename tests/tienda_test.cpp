#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "../src/tienda.h"
#include "./../src/excepcionNoSePuedeLeerArchivo.h"




using namespace std;

namespace Tarea3
{
    TEST(Tienda_Test, EscriturayLectura_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        string nombre="vendeTodo";
        string direccionWeb="vendeTodo@nadagratis";
        string direccionFisica="a la par de la escuela";
        string telefono="8888888";

        Tarea3::Tienda *inventarioEsperado = new Tienda();
        
        Tarea3::Tienda *tienda = new Tienda(nombre, direccionWeb, direccionFisica, telefono);

        Producto *producto1 = new Producto(1, "Bananas", 3);
        inventarioEsperado->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2, "Pijamas", 2);
        inventarioEsperado->AgregarProducto(producto2);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;

       // Tienda *tiendaLectura = new Tienda("archivo_test.dat");

       archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            throw ExcepcionNoSePuedeLeerArchivo();
            FAIL();
        }

        inventarioEsperado->GuardarEnStream(&archivoSalida);
        
       // tiendaLectura->CerrarArchivoBinario();
        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            throw ExcepcionNoSePuedeLeerArchivo();
            FAIL();
        }
    
        Tarea3::Tienda *inventarioLeido = new Tienda();
        
        inventarioLeido->CargarDesdeStream(&archivoEntrada);

        ostringstream streamSalidaInventarioLeido;
        streamSalidaInventarioLeido << inventarioLeido;

        ostringstream streamSalidaInventarioEsperado;
        streamSalidaInventarioEsperado << inventarioEsperado;

        delete inventarioLeido;
        delete inventarioEsperado;

        string esperado = "Inventario: \n[1] - Bananas 3\n[2] - Pijamas 2\n" ; 
        string salidaInventarioEsperado = streamSalidaInventarioEsperado.str();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(esperado, salidaInventarioEsperado);

        string salidaInventarioLeidoDeArchivo = streamSalidaInventarioEsperado.str();
        EXPECT_EQ(esperado, salidaInventarioLeidoDeArchivo);
    }
    
    
}