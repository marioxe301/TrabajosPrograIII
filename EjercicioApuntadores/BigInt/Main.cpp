#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
	BigInt numero1;
	BigInt numero2;
	
	cout << "Escriba un numero de 10 digitos: ";
	cin >> numero1;
	cout << endl;
	cout <<"Numero 1: "<< numero1<<endl;
	cout << "Escriba otro de 10 digitos: ";

	cin >> numero2;
	cout << "Numero 2: " << numero2 << endl;
	cout << endl;

	cout << numero1 + numero2; // da la respuesta en los ultimos digitos
	cout << endl;
	cout << numero1 - numero2; // da la espuesta en los ultimos digitos

	//nota pendiente en corregir ese detalle al momento de la impresion
	cout << endl;
	numero1 == numero2 ? cout<<"Es igual" : cout<<"No es igual";
	cout << endl;
	numero1 <= numero2 ? cout << "Es igual o menor" : cout << "No es igual o menor";
	cout << endl;
	numero1 >= numero2 ? cout << "Es igual o mayor" : cout << "No es igual o mayor";
	cout << endl;
	numero1 < numero2 ? cout << "Es menor" : cout << "Es mayor";
	cout << endl;
	numero1 > numero2 ? cout << "Es mayor" : cout << "Es menor";
	cout << endl;
	system("pause");
}