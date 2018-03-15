#include <iostream>
#include <conio.h>
#include "Utilidades.h"
using namespace std;

int main() {
	Nodo * lista = 0;
	Nodo *lista2 = 0;

	UtilidadesListasEnlazadas::InsertarFinal(&lista, 5);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 7);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 4);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 11);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 12);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 5);
	UtilidadesListasEnlazadas::InsertarFinal(&lista, 3);

	lista2 = UtilidadesListasEnlazadas::CrearLista(5);

	UtilidadesListasEnlazadas::ImprimirLista(&lista2);

	cout << "\n";


	UtilidadesListasEnlazadas::ImprimirLista(&lista);// funcion creada solo para fines de prueba 

	cout << "\n";
	
	UtilidadesListasEnlazadas::OrdenarLista(&lista);


	UtilidadesListasEnlazadas::ImprimirLista(&lista); // funcion creada solo para fines de prueba 

	UtilidadesListasEnlazadas::GuardarLista(&lista, "lista1.dat");
	

	_getch();
}