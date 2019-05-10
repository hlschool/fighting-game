#ifndef MOVE_H
#define MOVE_H

#include "hitbox.h"
#include "vector.h"

struct attack
{
public:

	hitbox *hb;
	vector right_pos;
	vector left_pos;

	int damage;
	vector knockback;

	int w;
	int h;

	int buffer_frames;
	int delay_frames;
	int stun_frames;
};
#endif
