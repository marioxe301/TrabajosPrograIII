#include "ListaEnlazada.h"
#include <iostream>
ListaEnlazada::ListaEnlazada():primero(0),ultimo(0)
{}

bool ListaEnlazada::esVacia() {
	return primero == 0;
}
void ListaEnlazada::agregar(int valor) {
	Nodo *tmp = new Nodo;
	tmp->setValor(valor);
	if (esVacia()) {
		ultimo = primero = tmp;
	}
	else {
		ultimo->setSig(tmp);
		ultimo = tmp;
	}
}

void ListaEnlazada::imprimir() {
	Nodo *tmp = primero;

	while (tmp!=0)
	{
		std::cout << tmp->getValor() << " ";
		tmp = tmp->getSig();
	}
	std::cout << std::endl;
}

void ListaEnlazada::insertar(int poscicion, int valor) {
	Nodo * tmp = primero;
	Nodo *ant = 0;
	Nodo *nuevo = new Nodo;
	nuevo->setValor(valor);
	int cont = 0;
	if (poscicion > getTamaño()) {
		std::cout << "Poscicion Incorrecta!... \n";
	}
	else {

		while (tmp != 0)
		{
			cont++;
			if (cont == poscicion) {
				if (tmp==primero)
				{
					nuevo->setSig(primero);
					ultimo = primero;
					primero = nuevo;
				}
				else if (tmp == ultimo) {
					ant->setSig(nuevo);
					nuevo->setSig(ultimo);
						
				}
				else {
					ant->setSig(nuevo);
					nuevo->setSig(tmp);
				}
			}

			ant = tmp;
			tmp = tmp->getSig();
		}
	}
}

int ListaEnlazada::getTamaño() {
	Nodo *tmp = primero;
	int cont = 0;
	while (tmp!=0)
	{
		cont++;
		tmp = tmp->getSig();
	}
	return cont;
}