#ifndef CHARACTER_H
#define CHARACTER_H
#include "rectangle.h"
#include "moveset.h"
#include "SDL_image.h"
#include "hitbox.h"
#include "constants.h"
enum move_types {
	AERIAL,
	JAB,
	DASH,
	SPECIAL
};

class character:public rectangle
{
public:
	void attack(move_types);
	void kill();
	
	bool isOwnHitbox(hitbox*) const;

	void update();
	void draw(SDL_Renderer*);

	character();

	void setFighter();
	//void setSteve();

	moveset moves = { { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Aerial
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Jab
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Dash
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun }, }; // Special;

	SDL_Texture* texture;
	SDL_Surface* surface;

	bool flipped = false;
	bool dead = false;
	int attack_delay = 0;
	int delay_count = 0;

	double HP;
	double EHP;
};

#endif