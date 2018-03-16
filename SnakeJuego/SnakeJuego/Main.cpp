#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_native_dialog.h>
#include <string>
#include "Snake.h"
#include "Food.h"

int Food::score = 0;
int main() {

	ALLEGRO_DISPLAY  * display;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_BITMAP *Background;
	ALLEGRO_BITMAP *SnakeImg;

	ALLEGRO_BITMAP *Comida;
	ALLEGRO_BITMAP *Comida2;
	ALLEGRO_BITMAP *Comida3;

	Snake *snake = new Snake();
	Food *food = new Food;
	

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
			food->SpawnFood(snake->getX(), snake->getY(), Comida,Comida2,Comida3);
			
			al_draw_text(font, al_map_rgb(100, 225, 200), 350, 0, 0, score2);
			ALLEGRO_EVENT event;
			if (!al_is_event_queue_empty(queue)) {
				al_wait_for_event(queue, &event);
			}
			snake->DibujarSnake(SnakeImg);
			
			snake->MoverSnake(&keyState);

			al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
		}
		break;
	}


}

