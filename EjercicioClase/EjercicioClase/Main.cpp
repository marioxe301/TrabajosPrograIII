#include <iostream>
#include "Herramienta.h"
using namespace std;


int main() {
	

	MetodosProductos::crearArchivoVacio();

	Tools herramienta;
	herramienta.codigo = 101;
	strcpy(herramienta.nombre, "Martillo");
	herramienta.costo = 10;
	herramienta.cantidad = 1;

	MetodosProductos::agregarProducto(herramienta);
	

	MetodosProductos::ImprimirProductos();

	/*MetodosProductos::modificarProducto(101);
	MetodosProductos::eliminarProducto(101);			/*PROBAR DE SEGUNDO(Luego de haber introducido un objeto)


	MetodosProductos::ImprimirProductos();*/


	system("pause");
}