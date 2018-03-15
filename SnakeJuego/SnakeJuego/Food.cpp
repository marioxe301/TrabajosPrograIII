#include "Food.h"
#include <time.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\bitmap.h>
#include <allegro5\allegro_image.h>


Food::Food(): X(1),Y(1),score(0)
{
	
}

Food::~Food()
{}

ALLEGRO_BITMAP *Comida = al_load_bitmap("f1.png");
ALLEGRO_BITMAP *Comida2 = al_load_bitmap("f1.png");
ALLEGRO_BITMAP *Comida3 = al_load_bitmap("f1.png");

void Food::SpawnFood() {
	int opcion_comida = rand() % 3;
	SetXY();
	switch (opcion_comida) {
	case 0:
		al_draw_bitmap(Comida, this->X, this->Y, 0);
		al_flip_display();
		break;
	case 1:
		al_draw_bitmap(Comida2, this->X, this->Y, 0);
		al_flip_display();
		break;

	case 2:
		al_draw_bitmap(Comida3, this->X, this->Y, 0);
		al_flip_display();
		break;

	}
	
	
}

void Food::SetXY() {
	int randX = (rand() % 6) + 1;
	int randY = (rand() % 4) + 1;
	this->X = (randX * 100);
	this->Y = (randY * 100);
}

void Food::ColisionFood(float X,float Y) {
	if ((X > this->X + 57) ||
		(X < this->X - 57) ||
		(Y > this->Y + 57) ||
		(Y < this->Y - 57))
		return;
	else
	{
		this->score = score + 1;
		SpawnFood();
	}
}