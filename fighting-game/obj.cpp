#include "obj.h"

obj::obj() { }

void obj::push(const vector& force) {
	if (!fixed) {
		acc += force;
	}
}

void obj::move(const vector& v) {
	if (!fixed) {
		pos += v;
	}
}

void obj::moveTo(const vector& v) {
	pos = v;
}

