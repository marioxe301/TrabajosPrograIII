#include "Herramienta.h"
#include <fstream>
#include <iostream>

using namespace std;

float MetodosProductos::poscicionVacia() {
	ifstream ArchivoProductos("productos.dat", ios::in | ios::binary);
	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return -1;
	}

	Tools tools;

	ArchivoProductos.seekg(0, ios::beg);
	
	int poscicion=0;

	ArchivoProductos.read(reinterpret_cast<char *>(&tools), sizeof(Tools));

	while (!ArchivoProductos.eof())
	{
		if (tools.codigo == -1) {

			ArchivoProductos.close();
			return poscicion;
		}
		ArchivoProductos.read(reinterpret_cast<char *>(&tools), sizeof(Tools));
		
		poscicion++;

	}
	ArchivoProductos.close();
	return -1;
}

void MetodosProductos::crearArchivoVacio() {
	ofstream ArchivoProductos("productos.dat", ios::out|ios::app | ios::binary);
	
	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return;
	}
	
	Tools tools;
	tools.codigo = -1;
	strcpy(tools.nombre, " ");
	tools.cantidad = -1;
	tools.costo = -1;

	ArchivoProductos.seekp(0, ios::end);
	for (int i = 0; i < 100; i++) {
		ArchivoProductos.write(reinterpret_cast<const char *>(&tools), sizeof(Tools));
	}
	ArchivoProductos.close();
}

void MetodosProductos::agregarProducto(Tools nuevo_herra){
	ofstream ArchivoProductos("productos.dat", ios::out|ios::in | ios::binary);

	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return;
	}
	int poscicion = poscicionVacia();
	
	ArchivoProductos.seekp(poscicion * sizeof(Tools),ios::beg);
	ArchivoProductos.write(reinterpret_cast<const char *>(&nuevo_herra), sizeof(Tools));
	

	ArchivoProductos.close();
}

void MetodosProductos::ImprimirProductos() {
	ifstream ArchivoProductos("productos.dat", ios::in | ios::binary);

	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return;
	}
	Tools tools;
	ArchivoProductos.seekg(0, ios::beg);

	ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));
	while (!ArchivoProductos.eof()) {
		if (tools.codigo == -1) {
			ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));
		}
		else
		{
			cout << "Codigo: " << tools.codigo << " Nombre: " << tools.nombre << " Cantidad: " <<
				tools.cantidad << " Precio: " << tools.costo << "\n";
			ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));

		}
	}
	ArchivoProductos.close();
}

void MetodosProductos::eliminarProducto(int codigo) {
	fstream ArchivoProductos("productos.dat", ios::out |ios::in| ios::binary);

	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return;
	}

	Tools tools;
	ArchivoProductos.seekg(0, ios::beg);
	int poscicion = 0;
	ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));

	
		while (!ArchivoProductos.eof())
		{
			if (tools.codigo == codigo) {
				ArchivoProductos.seekp(poscicion * sizeof(Tools), ios::beg);
				tools.codigo = -1;
				tools.cantidad = 0;
				tools.costo = 0;
				strcpy(tools.nombre, " ");
				ArchivoProductos.write(reinterpret_cast<const char *>(&tools), sizeof(tools));
				ArchivoProductos.close();
				return;
			}
			else
			{
				poscicion++;
				ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));
			}

		}
		ArchivoProductos.close();

	
}

void MetodosProductos::modificarProducto(int codigo) {
	fstream ArchivoProductos("productos.dat", ios::out | ios::in | ios::binary);

	if (!ArchivoProductos) {
		cout << "Error al abrir archivo productos.dat";
		return;
	}

	Tools tools;
	ArchivoProductos.seekg(0, ios::beg);
	int poscicion = 0;
	ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));


	while (!ArchivoProductos.eof())
	{
		if (tools.codigo == codigo) {
			ArchivoProductos.seekp(poscicion * sizeof(Tools), ios::beg);
			char *tmN=0;
			cout << "Codigo: ";
			cin >> tools.codigo;
			cout << "Cantidad: ";
			cin >> tools.cantidad;
			cout << "Costo: ";
			cin >> tools.costo;
			cout << "Nombre: ";
			cin >>tools.nombre;
			


			ArchivoProductos.write(reinterpret_cast<const char *>(&tools), sizeof(tools));
			ArchivoProductos.close();
			return;
		}
		else
		{
			poscicion++;
			ArchivoProductos.read(reinterpret_cast<char*>(&tools), sizeof(Tools));
		}

	}
	ArchivoProductos.close();
}

