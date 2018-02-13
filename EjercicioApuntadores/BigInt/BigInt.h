#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>

#define TAM_ARREGLO 10 // es un valor introduccido y modificable del arreglo en este caso del tamañide nuestro entero


class BigInt {

	friend std::istream& operator>>(std::istream  &, BigInt &); // sobrecarga operador salida
	friend std::ostream& operator<<(std::ostream &, const BigInt&); // "  "  entrada
	friend BigInt operator+(const BigInt&,const BigInt&);// " " suma
	friend BigInt operator-(const BigInt&, const BigInt&);// " " resta

	 // " " operadores de condicion
	
	
	

public:
	BigInt(); // constructor

	bool operator==(const BigInt &);
	bool operator>=(const BigInt &);
	bool operator<=(const BigInt &);
	bool operator<(const BigInt &);
	bool operator>(const BigInt &);

private:
	char a[TAM_ARREGLO]; //arreglo para entrada de datos para luego agregarlo en el otro arreglo de enteros
	int entero[TAM_ARREGLO];
};




#endif // !BIGINT_H
