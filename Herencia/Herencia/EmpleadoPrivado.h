#pragma once
#include"Empleado.h"
#include <iostream>
#include <string>

class EmpleadoPrivado : public Empleado {
public:
	EmpleadoPrivado();
	EmpleadoPrivado(string, int, char, string, double, string, string);
	~EmpleadoPrivado();
};