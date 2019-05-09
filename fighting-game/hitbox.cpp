#include "hitbox.h"

hitbox::hitbox(int width, int height) {
	w = width;
	h = height;
	exists = false;
	frame_counter = 0;
}

void hitbox::load() {
	exists = true;
}

void hitbox::update() {
	if (exists && frame_counter >= 5) {
		exists = false;
		frame_counter = 0;
	}
	else if (exists) {
		frame_counter++;
	}
}

