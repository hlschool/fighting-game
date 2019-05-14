#include "rectangle.h"
#include <iostream>
#include <cstring>
#include "SDL_image.h"
using namespace std;

rectangle::rectangle() {}

rectangle::rectangle(int width, int height) {
	w = width;
	h = height;
};

void rectangle::update() {
	move(vel);
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