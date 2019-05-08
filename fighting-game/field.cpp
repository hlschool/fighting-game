#include "field.h"
#include "rectangle.h"
#include "obj.h"

field::field() {
	objs = new unorderedLinkedList<obj*>;
	platforms = new unorderedLinkedList<platform*>;
	background.fixed = true;
}

void field::add(obj* o) {
	objs->insertFirst(o);
}

void field::addPlatform(platform* p) {
	platforms->insertFirst(p);
}

void field::setBackground(const rectangle& b) {
	background = b;
}

void field::setGravity(const vector& g) {
	gravity = g;
}


//dont ask me how my code works, i actually dont know
//"your code looks like song lyrics written using only the stuff that comes after the question mark in a url"
bool field::collides(const obj& o, platform** p, int* dir, int* amt) {
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
			if(calc_platform)
				temp_p[amount] = platforms->get(i);
			if(calc_dir)
				temp_d[amount] = *temp_dir;
			amount++;
			collides = true;
		}
	}
	for (int i = 0; i < amount; i++) {
		if(calc_platform)
			p[i] = temp_p[i];
		if(calc_dir)
			dir[i] = temp_d[i];
	}
	if (calc_amount)
		*amt = amount;
	return collides;
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
}

//k: hello
//hello