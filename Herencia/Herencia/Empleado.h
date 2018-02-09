#pragma once
#ifndef EMPLEADO_H

#define EMPLEADO_H


#include"Persona.h"
#include<iostream>
#include <string>
class Empleado : public Persona {

public:
	Empleado();
	Empleado(string,int,char,string,double,string,string);
	~Empleado();

	void setSalario(double);
	void setPuesto(string);
	void setEmpresa(string);
	

	double getSalario();
	string getPuesto();
	string getEmpresa();

	void ImprimirEmpleado();

protected:
	double salario;
	string puesto;
	string empresa;

};
#endif // !EMPLEADO_H
