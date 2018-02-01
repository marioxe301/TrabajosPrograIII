#include"Persona.h"
#include <string>
Persona::Persona() {
	cout << "Se contruyo Persona...\n";
}

Persona::~Persona() {
	cout << "Se destruyo persona...\n";
}

void Persona::setNombre(string nombre) {

	this->nombre= nombre;
}

void Persona::setEstadoCivil(string estado) {
	this->estado_civil = estado;
}

void Persona::setGenero(char genero) {
	this->genero = genero;
}

void Persona::setEdad(int edad) {
	this->edad = edad;
}
string Persona::getNombre() {
	return nombre;
}

string Persona::getEstadoCivil() {
	return estado_civil;
}

char Persona::getGenero() {
	return genero;
}

int Persona::getEdad() {
	return edad;
}

void Persona::ImprimirPersona() {
	cout << "Nombre: " << nombre << endl;
	cout << "Edad:  " << edad << endl;
	cout << "Genero : " << genero << endl;
	cout << "Estado Civil: " << estado_civil << endl;
}