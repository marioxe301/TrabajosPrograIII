
#include "EmpleadoPrivado.h"
#include<iostream>
#include <string>

int main() {
	Empleado ep("Mario", 19, 'M', "Soltero", 100000, "Programador", "Unitec");
	ep.setGenero('M');
	ep.ImprimirEmpleado();

	//ejemplo No.2

	cout << "=======================\n\n";

	EmpleadoPrivado empp;
	empp.setGenero('F');
	empp.setEmpresa("Microsoft");
	empp.setEdad(30);
	
	empp.ImprimirEmpleado();

	//Ejemplo no.3

	cout << "======================\n\n";
	Empleado *emp = new Empleado("Oscar", 21, 'M', "Soltero", 100000, "Programador", "Banco");
	Empleado *emp2 = emp;
	emp2->ImprimirEmpleado();
	system("pause");
}
