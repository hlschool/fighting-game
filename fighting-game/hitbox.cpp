#include "hitbox.h"
#include <iostream>

void hitbox::load(int width, int height, int dam, int s, vector kb, vector p) {
	w = width;
	h = height;
	damage = dam;
	stun_frames = s;
	knockback = kb;
	frame_counter = 0;
	exists = true;
	moveTo(p);
}

hitbox::hitbox() {
	exists = false;
	pos = { 0, 0 };
	r = 255;
	g = 0;
	b = 0;
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

