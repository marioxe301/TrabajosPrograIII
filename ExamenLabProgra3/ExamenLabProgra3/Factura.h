#ifndef FACTURA_H
#define FACTURA_H
#include "Fecha.h"
#include "Producto.h"
#include <iostream>

class Factura {
public:
	Factura();
	
	void agregarProducto(std::string, float, int);
	void imprimirFactura();
	void setFecha(Fecha);
	Fecha getFecha();
	
	void setNombreCliente(std::string);
	std::string getNombre();

	
	bool VacioProducto();

	void setFacturaSig(Factura*);
	Factura * getFacturaSig();

private:
	std::string NombreCliente;
	Fecha fecha;
	Factura *FacturaS;
	Producto *productoP, *productoU;
};



#endif // !FACTURA_H