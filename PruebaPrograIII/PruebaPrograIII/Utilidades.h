#pragma once
#ifndef UTILIDADES_H
#define UTILIDADES_H

struct Nodo {
	int valor;
	Nodo *sig;
	Nodo *ant;
	Nodo() {
		sig = 0;
		ant = 0;
	}
};

class Utilidades {
public:
	
	static void InsertarFinal(Nodo **, int);
	static Nodo * CrearLista(int);
	static void OrdenarLista(Nodo **);
	static void GuardarLista(Nodo **, char *);
	static void ImprimirLista(Nodo **);

};

#endif // !UTILIDADES_H
