#include "platform.h"
#include <iostream>
using namespace std;

platform::platform(int width, int height) {
	w = width;
	h = height;
	fixed = true;
};

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