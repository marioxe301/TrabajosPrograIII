#pragma once
#ifndef LISTAFACTURA_H
#define LISTAFACTURA_H
#include "Factura.h"
class ListaFacturas {
public:

	ListaFacturas();
	void agregarFactura(std::string, Fecha);
	Factura * BuscarFactura(std::string);
	void ImprimirDatosFactura(std::string);

private:
	Factura *primeraF, *UltimaF;
};

#endif // !LISTAFACTURA_H
