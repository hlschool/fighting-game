#ifndef HITBOX_H
#define HITBOX_H
#include "rectangle.h"
#include "SDL.h"

class hitbox : public rectangle {
public:

	void load();

	void update();
	//void draw(SDL_Renderer*);

	hitbox(int, int);

	bool exists;

private:
	int frame_counter;
};

#endif