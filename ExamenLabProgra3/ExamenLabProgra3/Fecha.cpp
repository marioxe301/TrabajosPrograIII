#include "Fecha.h"
#include <iostream>
Fecha::Fecha(): dia(1),mes(1),a�o(1)
{}

void Fecha::setDia(int dia) {
	this->dia = dia;
}
void Fecha::setMes(int mes) {
	this->mes = mes;
}

void Fecha::setA�o(int a�o) {
	this->a�o = a�o;
}

int Fecha::getDia() {
	return this->dia;
}

int Fecha::getMes() {
	return this->mes;
}

int Fecha::getA�o() {
	return this->a�o;
}

void Fecha::imprimirFecha() {
	std::cout << this->dia << "/" << this->mes << "/" << this->a�o<<std::endl;
}