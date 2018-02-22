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
		//Lista Doblemente Enlazada

		ultimo->setSig(tmp);
		tmp->setAnt(ultimo);
		ultimo = tmp;

		/* ListaEnlazada Simple
		ultimo->setSig(tmp);
		ultimo = tmp;
		*/
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
					//Lista doblemente enlazada

					nuevo->setSig(primero);
					primero->setAnt(nuevo);
					primero = nuevo;

					//Lista Enlazada Simple
					/*nuevo->setSig(primero);
					ultimo = primero;
					primero = nuevo;*/
				}
				else if (tmp == ultimo) {
					//Lista doblemente enlazada
					ultimo->setSig(nuevo);
					nuevo->setAnt(ultimo);
					ultimo = nuevo;


					//Lista Enlazada Simple
					/*ant->setSig(nuevo);
					nuevo->setSig(ultimo);*/
						
				}
				else {
					//Lista Doblemente enlazada
					ant->setSig(nuevo);
					nuevo->setAnt(ant);
					nuevo->setSig(tmp);
					tmp->setAnt(nuevo);


					// Lista Enlazada simple
					/*ant->setSig(nuevo);
					nuevo->setSig(tmp);*/
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

bool ListaEnlazada::borrar(int valor) {
	Nodo *actual = primero;
	Nodo *anterior = 0;

	while (actual!=0)
	{
		if (actual->getValor()==valor)
		{
			if (actual == primero) {
				// Listadoblemente enlazada
				primero = actual->getSig();
				primero->setAnt(0);

				delete actual;

				//Lista enlazada simple
				//primero = actual->getSig();

			}
			else if (actual == ultimo) {
				ultimo = actual->getAnt();
				ultimo->setSig(0);

				delete actual;
				//ultimo = anterior;

			}
			else
			{
				//lista Doblemente enlazada

				actual->getAnt()->setSig(actual->getSig());
				actual->getSig()->setAnt(actual->getAnt());

				delete actual;

				//lista enlazada simple
				//anterior->setSig(actual->getSig());
			}
			return true;
		}
		anterior = actual;
		actual = actual->getSig();
	
	}
	return false;
}

int ListaEnlazada::buscar(int valor) {
	Nodo *tmp = primero;
	int poscicion = 0;

	while (tmp!=0)
	{
		poscicion++;
		if (tmp->getValor() == valor) {
			return poscicion;
		}

		tmp = tmp->getSig();
	}
	return -1;
}

void ListaEnlazada::imprimirReversa() {
	Nodo*tmp = ultimo;

	while (tmp!=0)
	{
		std::cout << tmp->getValor()<< " ";
		tmp = tmp->getAnt();
	}
	std::cout << std::endl;
}
