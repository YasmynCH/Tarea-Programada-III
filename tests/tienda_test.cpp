#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"
#include "./../src/controlTienda.h"


using namespace Tarea3 
{
    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario

        ControlTienda *inventarioEsperado = new ControlTienda("archivo_test.dat");
        
        string nombre="vendeTodo";
        string direccionWeb="vendeTodo@nadagratis";
        string direccionFisica="a la par de la escuela";
        string telefono="8888888";

        Tienda *tienda = new Tienda(nombre, direccionWeb, direccionFisica, telefono);

        Producto *producto1 = new Producto(1, "Bananas", 3);
        inventarioEsperado->AgregarProducto(producto1);

        Producto *producto2 = new Producto(2, "Pijamas", 2);
        inventarioEsperado->AgregarProducto(producto2);

        // Act - ejecute la operación
        // Escribir un archivo de prueba

        ControlTienda archivoSalida {"archivo_test.dat"}; 

        inventarioEsperado->GuardarEnStream(ostream &archivoSalida);

        inventarioEsperado->CerrarArchivoBinario();
        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        ControlTienda *inventarioLeido = new ControlTienda("archivo_test.dat");
        
        //Tienda *tienda = new Tienda(nombre, direccionWeb, direccionFisica, telefono);
        
        inventarioLeido->CargarDesdeStream(ifstream &archivoEntrada);

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