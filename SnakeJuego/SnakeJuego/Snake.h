#pragma once
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#include <vector>

#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
	Snake();
	~Snake();

	void DibujarSnake(ALLEGRO_BITMAP *);
	// void DibujarCuerpo(const std::vector<ALLEGRO_BITMAP*>& cuerpo);
	void MoverSnake(ALLEGRO_KEYBOARD_STATE *);
	bool getEstado();
	float getX();
	float getY();

private:
	float PosX;
	float PosY;
	float Velocidad = 0.15;
	bool running;
	//posciciones anteriores

	int	PosAntX;
	int PosAntY;

};

#endif // !SNAKE_H
