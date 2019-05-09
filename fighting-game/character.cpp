#include "character.h"

character::character() {
	surface = IMG_Load(img_path.c_str());
	w = surface->w;
	h = surface->h;
	attk_hb = new hitbox(100, 40);
	spike_hb = new hitbox(40, 100);
}

void character::attack(bool spike) {
	if (delay_count == 0) {
		if (spike)
			spike_hb->load();
		else
			attk_hb->load();
	}
	delay_count++;
}

void character::kill() {
	dead = true;
}

void character::update() {
	vector temp = pos;
	if (!dead) {
		pos += vel;
		vel += acc;
		acc = { 0, 0 };
		last_pos = temp;
	}

	if(flipped)
		attk_hb->moveTo({ pos.x - attk_hb->w, (pos.y + (h / 2)) - (attk_hb->h / 2) });
	else
		attk_hb->moveTo({ pos.x + w, (pos.y + (h / 2)) - (attk_hb->h / 2) });
	spike_hb->moveTo({ ((pos.x + (w / 2)) - (spike_hb->w / 2)), pos.y + h });

	if ((flipped && vel.x > 0) || (!flipped && vel.x < 0))
		flipped = !flipped;

	if (delay_count >= attack_delay)
		delay_count = 0;
	else if (delay_count > 0)
		delay_count++;
}

void character::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopyEx(renderer, texture, NULL, &fillRect, 0, NULL, (flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
}