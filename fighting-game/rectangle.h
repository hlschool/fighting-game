#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "obj.h"

class rectangle : public obj {
public:
	int w;
	int h;

	int r = 255;
	int g = 255; 
	int b = 255;

	bool collidesWith(const obj&, vector*);
	void update();

	void setColor(int, int, int);
	void draw(SDL_Renderer*);

	rectangle(int, int);
};

#endif

