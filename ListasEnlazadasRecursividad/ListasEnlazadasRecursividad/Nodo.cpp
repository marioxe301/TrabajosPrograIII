#include "Nodo.h"
#include <iostream>

void insertarInicio(nodo**inicio, nodo*nuevo) {
	if (*inicio == 0) {
		*inicio = nuevo;
	}
	else {
		nodo *tmp = *inicio;
		*inicio = nuevo;
		(*inicio)->sig = tmp;
		tmp->ant = (*inicio);


	}
}

void insertarFinalR(nodo**actual, nodo*nuevo) {
	if (*actual == 0) {
		*actual = nuevo;
	}
	else if ((*actual)->sig = 0) {
		nuevo->ant = *actual;
		insertarFinalR(&(*actual)->sig,nuevo);
	}
	else
	{
		insertarFinalR(&(*actual)->sig, nuevo);
	}

	}


void insertarFinal(nodo**inicio, nodo *nuevo) {
	if (*inicio == 0) {
		*inicio = nuevo;
	}
	else {
		nodo *actual = *inicio;
		nodo *anterior = 0;
		while (actual!=0) {
			anterior = actual;
			actual = actual->sig;

		}
		anterior->sig = nuevo;
		nuevo->ant = anterior;
	}
}

nodo *buscar(nodo**actual, int valor) {
	if (*actual == 0) {
		return 0;
	}
	else if ((*actual)->valor == valor) {
		return *actual;
	}
	else
	{
		return buscar(&(*actual)->sig, valor);
	}
}

void imprimirLista(nodo **actual) {
	if (*actual == 0) {
		return;
	}
	else {
		std::cout<< (*actual)->valor<<" ";
		imprimirLista(&(*actual)->sig); // amperson por valor de referencia
	}
}