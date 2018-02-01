#pragma once

#include<iostream>

using namespace std;

class Persona {
public:
	Persona();
	~Persona();//destructor de la clase

	void setNombre(string);
	void setEstadoCivil(string);
	void setEdad(int);
	void setGenero(char);

	string getNombre();
	string getEstadoCivil();
	int getEdad();
	char getGenero();

	void ImprimirPersona();
protected:
	string nombre, estado_civil;
	int edad;
	char genero;

};
