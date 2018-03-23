#pragma once
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#include "Food.h"
#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
	Snake();
	~Snake();

	void DibujarSnake(ALLEGRO_BITMAP *);
	void DibujarCuerpo(Food*,float,float, Snake *,ALLEGRO_BITMAP*[]);
	void DibujarCuerpo(Food*,bool, Snake *, ALLEGRO_BITMAP*[]);
	void MoverSnake(ALLEGRO_KEYBOARD_STATE *);
	bool getEstado();
	float getX();
	float getY();

	int size;
	

	ALLEGRO_BITMAP * Cuerpo[100];

private:
	float PosX;
	float PosY;
	float Velocidad = 0.15;
	bool running;
	//posciciones anteriores

	
	

};

#endif // !SNAKE_H
