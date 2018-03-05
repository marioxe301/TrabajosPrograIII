#include <iostream>
#include <conio.h>
#include "Nodo.h"
using namespace std;

int main() {
	nodo *lista = 0;

	nodo *nuevo = new nodo;
	nuevo->valor = 9;

	insertarInicio(&lista, nuevo);

	nuevo = new nodo;
	nuevo->valor = 6;

	insertarInicio(&lista, nuevo);

	nuevo = new nodo;
	nuevo->valor = 2;

	insertarInicio(&lista, nuevo);

	nuevo = new nodo;
	nuevo->valor = 3;

	insertarFinal(&lista, nuevo);

	nuevo = new nodo;
	nuevo->valor = 10;

	insertarFinalR(&lista, nuevo);

	imprimirLista(&lista);

	nodo *busqueda = buscar(&lista, 30);


	_getch();
}