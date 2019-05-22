#include "menu.h"
#include "constants.h"
#include <SDL.h>
#include "rendering.h"

menu::menu() {
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
			if (p1_character == HERNANDEZ) {
				renderImage(renderer, constants::fighter_img_path, { 0, 0 });
			}
			else {
				renderImage(renderer, constants::steve_img_path, { 0, 0 });
			}
			renderText(renderer, Sans, ">", { (float)(constants::screen_width * 0.25), 417 }, ((p1_selector == 0) ? blue : white));
			renderText(renderer, Sans, "Start", { (float)(constants::screen_width * 0.5), 492 }, ((p1_selector == 1) ? blue : white));
			renderText(renderer, Sans, ">", { (float)(constants::screen_width * 0.75), 417 }, ((p2_selector == 0) ? red : white));
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
			case 0:
				p1_menu_max = 1;
				screen = CHARACTER_SELECT;
				break;
			case 1:
				screen = STAGE_SELECT;
				break;
			case 2:
				screen = HIGH_SCORES;
				break;
			}
			break;
		case CHARACTER_SELECT:
			switch (p1_selector) {
			case 0:
				if (p1_character == HERNANDEZ) p1_character = BUSCEMI;
				else if(p1_character == BUSCEMI) p1_character = HERNANDEZ;
				break;
			case 1:
				//start game
				break;
			}
			break;
		}
	} else if (key == SDLK_KP_0) {
		switch (screen) {
		case CHARACTER_SELECT:
			switch (p2_selector) {
			case 0:
				if (p2_character == HERNANDEZ) p2_character = BUSCEMI;
				else if (p2_character == BUSCEMI) p2_character = HERNANDEZ;
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
	p1_character = HERNANDEZ;
	p2_character = HERNANDEZ;
	screen = MAIN;
}
