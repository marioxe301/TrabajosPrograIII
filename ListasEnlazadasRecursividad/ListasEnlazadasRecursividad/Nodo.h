#pragma once
#ifndef NODO_H
#define NODO_H

struct nodo
{
	int valor;
	nodo *sig;
	nodo *ant;
	nodo() {
		sig = 0;
		ant = 0;
	}

};

void insertarInicio(nodo **,nodo*);
void insertarFinal(nodo**,nodo*);
void imprimirLista(nodo**);

void insertarFinalR(nodo**, nodo*);
nodo *buscar(nodo**, int);
#endif // !NODO_H
