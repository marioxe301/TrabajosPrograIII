#include <iostream>
#include "Object.h"
#include "String.h"
#include "Char.h"
#include "Integer.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

int main() {
	
	int contS = 0,contC=0,contI=0;
	int opcion = 0;
	int Tam_arreglo = 0;
	Object *arreglo[4];
	string cadena;
	char c;
	int i;

	for (int i = 0; i < 4;i++) { //inicializa en null el arreglo
		arreglo[i] = 0;
	}
	do {
		system("cls");
		cout << endl;
		cout << "1.Añadir a Arreglo" << endl;
		cout << "2.Imprimir Arreglo " << endl;
		cout << "3.salir" << endl;
		cin >> opcion;
		
		switch (opcion)
		{
		case 1:
			if (Tam_arreglo < 4) {
				int op;
				cout << endl;
				cout << "1.Añadir String" << endl;
				cout << "2.Añadir Char" << endl;
				cout << "3.Añadir Int" << endl;
				cin >> op;

				switch (op) {
				case 1:
					cout << "Ingrese su cadena: ";
					cin >> cadena;

					arreglo[Tam_arreglo] = new String(cadena);
					Tam_arreglo++;
					
					system("cls");
					break;

				case 2:

					cout << "Ingrese su caracter: ";
					cin >> c;

					arreglo[Tam_arreglo] = new Char(c);
					Tam_arreglo++;
					system("cls");
					break;

				case 3:
					cout << "Ingrese su entero: ";
					cin >> i;

					arreglo[Tam_arreglo] = new Integer(i);
					Tam_arreglo++;
					system("cls");

					break;

				default:
					cout << "Opcion invalida" << endl;
					system("cls");
					break;
				}
				break;
			}
			else {
				cout << "Arreglo Lleno"<<endl;
				Sleep(1000);
			}
			break;
		case 2:
			contS=contI=contC = 0;
			for (int i = 0; i < 4; i++) {
				if (arreglo[i] != 0) {
					arreglo[i]->imprimir();
					if (arreglo[i]->getTipo() == 0) {
						contC++;
					}
					else if (arreglo[i]->getTipo() == 1) {
						contS++;
					}
					else if (arreglo[i]->getTipo() == 2) {
						contI++;
					}

				}
			}
			cout << endl;
			cout << "Objeto String-> " << contS<<endl;
			cout << "Objeto Char-> " << contC << endl;
			cout << "Objeto Integer-> " << contI << endl;
			_getch();
			break;

		case 3:
			break;

		default:
			cout << "Opcion no valida" << endl;
			
			break;
		}




	} while (opcion != 3);
		
}