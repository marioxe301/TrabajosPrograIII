#pragma once
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#ifndef FOOD_H
#define FOOD_H

class Food {
public:
	Food();
	~Food();

	void SpawnFood(float, float, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *);
	void SpawnFood(bool, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *);
	bool ColisionFood(float X,float Y);
	void SetXY();

	static int score;
private:
	float X;
	float Y;

};

#endif // !FOOD_H
