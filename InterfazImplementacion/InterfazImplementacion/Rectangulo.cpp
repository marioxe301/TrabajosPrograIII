
#include <iostream>
#include "rectangulo.h"
using namespace std;

Rectangulo::Rectangulo(): 
	base(0),altura(0)// inicializar variables
	{ }//cuerpo de constructor vacio

Rectangulo::Rectangulo(int b, int h) {

	setAltura(h);
	setBase(b);
}

void Rectangulo::setBase(int b) {
	if (b >= 0) {
		base = b;
	}
	else {
		cout << "Error en valor de la base " << endl;
	}
}
void Rectangulo::setAltura(int h) {
	if (h >= 0) {
		altura = h;
	}
	else {
		cout << "Error en valor de la altura" << endl;
	}
}

int Rectangulo::getBase() {
	return base;

}
int Rectangulo::getAltura() {
	return altura;
}
int Rectangulo::getArea() {
	return base * altura;

}

int Rectangulo::getPerimetro() {
	return 2 * (base + altura);
}

void Rectangulo::imprimirRectangulo() {
	cout << "\nBase: " << base << "\nAltura: " << altura;
}