#include "ListaFacturas.h"
#include <iostream>
ListaFacturas::ListaFacturas(): primeraF(0),UltimaF(0)
{}

void ListaFacturas::agregarFactura(std::string nombre,Fecha fecha) {
	Factura *tmp = new Factura;
	tmp->setNombreCliente(nombre);
	tmp->setFecha(fecha);
	if (primeraF == 0) {
		primeraF = UltimaF = tmp;
	}
	else {
		UltimaF->setFacturaSig(tmp);
		UltimaF = tmp;
	}
}

Factura*  ListaFacturas::BuscarFactura(std::string nombre) {
	Factura * tmp = primeraF;
	while (tmp!=0) {
		if (tmp->getNombre() == nombre) {
			return tmp;
		}
		tmp = tmp->getFacturaSig();
	}
	return 0;
}

void ListaFacturas::ImprimirDatosFactura(std::string nombre) {
	Factura * tmp = primeraF;
	while (tmp != 0) {
		if (tmp->getNombre() == nombre) {
			tmp->getFecha().imprimirFecha();
			std::cout << "Nombre: " << tmp->getNombre()<<std::endl<<std::endl;
			

		}
		tmp = tmp->getFacturaSig();
	}
}