
#include "Empleado.h"

#include<iostream>
#include <string>

Empleado::Empleado() {
	cout << "Se construyo Empleado...\n";
}
Empleado::Empleado(string nombre, int edad, char genero, string estado_civil, double salario, string puesto, string empresa) {

	this->nombre = nombre;
	this->edad = edad;
	this->genero = genero;
	this->estado_civil = estado_civil;
	this->salario = salario;
	this->puesto = puesto;
	this->empresa = empresa;

	cout << "Se construyo Empleado...\n";

}

Empleado::~Empleado() {
	cout << "Se destruyo Empleado...\n";
}

void Empleado::setSalario(double salario) {
	this->salario = salario;
}

void Empleado::setPuesto(string puesto) {
	this->puesto = puesto;
}

void Empleado::setEmpresa(string empresa) {
	this->empresa = empresa;
}

string Empleado::getPuesto() {
	return puesto;
}

string Empleado::getEmpresa() {
	return empresa;
}

double Empleado::getSalario() {
	return salario;
}

void Empleado::ImprimirEmpleado() {
	this->ImprimirPersona();
	cout << "Salario: " << salario << endl;
	cout << "Puesto: " << puesto << endl;
	cout << "Empresa: " << empresa << endl;
}