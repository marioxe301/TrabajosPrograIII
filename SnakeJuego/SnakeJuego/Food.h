#pragma once
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#ifndef FOOD_H
#define FOOD_H

class Food {
	Food();
	~Food();

	void SpawnFood();
	void ColisionFood(float X,float Y);
	void SetXY();

private:
	float X;
	float Y;
	int score=0;

};

#endif // !FOOD_H
