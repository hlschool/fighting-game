#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>

class menu {
public:
	int menu_selector = 0;
	int menu_select = 0;
	int menu_max;

	void draw(SDL_Renderer*);
	menu();
	
private:
	const SDL_Color white = { 255, 255, 255 };
	const SDL_Color blue = { 0, 0, 255 };

	TTF_Font* Sans;
};

#endif
