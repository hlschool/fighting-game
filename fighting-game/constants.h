#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vector.h"
#include <string>
using namespace std;

enum menu_screens {
	MAIN,
	CHARACTER_SELECT,
	STAGE_SELECT,
	HIGH_SCORES
};

enum characters {
	HERNANDEZ,
	BUSCEMI
};

enum move_types {
	AERIAL,
	JAB,
	DASH,
	SPECIAL,
	NOTHING
};

enum sound_types {
	DEATH,
	ATTACK,
	DAMAGE
};

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

	const static string death_sound;
	const static string attack_sound_1;
	const static string attack_sound_2;
	const static string attack_sound_3;
	const static string attack_sound_4;
	const static string damage_sound_1;
	const static string damage_sound_2;
	const static string damage_sound_3;
	const static string damage_sound_4;
	const static string damage_sound_5;
	

};

static string getImagePath(characters c) {
	switch (c) {
	case HERNANDEZ:
		return constants::fighter_img_path;
	case BUSCEMI:
		return constants::steve_img_path;
	}
}

static int getImageHeight(characters c) {
	switch (c) {
	case HERNANDEZ:
		return constants::fighter_img_h;
	case BUSCEMI:
		return constants::steve_img_h;
	}
}

static int getImageWidth(characters c) {
	switch (c) {
	case HERNANDEZ:
		return constants::fighter_img_w;
	case BUSCEMI:
		return constants::steve_img_w;
	}
}

static int getHitboxWidth(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_hitbox_w;
		case JAB:
			return constants::fighter_jab_hitbox_w;
		case DASH:
			return constants::fighter_dash_hitbox_w;
		case SPECIAL:
			return constants::fighter_special_hitbox_w;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_hitbox_w;
		case JAB:
			return constants::steve_jab_hitbox_w;
		case DASH:
			return constants::steve_dash_hitbox_w;
		case SPECIAL:
			return constants::steve_special_hitbox_w;
		}
	}
}

static int getHitboxHeight(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_hitbox_h;
		case JAB:
			return constants::fighter_jab_hitbox_h;
		case DASH:
			return constants::fighter_dash_hitbox_h;
		case SPECIAL:
			return constants::fighter_special_hitbox_h;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_hitbox_h;
		case JAB:
			return constants::steve_jab_hitbox_h;
		case DASH:
			return constants::steve_dash_hitbox_h;
		case SPECIAL:
			return constants::steve_special_hitbox_h;
		}
	}
}

static int getDamage(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_damage;
		case JAB:
			return constants::fighter_jab_damage;
		case DASH:
			return constants::fighter_dash_damage;
		case SPECIAL:
			return constants::fighter_special_damage;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_damage;
		case JAB:
			return constants::steve_jab_damage;
		case DASH:
			return constants::steve_dash_damage;
		case SPECIAL:
			return constants::steve_special_damage;
		}
	}
}

static int getBuffer(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_buffer;
		case JAB:
			return constants::fighter_jab_buffer;
		case DASH:
			return constants::fighter_dash_buffer;
		case SPECIAL:
			return constants::fighter_special_buffer;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_buffer;
		case JAB:
			return constants::steve_jab_buffer;
		case DASH:
			return constants::steve_dash_buffer;
		case SPECIAL:
			return constants::steve_special_buffer;
		}
	}
}

static int getDelay(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_delay;
		case JAB:
			return constants::fighter_jab_delay;
		case DASH:
			return constants::fighter_dash_delay;
		case SPECIAL:
			return constants::fighter_special_delay;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_delay;
		case JAB:
			return constants::steve_jab_delay;
		case DASH:
			return constants::steve_dash_delay;
		case SPECIAL:
			return constants::steve_special_delay;
		}
	}
}

static int getStun(characters c, move_types m) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return constants::fighter_aerial_stun;
		case JAB:
			return constants::fighter_jab_stun;
		case DASH:
			return constants::fighter_dash_stun;
		case SPECIAL:
			return constants::fighter_special_stun;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return constants::steve_aerial_stun;
		case JAB:
			return constants::steve_jab_stun;
		case DASH:
			return constants::steve_dash_stun;
		case SPECIAL:
			return constants::steve_special_stun;
		}
	}
}

static vector getKnockback(characters c, move_types m, bool flipped) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return { ((flipped) ? -constants::fighter_aerial_knockback.x : constants::fighter_aerial_knockback.x), constants::fighter_aerial_knockback.y };
		case JAB:
			return { ((flipped) ? -constants::fighter_jab_knockback.x : constants::fighter_jab_knockback.x), constants::fighter_jab_knockback.y };
		case DASH:
			return { ((flipped) ? -constants::fighter_dash_knockback.x : constants::fighter_dash_knockback.x), constants::fighter_dash_knockback.y };
		case SPECIAL:
			return { ((flipped) ? -constants::fighter_special_knockback.x : constants::fighter_special_knockback.x), constants::fighter_special_knockback.y };
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return { ((flipped) ? -constants::steve_aerial_knockback.x : constants::steve_aerial_knockback.x), constants::steve_aerial_knockback.y };
		case JAB:
			return { ((flipped) ? -constants::steve_jab_knockback.x : constants::steve_jab_knockback.x), constants::steve_jab_knockback.y };
		case DASH:
			return { ((flipped) ? -constants::steve_dash_knockback.x : constants::steve_dash_knockback.x), constants::steve_dash_knockback.y };
		case SPECIAL:
			return { ((flipped) ? -constants::steve_special_knockback.x : constants::steve_special_knockback.x), constants::steve_special_knockback.y };
		}
	}
}

static vector getPos(characters c, move_types m, bool flipped) {
	switch (c) {
	case HERNANDEZ:
		switch (m) {
		case AERIAL:
			return flipped ? constants::fighter_aerial_left_pos : constants::fighter_aerial_right_pos;
		case JAB:
			return flipped ? constants::fighter_jab_left_pos : constants::fighter_jab_right_pos;
		case DASH:
			return flipped ? constants::fighter_dash_left_pos : constants::fighter_dash_right_pos;
		case SPECIAL:
			return flipped ? constants::fighter_special_left_pos : constants::fighter_special_right_pos;
		}
	case BUSCEMI:
		switch (m) {
		case AERIAL:
			return flipped ? constants::steve_aerial_left_pos : constants::steve_aerial_right_pos;
		case JAB:
			return flipped ? constants::steve_jab_left_pos : constants::steve_jab_right_pos;
		case DASH:
			return flipped ? constants::steve_dash_left_pos : constants::steve_dash_right_pos;
		case SPECIAL:
			return flipped ? constants::steve_special_left_pos : constants::steve_special_right_pos;
		}
	}
}

static string getRandomAudio(sound_types s) {
	int random = rand();
	switch (s) {
	case DEATH:
		return constants::death_sound;
	case ATTACK:
		random = (random % 4) + 1;
		switch (random) {
		case 1:
			return constants::attack_sound_1;
		case 2:
			return constants::attack_sound_2;
		case 3:
			return constants::attack_sound_3;
		case 4:
			return constants::attack_sound_4;
		}
	case DAMAGE:
		random = (random % 4) + 1;
		switch (random) {
		case 1:
			return constants::damage_sound_1;
		case 2:
			return constants::damage_sound_2;
		case 3:
			return constants::damage_sound_3;
		case 4:
			return constants::damage_sound_4;
		case 5:
			return constants::damage_sound_5;
		}
	}
}

#endif