#include "Char.h"
#include <iostream>
Char::Char(char a) {
	this->setValor(a);
}

Char::~Char()
{}

void Char::imprimir() {
	std::cout << "Object: " << "Char " << "{ " << this->getValor() << " }" << std::endl;
}

Tipo Char::getTipo() {
	return T_char;
}

char Char::getValor() {
	return this->valor;
}

void Char::setValor(char a) {
	this->valor = a;
}