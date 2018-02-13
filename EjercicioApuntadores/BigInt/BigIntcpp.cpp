#include "BigInt.h"


BigInt::BigInt() {
	for (int i = 0; i < TAM_ARREGLO; i++) {
		a[i] = '0';
		entero[i] = 0;
	}
}

std::istream & operator>>(std::istream &in, BigInt &b) {
	in >> b.a;
	int final_Arreglo = TAM_ARREGLO - 1;
	for (int i = strlen(b.a) - 1; i >= 0;i--) {
		switch (b.a[i]) {
		case '0':
			b.entero[final_Arreglo] = 0;
			break;
		case '1':
			b.entero[final_Arreglo] = 1;
			break;
		case '2':
			b.entero[final_Arreglo] = 2;
			break;
		case '3':
			b.entero[final_Arreglo] = 3;
			break;
		case '4':
			b.entero[final_Arreglo] = 4;
			break;
		case '5':
			b.entero[final_Arreglo] = 5;
			break;
		case '6':
			b.entero[final_Arreglo] = 6;
			break;
		case '7':
			b.entero[final_Arreglo] = 7;
			break;
		case '8':
			b.entero[final_Arreglo] = 8;
			break;
		case '9':
			b.entero[final_Arreglo] = 9;
			break;
		
		}
		final_Arreglo--;
	}
	return in;
}

std::ostream & operator<<(std::ostream &out, const BigInt &b) {
	for (int i = 0; i < strlen(b.a); i++) {
		out << b.entero[TAM_ARREGLO - strlen(b.a) + i];

	}
	return out;
}

BigInt operator+(const BigInt&b, const BigInt&c) {
	BigInt Temporal;

	for (int i = TAM_ARREGLO - 1; i >= 0;i--) {
		int suma = 0;
		suma = b.entero[i] + c.entero[i];
		if (suma > 9) {
			Temporal.entero[i] = suma - 10;
			Temporal.entero[i - 1] = Temporal.entero[i - 1] + 1;

		}
		else {
			Temporal.entero[i] =Temporal.entero[i] +  suma;
		}
	}// Fin For
	return Temporal;

}

BigInt operator-(const BigInt&b, const BigInt&c) {
	BigInt Temporal;
	for (int i = TAM_ARREGLO - 1; i >= 0; i--) {
		int resta = 0;
		resta = b.entero[i] - c.entero[i];
		if (resta<0)
		{
			
			Temporal.entero[i] = (b.entero[i] + 10) - c.entero[i];
			if (Temporal.entero[i-1]-1 < 0)
			{
				Temporal.entero[i-1] = (b.entero[i] + 10) - c.entero[i];
			}


		}
		else {
			Temporal.entero[i] = Temporal.entero[i] + resta;
		}
		
	}// Fin For
	return Temporal;


	
}

bool BigInt::operator==(const BigInt&b) {
	if (strlen(this->a) == strlen(b.a)) {
		for (int i = TAM_ARREGLO - 1; i >= 0; i--) {
			if (this->entero[i] == b.entero[i]) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}
bool BigInt::operator<=(const BigInt&b) {
	
	if (strlen(this->a) == strlen(b.a)) {
		for (int i = strlen(b.a)-1; i >TAM_ARREGLO; i++) {
			if (this->entero[i] <= b.entero[i]) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if(strlen(this->a) < strlen(b.a)) {
		return true;
	}
	else {
		return false;
	}
}
bool BigInt::operator<(const BigInt&b) {
	
	if (strlen(this->a) == strlen(b.a)) {
		for (int i = strlen(b.a)-1; i >TAM_ARREGLO; i++) {
			if (this->entero[i] < b.entero[i] ) {
				return true;
				
			}
			else
			{
				return false;
			}
		}
	}
	else if(strlen(this->a) < strlen(b.a)) {
		return true;
	}
	else {
		return false;
	}
}

bool BigInt::operator>(const BigInt&b) {
	if (strlen(this->a) == strlen(b.a)) {
		for (int i = strlen(b.a) - 1; i >TAM_ARREGLO; i++) {
			if (this->entero[i] > b.entero[i]) {
				return true;

			}
			else
			{
				return false;
			}
		}
	}
	else if (strlen(this->a) > strlen(b.a)) {
		return true;
	}
	else {
		return false;
	}
}

bool BigInt::operator>=(const BigInt&b) {
	if (strlen(this->a) == strlen(b.a)) {
		for (int i = strlen(b.a) - 1; i >TAM_ARREGLO; i++) {
			if (this->entero[i] >= b.entero[i]) {
				return true;

			}
			else
			{
				return false;
			}
		}
	}
	else if (strlen(this->a) > strlen(b.a)) {
		return true;
	}
	else {
		return false;
	}
}

