#include "field.h"
#include "rectangle.h"
#include "obj.h"


field::field() {
	objs = new unorderedLinkedList<obj*>;
	platforms = new unorderedLinkedList<platform*>;
	hitboxes = new unorderedLinkedList<hitbox*>;
	background.fixed = true;
}

void field::add(obj* o) {
	objs->insertFirst(o);
}

void field::addPlatform(platform* p) {
	platforms->insertFirst(p);
}

void field::addHitbox(hitbox* h) {
	hitboxes->insertFirst(h);
}

void field::addCharacter(character* c) {
	objs->insertFirst(c);
	hitboxes->insertFirst(c->hb);
}

void field::setBackground(const rectangle& b) {
	background = b;
}

void field::setGravity(const vector& g) {
	gravity = g;
}


//dont ask me how my code works, i actually dont know
//"your code looks like song lyrics written using only the stuff that comes after the question mark in a url"
bool field::collides(const obj& o, obj** p, int* dir, int* amt, bool* hitbox) {
	bool collides = false;
	bool calc_platform = p != NULL;
	bool calc_dir = dir != NULL;
	bool calc_amount = amt != NULL;
	bool calc_hitbox = hitbox != NULL;
	obj **temp_p = new obj*[platforms->length() + hitboxes->length()];
	int *temp_d = new int[platforms->length() + hitboxes->length()];
	bool *temp_h = new bool[platforms->length() + hitboxes->length()];
	int amount = 0;
	for (int i = 0; i < platforms->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*platforms->get(i), nullptr, nullptr, temp_dir)) {
			if(calc_platform)
				temp_p[amount] = platforms->get(i);
			if(calc_dir)
				temp_d[amount] = *temp_dir;
			if (calc_hitbox)
				temp_h[amount] = false;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < hitboxes->length(); i++) {
		int *temp_dir = new int;
		if (o.collidesWith(*hitboxes->get(i), nullptr, nullptr, temp_dir)) {
			if (calc_platform)
				temp_p[amount] = platforms->get(i);
			if (calc_dir)
				temp_d[amount] = *temp_dir;
			if (calc_hitbox)
				temp_h[amount] = true;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < amount; i++) {
		if(calc_platform)
			p[i] = temp_p[i];
		if(calc_dir)
			dir[i] = temp_d[i];
		if (calc_hitbox)
			hitbox[i] = temp_h[i];
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

bool field::isHit(const obj& c) {
	bool hit = false;
	for (int i = 0; i < hitboxes->length(); i++) {
		if (c.collidesWith(*hitboxes->get(i), nullptr, nullptr, nullptr) /*&& c.hb != hitboxes->get(i)*/ && hitboxes->get(i)->exists) {
			hit = true;
			break;
		}
	}
	return hit;
}

void field::update() {
	for (int i = 0; i < objs->length(); i++) {
		objs->get(i)->push(gravity);
		objs->get(i)->update();
		for (int j = 0; j < platforms->length(); j++) {
			vector *normal = new vector(0, 0);
			vector *move = new vector(0, 0);
			objs->get(i)->collidesWith(*platforms->get(j), normal, move, nullptr);
			objs->get(i)->push(*normal);
			objs->get(i)->move(*move);
		}
		for (int j = 0; j < hitboxes->length(); j++) {
			//objs->get(i)->collidesWith(*hitboxes->get(j), nullptr, nullptr, nullptr);
		}
	}
	for (int i = 0; i < hitboxes->length(); i++) {
		hitboxes->get(i)->update();
	}
}

void field::draw(SDL_Renderer* renderer) {
	background.draw(renderer);
	for (int i = 0; i < objs->length(); i++) {
		objs->get(i)->draw(renderer);
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