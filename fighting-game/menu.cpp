#include "menu.h"
#include "constants.h"
#include <SDL.h>
#include "rendering.h"

menu::menu() {
	Sans = TTF_OpenFont("OpenSans-Bold.ttf", 40);
}

void menu::draw(SDL_Renderer* renderer) {
	renderText(renderer, Sans, "Menu", { (float) (constants::screen_width / 2), 100 }, white);
	switch(menu_select) {
	case 0:
		menu_max = 2;
		renderText(renderer, Sans, "Character Select", { (float) (constants::screen_width / 2), 225 }, ((menu_selector == 0) ? blue : white));
		renderText(renderer, Sans, "Stage Select", { (float) (constants::screen_width / 2), 300 }, ((menu_selector == 1) ? blue : white));
		renderText(renderer, Sans, "High Scores", { (float) (constants::screen_width / 2), 375 }, ((menu_selector == 2) ? blue : white));
		break;
	case 1:
		menu_max = 2;
		renderText(renderer, Sans, "Sonic", { (float) (constants::screen_width / 2), 225 }, ((menu_selector == 0) ? blue : white));
		renderText(renderer, Sans, "Mister", { (float) (constants::screen_width / 2), 300 }, ((menu_selector == 1) ? blue : white));
		renderText(renderer, Sans, "Buscemi", { (float) (constants::screen_width / 2), 375 }, ((menu_selector == 2) ? blue : white));
		break;
	case 2:
		menu_max = 1;
		renderText(renderer, Sans, "1", { (float) (constants::screen_width / 2), 225 }, ((menu_selector == 0) ? blue : white));
		renderText(renderer, Sans, "2", { (float) (constants::screen_width / 2), 300 }, ((menu_selector == 1) ? blue : white));
		break;
	case 3:
		
		break;
	}
}