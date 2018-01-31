
#include<iostream>

using namespace std;

class nota {
private:
	double valor;
	static double notaMinima;
public:
	nota() {
		valor = 0;
	}

	nota(double v) {
		valor = v;
	}

	void setValor(double v) {
		if (v >= 0 && v <= 100) {
			valor = v;
		}
		else {
			cout << "Error de Ingreso de nota..." << endl;
		}
	}
	double getValor(){
		return valor;
	}

	bool isAprobado() {
		if (valor>=notaMinima)
		{
			return true;
		}
		else {
			return false;
		}


	}

	static void setNotaMinima(double min) {
		notaMinima = min;
	}
};
double nota::notaMinima = 60;
int main() {
	nota n1, n2(59);
	n1.setValor(80);
	cout << "N1: " << n1.getValor() << (n1.isAprobado() ? " Aprobado" : " Reprobado")<<endl;
	cout << "N2: " << n2.getValor() << (n2.isAprobado() ? " Aprobado" : " Reprobado") << endl<<endl;

	nota::setNotaMinima(50);
	cout << "N1: " << n1.getValor() << (n1.isAprobado() ? " Aprobado" : " Reprobado") << endl;
	cout << "N2: " << n2.getValor() << (n2.isAprobado() ? " Aprobado" : " Reprobado") << endl;
	system("pause");
}