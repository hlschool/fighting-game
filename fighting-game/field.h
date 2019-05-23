#ifndef FIELD_H
#define FIELD_H

#include "linkedList.h"
#include "obj.h"
#include "rectangle.h"
#include "platform.h"
#include "hitbox.h"
#include "character.h"
#include <SDL.h>

class field {
public:
	character *p_1;
	character *p_2;
	linkedList<platform*> *platforms;

	rectangle background = { 0, 0 };
	vector gravity = { 0, 0 };

	void addPlatform(platform*);
	void setPlayer1(character*);
	void setPlayer2(character*);
	character* getPlayer1();
	character* getPlayer2();
	void reset();
	void setBackground(const rectangle&);
	void setGravity(const vector&);

	bool hitsPlatform(const obj&, platform**, int*, int*);
	bool hitsGround(const obj&);

	void update();
	void draw(SDL_Renderer*);

	field();
};

#endif

//comment
