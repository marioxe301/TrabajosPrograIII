#pragma once
#ifndef RECTANGULO_H
#define RECTANGULO_H

#include"Figura.h"
class Rectangulo: public Figura {
public:
	Rectangulo();
	Rectangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();

	float getPerimetro();
	float getArea();

	void imprimir();
	
	int getTipo();

private:
	float base, altura;
};

#endif // !RECTANGULO_H
