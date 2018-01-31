#include <iostream>
#include "rectangulo.h";
using namespace std;

int main() {
	int base, altura;
	cout << "Ingrese la base: ";
	cin >> base;
	cout << "Ingrese la altura: ";
	cin >> altura;

	Rectangulo r(base, altura);
	cout << "\nArea: " << r.getArea() << endl;
	cout << "\nPerimetro: " << r.getPerimetro() << endl;

	Rectangulo r2;
	r2.setBase(6);
	r2.setAltura(9);

	cout << "\nArea: " << r2.getArea() << endl;
	cout << "\nPerimetro: " << r2.getPerimetro() << endl;
	system("pause");

}