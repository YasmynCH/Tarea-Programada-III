#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"


using namespace std;

namespace Tarea3
{
    TEST(Planilla_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *inventarioEsperado = new Tienda();

        Producto *producto1 = new Producto(1, "Bananas", 3);
        inventarioEsperado->AgregarProducto(producto1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        inventarioEsperado->GuardarEnStream(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *inventarioLeido = new Tienda();
        inventarioLeido->CargarDesdeStream(&archivoEntrada);

        ostringstream streamSalidaInventarioLeido;
        streamSalidaInventarioLeido << inventarioLeido;

        ostringstream streamSalidaInventarioEsperado;
        streamSalidaInventarioEsperado << inventarioEsperado;

        delete inventarioLeido;
        delete inventarioEsperado;

        string esperado = "Planilla: \n[1] - Pedro 20\n"; 
        string salidaInventarioEsperado = streamSalidaInventarioEsperado.str();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(esperado, salidaInventarioEsperado);

        string salidaInventarioLeidoDeArchivo = streamSalidaInventarioEsperado.str();
        EXPECT_EQ(esperado, salidaInventarioLeidoDeArchivo);
    }
    
}