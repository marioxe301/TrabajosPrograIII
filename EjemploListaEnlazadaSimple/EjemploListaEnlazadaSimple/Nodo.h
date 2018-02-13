#pragma once
#ifndef NODO_H

#define NODO_H


class Nodo {
public:
	Nodo();
	void setValor(int);
	int getValor();
	void setSig(Nodo*);
	Nodo* getSig();

private:
	int valor;
	Nodo *sig;
};

#endif // !NODO_H