#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "field.h"

class menu {
public:
	menu_screens screen = MAIN;
	int p1_selector = 0;
	int p2_selector = 0;
	int p1_menu_max = 3;
	int p2_menu_max = 0;
	bool is_active = true;

	void handle(int);
	void open();
	void reset();

	void draw(SDL_Renderer*);
	menu(field*, bool*);

	field* field_pointer;
	bool* running_pointer;
	
private:
	const SDL_Color white = { 255, 255, 255 };
	const SDL_Color blue = { 0, 0, 255 };
	const SDL_Color red = { 255, 0, 0 };

	TTF_Font* Sans;
};

#endif
