#include "rectangle.h"
//#include "moveset.h"
#include "SDL_image.h"
class character:public rectangle
{
public:
	//void attack(move);

	void draw(SDL_Renderer*);

	character();

	SDL_Texture* texture;
	SDL_Surface* surface;
	string img_path = "Steve.png";

	double HP;
	double EHP;

	//moveset m;

};