#pragma once
#ifndef JUEGO_H
#define JUEGO_H

class Juego {
public:

	void menu();
	void empezar();
	void LoadMap();
	void setCarro(int, int);
	void setCarroEnemigo();

	void InfoMenu();
	void SumarPuntuacion();
	void CambiarNivel();
	void VerificarColision();
	void ImprimirMapa();
	void MoverCarro();
	void MoverCarroEnemigo(); 
	void Imprimir_datos();
	void Cambiar_Velocidad();
	
	void MostrarEstadisticas();
	void CargarEstadisticas();

	void ClearScreen(); // evitar parpadeo de la consola
	void HideCursor(); // ocultar el cursor
	void gotoXY(int, int); // poscicionar en consola ciertos elementos

	// variables 
	static int speed;
	static int puntos;
	static int vidas;
	static bool choque;
	static int nivel;
	static int nivelVelocidad;

	//arreglo puntajes
	static int Puntuaciones[];
};

#endif // !JUEGO_H
