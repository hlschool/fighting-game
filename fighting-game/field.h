#ifndef FIELD_H
#define FIELD_H

#include "linkedList.h"
#include "obj.h"
#include "rectangle.h"
#include <SDL.h>

class field {
public:
	linkedList<obj*> *l;

	rectangle background = { 0, 0 };
	vector gravity = { 0, 0 };

	void add(obj*);
	void setBackground(const rectangle&);
	void setGravity(const vector&);

	int objects();

	void update();
	void draw(SDL_Renderer*);

	field();
};

#endif
