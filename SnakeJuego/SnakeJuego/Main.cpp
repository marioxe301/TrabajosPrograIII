#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_native_dialog.h>
#include <Windows.h>
#define LARGO = 600
#define ANCHO = 800

int main()
{
	
	bool arriba = false;
	bool abajo = false;
	bool izquierda = false;
	bool derecha = false;
	// variales de movimiento

	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_BITMAP * bitmap = NULL;
	static ALLEGRO_BITMAP * food = NULL;

	//Allegro Variables

	
	static int score = 0;


	//Creaci�n de la ventana y de la lista de eventos
	al_init();
	display = al_create_display(800, 600);
	queue = al_create_event_queue();

	al_install_keyboard();
	//al_install_mouse();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));

	//al_register_event_source(queue, al_get_mouse_event_source());

	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_ttf_font("YARDSALE.ttf", 64, 0);

	//Cargar imagen
	bitmap = al_load_bitmap("snake.png");
	food = al_load_bitmap("food.png");
	assert(bitmap != NULL);
	assert(food != NULL);

	//X y Y indican la posici�n de la im�gen
	bool running = true;
	static float x = 300, y = 200;
	static int i=0, j=0;
	static int cola = 1;
	
	class foodImg
	{
	public:
		foodImg() {}

		void spawnFood()
		{
			al_draw_bitmap(food, this->X, this->Y, 0);
		}

		void collision()

		{//57x57 pixeles tama�o del snake y food
			if ((x > this->X + 57) ||
				(x < this->X - 57) ||
				(y > this->Y + 57) ||
				(y < this->Y - 57))
				return;
			else
			{
				++score;
				cola++;
				
				//foodOnScreen--;
				this->X = 850;
			}
		}

		void setXY()
		{
			if (this->X > 0 && this->X < 810)
				return;
			//foodOnScreen++;
			srand((int)time(0));
			int randX = (rand() % 6) + 1;
			int randY = (rand() % 4) + 1;
			this->X = (randX * 100);
			this->Y = (randY * 100);
		}

	private:
		float X;
		float Y;
	};

	
	foodImg *fd1 = new foodImg();
	
	while (running) {
		std::string s = std::to_string(score);
		char const *score2 = s.c_str();
		al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
		al_draw_text(font, al_map_rgb(100, 255, 200), 400, 0, 0, score2);
		al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x+i*cola, y+j*cola, 0);
		
		fd1->setXY();
		fd1->spawnFood();
		fd1->collision();
		al_flip_display();

		
		ALLEGRO_EVENT event;

		if (!al_is_event_queue_empty(queue)) {
			al_wait_for_event(queue, &event);
			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				running = false;
		}

		// Evaluaci�n activa del teclado
		ALLEGRO_KEYBOARD_STATE keyState;

		//Movimiento de la im�gen en las cuatro direcciones
		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
			abajo = false;
			arriba = false;
			izquierda = false;
			derecha = true;
			i = -37;
			j = 0;
			
		}
		//x += 0.1;
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		{
			abajo = false;
			arriba = false;
			izquierda = true;
			derecha = false;
			i = 37;
			j = 0;
			
		}
		//x -= 0.1;
		if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		{
			abajo = false;
			arriba = true;
			izquierda = false;
			derecha = false;
			i = 0;
			j = 37;
		}
		//y -= 0.1;
		if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		{
			abajo = true;
			arriba = false;
			izquierda = false;
			derecha = false;
			i = 0;
			j = -37;
		}
		//y += 0.1;
		if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) {
			running = false;
		}

		if (arriba == true) {
			y -= 0.1;
			
			if (y <= 0) {
				y = 600;
			}
		}
		else if (abajo == true) {
			y += 0.1;
			
			if (y >= 600) {
				y = 0;
			}
		}
		else if (izquierda == true) {
			x -= 0.1;
			
			if (x<=0) {
				x = 800;
			}
		}
		else if (derecha == true) {
			x += 0.1;
			
			if (x >= 800) {
				x=0;
			}
		}
	}

	//Destrucci�n del programa despu�s de que se cierre manualmente
	al_destroy_display(display);
	al_uninstall_keyboard();
	//al_uninstall_mouse();
	al_destroy_bitmap(bitmap);

	system("pause");

	return 0;
}
