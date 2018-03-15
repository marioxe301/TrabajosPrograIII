#include "Utilidades.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void Utilidades::InsertarFinal(Nodo **inicio, int valor) {
	if ((*inicio) == 0) {
		Nodo *nuevo = new Nodo;
		nuevo->valor = valor;
		
		*inicio = nuevo;


	}
	else {
		Nodo *actual = *inicio;
		Nodo *nuevo = new Nodo;
		nuevo->valor = valor;
		Nodo *ant = 0;
		while (actual != 0) {
			ant = actual;
			actual = actual->sig;
			
		}
		ant->sig = nuevo;
		nuevo->ant = ant;
		
	}


}

Nodo * Utilidades::CrearLista(int numeroE) {
	srand(time(0));

	Nodo *Lista = 0;

	for (int i = 0; i < numeroE; i++) {
		int numero = rand() % (numeroE + 1);
		InsertarFinal(&Lista, numero);
	}

	return Lista;

}

void Utilidades::OrdenarLista(Nodo **inicio) {
	Nodo *actual = *inicio;
	Nodo *siguiente;
	int i = 0;
	if (*inicio == 0) {
		return;
	}
	else {
		while (actual->sig != NULL) {
			siguiente = actual->sig;
			while (siguiente != NULL) {
				if (actual->valor > siguiente->valor) {
					i = siguiente->valor;
					siguiente->valor = actual->valor;
					actual->valor = i;
				}
				siguiente = siguiente->sig;
			}
			actual = actual->sig;
			siguiente = actual->sig;
		}

	}

}
	



void Utilidades::ImprimirLista(Nodo **inicio) {     //SOLO CREE LA FUNCION PARA MOTIVOS DE PRUEBA
	if (*inicio == 0) {
		return;
	}
	else {
		std::cout << (*inicio)->valor << " ";
		ImprimirLista(&(*inicio)->sig);
	}
}

void Utilidades::GuardarLista(Nodo **Lista,char * nombre_archivo) {
	std::ofstream archivoApuntadores(nombre_archivo, std::ios::app);
	if (!archivoApuntadores) {
		std::cout << "Error al implementar el archivo " << nombre_archivo;
	}
	Nodo *actual = *Lista;
	int numero;
	while (actual!=0)
	{
		numero = actual->valor;
		archivoApuntadores << numero << ' ';
		actual = actual->sig;

	}
	archivoApuntadores.close();
	

}