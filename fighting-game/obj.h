#ifndef OBJ_H
#define OBJ_H

#include "vector.h"
#include <SDL.h>

class obj {
public:
	vector pos = { 0, 0 };
	vector vel = { 0, 0 };
	vector acc = { 0, 0 };

	vector last_pos = { 0, 0 };

	int w, h;

	bool fixed = false;

	void push(const vector&);
	void move(const vector&);
	void moveTo(const vector&);
	
	virtual bool collidesWith(const obj&, vector*, vector*, int*) const = 0;
	virtual void update() = 0;
	virtual void draw(SDL_Renderer*) = 0;

	obj();
};

#endif
