#pragma once
#ifndef CHAR_H
#define CHAR_H
#include "Object.h"

class Char : public Object {
public:
	Char(char);
	~Char();

	void setValor(char);
	char getValor();

	Tipo getTipo();
	void imprimir();
private:
	char valor;

};

#endif // !1
