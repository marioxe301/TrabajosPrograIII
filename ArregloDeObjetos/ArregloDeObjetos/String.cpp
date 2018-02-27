#include "String.h"
#include <iostream>
#include <string>
String::String(std::string a) {
	this->setValor(a);
}

String::~String()
{}

void String::imprimir() {
	std::cout << "Object: " << "String " << "{ " << this->getValor() << " }" << std::endl;
}

Tipo String::getTipo() {
	return T_String;
}

std::string String::getValor() {
	return this->valor;
}

void String::setValor(std::string a) {
	this->valor = a;
}