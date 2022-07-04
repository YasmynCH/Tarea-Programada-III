FLAGS = -g -c --std=c++17 -fPIC 


all:
	mkdir -p bin
	mkdir -p obj
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ -shared -o bin/libtienda.so obj/tienda.o
	g++ -shared -o bin/libproducto.so obj/producto.o
	mkdir -p bin/include
	cp src/tienda.h ./bin/include
	cp src/producto.h ./bin/include
	
	
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o obj/tienda_test.o
	g++ $(FLAGS) tests/tienda_test_buscar.cpp -o obj/tienda_test_buscar.o
	g++ $(FLAGS) tests/tienda_test_modificar.cpp -o obj/tienda_test_modificar.o
	g++ $(FLAGS) tests/tienda_test_eliminar.cpp -o obj/tienda_test_eliminar.o
	g++ -g -o bin/tests obj/tienda.o obj/producto.o obj/tienda_test.o obj/tienda_test_buscar.o obj/tienda_test_modificar.o obj/tienda_test_eliminar.o  -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj

	