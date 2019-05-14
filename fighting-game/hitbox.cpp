#include "hitbox.h"
#include <iostream>

hitbox::hitbox(int width, int height, int s, int d, vector kb) {
	w = width;
	h = height;
	stun = s;
	damage = d;
	knockback = kb;
	r = 255;
	g = 0; 
	b = 0;
	exists = false;
	frame_counter = 0;
}

void hitbox::load() {
	exists = true;
}

void hitbox::update() {
	if (exists && frame_counter >= 1) {
		exists = false;
		frame_counter = 0;
	}
	else if (exists) {
		frame_counter++;
	}
}

