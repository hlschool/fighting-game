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

	int buffer_frames;
	int delay_frames;
};
#endif
