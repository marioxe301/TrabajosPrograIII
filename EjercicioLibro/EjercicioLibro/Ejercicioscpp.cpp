#include <iostream>
#include <string>
using namespace std;

void numero_mayor_y_menor(int, int, int, int, int);//2.23
void numero_par_impar(int);//2.24
void multiplos(int, int);//2.25
void Kilometros_por_litro(float, float);//4.13
void Comisiones_de_Venta(double);//4.15
void Calculadora_de_salario(int, double);//4.16
void Palindromo_numeros(int);//4.26
void Calculos_del_Circulo(double);//4.30

int main() {
	numero_mayor_y_menor(1, 4, 8, 2, 3);
	cout << endl;
	numero_par_impar(15);
	cout << endl;
	multiplos(15, 3);
	cout << endl;
	Kilometros_por_litro(0, 0);
	cout << endl;
	Comisiones_de_Venta(0);
	cout << endl;
	Calculadora_de_salario(0, 0);
	cout << endl;
	Calculos_del_Circulo(0);
	cout << endl;
	system("pause");
}

void numero_mayor_y_menor(int a, int b, int c, int d, int e) {
	if (a > b&&a > c&&a > e&&a > d) {
		cout << "El numero mayor: " << a << endl;
	}
	else if (b > a&&b > c&&b > e&&b > d) {
		cout << " El numero mayor: " << b << endl;
	}
	else if (c > a&&c > b&&c > e&&c > d) {
		cout << " El numero mayor: " << c << endl;
	}
	else if (d > a&&d > b&&d > c&&d > e) {
		cout << " El numero mayor: " << d << endl;
	}
	else if (e > a&&e > b&&e > c&&e > d) {
		cout << " El numero mayor: " << e << endl;
	}


	if (a < b&&a < c&&a < e&&a < d) {
		cout << "El numero menor: " << a << endl;
	}
	else if (b < a&&b < c&&b < e&&b < d) {
		cout << " El numero menor: " << b << endl;
	}
	else if (c < a&&c < b&&c < e&&c < d) {
		cout << " El numero menor: " << c << endl;
	}
	else if (d < a&&d < b&&d < c&&d < e) {
		cout << " El numero menor: " << d << endl;
	}
	else if (e < a&&e < b&&e < c&&e < d) {
		cout << " El numero menor: " << e << endl;
	}


}

void numero_par_impar(int numero) {
	if (numero % 2 == 0) {
		cout << "El numero es Par"<<endl;
	}
	else {
		cout << "El numero es impar"<<endl;
	}

}

void multiplos(int a, int b) {
	if (a%b==0)
	{
		cout << "Es multiplo" << endl;
	}
	else {
		cout << "No es multiplo" << endl;
	}
}

void Kilometros_por_litro(float km, float litros) {
	int klm = 0;
	int l = 0;
	while(km!=-1){
		cout << "Kilometraje recorrido: ";
		cin >> km;
		if (km==-1){
			break;
		}
		cout << "Litros cosumido: ";
		cin >> litros;

		cout << "KPL es: " << km / litros << endl;
	

	}
}

void Comisiones_de_Venta(double ventas){
	while (ventas != -1) {
		cout << "Ingrese sus ventas: ";
		cin >> ventas;
		if (ventas == -1){
			break;
		}
		cout << "Su salario es: " << 200 + (0.09*ventas) << endl;

	}
}

void Calculadora_de_salario(int horas,double tarifa) {
	while (true) {

		cout << "Escriba las horas trabajadas: ";
		cin >> horas;
		if (horas == -1) {
			break;
		}
		else {

			cout << "Escriba la tarifa por horas trabajadas: ";
			cin >> tarifa;



			if (horas <= 40) {
				cout << "Salario: " << horas*tarifa << endl;
			}
			else {
				cout << "Salario: " << horas*(tarifa*0.5) << endl;
			}

		}
	}

}

void Palindromo_numeros(int b) {
	cout << "Ingrese un numero de 5 digitos(entero): ";
	cin >> b;


}

void Calculos_del_Circulo(double radio) {
	cout << "Escriba el radio del circulo: ";
	cin >> radio;

	cout << "Perimetro: " << radio * 3.1416<<endl;
	cout << "Area: " << (radio*radio)*3.1416<<endl;
}