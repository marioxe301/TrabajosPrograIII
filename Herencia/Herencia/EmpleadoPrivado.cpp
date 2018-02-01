#include "EmpleadoPrivado.h"
#include <iostream>
#include <string>

EmpleadoPrivado::EmpleadoPrivado():
	Empleado("Fulano",20,'M',"Soltero",1000,"Programador","Monge")
{
	cout << "Se contruyo empleado privado...\n";
}

EmpleadoPrivado::EmpleadoPrivado(string nombre, int edad, char genero, string estado_civil, double salario, string puesto, string empresa) :
	Empleado(nombre,edad,genero,estado_civil,salario,puesto,empresa)
{
	cout << "Se construyo Empleado Privado...\n";
}

EmpleadoPrivado::~EmpleadoPrivado(){
	cout << "Se destruyo Empleado Privado...\n";
}