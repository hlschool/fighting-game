#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vector.h"
#include <string>
using namespace std;

class constants {
public:
	const static int screen_width;
	const static int screen_height;

	const static string fighter_img_path;
	const static int fighter_img_w;
	const static int fighter_img_h;

	const static int fighter_aerial_hitbox_w;
	const static int fighter_aerial_hitbox_h;
	const static vector fighter_aerial_right_pos;
	const static vector fighter_aerial_left_pos;
	const static int fighter_aerial_damage;
	const static vector fighter_aerial_knockback;
	const static int fighter_aerial_buffer;
	const static int fighter_aerial_delay;
	const static int fighter_aerial_stun;

	const static int fighter_jab_hitbox_w;
	const static int fighter_jab_hitbox_h;
	const static vector fighter_jab_right_pos;
	const static vector fighter_jab_left_pos;
	const static int fighter_jab_damage;
	const static vector fighter_jab_knockback;
	const static int fighter_jab_buffer;
	const static int fighter_jab_delay;
	const static int fighter_jab_stun;

	const static int fighter_dash_hitbox_w;
	const static int fighter_dash_hitbox_h;
	const static vector fighter_dash_right_pos;
	const static vector fighter_dash_left_pos;
	const static int fighter_dash_damage;
	const static vector fighter_dash_knockback;
	const static int fighter_dash_buffer;
	const static int fighter_dash_delay;
	const static int fighter_dash_stun;

	const static int fighter_special_hitbox_w;
	const static int fighter_special_hitbox_h;
	const static vector fighter_special_right_pos;
	const static vector fighter_special_left_pos;
	const static int fighter_special_damage;
	const static vector fighter_special_knockback;
	const static int fighter_special_buffer;
	const static int fighter_special_delay;
	const static int fighter_special_stun;

	const static string steve_img_path;
	const static int steve_img_w;
	const static int steve_img_h;

	const static int steve_aerial_hitbox_w;
	const static int steve_aerial_hitbox_h;
	const static vector steve_aerial_right_pos;
	const static vector steve_aerial_left_pos;
	const static int steve_aerial_damage;
	const static vector steve_aerial_knockback;
	const static int steve_aerial_buffer;
	const static int steve_aerial_delay;
	const static int steve_aerial_stun;

	const static int steve_jab_hitbox_w;
	const static int steve_jab_hitbox_h;
	const static vector steve_jab_right_pos;
	const static vector steve_jab_left_pos;
	const static int steve_jab_damage;
	const static vector steve_jab_knockback;
	const static int steve_jab_buffer;
	const static int steve_jab_delay;
	const static int steve_jab_stun;

	const static int steve_dash_hitbox_w;
	const static int steve_dash_hitbox_h;
	const static vector steve_dash_right_pos;
	const static vector steve_dash_left_pos;
	const static int steve_dash_damage;
	const static vector steve_dash_knockback;
	const static int steve_dash_buffer;
	const static int steve_dash_delay;
	const static int steve_dash_stun;

	const static int steve_special_hitbox_w;
	const static int steve_special_hitbox_h;
	const static vector steve_special_right_pos;
	const static vector steve_special_left_pos;
	const static int steve_special_damage;
	const static vector steve_special_knockback;
	const static int steve_special_buffer;
	const static int steve_special_delay;
	const static int steve_special_stun;

};

#endif