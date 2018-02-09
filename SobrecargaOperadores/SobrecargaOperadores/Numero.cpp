#include "Numero.h"

Numero::Numero() {
	setNumero(0);
}

void Numero::setNumero(double valor) {
	n = valor;
}

double Numero::getNumero() {
	return n;
}

std::istream &operator>>(std::istream &entrada, Numero &a) {
	entrada >> a.n;
	return entrada;
}

std::ostream &operator<<(std::ostream &salida, const Numero&a) {
	salida << a.n;
	return salida;
}

Numero operator+(const Numero&a, const Numero&b) {
	Numero temp;
	temp.n = a.n + b.n;
	return temp;
}

Numero operator-(const Numero&a, const Numero&b) {
	Numero temp;
	temp.n = a.n - b.n;
	return temp;
}

Numero operator*(const Numero&a, const Numero&b) {
	Numero temporal;
	temporal.n = a.n * b.n;
	return temporal;
}

Numero operator/(const Numero&a, const Numero&b) {
	
	if (b.n == 0) {
		std::cout << "No puede dividirse entre 0";
		system("pause");
		exit(1);
		
	}
	Numero temporal;
	temporal.n = a.n / b.n;
	return temporal;
}

bool Numero::operator<(const Numero&a) {
	return this->n < a.n ? true : false;
}