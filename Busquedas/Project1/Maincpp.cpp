#include <iostream>
using namespace std;
int arreglo[100];
void llenarArray() {
	for (int i = 0; i <100; i++) {
		arreglo[i] = i;
	}

}


void BusquedaSecuencial(int buscar) {
	bool a = false;
	if (buscar >=99){
		cout << "El numero no se encontro" << endl;
		
	}
	else {


		for (int i = 0; i < 100; i++) {
			if (arreglo[i] == buscar) {
				cout << "Numero: " << arreglo[i] << " Poscicion: " << i << endl;
				a = true;
				break;
			}
		}
		if (a == false) {
			cout << "El numero no se encontro" << endl;
		}
	}
}

void BusquedaBinaria(int buscar) {
	int Inicio = 0;
	int fin = 99;
	int pivote;
	bool a = false;
	if (buscar >= 99) {
		cout << "Valor no encontrado" << endl;
	}
	else {
		while (Inicio <= fin) {
			pivote = (Inicio + fin) / 2;
			if (buscar == arreglo[pivote]) {
				cout << "Numero: " << arreglo[pivote] << " Poscicion: " << pivote<<endl;
				a = true;
				break;
			}
			else if (buscar > arreglo[pivote]) {
				Inicio = pivote + 1;
			}
			else
			{
				fin = pivote - 1;
			}
		}
	}
	if (a == false) {
		cout << "Valor no encontrado" << endl;
	}
}
int main() {
	llenarArray();
	int opcion;
	int numero = 0;
	cout << "1.Busqueda Secuencial"<<endl;
	cout << "2.Busqueda Binaria"<<endl;
	cin >> opcion;
	switch (opcion){
	case 1:
		cout << "Ingrese el numero: "<<endl; cin >> numero;
		BusquedaSecuencial(numero);
		break;
	case 2:
		cout << "Ingrese el numero: " << endl; cin >> numero;
		BusquedaBinaria(numero);
		break;
	default:
		cout << "Opcion Invalida" << endl;
		break;
	}
	system("pause");
}