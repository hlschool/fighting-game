#include "field.h"
#include "rectangle.h"
#include "obj.h"
#include <iostream>

field::field() {
	p_1 = new character;
	p_2 = new character;
	platforms = new unorderedLinkedList<platform*>;
	background.fixed = true;
}

void field::addPlatform(platform* p) {
	platforms->insertFirst(p);
}

void field::setPlayer1(character* c) {
	p_1 = c;
}

void field::setPlayer2(character* c) {
	p_2 = c;
}

character* field::getPlayer1() {
	return p_1;
}

character* field::getPlayer2() {
	return p_2;
}

void field::reset() {
	//TODO:
}

void field::setBackground(const rectangle& b) {
	background = b;
}

void field::setGravity(const vector& g) {
	gravity = g;
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

void field::update() {

	vector sum_move = { 0, 0 };
	vector sum_push = { 0, 0 };
	vector *normal = new vector(0, 0);
	vector *move = new vector(0, 0);
	int *dir = new int;

	//player_1
	p_1->push(gravity);
	for (int j = 0; j < platforms->length(); j++) {
		normal = new vector(0, 0);
		move = new vector(0, 0);
		dir = new int;
		p_1->collidesWith(*platforms->get(j), normal, move, dir);
		sum_move += *move;
		sum_push += *normal;
	}
	p_1->push(sum_push);
	p_1->move(sum_move);
	p_1->update();
	if (p_1->collidesWith(p_2->attack, nullptr, nullptr, nullptr) && p_2->attack.exists) {
		p_1->hit(p_2);
	}

	sum_move = { 0, 0 };
	sum_push = { 0, 0 };

	//player_2
	p_2->push(gravity);
	for (int j = 0; j < platforms->length(); j++) {
		normal = new vector(0, 0);
		move = new vector(0, 0);
		dir = new int;
		p_2->collidesWith(*platforms->get(j), normal, move, dir);
		sum_move += *move;
		sum_push += *normal;
	}
	p_2->push(sum_push);
	p_2->move(sum_move);
	p_2->update();
	if (p_2->collidesWith(p_1->attack, nullptr, nullptr, nullptr) && p_1->attack.exists) {
		p_2->hit(p_1);
	}
}

void field::draw(SDL_Renderer* renderer) {
	background.draw(renderer);
	p_1->draw(renderer);
	p_1->attack.draw(renderer);
	p_2->draw(renderer);
	p_2->attack.draw(renderer);
	for (int i = 0; i < platforms->length(); i++) {
		platforms->get(i)->draw(renderer);
	}
}

//k: hello
//hello