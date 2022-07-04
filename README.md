Tarea-Programada-III | B41761 - Yasmyn Chacón Hernández Para el programa Para compilar este programa ejecute la siguiente instrucción:

make

Para ejecutar este programa corra la siguiente instrucción:

./bin/Tarea-III

Para los tests Para compilar los tests de este programa ejecute la siguiente instrucción:

make test

Para ejecutar los tests de este programa corra la siguiente instrucción:

./bin/tests


*La estructura de una tienda*
Campo             |	Tamaño en bytes  |	Offset
Nombre Tienda     |	      15         |    0
Dirección web     |	      24         |    15
Dirección física  | 	  24         |    39
Teléfono          |       8          |    63
Id Producto       |       4          |    71
Nombre Producto   |       20         |    75
Existencias       |       4          |    95

Total: 71 bytes datos de la tienda.
Total: 28 bytes datos de cada producto.

Cómo leo el producto n? Offset: n*28 + 71

*Índice*
ID |	Offset
1  |	71
2  |	99
