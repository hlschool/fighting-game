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
	linkedList<obj*> *objs;
	linkedList<platform*> *platforms;
	linkedList<hitbox*> *hitboxes;

	rectangle background = { 0, 0 };
	vector gravity = { 0, 0 };

	void add(obj*);
	void addPlatform(platform*);
	void addHitbox(hitbox*);
	void addCharacter(character*);
	void setBackground(const rectangle&);
	void setGravity(const vector&);

	bool collides(const obj&, obj**, int*, int*, bool*);
	bool hitsPlatform(const obj&, platform**, int*, int*);
	bool isHit(const obj&);

	void update();
	void draw(SDL_Renderer*);

	field();
};

#endif

//comment
