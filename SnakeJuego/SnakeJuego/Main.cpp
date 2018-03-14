#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_native_dialog.h>
#include "Snake.h"
#include "Food.h"
int main() {

	ALLEGRO_DISPLAY  * display;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_BITMAP *Background= al_load_bitmap("fong.jpeg");
	ALLEGRO_FONT *font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
	Snake *snake = new Snake();
	//Food *cmida = new Food();

	al_init();
	display = al_create_display(800, 600);
	
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_init_image_addon();

	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());


	while (snake->getEstado())
	{
		al_draw_bitmap(Background, 0, 0, 0);
		snake->DibujarSnake();
		snake->MoverSnake();

	}

}