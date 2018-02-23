#include <iostream>
#include "Factura.h"
#include "Fecha.h"
#include "ListaFacturas.h"

using namespace std;


int main() {
	Fecha fecha;
	fecha.setAño(2018);
	fecha.setDia(23);
	fecha.setMes(2);
	ListaFacturas *lista = new ListaFacturas;
	lista->agregarFactura("Mario",fecha);
	lista->agregarFactura("Max", fecha);


	lista->BuscarFactura("Mario")->agregarProducto("Balones", 23, 2);

	lista->BuscarFactura("Max")->agregarProducto("Tennis", 50, 2);
	
	lista->BuscarFactura("Mario")->agregarProducto("Zapatos", 100, 1);

	lista->ImprimirDatosFactura("Mario");
	lista->BuscarFactura("Mario")->imprimirFactura();
	

	cout << endl;
	lista->ImprimirDatosFactura("Max");
	lista->BuscarFactura("Max")->imprimirFactura();


	system("pause");
}


