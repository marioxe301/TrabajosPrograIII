#pragma once
#include <allegro5\bitmap.h>
#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
	Snake();
	~Snake();

	void DibujarSnake(ALLEGRO_BITMAP);
	void DibujarCuerpo(ALLEGRO_BITMAP);
	void MoverSnake();

private:
	float PosX;
	float PosY;
	float Velocidad;
	bool running = true;

};

#endif // !SNAKE_H
