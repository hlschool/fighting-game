#include "character.h"

character::character() {
	surface = IMG_Load(img_path.c_str());
	w = surface->w;
	h = surface->h;
	hb = new hitbox(100, 40);
}

void character::attack() {
	hb->load();
}

void character::update() {
	vector temp = pos;
	pos += vel;
	vel += acc;
	acc = { 0, 0 };
	last_pos = temp;
	hb->moveTo({ pos.x + w, (pos.y + (h / 2)) - (hb->h / 2) });
}

void character::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, &fillRect);
}