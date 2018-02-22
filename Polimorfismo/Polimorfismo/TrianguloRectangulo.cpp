#include "TrianguloRectangulo.h"
#include <cmath>
#include <iostream>

TrianguloRectangulo::TrianguloRectangulo(): base(1),altura(1)
{}

TrianguloRectangulo::TrianguloRectangulo(float base, float altura) {
	setBase(base);
	setAltura(altura);
}

void TrianguloRectangulo::setBase(float base) {
	if (base > 0) {
		this->base = base;

	}
	else
	{
		this->base = 1;
	}
}

void TrianguloRectangulo::setAltura(float altura) {
	if (altura > 0) {
		this->altura = altura;

	}
	else
	{
		this->altura = 1;
	}
}

float TrianguloRectangulo::getBase() {
	return base;
}

float TrianguloRectangulo::getAltura() {
	return altura;
}

float TrianguloRectangulo::getPerimetro() {
	return base + altura + sqrt(base*base + altura*altura);
}

float TrianguloRectangulo::getArea() {
	return (base+altura)/2;

}

float TrianguloRectangulo::getHipotenusa() {
	return sqrt(base*base + altura*altura);
}

void TrianguloRectangulo::imprimir() {
	std::cout << "Triangulo Rectangulo{base: " << getBase() << " ,altura: "
		<< getAltura() << "} area: " << getArea() << " Perimetro: " << getPerimetro() << std::endl;
}

int TrianguloRectangulo::getTipo() {
	return 2;
}