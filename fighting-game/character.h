#ifndef CHARACTER_H
#define CHARACTER_H
#include "rectangle.h"
#include "SDL_image.h"
#include "hitbox.h"
#include "constants.h"
#include <SDL_ttf.h>

class character:public rectangle
{
public:
	void startAttack(move_types);
	void hit(character*);

	void control(const vector);

	void update();
	void draw(SDL_Renderer*);

	character();

	void setCharacter(characters c);

	characters type;

	move_types attack_type;
	bool attacking = false;
	hitbox attack;

	SDL_Texture* texture;
	SDL_Surface* surface;
	TTF_Font *Sans;

	bool flipped = false;

	bool delayed = false;
	int delay_frames = 0;
	int delay_count = 0;

	bool buffered = false;
	int buffer_frames = 0;
	int buffer_count = 0;
	
	bool stunned = false;
	int stun_frames = 0;
	int stun_count = 0;

	double HP;
	double EHP;
};

#endif