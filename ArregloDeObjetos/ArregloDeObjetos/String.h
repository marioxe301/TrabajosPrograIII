#pragma once
#ifndef STRING_H
#define STRING_H
#include "Object.h"
#include <string>

class String : public Object {
public:
	String(std::string);
	~String();

	Tipo getTipo();
	void imprimir();

	void setValor(std::string);
	std::string getValor();

private:
	std::string valor;

};

#endif // !STRING_H
