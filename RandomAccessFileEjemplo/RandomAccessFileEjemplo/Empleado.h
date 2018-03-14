#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

struct Empleado
{
	int codigo;
	char nombre[30]; // 4 bytes
	char puesto[15]; // 30 bytes
	int codigo_jefe; // 4 bytes
	bool activo; // 1 byte

	//sizeof = 54 bytes
};

void registrarEmpleados();
void consultarEmpleados();
#endif // !EMPLEADO_H
