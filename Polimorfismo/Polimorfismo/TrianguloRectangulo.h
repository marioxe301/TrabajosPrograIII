#pragma once
#ifndef TRIANGULORECTANGULO_H
#define TRIANGULORECTANGULO_H
#include "Figura.h"

class TrianguloRectangulo : public Figura {
public:
	TrianguloRectangulo();
	TrianguloRectangulo(float, float);

	void setBase(float);
	void setAltura(float);

	float getBase();
	float getAltura();

	float getPerimetro();
	float getArea();
	float getHipotenusa();

	void imprimir();

	int getTipo();

private: 
	float base, altura;
};

#endif // !TRIANGULORECTANGULO_H
