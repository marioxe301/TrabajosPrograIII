

#include <iostream>
using namespace std;

void OrdenamientoPorSeleccion(int v[]);

int main() {
	int arreglo[] = { 2,12,45,23,46,78,32,56,67,34};
	//Arreglo No Ordenado
	for (int i = 0; i < 10; i++)
	{
		cout << arreglo[i] << "\t";
	}

	cout << endl<< endl;
	//Ordenamiento
	for  (int i = 0; i < 10; i++)
	{
		int minimo = i;
		for (int j = i + 1; j < 10; j++) {
			if (arreglo[j] < arreglo[minimo]) {
				minimo = j;
			}
		}
		int auxiliar = arreglo[i];
		arreglo[i] = arreglo[minimo];
		arreglo[minimo] = auxiliar;
	}
	
	//Arreglo Ordenado
	for (int i = 0; i < 10; i++)
	{
		cout << arreglo[i] << "\t";
	}

	system("pause");
}

