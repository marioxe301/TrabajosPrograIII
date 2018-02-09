#include "EnteroLargo.h"

EnteroLargo::EnteroLargo() {
	n = new char[TAM_ENTERO];
	numero = new int[TAM_ENTERO];

	for (int i = 0; i < TAM_ENTERO; i++)
	{
		n[i] = 'a';
		numero[i] = 0;
	}
}

std::istream & operator>>(std::istream &in,EnteroLargo &a) {
	in >> a.n;
	int final_arreglo = TAM_ENTERO - 1;
	for (int i = strlen(a.n) - 1; i >= 0;i--) {
		switch (a.n[i])
		{
		case '0':
			a.numero[final_arreglo] = 0;

			break;
		case '1':
			a.numero[final_arreglo] = 1;

			break;
		case '2':
			a.numero[final_arreglo] = 2;

			break;
		case '3':
			a.numero[final_arreglo] = 3;

			break;
		case '4':
			a.numero[final_arreglo] = 4;

			break;
		case '5':
			a.numero[final_arreglo] = 5;

			break;
		case '6':
			a.numero[final_arreglo] = 6;

			break;
		case '7':
			a.numero[final_arreglo] = 7;

			break;
		case '8':
			a.numero[final_arreglo] = 8;

			break;
		case '9':
			a.numero[final_arreglo] = 9;

			break;

		}//fin switch
		final_arreglo--;
	}//fin de for
	return in;
}

std::ostream & operator<<(std::ostream &out, const EnteroLargo &a) {
	for (int i = 0;i< strlen(a.n);i++) {
		out << a.numero[TAM_ENTERO - strlen(a.n) + i];

	}
	return out;
}
