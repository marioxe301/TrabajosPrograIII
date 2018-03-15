#include <iostream>
#include <conio.h>
#include "Utilidades.h"
using namespace std;

int main() {
	Nodo * lista = 0;
	Nodo *lista2 = 0;

	Utilidades::InsertarFinal(&lista, 5);
	Utilidades::InsertarFinal(&lista, 7);
	Utilidades::InsertarFinal(&lista, 4);
	Utilidades::InsertarFinal(&lista, 11);
	Utilidades::InsertarFinal(&lista, 12);
	Utilidades::InsertarFinal(&lista, 5);
	Utilidades::InsertarFinal(&lista, 3);

	lista2 = Utilidades::CrearLista(5);

	Utilidades::ImprimirLista(&lista2);

	cout << "\n";


	Utilidades::ImprimirLista(&lista);// funcion creada solo para fines de prueba 

	cout << "\n";
	
	Utilidades::OrdenarLista(&lista);


	Utilidades::ImprimirLista(&lista); // funcion creada solo para fines de prueba 

	Utilidades::GuardarLista(&lista, "lista1.dat");
	

	_getch();
}