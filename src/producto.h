#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

namespace Tarea3 {

class Producto{

    int id;
    char nombre [20];
    int exitencias; 


    public:

    Producto (int id, string nombre, int existencias);
    friend ostream& operator << (ostream &o, const Producto *prodcuto);
};

}

#endif
