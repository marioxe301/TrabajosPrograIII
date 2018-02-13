#pragma once

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "Nodo.h"
class ListaEnlazada {
public:
	ListaEnlazada();
	bool esVacia();
	int getTamaño();

	void agregar(int);
	void insertar(int, int);
	void imprimir();
private:
	Nodo *primero, *ultimo;

};

#endif // !LISTAENLAZADA_H
