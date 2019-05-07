#include "platform.h"
#include <iostream>
using namespace std;

platform::platform(int width, int height) {
	w = width;
	h = height;
};

bool platform::collidesWith(const obj& o, vector* n, vector* m) {
	bool collides = ((pos.y + h) >= (o.pos.y)) && ((pos.y) <= (o.pos.y + o.h)) && ((pos.x + w) >= (o.pos.x)) && ((pos.x) <= (o.pos.x + o.w));
	bool calc_normal = n != NULL;
	bool calc_move = m != NULL;
	if (collides) {
		float pos_sum_x = (((vel.x > 0) ? vel.x : 0) + ((acc.x > 0) ? acc.x : 0));
		float pos_sum_y = (((vel.y > 0) ? vel.y : 0) + ((acc.y > 0) ? acc.y : 0));
		float neg_sum_x = (((vel.x > 0) ? 0 : vel.x) + ((acc.x > 0) ? 0 : acc.x));
		float neg_sum_y = (((vel.y > 0) ? 0 : vel.y) + ((acc.y > 0) ? 0 : acc.y));
		if (pos.y < o.pos.y) {
			if (calc_normal)
				n->y += pos_sum_y * -1;
			if (calc_move)
				m->y -= ((pos.y + h) - o.pos.y);
		}
		if (((pos.y + h) > (o.pos.y + h))) {
			if (calc_normal)
				n->y += neg_sum_y * -1;
			if (calc_move)
				m->y += ((o.pos.y + h) - pos.y);
		}
		if (pos.x < o.pos.x) {
			if (calc_normal)
				n->x += pos_sum_x * -1;
			if (calc_move)
				m->x -= ((pos.x + h) - o.pos.x);
		}
		if (((pos.y + h) > (o.pos.y + h))) {
			if (calc_normal)
				n->x += neg_sum_x * -1;
			if (calc_move)
				m->x += ((o.pos.x + h) - pos.x);
		}
	}
	return collides;
}

void platform::update() {
	pos = { 0, 0 };
	vel = { 0, 0 };
	acc = { 0, 0 };
}

void platform::setColor(int red, int green, int blue) {
	r = red;
	g = green;
	b = blue;
}

void platform::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}