#include "rectangle.h"

rectangle::rectangle(int width, int height) {
	w = width;
	h = height;
};

bool rectangle::collidesWith(const obj& o, vector* f) {
	return false;
}

void rectangle::update() {
	pos += vel;
	vel += acc;
	acc = { 0, 0 };
}

void rectangle::setColor(int red, int green, int blue) {
	r = red;
	g = green;
	b = blue;
}

void rectangle::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}