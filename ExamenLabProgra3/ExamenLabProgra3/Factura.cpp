#include "Factura.h"



Factura::Factura():NombreCliente(" "),FacturaS(0),productoP(0),productoU(0)
{}
void Factura::setFacturaSig(Factura*factura) {
	this->FacturaS = factura;
}


Factura* Factura::getFacturaSig() {
	return this->FacturaS;
}

bool Factura::VacioProducto() {
	return productoP == 0;
}

void Factura::agregarProducto(std::string nombre, float precio, int cantidad) {
	Producto *tmp = new Producto;
	tmp->setNombre(nombre);
	tmp->setPrecio(precio);
	tmp->setCantidad(cantidad);

	if (VacioProducto()) {
		productoP = productoU = tmp;
	}
	else {
		productoU->setSigProducto(tmp);
		productoU = tmp;
	}

}

void Factura::imprimirFactura() {
	Producto *tmp = productoP;

	float subtotal = 0;
	float ISV = 0;
	float total = 0;
	while (tmp != 0) {
		subtotal = subtotal + (tmp->getCantidad() * tmp->getPrecio());

		tmp = tmp->getSigProducto();
	}
	ISV = 0.07 * subtotal;
	total = subtotal + ISV;
	
	std::cout << "Subtotal: " << subtotal<<"\n";
	std::cout << "ISV: " << ISV << "\n";
	std::cout << "Total: " << total << "\n";
	
}

//void Factura::agregarFactura(std::string nombre,Fecha fecha) {
//	Factura *tmp = new Factura;
//	tmp->setNombreCliente(nombre);
//	tmp->setFecha(fecha);
//	if (primeraF == 0) {
//		primeraF = ultimaF = tmp;
//	}
//	else {
//		ultimaF->setFacturaSig(tmp);
//		ultimaF = tmp;
//	}
//}

void Factura::setFecha(Fecha fecha) {
	this->fecha = fecha;
}

//Factura*  Factura::BuscarFactura(std::string nombre) {
//	Factura * tmp = primeraF;
//	while (tmp!=0) {
//		if (tmp->getNombre() == nombre) {
//			return tmp;
//		}
//		tmp = tmp->getFacturaSig();
//	}
//	return 0;
//}

std::string Factura::getNombre() {
	return  this->NombreCliente;
}

void Factura::setNombreCliente(std::string nombre) {
	this->NombreCliente = nombre;
}
Fecha Factura::getFecha() {
	return this->fecha;
}