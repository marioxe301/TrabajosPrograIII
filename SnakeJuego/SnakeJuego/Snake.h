#pragma once
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
	Snake();
	~Snake();

	void DibujarSnake();
	void DibujarCuerpo();
	void MoverSnake();
	bool getEstado();

private:
	float PosX;
	float PosY;
	float Velocidad=57;
	bool running;
	ALLEGRO_BITMAP * cuerpo[30];
	int	PosAntX;
	int PosAntY;

};

#endif // !SNAKE_H
