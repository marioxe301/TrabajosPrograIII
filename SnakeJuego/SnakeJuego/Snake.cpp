#include "Snake.h";
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <vector>

Snake::Snake() :PosX(300), PosY(200), running(true), size(1)
{

}

Snake::~Snake()
{}


ALLEGRO_BITMAP * Cuerpo[100];
int rotarCabeza = 0;
int rotarVert = 0;

//ALLEGRO_KEYBOARD_STATE *Keystate;
bool arriba, abajo, izquierda, derecha;


void Snake::DibujarSnake(ALLEGRO_BITMAP *snake){
	al_draw_rotated_bitmap(snake, 57/2, 57/2, this->PosX, this->PosY, rotarVert, rotarCabeza); // eje de rotacion
	al_flip_display();
}

void Snake::MoverSnake(ALLEGRO_KEYBOARD_STATE *Keystate){
	
	al_get_keyboard_state(Keystate);
	if (al_key_down(Keystate, ALLEGRO_KEY_RIGHT)) {
		abajo = false;
		arriba = false;
		izquierda = false;
		derecha = true;
		rotarCabeza = 0;
		rotarVert = 0;
	}
	//x += 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_LEFT))
	{
		abajo = false;
		arriba = false;
		izquierda = true;
		derecha = false;
		rotarCabeza = 1;
		rotarVert = 0;
	}
	//x -= 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_UP))
	{
		abajo = false;
		arriba = true;
		izquierda = false;
		derecha = false;
		rotarCabeza = 0;
		rotarVert = 5 * ALLEGRO_PI / 3;
	}
	//y -= 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_DOWN))
	{
		abajo = true;
		arriba = false;
		izquierda = false;
		derecha = false;
		rotarCabeza = 0;
		rotarVert = 2 * ALLEGRO_PI / 3;
	}
	if (al_key_down(Keystate, ALLEGRO_KEY_ESCAPE)) {
		this->running = false;
	}

	if (arriba == true) {
		this->PosY -= this->Velocidad;

		if (this->PosY <= -57) {
			this->PosY = 600;
		}
	}
	else if (abajo == true) {
		this->PosY += this->Velocidad;

		if (this->PosY >= 600) {
			this->PosY = 0;
		}
	}
	else if (izquierda == true) {
		this->PosX -= this->Velocidad;

		if (this->PosX <= -57) {
			this->PosX = 800;
		}
	}
	else if (derecha == true) {
		this->PosX += this->Velocidad;

		if (this->PosX >= 800) {
			this->PosX = 0;
		}
	}
}

bool Snake::getEstado() {
	return this->running;
}

float Snake::getX()
{
	return this->PosX;
}

float Snake::getY()
{
	return this->PosY;
}

void Snake::DibujarCuerpo(Food *food, bool m,Snake *snake, ALLEGRO_BITMAP *cuerpo[]) {
	if (m == true) {
		if (cuerpo[0] == 0) {
			for (int i = 0; i < 100; i++) {
				cuerpo[i] = al_load_bitmap("cuerpo.png");
				

			}
			al_draw_bitmap(cuerpo[0], 50, 50, 0);
			snake->size++;
		}
		else {
		for (int i = 0; i < snake->size; i++) {
		cuerpo[i] = al_load_bitmap("cuerpo.png");
		al_draw_bitmap(cuerpo[i], snake->PosX, snake->PosY, 0);
		}
		snake->size++;
		}
	}
}
	

