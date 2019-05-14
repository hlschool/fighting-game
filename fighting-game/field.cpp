#include "field.h"
#include "rectangle.h"
#include "obj.h"
#include <iostream>

field::field() {
	characters = new unorderedLinkedList<character*>;
	platforms = new unorderedLinkedList<platform*>;
	hitboxes = new unorderedLinkedList<hitbox*>;
	background.fixed = true;
}

void field::addPlatform(platform* p) {
	platforms->insertFirst(p);
}

void field::addHitbox(hitbox* h) {
	hitboxes->insertFirst(h);
}

void field::addCharacter(character* c) {
	characters->insertFirst(c);
	hitboxes->insertFirst(c->moves.aerial.hb);
	hitboxes->insertFirst(c->moves.jab.hb);
	hitboxes->insertFirst(c->moves.dash.hb);
	hitboxes->insertFirst(c->moves.special.hb);
}

void field::setBackground(const rectangle& b) {
	background = b;
}

void field::setGravity(const vector& g) {
	gravity = g;
}


//dont ask me how my code works, i actually dont know
//"your code looks like song lyrics written using only the stuff that comes after the question mark in a url"
bool field::collides(const obj& o, obj** p, int* dir, int* amt, int* type) {
	bool collides = false;
	bool calc_platform = p != NULL;
	bool calc_dir = dir != NULL;
	bool calc_amount = amt != NULL;
	bool calc_type = type != NULL;
	obj **temp_p = new obj*[platforms->length() + hitboxes->length() + characters->length()];
	int *temp_d = new int[platforms->length() + hitboxes->length() + characters->length()];
	int *temp_h = new int[platforms->length() + hitboxes->length() + characters->length()];
	int amount = 0;
	for (int i = 0; i < platforms->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*platforms->get(i), nullptr, nullptr, temp_dir)) {
			if(calc_platform)
				temp_p[amount] = platforms->get(i);
			if(calc_dir)
				temp_d[amount] = *temp_dir;
			if (calc_type)
				temp_h[amount] = 0;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < hitboxes->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*hitboxes->get(i), nullptr, nullptr, temp_dir)) {
			if (calc_platform)
				temp_p[amount] = hitboxes->get(i);
			if (calc_dir)
				temp_d[amount] = *temp_dir;
			if (calc_type)
				temp_h[amount] = 1;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < characters->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*characters->get(i), nullptr, nullptr, temp_dir)) {
			if (calc_platform)
				temp_p[amount] = characters->get(i);
			if (calc_dir)
				temp_d[amount] = *temp_dir;
			if (calc_type)
				temp_h[amount] = 2;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < amount; i++) {
		if(calc_platform)
			p[i] = temp_p[i];
		if(calc_dir)
			dir[i] = temp_d[i];
		if (calc_type)
			type[i] = temp_h[i];
	}
	if (calc_amount)
		*amt = amount;
	return collides;
}

bool field::hitsPlatform(const obj& o, platform** p, int* dir, int* amt) {
	bool collides = false;
	bool calc_platform = p != NULL;
	bool calc_dir = dir != NULL;
	bool calc_amount = amt != NULL;
	platform **temp_p = new platform*[platforms->length()];
	int *temp_d = new int[platforms->length()];
	int amount = 0;
	for (int i = 0; i < platforms->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*platforms->get(i), nullptr, nullptr, temp_dir)) {
			if (calc_platform)
				temp_p[amount] = platforms->get(i);
			if (calc_dir)
				temp_d[amount] = *temp_dir;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < amount; i++) {
		if (calc_platform)
			p[i] = temp_p[i];
		if (calc_dir)
			dir[i] = temp_d[i];
	}
	if (calc_amount)
		*amt = amount;
	return collides;
}

bool field::hitsGround(const obj& o) {
	for (int i = 0; i < platforms->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*platforms->get(i), nullptr, nullptr, temp_dir)) {
			cout << *temp_dir << endl;
			if (*temp_dir == 1) {
				return true;
			}
		}
	}
	return false;
}

bool field::isHit(const character& c, hitbox* hb) {
	bool calc_hitbox = hb != NULL;
	bool hit = false;
	for (int i = 0; i < hitboxes->length(); i++) {
		if (c.collidesWith(*hitboxes->get(i), nullptr, nullptr, nullptr) && !c.isOwnHitbox(hitboxes->get(i)) && hitboxes->get(i)->exists) {
			if (calc_hitbox)
				*hb = *hitboxes->get(i);
			hit = true;
			break;
		}
	}
	return hit;
}

void field::update() {
	for (int i = 0; i < characters->length(); i++) {
		characters->get(i)->push(gravity);
		
		vector sum_move = { 0, 0 };
		vector sum_push = { 0, 0 };
		for (int j = 0; j < platforms->length(); j++) {
			vector *normal = new vector(0, 0);
			vector *move = new vector(0, 0);
			int *dir = new int;
			characters->get(i)->collidesWith(*platforms->get(j), normal, move, dir);
			sum_move += *move;
			sum_push += *normal;
		}
		characters->get(i)->push(sum_push);
		characters->get(i)->move(sum_move);
		characters->get(i)->update();
		hitbox *temp_hb = new hitbox(0, 0, 0, 0, { 0, 0 });
		if (isHit(*characters->get(i), temp_hb)) {
			characters->get(i)->hit(temp_hb->stun, temp_hb->damage, temp_hb->knockback);
			temp_hb->exists = false;
			temp_hb->frame_counter = 0;
		}
	}
	for (int i = 0; i < hitboxes->length(); i++) {
		hitboxes->get(i)->update();
	}
}

void field::draw(SDL_Renderer* renderer) {
	background.draw(renderer);
	for (int i = 0; i < characters->length(); i++) {
		characters->get(i)->draw(renderer);
	}
	for (int i = 0; i < platforms->length(); i++) {
		platforms->get(i)->draw(renderer);
	}
	for (int i = 0; i < hitboxes->length(); i++) {
		if (hitboxes->get(i)->exists) 
			hitboxes->get(i)->draw(renderer);
	}
}

//k: hello
//hello