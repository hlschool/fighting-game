#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "obj.h"
#include <string>
//#include "STEVE BUSCEMI.h"
#include "SDL_image.h"
using namespace std;

class rectangle : public obj {
public:

	int r = 255;
	int g = 255; 
	int b = 255;

	void update();

	void setColor(int, int, int);
	void draw(SDL_Renderer*);

	rectangle();
	rectangle(int, int);
};

#endif

