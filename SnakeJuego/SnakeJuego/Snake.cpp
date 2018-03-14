#include "Snake.h";

Snake::Snake() :PosX(300), PosY(200), running(true)
{}

Snake::~Snake()
{}

ALLEGRO_BITMAP *Cabeza = al_load_bitmap("snake2.png");
int rotarCabeza=0;

ALLEGRO_KEYBOARD_STATE *Keystate;
bool arriba, abajo, izquierda, derecha;

void Snake::DibujarSnake(){
	al_draw_bitmap(Cabeza, this->PosX, this->PosY, rotarCabeza);
	al_flip_display();
}

void Snake::MoverSnake(){
	
	al_get_keyboard_state(Keystate);
	if (al_key_down(Keystate, ALLEGRO_KEY_RIGHT)) {
		abajo = false;
		arriba = false;
		izquierda = false;
		derecha = true;
		
	}
	//x += 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_LEFT))
	{
		abajo = false;
		arriba = false;
		izquierda = true;
		derecha = false;
		

	}
	//x -= 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_UP))
	{
		abajo = false;
		arriba = true;
		izquierda = false;
		derecha = false;
		
	}
	//y -= 0.1;
	if (al_key_down(Keystate, ALLEGRO_KEY_DOWN))
	{
		abajo = true;
		arriba = false;
		izquierda = false;
		derecha = false;
		
	}
	if (al_key_down(Keystate, ALLEGRO_KEY_ESCAPE)) {
		this->running = false;
	}

	if (arriba == true) {
		this->PosY-= Velocidad;

		if (this->PosY <= 0) {
			this->PosY = 600;
		}
	}
	else if (abajo == true) {
		this->PosY += Velocidad;

		if (this->PosY >= 600) {
			this->PosY = 0;
		}
	}
	else if (izquierda == true) {
		this->PosX -= Velocidad;

		if (this->PosX <= 0) {
			this->PosX = 800;
		}
	}
	else if (derecha == true) {
		this->PosX +=Velocidad;

		if (this->PosX >= 800) {
			this->PosX = 0;
		}
	}
}

bool Snake::getEstado() {
	return this->running;
}