#pragma once
#ifndef FIGURA_H
#define FIGURA_H

class Figura {
public:
	virtual float getPerimetro() = 0; // el 0 fuerza al usuario para implemetar el metodo en las clases hijas
	virtual float getArea() = 0;
	virtual void imprimir() = 0;
	virtual int getTipo() = 0;
	
};

#endif // !FIGURA_H
