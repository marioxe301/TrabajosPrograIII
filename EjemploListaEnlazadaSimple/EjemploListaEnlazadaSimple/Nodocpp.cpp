#include "Nodo.h"

Nodo::Nodo():valor(-1),sig(0)
{}

void Nodo::setValor(int Valor) {
	this->valor = Valor;
}

int Nodo::getValor() {
	return this->valor;
}

Nodo* Nodo::getSig() {
	return this->sig;
}
void Nodo::setSig(Nodo* sig) {
	this->sig = sig;
}