#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "field.h"

enum menu_screens {
	MAIN,
	CHARACTER_SELECT,
	STAGE_SELECT,
	HIGH_SCORES
};

enum characters {
	HERNANDEZ,
	BUSCEMI
};

class menu {
public:
	menu_screens screen = MAIN;
	int p1_selector = 0;
	int p2_selector = 0;
	int p1_menu_max = 2;
	int p2_menu_max = 0;
	bool is_active = true;

	characters p1_character = HERNANDEZ;
	characters p2_character = HERNANDEZ;

	void handle(int);
	void open();
	void reset();
	void start(field*);

	void draw(SDL_Renderer*);
	menu();
	
private:
	const SDL_Color white = { 255, 255, 255 };
	const SDL_Color blue = { 0, 0, 255 };
	const SDL_Color red = { 255, 0, 0 };

	TTF_Font* Sans;
};

#endif
