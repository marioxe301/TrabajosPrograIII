#pragma once
#ifndef FECHA_H
#define FECHA_H
class Fecha {
public:
	Fecha();
	void imprimirFecha();
	void setDia(int);
	int getDia();

	void setMes(int);
	int getMes();

	void setA�o(int);
	int getA�o();

private:
	int dia, mes, a�o;
};


#endif // !FECHA_H

