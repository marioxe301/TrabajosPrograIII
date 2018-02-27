#pragma once
#ifndef INTEGER_H
#define INTEGER_H

#include "Object.h"

class Integer : public Object
{
public:
	Integer(int);
	~Integer();

	void setValor(int);
	int getValor();

	Tipo getTipo();
	void imprimir();


private:
	int valor;
};



#endif // !INTEGER_H
