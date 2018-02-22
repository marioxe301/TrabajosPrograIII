#include <iostream>
#include "Figura.h"
#include "Rectangulo.h"
#include "TrianguloRectangulo.h"
#include <conio.h>
using namespace std;

int main() {
	Figura *figuras[4];

	figuras[0] = new Rectangulo(4, 6);
	figuras[1] = new Rectangulo(5, 8);
	figuras[2] = new TrianguloRectangulo(4, 6);
	figuras[3] = new TrianguloRectangulo(5, 8);

	for (int i = 0; i < 4; i++) {
		figuras[i]->imprimir();
	}



	_getch();

	system("pause");
}