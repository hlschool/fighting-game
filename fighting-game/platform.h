#ifndef PLATFORM_H
#define PLATFORM_H

#include "obj.h"

class platform : public obj {
public:

	int r = 255;
	int g = 255;
	int b = 255;

	bool collidesWith(const obj&, vector*, vector*, int*) const;
	void update();

	void setColor(int, int, int);
	void draw(SDL_Renderer*);

	platform(int, int);
};

#endif
