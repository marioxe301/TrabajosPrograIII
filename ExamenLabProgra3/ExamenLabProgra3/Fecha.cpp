#include "Fecha.h"
#include <iostream>
Fecha::Fecha(): dia(1),mes(1),año(1)
{}

void Fecha::setDia(int dia) {
	this->dia = dia;
}
void Fecha::setMes(int mes) {
	this->mes = mes;
}

void Fecha::setAño(int año) {
	this->año = año;
}

int Fecha::getDia() {
	return this->dia;
}

int Fecha::getMes() {
	return this->mes;
}

int Fecha::getAño() {
	return this->año;
}

void Fecha::imprimirFecha() {
	std::cout << this->dia << "/" << this->mes << "/" << this->año<<std::endl;
}