#ifndef CHARACTER_H
#define CHARACTER_H
#include "rectangle.h"
#include "moveset.h"
#include "SDL_image.h"
#include "hitbox.h"
#include "constants.h"
#include <SDL_ttf.h>
enum move_types {
	AERIAL,
	JAB,
	DASH,
	SPECIAL,
	NOTHING
};

class character:public rectangle
{
public:
	void startAttack(move_types);
	void hit(int, int, const vector);

	void control(const vector);
	
	bool isOwnHitbox(hitbox*) const;

	void update();
	void draw(SDL_Renderer*);

	character();

	void setFighter();
	void setSteve();

	moveset moves = { { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Aerial
					  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Jab
					  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Dash
					  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay }, }; // Special;

	SDL_Texture* texture;
	SDL_Surface* surface;
	TTF_Font *Sans;

	bool flipped = false;

	move_types attacking;

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