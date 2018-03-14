#pragma once
#include <allegro5\bitmap.h>
#ifndef FOOD_H
#define FOOD_H

class Food {
	Food();
	~Food();

	void SpawnFood(ALLEGRO_BITMAP);
	void ColisionFood();

private:
	float X;
	float Y;
	

};

#endif // !FOOD_H
