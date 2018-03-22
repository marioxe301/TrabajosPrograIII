#include "Notas.h"

#include <fstream>
#include<iostream>

using namespace std;

void Notas::registrarAlumnos() {
	ofstream archivoAlumnos("alumnos.dat", ios::app);// (nombre del file, para no sobre escribir y ponerse al final de la linea)

	if (!archivoAlumnos) {
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return;
	}

	int cuenta, edad,cantidad;
	char nombre[50];

	cout << "\n\n *** I N G R E S O  D E  A L U M N O S ***\n\n";
	cout << "Cantidad de alumnos a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad;i++) {
		cout << "Ingrese numero de cuenta: ";
		cin >> cuenta;
		cout << "Ingrese nombre de alumno: ";
		cin >> nombre;
		cout << "Ingrese edad: ";
		cin >> edad;

		archivoAlumnos << cuenta << ' ' << nombre << ' ' << edad << ' ' << "\n";
		cout << endl;
	}

	archivoAlumnos.close();
}

void Notas::consultarAlumnos() {
	ifstream archivoAlumnos("alumnos.dat", ios::app);

	if (!archivoAlumnos) {
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return;
	}

	int cuenta, edad;
	char nombre[50];

	cout << "\n\n*** C O N S U L T A  D E  A L U M N O S ***\n\n";

	//archivoAlumnos.seekg(0, ios::beg);

	while (archivoAlumnos>>cuenta>>nombre>>edad) {
		cout << cuenta << ' ' << nombre << ' ' << edad << "\n";
	}

	archivoAlumnos.close();
}

void Notas::registrarMaterias() {
	ofstream archivoMateriasOut("materias.dat", ios::app); // ofstream escritura y istream lectura

	if (!archivoMateriasOut) {
		cout << "Erro al abrir el archivo materias.dat\n";
		return;
	}

	int cantidad, codigoM;
	char Nombre[30];

	cout << "\n\n *** I N G R E S O  D E  M A T E R I A S ***\n\n";

	cout << "Ingrese la cantidad de materias: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad;i++) {
		cout << "Escriba el codigo de la materia: ";
		cin >> codigoM;
		cout << "Escriba nombre de la clase: ";
		cin >> Nombre;

		archivoMateriasOut << codigoM << ' ' << Nombre << ' ' << "\n";
	}
	archivoMateriasOut.close();

}

void Notas::consultarMaterias() {
	ifstream archivomaterias("materias.dat",ios::in);

	if (!archivomaterias) {
		cout << "Erro al abrir el archivo materias.dat\n";
		return;
	}
	archivomaterias.seekg(0, ios::beg);

	int codigo;
	char nombre[30];

	cout << "\n\n *** C O N S U L T A  D E  M A T E R I A S ***\n\n";

	while (archivomaterias>>codigo>>nombre) {
		cout << codigo << ' ' << nombre << "\n";
	}

	archivomaterias.close();
}

void Notas::registrarNotas() {
	ofstream archivoNotasout("notas.dat", ios::app);
	
	if (!archivoNotasout) {
		cout << "Error al abrir archivo notas.dat\n";
		return;
	}

	int opcion = 0;
	cout << "\n\n *** I N G R E S O  D E  N O T A S ***\n\n";

	do {

		char nombreM[30];
		char nombreA[50];
		int codigoM,codigoA,nota;

		do {
			cout << "Ingrese Materia: ";
			cin >> nombreM;
			codigoM = obtenerCodigoMateria(nombreM);

		} while (codigoM ==-1);

		do {
			cout << "Ingrese Alumno: ";
			cin >> nombreA;
			codigoA = ObtenerCodigoAlumno(nombreA);

		} while (codigoA == -1);

		cout << "Ingrese Nota: ";
		cin >> nota;

		archivoNotasout << codigoM << ' ' << codigoA << ' ' << nota << "\n";

		cout << "Desea ingresar una nueva nota? -1 para salir.";
		cin >> opcion;

	} while (opcion != -1);

	archivoNotasout.close();
	
}

int Notas::obtenerCodigoMateria(char * Nombre) {
	ifstream archivoMaterias("materias.dat", ios::in);

	if (!archivoMaterias) {
		cout << "Error al abrir archivo materias.dat\n";
		return -1;
	}

	archivoMaterias.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMaterias>>codigo >>nombre)
	{
		if (strcmp(nombre,Nombre)==0) {
			return codigo;
		}

	}

	return -1;
}

int Notas::ObtenerCodigoAlumno(char *Nombre) {
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos) {
		cout << "Error al abrir archivo alumnos.dat\n";
		return -1;
	}

	archivoAlumnos.seekg(0, ios::beg);
	int codigo,edad;

	char nombre[50];

	while (archivoAlumnos >> codigo >> nombre >> edad)
	{
		if (strcmp(nombre, Nombre) == 0) { // si retorna 0 son iguales
			return codigo;
		}

	}

	return -1;
}

char * Notas::obtenerNombreAlumno(const int codigoAlumno) {
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir alumnos.dat\n";
		return NULL;
	} 

	archivoAlumnos.seekg(0, ios::beg);
	int codigo, edad;
	char nombre[50];

	
	while (archivoAlumnos >> codigo >> nombre >> edad) {
		if (codigoAlumno == codigo) {
			char * retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
		
			retorno[strlen(nombre)] = '\0';
			archivoAlumnos.close();
			return retorno;
		}
	}
	archivoAlumnos.close();
	return NULL;
}

char *Notas::obtenerNombreClase(const int codigoMateria) {
	ifstream archivoMaterias("materias.dat", ios::in);

	if (!archivoMaterias)
	{
		cout << "Error al intentar abrir alumnos.dat\n";
		return NULL;
	}
	archivoMaterias.seekg(0, ios::beg);
	int codigo;
	char nombre[30];
	

	while (archivoMaterias >> codigo >> nombre ) {
		if (codigoMateria == codigo) {
			char * retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			
			retorno[strlen(nombre)] = '\0';
			archivoMaterias.close();
			return retorno;
		}
	}

	archivoMaterias.close();
	return NULL;
}

void Notas::consultarNotas() {
	ifstream archivoNotas("notas.dat", ios::in);

	if (!archivoNotas) {
		cout << "Error al abrir notas.dat";
		return;
	}

	cout << "\n\n *** C O N S U L T A  D E  N O T A S *** \n\n";

	int codigoM, codigoA, nota;
	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoM >> codigoA >> nota)
	{
		cout << obtenerNombreClase(codigoM)<<' '<<
			obtenerNombreAlumno(codigoA)<<' ' << nota <<"\n";

	}

	archivoNotas.close();


}

void Notas::ObtenerPromedioAlumno(char * nombre) {
	ifstream archivoNotas("notas.dat", ios::in);

	if (!archivoNotas) {
		cout << "Error al abrir notas.dat";

	}
	int i = 0; float  suma = 0;
	float promedio=0;
	char *n=0;
	

	int codigoC, codigoA, nota;
	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas>>codigoC>>codigoA>>nota)
	{
		if (ObtenerCodigoAlumno(nombre) == -1) {
			cout << "El alumno no existe\n";
			archivoNotas.close();
			return;
		}
		else
		{
			if (ObtenerCodigoAlumno(nombre) == codigoA) {
				n = obtenerNombreAlumno(codigoA);
				
				suma = suma + nota;
				i++;
			}
			
		}

	}
	archivoNotas.close();
	promedio = suma / i;
	
	cout << "Promedio de " << n << ": " << promedio<<endl;
}

void Notas::ObtenerPromedioClases(char * nombreC) {
	ifstream archivoNotas("notas.dat", ios::in);
	
	if (!archivoNotas) {
		cout << "Error al abrir notas.dat";

	}
	int i = 0; float suma = 0;
	float promedio = 0;
	char *n=0;


	int codigoC, codigoA, nota;
	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoC >> codigoA >> nota)
	{
		if (obtenerCodigoMateria(nombreC) == -1) {
			cout << "La materia no existe\n";
			archivoNotas.close();
			return;
		}
		else
		{
			if (obtenerCodigoMateria(nombreC) == codigoC) {
				n = obtenerNombreClase(codigoC);

				suma = suma + nota;
				i++;
			}

		}

	}
	archivoNotas.close();
	promedio = suma / i;
	
	cout << "Promedio de " << n << ": " << promedio<<endl;
}