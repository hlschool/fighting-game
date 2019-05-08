#ifndef FIELD_H
#define FIELD_H

#include "linkedList.h"
#include "obj.h"
#include "rectangle.h"
#include "platform.h"
#include <SDL.h>

class field {
public:
	linkedList<obj*> *objs;
	linkedList<platform*> *platforms;

	rectangle background = { 0, 0 };
	vector gravity = { 0, 0 };

	void add(obj*);
	void addPlatform(platform*);
	void setBackground(const rectangle&);
	void setGravity(const vector&);

	bool collides(const obj&, platform**, int*, int*);

	void update();
	void draw(SDL_Renderer*);

	field();
};

#endif

//comment
