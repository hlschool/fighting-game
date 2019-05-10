#include "character.h"
#include "constants.h"

character::character() {
	setFighter();
}

void character::attack(move_types m) {
	switch (m) {
	case AERIAL:
		moves.aerial.hb->load();
		attack_delay = moves.aerial.buffer_frames;
		break;
	case JAB:
		moves.jab.hb->load();
		attack_delay = moves.jab.buffer_frames;
		break;
	case DASH:
		moves.dash.hb->load();
		attack_delay = moves.dash.buffer_frames;
		break;
	case SPECIAL:
		moves.special.hb->load();
		attack_delay = moves.special.buffer_frames;
		break;
	}

}

void character::kill() {
	dead = true;
}

bool character::isOwnHitbox(hitbox* h) const {
	if (h == (moves.aerial.hb) || h == (moves.jab.hb) || h == (moves.dash.hb) || h == (moves.special.hb)) {
		return true;
	}
	return false;
}

void character::update() {
	vector temp = pos;
	if (!dead) {
		pos += vel;
		vel += acc;
		acc = { 0, 0 };
		last_pos = temp;
	}

	if (flipped) {
		moves.aerial.hb->moveTo(pos + moves.aerial.left_pos);
		moves.jab.hb->moveTo(pos + moves.jab.left_pos);
		moves.dash.hb->moveTo(pos + moves.dash.left_pos);
		moves.special.hb->moveTo(pos + moves.special.left_pos);
	}
	else {
		moves.aerial.hb->moveTo(pos + moves.aerial.right_pos);
		moves.jab.hb->moveTo(pos + moves.jab.right_pos);
		moves.dash.hb->moveTo(pos + moves.dash.right_pos);
		moves.special.hb->moveTo(pos + moves.special.right_pos);
	}

	if ((flipped && vel.x > 0) || (!flipped && vel.x < 0))
		flipped = !flipped;

	if (delay_count >= attack_delay)
		delay_count = 0;
	else if (delay_count > 0)
		delay_count++;
}

void character::draw(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopyEx(renderer, texture, NULL, &fillRect, 0, NULL, (flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
}

void character::setFighter() {
	surface = IMG_Load("FighterTest.png");
	w = surface->w;
	h = surface->h;
	//moves = { { new hitbox(constants::fighter_aerial_hitbox_w, constants::fighter_aerial_hitbox_h), constants::fighter_aerial_right_pos, constants::fighter_aerial_left_pos, constants::fighter_aerial_damage, constants::fighter_aerial_knockback, constants::fighter_aerial_buffer, constants::fighter_aerial_delay, constants::fighter_aerial_stun },    //Aerial
	//		  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Jab
	//		  { new hitbox(constants::fighter_dash_hitbox_w, constants::fighter_dash_hitbox_h), constants::fighter_dash_right_pos, constants::fighter_dash_left_pos, constants::fighter_dash_damage, constants::fighter_dash_knockback, constants::fighter_dash_buffer, constants::fighter_dash_delay, constants::fighter_dash_stun },    //Dash
	//		  { new hitbox(constants::fighter_special_hitbox_w, constants::fighter_special_hitbox_h), constants::fighter_special_right_pos, constants::fighter_special_left_pos, constants::fighter_special_damage, constants::fighter_special_knockback, constants::fighter_special_buffer, constants::fighter_special_delay, constants::fighter_special_stun }, }; // Special
	
	moves = { { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Aerial
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Jab
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun },    //Dash
	{ new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_damage, constants::fighter_jab_knockback, constants::fighter_jab_buffer, constants::fighter_jab_delay, constants::fighter_jab_stun }, }; // Special
}