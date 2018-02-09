#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main(int argc, char **argv) {

	if (!al_init()) {
		fprintf(stderr, "Failed to initialize Allegro.\n");
		return -1;
	}

	

	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	al_set_window_title(display, "Hola Mundo");

	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return -1;
	}
	al_init_font_addon(); 
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_ttf_font("Times.ttf", 76, NULL);

	if (!font) {
		fprintf(stderr, "Could not load 'Times.ttf'.\n");
		return -1;
	}

	al_clear_to_color(al_map_rgb(50, 10, 70));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Hola Mundo!!!");

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);

	return 0;
}