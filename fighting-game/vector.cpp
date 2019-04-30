#include "vector.h"
#include <cmath>

float vector::mag() {
	return hypot(x, y);
}

float vector::dir() {
	return atan2(y, x);
}

vector& vector::operator+(const vector& v) const {
	vector new_vec = { x + v.x, y + v.y};
	return new_vec;
}

vector& vector::operator*(float s) const {
	vector new_vec = { x * s, y * s };
	return new_vec;
}

void vector::operator=(const vector& v) {
	x = v.x;
	y = v.y;
}

void vector::operator+=(const vector& v) {
	x += v.x;
	y += v.y;
}

void vector::operator*=(float s) {
	x *= s;
	y *= s;
}

vector::vector(float a, float b) {
	x = a;
	y = b;
}