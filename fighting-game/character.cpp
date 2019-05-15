#include "character.h"
#include "constants.h"
#include <iostream>;
#include <SDL_ttf.h>

character::character() {
	HP = 100;
	attacking = NOTHING;
	TTF_Init();
	Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);
	setFighter();
}

void character::startAttack(move_types m) {
	if (!delayed && !buffered && !stunned)
		attacking = m;
}

void character::hit(int stun, int damage, const vector knockback) {
	stun_frames = stun;
	stun_count = 0;
	stunned = true;
	push(knockback);
	HP -= damage;
	if(HP <= 0) {
		HP = 0;
		stun_frames = -1;
	}
}

void character::control(const vector v) {
	if (!stunned) {
		if (v.x != 0)
			vel.x = 0;
		if (v.y != 0)
			vel.y = 0;
		move(v);

		if ((flipped && v.x > 0) || (!flipped && v.x < 0)) {
			moves.aerial.hb->knockback = { -moves.aerial.hb->knockback.x, moves.aerial.hb->knockback.y };
			moves.jab.hb->knockback = { -moves.jab.hb->knockback.x, moves.jab.hb->knockback.y };
			moves.dash.hb->knockback = { -moves.dash.hb->knockback.x, moves.dash.hb->knockback.y };
			moves.special.hb->knockback = { -moves.special.hb->knockback.x, moves.special.hb->knockback.y };
			flipped = !flipped;
		}
	}
}

bool character::isOwnHitbox(hitbox* h) const {
	if (h == (moves.aerial.hb) || h == (moves.jab.hb) || h == (moves.dash.hb) || h == (moves.special.hb)) {
		return true;
	}
	return false;
}

void character::update() {
	last_pos = pos;
	move(vel);
	vel += acc;
	acc = { 0, 0 };

	if (flipped) {
		moves.aerial.hb->moveTo((pos + moves.aerial.left_pos));
		moves.jab.hb->moveTo((pos + moves.jab.left_pos));
		moves.dash.hb->moveTo((pos + moves.dash.left_pos));
		moves.special.hb->moveTo((pos + moves.special.left_pos));
	}
	else {
		moves.aerial.hb->moveTo((pos + moves.aerial.right_pos));
		moves.jab.hb->moveTo((pos + moves.jab.right_pos));
		moves.dash.hb->moveTo((pos + moves.dash.right_pos));
		moves.special.hb->moveTo((pos + moves.special.right_pos));
	}

	if (!stunned) {
		if (attacking != NOTHING) {
			if (!delayed && !buffered && !stunned) {
				delay_count = 0;
				delayed = true;
				switch (attacking) {
				case AERIAL:
					delay_frames = moves.aerial.delay_frames;
					break;
				case JAB:
					delay_frames = moves.jab.delay_frames;
					break;
				case DASH:
					delay_frames = moves.dash.delay_frames;
					break;
				case SPECIAL:
					delay_frames = moves.special.delay_frames;
					break;
				}
			}
			if (delayed && delay_count < delay_frames) {
				delay_count++;
			}
			if (delayed && delay_count >= delay_frames) {
				delayed = false;
				buffer_count = 0;
				buffered = true;
				switch (attacking) {
				case AERIAL:
					moves.aerial.hb->load();
					buffer_frames = moves.aerial.buffer_frames;
					break;
				case JAB:
					moves.jab.hb->load();
					buffer_frames = moves.jab.buffer_frames;
					break;
				case DASH:
					moves.dash.hb->load();
					buffer_frames = moves.dash.buffer_frames;
					break;
				case SPECIAL:
					moves.special.hb->load();
					buffer_frames = moves.special.buffer_frames;
					break;
				}
			}
			if (buffered && buffer_count < buffer_frames) {
				buffer_count++;
			}
			if (buffered && buffer_count >= buffer_frames) {
				buffered = false;
				attacking = NOTHING;
			}
		}
	}
	if (stunned && stun_count < stun_frames) {
		stun_count++;
	}
	if (stunned && stun_count == stun_frames) {
		stun_count = 0;
		stunned = false;
		delay_count = 0;
		delayed = false;
		buffer_count = 0;
		buffered = false;
	}
}

void character::draw(SDL_Renderer* renderer) {
	//HP
	string health_string = to_string((int) HP);
	const char* health_char = health_string.c_str();
	SDL_Surface* message_surf = TTF_RenderText_Solid(Sans, health_char, { 255, (Uint8) (HP * 255 / 100), (Uint8) (HP * 255 / 100) });
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, message_surf);
	SDL_Rect message_rect = { pos.x, pos.y - message_surf->h, message_surf->w, message_surf->h };
	SDL_FreeSurface(message_surf);
	SDL_RenderCopy(renderer, message, NULL, &message_rect);

	//Img
	SDL_Rect fillRect = { pos.x, pos.y, w, h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopyEx(renderer, texture, NULL, &fillRect, 0, NULL, (flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
}

void character::setFighter() {
	surface = IMG_Load(constants::fighter_img_path.c_str());
	w = constants::fighter_img_w;
	h = constants::fighter_img_h;
	//moves = { { new hitbox(constants::fighter_aerial_hitbox_w, constants::fighter_aerial_hitbox_h, constants::fighter_aerial_stun, constants::fighter_aerial_damage, constants::fighter_aerial_knockback), constants::fighter_aerial_right_pos, constants::fighter_aerial_left_pos, constants::fighter_aerial_buffer, constants::fighter_aerial_delay },    //Aerial
	//		  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Jab
	//		  { new hitbox(constants::fighter_dash_hitbox_w, constants::fighter_dash_hitbox_h, constants::fighter_dash_stun, constants::fighter_dash_damage, constants::fighter_dash_knockback), constants::fighter_dash_right_pos, constants::fighter_dash_left_pos, constants::fighter_dash_buffer, constants::fighter_dash_delay },    //Dash
	//		  { new hitbox(constants::fighter_special_hitbox_w, constants::fighter_special_hitbox_h, constants::fighter_special_stun, constants::fighter_special_damage, constants::fighter_special_knockback), constants::fighter_special_right_pos, constants::fighter_special_left_pos, constants::fighter_special_buffer, constants::fighter_special_delay }, }; // Special;
	
	moves = { { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Aerial
			  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Jab
			  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay },    //Dash
			  { new hitbox(constants::fighter_jab_hitbox_w, constants::fighter_jab_hitbox_h, constants::fighter_jab_stun, constants::fighter_jab_damage, constants::fighter_jab_knockback), constants::fighter_jab_right_pos, constants::fighter_jab_left_pos, constants::fighter_jab_buffer, constants::fighter_jab_delay }, }; // Special;
}