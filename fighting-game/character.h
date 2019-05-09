#ifndef CHARACTER_H
#define CHARACTER_H
#include "rectangle.h"
//#include "moveset.h"
#include "SDL_image.h"
#include "hitbox.h"
class character:public rectangle
{
public:
	void attack();

	void update();
	void draw(SDL_Renderer*);

	character();
	
	hitbox *hb;

	SDL_Texture* texture;
	SDL_Surface* surface;
	string img_path = "steve.png";

	double HP;
	double EHP;

	//moveset m;

};

#endif