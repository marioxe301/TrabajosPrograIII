#include "Empleado.h"
#include <fstream>
#include <iostream>

using namespace std;

//archivo.tellg(); devueleve la poscicion en memoria y tamaño

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

	while (!ArchivoIn.eof()) // end of file
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

Empleado * BuscarEmpleado(int poscicion) {
	ifstream ArchivoIn("empleados.dat", ios::in | ios::binary);
	if (!ArchivoIn) {
		cout << "Error al abrir archivo empleados.dat";
		return NULL;
	}
	Empleado * emp;
	ArchivoIn.seekg(0, ios::end);
	int bytes_totales = ArchivoIn.tellg();
	int cantidad = bytes_totales / sizeof(Empleado);

	if (poscicion > cantidad) {
		cout << "No existe esa poscicion"<<"\n";
		ArchivoIn.close();
		return NULL;
	}
	else
	{
		ArchivoIn.seekg((poscicion - 1) * sizeof(Empleado),ios::beg);
		ArchivoIn.read(reinterpret_cast<char *>(&emp),sizeof(Empleado));
		ArchivoIn.close();
		cout << "Empleado Existente";
		return emp;
	}

}

void Imprimir_Subordinados(char * jefe) {
	ifstream ArchivoIn("empleados.dat", ios::in | ios::binary);

	Empleado emp;
	Empleado sub;
	int codigoJefe;
	int i = 1;

	if (!ArchivoIn) {
		cout << "Error al abrir archivo empleados.dat";
		return;
	}
	ArchivoIn.seekg(0, ios::beg);
	ArchivoIn.read(reinterpret_cast<char *>(&emp), sizeof(Empleado));
	char nom[30];

	while (ArchivoIn.eof())
	{
		strcpy(nom, emp.nombre);
		if (nom == jefe) {
			cout << "Jefe: " << emp.nombre<<"\n";
			codigoJefe = emp.codigo;
			ArchivoIn.seekg(0, ios::beg);
			ArchivoIn.read(reinterpret_cast<char *>(&sub), sizeof(Empleado));
			while (ArchivoIn.eof()) {

				if (sub.codigo_jefe == codigoJefe) {
					cout << "S" << i << sub.nombre<<"\n";
					i++;
				}
				ArchivoIn.read(reinterpret_cast<char *>(&sub), sizeof(Empleado));
			}
			ArchivoIn.close();
			return;
			
		}
		ArchivoIn.read(reinterpret_cast<char *>(&emp), sizeof(Empleado));
	}
	ArchivoIn.close();

}