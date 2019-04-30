#ifndef VECTOR_H
#define VECTOR_H

class vector {
public:
	float x;
	float y;

	float mag();
	float dir();

	void rotate(float);

	vector& operator+(const vector&) const;
	vector& operator*(float) const;

	void operator=(const vector&);
	void operator+=(const vector&);
	void operator*=(float);

	vector(float, float);
};

#endif