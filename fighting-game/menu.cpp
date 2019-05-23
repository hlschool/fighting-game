#include "menu.h"
#include "constants.h"
#include "field.h"
#include <SDL.h>
#include "rendering.h"

menu::menu(field *f, bool* r) {
	running_pointer = r;
	field_pointer = f;
	Sans = TTF_OpenFont("OpenSans-Bold.ttf", 40);
}

void menu::draw(SDL_Renderer* renderer) {
	if (is_active) {
		renderText(renderer, Sans, "Menu", { (float)(constants::screen_width / 2), 100 }, white);
		switch (screen) {
		case MAIN:
			renderText(renderer, Sans, "Character Select", { (float)(constants::screen_width / 2), 225 }, ((p1_selector == 0) ? blue : white));
			renderText(renderer, Sans, "Stage Select", { (float)(constants::screen_width / 2), 300 }, ((p1_selector == 1) ? blue : white));
			renderText(renderer, Sans, "High Scores", { (float)(constants::screen_width / 2), 375 }, ((p1_selector == 2) ? blue : white));
			renderText(renderer, Sans, "Exit", { (float)(constants::screen_width / 2), 450 }, ((p1_selector == 3) ? blue : white));
			break;
		case CHARACTER_SELECT:
			renderText(renderer, Sans, ">", { (float)(constants::screen_width / 2 - 300), 417 }, ((p1_selector == 0) ? blue : white));
			renderText(renderer, Sans, "Start", { (float)(constants::screen_width * 0.5), 492 }, ((p1_selector == 1) ? blue : white));
			renderText(renderer, Sans, ">", { (float)(constants::screen_width / 2 + 300), 417 }, ((p2_selector == 0) ? red : white));
			break;
		case STAGE_SELECT:
			renderText(renderer, Sans, "1", { (float)(constants::screen_width / 2), 225 }, ((p1_selector == 0) ? blue : white));
			renderText(renderer, Sans, "2", { (float)(constants::screen_width / 2), 300 }, ((p1_selector == 1) ? blue : white));
			break;
		case 3:

			break;
		}
	}
}

void menu::handle(int key) {
	if (key == SDLK_w && p1_selector != 0) {
		p1_selector--;
	} else if (key == SDLK_s && p1_selector < p1_menu_max) {
		p1_selector++;
	} else if (key == SDLK_UP && p2_selector != 0) {
		p2_selector--;
	} else if (key == SDLK_DOWN && p2_selector < p2_menu_max) {
		p2_selector++;
	} else if (key == SDLK_g) {
		switch (screen) {
		case MAIN:
			switch (p1_selector) {
			case 0: //to CHARACTER_SELECT screen
				p1_menu_max = 1;
				screen = CHARACTER_SELECT;
				field_pointer->getPlayer1()->HP = 100;
				field_pointer->getPlayer2()->HP = 100;
				field_pointer->getPlayer1()->moveTo({ (float)((constants::screen_width / 2 - 300) - (getImageWidth(field_pointer->getPlayer1()->type) / 2)), 255 });
				field_pointer->getPlayer2()->moveTo({ (float)((constants::screen_width / 2 + 300) - (getImageWidth(field_pointer->getPlayer2()->type) / 2)), 255 });
				break;
			case 1: //to STAGE_SELECT screen
				p1_menu_max = 1;
				screen = STAGE_SELECT;
				break;
			case 2: //to HIGH_SCORES screen
				//screen = HIGH_SCORES;
				break;
			case 3: //exit
				*running_pointer = false;
			}
			break;
		case CHARACTER_SELECT:
			switch (p1_selector) {
			case 0: //cycle character
				if (field_pointer->getPlayer1()->type == HERNANDEZ) {
					field_pointer->getPlayer1()->setCharacter(BUSCEMI);
				} else if (field_pointer->getPlayer1()->type == BUSCEMI) {
					field_pointer->getPlayer1()->setCharacter(HERNANDEZ);
				}
				break;
			case 1: //start game
				is_active = false;
				break;
			}
			break;
		}
	} else if (key == SDLK_KP_0) {
		switch (screen) {
		case CHARACTER_SELECT:
			switch (p2_selector) {
			case 0:
				if (field_pointer->getPlayer2()->type == HERNANDEZ) {
					field_pointer->getPlayer2()->setCharacter(BUSCEMI);
				}
				else if (field_pointer->getPlayer2()->type == BUSCEMI) {
					field_pointer->getPlayer2()->setCharacter(HERNANDEZ);
				}
				break;
			}
		}
	}
	
}

void menu::open() {
	reset();
	is_active = !is_active;
}

void menu::reset() {
	p1_selector = 0;
	p2_selector = 0;
	p1_menu_max = 3;
	p2_menu_max = 0;
	screen = MAIN;
}
