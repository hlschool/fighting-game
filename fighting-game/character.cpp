#include "character.h"

character::character() {
	surface = IMG_Load(img_path.c_str());
	w = surface->w;
	h = surface->h;
}

void character::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, &fillRect);
}