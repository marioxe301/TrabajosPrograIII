
#include "Numero.h"
#include <iostream>

using namespace std;

int main() {
	Numero A;
	Numero B;
	Numero C;

	cout << "Ingrese tres valores: " << endl;
	cin >> A;
	cin >> B;
	cin >> C;

	cout << "A = " << A << ",B = " << B << ", C = " << C<<endl;

	Numero resultado;

	resultado = A + B - C;
	cout << "Resultado: "<<A<<" +"<<B<<" -"<<C<<" = "<<resultado<<endl;

	Numero resultadoDiv;
	resultadoDiv = B / A;

	cout << "Resutado B/A= " << resultadoDiv << endl;

	if (A < B) {
		cout << "A es menor" << endl;
	}
	system("pause");
}