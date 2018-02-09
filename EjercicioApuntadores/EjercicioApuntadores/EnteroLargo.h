#pragma once

#ifndef ENTEROLARGO_H
#define ENTEROLARGO_H
#include <iostream>

#define TAM_ENTERO 50
class EnteroLargo
{
	friend std::istream& operator>>(std::istream  &,EnteroLargo &);
	friend std::ostream& operator<<(std::ostream &,const EnteroLargo&);

public:
	EnteroLargo();
private:

	char *n;
	int *numero;

};


#endif // !ENTEROLARGO_H

