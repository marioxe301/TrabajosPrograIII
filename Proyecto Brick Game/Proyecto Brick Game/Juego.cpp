#include "Juego.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>

int xC=2, yC=15; // mi carro
char carro = 207; // caracter ASCII
char muros = 186; //    ´´	  ASCII
char referencia = 00; // ´´   ASCII


// Variables para timer
clock_t tiempo;
int seg;
int i = 1;

// varibales de juego
bool gameover = true;
int Juego::speed = 120;
int Juego::vidas = 3;
int Juego::puntos = 0;
bool Juego::choque = false;
int Juego::nivel = 0;
int Juego::nivelVelocidad = 1;
int Juego::Puntuaciones[10];

int opcion;
char mapa[16][12]; // Y,X
int xE, yE = 0; // carro enemigo
int pasocarro = 0; //registra si paso el carro
int linea = rand() % 2;
int contTecla = 0;


void Juego::LoadMap() { // carga todo los elementos del mapa
	for (int y = 0; y < 16;y++) {
		for (int x = 0; x < 12;x++) {
			mapa[y][0]= muros;
			mapa[y][10]= muros;
			mapa[y][x] = ' ';

		}
	}

	setCarro(xC,yC);
	setCarroEnemigo();
	
	
}

void Juego::setCarro(int x, int y) {
	// parte central y sus lados
	mapa[y][x] = referencia; 
	mapa[y][x - 1] = carro;
	mapa[y][x + 1] = carro;

	// parte 2 del carro
	mapa[y - 1][x] = carro;
	 
	// parte 3 carro y sus lados
	mapa[y - 2][x] = carro;
	mapa[y - 2][x - 1] = carro;
	mapa[y - 2][x + 1] = carro;

	//ultima parte (Frontal)
	mapa[y - 3][x] = carro;

	
}

void Juego::setCarroEnemigo() {
	// condicion si el carro ya paso
	if (pasocarro == 15) {
		SumarPuntuacion();
		pasocarro = 0;
		yE = 0;

		linea = rand() % 3;

	}
	// condicion si choco se resetea
	else if (choque == true) {
		pasocarro = 0;
		yE = 0;

		linea = rand() % 3;
	}

	// poscicion del carrill

	switch (linea) {
	case 0:
		xE = 2;
		break;
	case 1:
		xE = 5;
		break;
	case 2:
		xE = 8;
		break;
	}
	
	
		// parte trasera 
	
		mapa[yE][xE] = referencia;
		mapa[yE][xE - 1] = carro;
		mapa[yE][xE + 1] = carro;
		
		// parte 2 del carro
		if((yE+1) < 15)
		mapa[yE + 1][xE] = carro;

		// parte 3 carro y sus lados
		if ((yE + 2) < 15) {
			mapa[yE + 2][xE] = carro;
			mapa[yE + 2][xE - 1] = carro;
			mapa[yE + 2][xE + 1] = carro;
		}
		//ultima parte (Frontal)
		if ((yE + 3) < 15)
			mapa[yE + 3][xE] = carro;

		yE++;
		pasocarro++;
	
}


	
	



void Juego::ImprimirMapa() { // imprime el mapa

	for (int y = 0; y < 16;y++) {
		std::cout << std::endl;
		for (int x = 0; x < 11; x++) {
			std::cout << mapa[y][x];
		}

	}
}

void Juego::MoverCarro() { // va tomando los eventos al presionar las teclas
	if (GetAsyncKeyState(VK_LEFT)) {
		xC -= 3;
		if (xC <= 0) {
			xC = 2;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		xC += 3;
		if (xC >= 10) {
			xC = 8;
		}
	}
	else if (GetAsyncKeyState(VK_UP)) {
		// una aceleracion base
		++contTecla;
		if (contTecla > 1) {
			speed = 30;
		}
		
		

	}
	else if (GetAsyncKeyState(VK_BACK)) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" ;
		system("pause");
		
	}
}

void Juego::ClearScreen() // funcion para evitar el parpadeo de la consola
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Juego::HideCursor() // esconde el cursor y evita que este se mueva al momento de que se este refrescando la pantalla
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Juego::VerificarColision() {
	

	if (mapa[yE + 3][xE] == carro || mapa[yE + 2][xE - 1] == carro||
		mapa[yE + 2][xE + 1]==carro|| mapa[yE][xE - 1]== carro|| mapa[yE][xE + 1]==carro) { // hitbox del carro
		choque = true;
		vidas--;
		xC = 2;
		yC = 15;
		yE = 0;
		

		Sleep(200);
	}
	else {
		choque = false;

	}
	if (vidas == 0) {
		
		gameover = false;
	}
	
}
void Juego::Imprimir_datos() { // imprime la informacion en tiemo real de juego
	gotoXY(13, 7); std::cout << "Vidas: " << vidas;
	gotoXY(13, 8); std::cout << "Puntaje: " << puntos;
	gotoXY(13, 10); std::cout << "Nivel: " << nivel;
	gotoXY(13, 11); std::cout << "Speed: " << nivelVelocidad;
	
}

void Juego::gotoXY(int X, int Y) { // posciciona el cursor en consola
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Juego::empezar() { // empieza todos los elementos del juego
	
	while (gameover) {
		
		HideCursor();
		ClearScreen();
		LoadMap();
		ImprimirMapa();
		MoverCarro();
		VerificarColision();
		Imprimir_datos();
		CambiarNivel();
		Sleep(speed);
	
		
	}
	system("cls");
		
}

void Juego::SumarPuntuacion() { // sumr puntuacion con respecto al nivel de la velocidad
	if (nivelVelocidad== 1) {
		speed = 120;
		puntos += 20;
	}
	else if (nivelVelocidad == 2) {
		speed = 110;
		puntos += 40;
	}
	else if (nivelVelocidad == 3) {
		speed = 100;
		puntos += 60;
	}
	else if (nivelVelocidad == 4) {
		speed = 90;
		puntos += 80;
	}
	else if (nivelVelocidad == 5) {
		speed = 80;
		puntos += 100;
	}
	else if (nivelVelocidad == 6) {
		speed = 70;
		puntos += 130;
	}
	else if (nivelVelocidad == 7) {
		speed = 70;
		puntos += 170;
	}
	else if (nivelVelocidad == 8) {
		speed = 60;
		puntos += 190;
	}
	else if (nivelVelocidad == 9) {
		speed = 50;
		puntos += 220;
	}
	else if (nivelVelocidad == 10) {
		speed = 40;
		puntos += 280;
	}

	if (nivelVelocidad > 10) {
		speed = 40;
		nivelVelocidad = 10;
		puntos += 280;
	}
}

void Juego::CambiarNivel() {
	
	tiempo = clock() - tiempo; // va obteniendo el tiempo transcurrido
	seg = tiempo / (int)CLOCKS_PER_SEC; // tiempo en seg
	if (seg/10 ==1*i ) {
		++nivel;
		++i;
		
	}
		if (nivel > 10) {
		
		nivel = 0 ;
		system("cls");
		++nivelVelocidad; // aumentos respectivos
		Imprimir_datos();

	}
	
	
}
void Juego::InfoMenu() {
	gotoXY(50, 10); std::cout << "Brick Game Racing "; 
	gotoXY(50, 15); std::cout << "1.JUGAR";
	gotoXY(50, 16); std::cout << "2.ESTADISTICAS ";
	gotoXY(50, 17); std::cout << "3.SALIR";
	gotoXY(50, 18); std::cin >> opcion;
	
}

void Juego::menu() {
	
	do {
		
		
		InfoMenu();
		system("cls");
		switch (opcion) {
		case 1:
			
			empezar();
			CargarEstadisticas(); // cargar antes de reiniciar variables


			//Reinicio de variables
			Juego::speed = 120;
			Juego::vidas = 3;
			Juego::puntos = 0;
			Juego::choque = false;
			Juego::nivel = 0;
			Juego::nivelVelocidad = 1;
			gameover = true;
			yE = 0; 
			pasocarro = 0; 
			linea = rand() % 2;

			// limpiar sistema
			system("cls");
			break;

		case 2:
			MostrarEstadisticas();
			_getch();
			break;
		case 3:
			exit(1);
			break;
		default:
			break;
		}
		system("cls");
	} while (opcion!=3);
}

void Juego::CargarEstadisticas() {
	for (int i = 0; i < 10; i++) {
		if (Puntuaciones[i] == 0) {
			Puntuaciones[i] = puntos;
			break;
		}


	}
}

void Juego::MostrarEstadisticas() {
	for (int i = 0; i < 10; i++) {
		if (Puntuaciones[i] != 0) {
			gotoXY(35, 3 + (i + 1)); std::cout << "Partida: " << i + 1 << "\t\t\t" << "Puntaje:" << Puntuaciones[i] << std::endl;
		}

	}
	gotoXY(40, 2); std::cout << "Datos de las ultimas 10 partidas ";
}


