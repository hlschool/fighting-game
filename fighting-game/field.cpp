#include "field.h"
#include "rectangle.h"
#include "obj.h"

field::field() {
	l = new unorderedLinkedList<obj*>;
	background.fixed = true;
}

void field::add(obj* o) {
	l->insertFirst(o);
}

int field::objects() {
	return l->length();
}

void field::setBackground(const rectangle& b) {
	background = b;
}

void field::setGravity(const vector& g) {
	gravity = g;
}

void field::update() {
	for (int i = 0; i < objects(); i++) {
		l->get(i)->push(gravity);
		l->get(i)->update();
	}
}

void field::draw(SDL_Renderer* renderer) {
	background.draw(renderer);
	for (int i = 0; i < objects(); i++) {
		l->get(i)->draw(renderer);
	}
}