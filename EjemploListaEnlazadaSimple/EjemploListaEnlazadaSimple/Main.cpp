

#include <iostream>
#include "ListaEnlazada.h"
using namespace std;

int main() {
	ListaEnlazada nuevo;
	nuevo.agregar(9);
	nuevo.agregar(2);
	nuevo.agregar(1);
	nuevo.agregar(12);
	nuevo.agregar(4);
	nuevo.agregar(5);

	nuevo.imprimir();

	nuevo.insertar(3, 5);

	nuevo.imprimir();

	system("pause");
}