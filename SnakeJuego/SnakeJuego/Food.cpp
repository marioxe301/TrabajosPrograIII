#include "Food.h"
#include "Snake.h"
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#include <allegro5\allegro_image.h>

int opcion = rand() % 3;

Food::Food(): X(1),Y(1)
{
	srand((int)time(0));
	
}

Food::~Food()
{}



void Food::SpawnFood(float X, float Y, ALLEGRO_BITMAP *Comida, ALLEGRO_BITMAP *Comida2, ALLEGRO_BITMAP *Comida3) {
	
	if (ColisionFood(X, Y) ==true) {
		SetXY();
	}
	if (opcion == 0) {
		al_draw_bitmap(Comida, this->X, this->Y, 0);
	}
	else if (opcion == 1) {
		al_draw_bitmap(Comida2, this->X, this->Y, 0);
	}
	else {
		al_draw_bitmap(Comida3, this->X, this->Y, 0);
	}
	
}

void Food::SpawnFood(bool colisiono, ALLEGRO_BITMAP *Comida, ALLEGRO_BITMAP *Comida2, ALLEGRO_BITMAP *Comida3) {

	if (colisiono == true) {
		SetXY();
	}
	if (opcion == 0) {
		al_draw_bitmap(Comida, this->X, this->Y, 0);
	}
	else if (opcion == 1) {
		al_draw_bitmap(Comida2, this->X, this->Y, 0);
	}
	else {
		al_draw_bitmap(Comida3, this->X, this->Y, 0);
	}

}

void Food::SetXY() {
	opcion = rand() % 3;
	int randX = (rand() % 6) + 1;
	int randY = (rand() % 4) + 1;
	this->X = (randX * 100);
	this->Y = (randY * 100);
}

bool Food::ColisionFood(float X, float Y) {
	if ((X >= this->X + 57) || (X <= this->X - 57) || (Y >= this->Y + 57) || (Y <= this->Y - 57))
	{
		return false;
	}
	
	score = score + 1;
	
	return true;
}