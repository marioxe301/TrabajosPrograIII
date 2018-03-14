#include "Empleado.h"
#include <fstream>
#include <iostream>

using namespace std;

void registrarEmpleados() {
	ofstream archivoOut("empleados.dat",ios::out |ios::app| ios::binary); // ios::out -> escritura
	if (!archivoOut) {
		cout << "Error al abrir achivo empleados.dat";
		return;
	}

	archivoOut.seekp(0, ios::end); // ubicarse al final de archivo

	cout << "\n\n *** R E G I S T R O  D E  E M P L E A D O S *** \n\n";

	int opcion=0;
	

	do {
		Empleado nuevo;
		cout << "Ingrese codigo: ";
		cin >> nuevo.codigo;

		cout << "Ingrese nombre: ";
		cin >> nuevo.nombre;

		cout << "Ingrese puesto: ";
		cin >> nuevo.puesto;

		cout << "Ingrese codigo jefe(-1 si no tiene): ";
		cin >> nuevo.codigo_jefe;

		nuevo.activo = true; // o = 1(true)

		archivoOut.write(reinterpret_cast<const char *>(&nuevo),sizeof(Empleado));

		cout << "Registro Guardado!\n\n";
		cout << "Desea agregar nuevo registro?(-1 para salir)";
		cin >> opcion;
	} while (opcion != -1);

	archivoOut.close();
}

void consultarEmpleados() {
	ifstream ArchivoIn("empleados.dat", ios::in|ios::binary);

	if (!ArchivoIn) {
		cout << "Error al abrir archivo empleados.dat";
		return;
	}

	ArchivoIn.seekg(0, ios::beg);
	cout << "\n\n *** C O N S U L T A  D E  E M P L E A D O S ***\n\n";
	Empleado actual;

	// leemos el primer registro
	ArchivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Empleado)); // no se usa cont ya que es lectura

	while (!ArchivoIn.eof())
	{
		if (actual.activo) {
			cout << "Codigo: " << actual.codigo << "\nNombre: " << actual.nombre
				<< "\nPuesto: " << actual.puesto << "\nJefe: " << actual.codigo_jefe;
			cout << "\n----------------------------------------------------\n";
		}

		ArchivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Empleado));
	}

	ArchivoIn.close();

}