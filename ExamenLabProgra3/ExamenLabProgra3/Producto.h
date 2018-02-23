#pragma once
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto {
public:
	Producto();
	void setCantidad(int);
	int getCantidad();

	void setNombre(std::string);
	std::string getNombre();

	void setPrecio(float);
	float getPrecio();

	void setSigProducto(Producto*);
	Producto * getSigProducto();


private:
	int Cantidad;
	std::string nombre;
	float precio;
	Producto *sigProducto;

};


#endif // !PRODUCTO_H
