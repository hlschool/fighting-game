#ifndef HITBOX_H
#define HITBOX_H
#include "rectangle.h"
#include "SDL.h"

class hitbox : public rectangle {
public:

	void load(int, int, int, int, vector, vector);

	void update();
	//void draw(SDL_Renderer*);

	hitbox();

	bool exists;

	int damage;
	int stun_frames;
	vector knockback = { 0, 0 };

	int frame_counter;
};

#endif