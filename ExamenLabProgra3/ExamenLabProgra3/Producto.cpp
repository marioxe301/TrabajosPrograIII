#include "Producto.h"

Producto::Producto() : Cantidad(1), nombre(" "), precio(1), sigProducto(0)
{}

void Producto::setCantidad(int cantidad) {
	this->Cantidad = cantidad;
}
void Producto::setNombre(std::string nombre) {
	this->nombre = nombre;
}
void Producto::setPrecio(float precio) {
	this->precio = precio;
}

void Producto::setSigProducto(Producto*nuevo) {
	this->sigProducto = nuevo;
}

int Producto::getCantidad() {
	return this->Cantidad;
}

std::string Producto::getNombre() {
	return this->nombre;
}

float Producto::getPrecio() {
	return this->precio;
}
Producto* Producto::getSigProducto() {
	return this->sigProducto;
}