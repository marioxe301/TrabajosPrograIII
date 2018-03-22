#pragma once
#ifndef HERRAMIENTA_H
#define HERRAMIENTA_H

struct Tools
{
	Tools(){}
	int codigo;
	char nombre[30];
	int cantidad;
	float costo;
	

};

class MetodosProductos {
public:

	static void crearArchivoVacio();
	static float poscicionVacia();
	static void agregarProducto(Tools);
	static void eliminarProducto(int);
	static void ImprimirProductos();
	static void modificarProducto(int);
	
};
#endif // !HERRAMIENTA_H
