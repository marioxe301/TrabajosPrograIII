#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_native_dialog.h>
#include <string>
#include "Snake.h"
#include "Food.h"

int Food::score = 0;
void dibujarCuerpo(/*Food*, Snake*, ALLEGRO_BITMAP *, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*,*/ ALLEGRO_BITMAP*[]);


int main() {

	ALLEGRO_DISPLAY  * display;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_BITMAP *Background;
	ALLEGRO_BITMAP *SnakeImg;
	ALLEGRO_BITMAP *cuerpo[100];
	ALLEGRO_BITMAP *Comida;
	ALLEGRO_BITMAP *Comida2;
	ALLEGRO_BITMAP *Comida3;
	
	Snake *snake = new Snake();
	Food *food = new Food;
	bool collision = false;
	

	al_init();
	display = al_create_display(800, 600);
	
	al_install_keyboard();

	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	SnakeImg = al_load_bitmap("snake2.png");
	Background = al_load_bitmap("fondo.jpg");
	ALLEGRO_FONT *font = al_load_ttf_font("YARDSALE.ttf", 64, 0);

	Comida = al_load_bitmap("f1.png");
	Comida2 = al_load_bitmap("f2.png");
	Comida3 = al_load_bitmap("f3.png");

	for (int i = 0; i < 100;i++) {
		cuerpo[i] = al_load_bitmap("cuerpo.png");
	}
	assert(font);
	assert(Comida);
	assert(Comida2);
	assert(Comida3);

	assert(SnakeImg);
	assert(Background);

	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	while (true)
	{
		food->SetXY();
		
		al_draw_bitmap(Background, 0, 0, 0);

		while (snake->getEstado())
		{
			std::string s = std::to_string(Food::score);
			char const *score2 = s.c_str();
			al_draw_bitmap(Background, 0, 0, 0);

			collision = food->ColisionFood(snake->getX(), snake->getY());
			//food->SpawnFood(snake->getX(), snake->getY(), Comida,Comida2,Comida3);
			food->SpawnFood(collision, Comida, Comida2, Comida3);

			al_draw_text(font, al_map_rgb(100, 225, 200), 350, 0, 0, score2);
			ALLEGRO_EVENT event;
			if (!al_is_event_queue_empty(queue)) {
				al_wait_for_event(queue, &event);
			}
			snake->DibujarSnake(SnakeImg);
			snake->DibujarCuerpo(food,collision, snake,cuerpo);
			snake->MoverSnake(&keyState);

			if (collision == true)
				collision = false;

			al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
		}
		break;
	}


}

//void dibujarCuerpo(Food *f,Snake *s,ALLEGRO_BITMAP *c1,ALLEGRO_BITMAP*c2,ALLEGRO_BITMAP*c3,*/ALLEGRO_BITMAP*cuerpo[]) {
//	/*if(f->ColisionFood(&s->getX,&s->getY,c1)==true || f->ColisionFood(&s->getX, &s->getY, c2) == true || f->ColisionFood(&s->getX, &s->getY, c3) == true){*/
//		
//	al_draw_bitmap(cuerpo[0], 50, 50, NULL);
//		
//}
//
//
