#include "platform.h"
#include <iostream>
using namespace std;

platform::platform(int width, int height) {
	w = width;
	h = height;
	fixed = true;
};

bool platform::collidesWith(const obj& o, vector* n, vector* m, int* dir) const {
	bool collides = ((pos.y + h) >= (o.pos.y)) && ((pos.y) <= (o.pos.y + o.h)) && ((pos.x + w) >= (o.pos.x)) && ((pos.x) <= (o.pos.x + o.w));
	bool calc_normal = n != NULL;
	bool calc_move = m != NULL;
	bool calc_dir = dir != NULL;
	if (collides && o.fixed) {
		float pos_sum_x = ((vel.x > 0) ? vel.x : 0) + ((acc.x > 0) ? acc.x : 0);
		float pos_sum_y = ((vel.y > 0) ? vel.y : 0) + ((acc.y > 0) ? acc.y : 0);
		float neg_sum_x = ((vel.x > 0) ? 0 : vel.x) + ((acc.x > 0) ? 0 : acc.x);
		float neg_sum_y = ((vel.y > 0) ? 0 : vel.y) + ((acc.y > 0) ? 0 : acc.y);
		//above o, dir = 1
		if ((last_pos.y + h) <= o.pos.y) {
			if (calc_normal)
				n->y += pos_sum_y * -1;
			if (calc_move)
				m->y -= ((pos.y + h) - o.pos.y);
			if (calc_dir)
				*dir = 1;
		}
		//below o, dir = 2
		if (((last_pos.y) >= (o.pos.y + o.h))) {
			if (calc_normal)
				n->y += neg_sum_y * -1;
			if (calc_move)
				m->y += ((o.pos.y + o.h) - pos.y);
			if (calc_dir)
				*dir = 2;
		}
		//left of o, dir = 3
		if ((last_pos.x + w) <= o.pos.x) {
			if (calc_normal)
				n->x += pos_sum_x * -1;
			if (calc_move)
				m->x -= ((pos.x + w) - o.pos.x);
			if (calc_dir)
				*dir = 3;
		}
		//right of o, dir = 4
		if (last_pos.x >= (o.pos.x + o.w)) {
			if (calc_normal)
				n->x += neg_sum_x * -1;
			if (calc_move)
				m->x += ((o.pos.x + o.w) - pos.x);
			if (calc_dir)
				*dir = 4;
		}
	}
	else {
		if (calc_normal)
			*n = { 0, 0 };
		if (calc_move)
			*m = { 0, 0 };
		if (calc_dir)
			*dir = 0;
	}
	return collides;
}

void platform::update() {
	vector temp = pos;
	pos += vel;
	vel += acc;
	acc = { 0, 0 };
	last_pos = temp;
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