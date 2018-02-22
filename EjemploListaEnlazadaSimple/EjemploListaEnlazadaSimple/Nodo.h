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

	void setAnt(Nodo *);
	Nodo *getAnt();

private:
	int valor;
	Nodo *sig;
	Nodo *ant;
};

#endif // !NODO_H