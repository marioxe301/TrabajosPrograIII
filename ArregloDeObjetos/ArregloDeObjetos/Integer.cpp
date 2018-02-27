#include "Integer.h"
#include <iostream>
Integer::Integer(int a) {
	this->setValor(a);
}

Integer::~Integer()
{}

void Integer::imprimir() {
	std::cout << "Object: " << "Integer " << "{ " << this->getValor() << " }" << std::endl;
}

Tipo Integer::getTipo() {
	return T_Int;
}

int Integer::getValor() {
	return this->valor;
}

void Integer::setValor(int a) {
	this->valor = a;
}