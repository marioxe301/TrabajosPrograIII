#include <conio.h>
#include "Notas.h"
#include <iostream>
using namespace std;
int main() {
	int opcion;
	char nombre[30];
	do {
		cout << endl << endl;
		cout << "1.registrar Alumnos"<<endl;
		cout << "2.registrar Materias" << endl;
		cout << "3.consultar Materias" << endl;
		cout << "4.registra Notas" << endl;
		cout << "5.Consultar Notas" << endl;
		cout << "6.Promedio Alumno" << endl;
		cout << "7.Promedio clases" << endl;
		cout << "8.Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			Notas::registrarAlumnos();
			break;
		case 2:
			Notas::registrarMaterias();
			break;

		case 3:
			Notas::consultarMaterias();
			break;

		case 4:
			Notas::registrarNotas();
			break;
		case 5:
			Notas::consultarNotas();
			break;

		case 6:
			
			cout << "Escriba el nombre del alumno: ";
			cin >> nombre;
			Notas::ObtenerPromedioAlumno(nombre);
			break;

		case 7:
			
			cout << "Escriba el nombre de la materia: ";
			cin >> nombre;
			Notas::ObtenerPromedioClases(nombre);
			break;
		case 8:
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}


	} while (opcion!=8);

}