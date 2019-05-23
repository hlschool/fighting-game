#include "character.h"
#include "constants.h"
#include <iostream>;
#include <SDL_ttf.h>

character::character() {
	HP = 100;
	attack_type = NOTHING;
	TTF_Init();
	Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);
	setCharacter(HERNANDEZ);
}

void character::startAttack(move_types m) {
	if (!delayed && !buffered && !stunned)
		attack_type = m;
}

void character::hit(character* c) {
	stun_frames = c->attack.stun_frames;
	stun_count = 0;
	stunned = true;
	push(c->attack.knockback);
	HP -= c->attack.damage;
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
			flipped = !flipped;
		}
	}
}

void character::update() {
	last_pos = pos;
	move(vel);
	vel += acc;
	acc = { 0, 0 };

	if (!stunned) {
		if (attack_type != NOTHING) {
			if (!delayed && !buffered && !stunned) {
				delay_count = 0;
				delayed = true;
				delay_frames = getDelay(type, attack_type);
			}
			if (delayed && delay_count < delay_frames) {
				delay_count++;
			}
			if (delayed && delay_count >= delay_frames) {
				delayed = false;
				buffer_count = 0;
				buffered = true;
				buffer_frames = getBuffer(type, attack_type);
				attack.load(getHitboxWidth(type, attack_type),
					getHitboxHeight(type, attack_type),
					getDamage(type, attack_type),
					getStun(type, attack_type),
					getKnockback(type, attack_type, flipped),
					(getPos(type, attack_type, flipped)) + pos);
			}
			if (buffered && buffer_count < buffer_frames) {
				buffer_count++;
			}
			if (buffered && buffer_count >= buffer_frames) {
				buffered = false;
				attack_type = NOTHING;
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
	attack.update();
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
	surface = IMG_Load(getImagePath(type).c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	int i = SDL_RenderCopyEx(renderer, texture, NULL, &fillRect, 0, NULL, (flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
	cout << i;
}

void character::setCharacter(characters c) {
	w = getImageWidth(type);
	h = getImageHeight(type);
	type = c;
}