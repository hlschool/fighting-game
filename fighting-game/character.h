#ifndef CHARACTER_H
#define CHARACTER_H
#include "rectangle.h"
//#include "moveset.h"
#include "SDL_image.h"
#include "hitbox.h"
class character:public rectangle
{
public:
	void attack(bool spike);
	void kill();

	void update();
	void draw(SDL_Renderer*);

	character();
	
	hitbox *attk_hb;
	hitbox *spike_hb;

	SDL_Texture* texture;
	SDL_Surface* surface;
<<<<<<< Updated upstream
	string img_path = "steve.png";

	bool flipped = false;
	bool dead = false;

	const int attack_delay = 30;
	int delay_count = 0;
=======
	string img_path = "FighterTest.png";
>>>>>>> Stashed changes

	double HP;
	double EHP;

	//moveset m;

};

#endif