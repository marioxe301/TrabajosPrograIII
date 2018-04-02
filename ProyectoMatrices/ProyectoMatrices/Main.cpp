#include <iostream>
#include "Matriz.h"
using namespace std;

int main() {
	Matriz *UtilidadesC= new Matriz;

	Matriz A;


	A.CrearMatriz("A.dat");
	A.LLenarMatriz("A.dat");

	A.ImprimirMatriz("A.dat");

	//cout << "Nodo ini: " << A.getNodo()->getValor();


	Matriz B;
	B.CrearMatriz("B.dat");
	B.LLenarMatriz("B.dat");
	cout << endl<<endl;

	B.ImprimirMatriz("B.dat");

	//cout << "Nodo ini: " << B.getNodo()->getSig()->getValor();

	system("pause");

	/*UtilidadesC->SumaMatriz(A, B, "A.dat", "B.dat", "A+B.dat");


	UtilidadesC->RestaMatriz(A, B, "A.dat", "B.dat", "A-B.dat");*/

	UtilidadesC->DeterminanteMatriz(A, "Adet.dat");

	/*UtilidadesC->MultiplicacionMatriz(A, B, "A.dat", "B.dat", "AB.dat");*/



	system("pause");
}