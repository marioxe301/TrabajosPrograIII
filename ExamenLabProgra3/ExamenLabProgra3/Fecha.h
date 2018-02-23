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

	void setAño(int);
	int getAño();

private:
	int dia, mes, año;
};


#endif // !FECHA_H

