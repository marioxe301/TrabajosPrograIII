#pragma once

#ifndef NUMERO_H
#define NUMERO_H
#include<iostream>

class Numero {
	friend std::istream &operator>>(std::istream &, Numero &);// cin
	friend std::ostream &operator<<(std::ostream &,const Numero &);// cout
	friend Numero operator+(const Numero &, const Numero &);
	friend Numero operator-(const Numero &, const Numero&);

	friend Numero operator*(const Numero &, const Numero &);
	friend Numero operator/(const Numero &, const Numero &);
	
public:
	Numero();
	void setNumero(double);
	double getNumero();

	bool operator<(const Numero&);

private:
	double n;
};

#endif // !NUMERO_H

