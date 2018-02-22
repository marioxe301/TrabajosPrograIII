

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

	nuevo.imprimirReversa();


	nuevo.insertar(3, 5);

	nuevo.imprimirReversa();


	
	nuevo.imprimir();

	nuevo.borrar(9);

	nuevo.imprimir();


	/*
	cout << "Ingrese valor a buscar: ";
	int valor;
	cin >> valor;

	int busqueda = nuevo.buscar(valor);
	if (busqueda!=-1)
	{
		cout << "Se encontro el elemento en la poscicion " << busqueda<<endl;
	}
	else {
		cout << "No se encontro el elemento " << endl;
	}*/

	system("pause");
}