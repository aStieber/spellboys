#pragma once
#include "vector2D.h"
#include <math.h>

vector2D::vector2D() {

}

vector2D::vector2D(float _x, float _y) {
	x = _x;
	y = _y;
}

float vector2D::getMagnitude() {
	return sqrtf((x * x) + (y * y));
}

void vector2D::scale(float z) {
	x *= z;
	y *= z;
}

vector2D vector2D::operator+(const vector2D & vec) {
	vector2D output = vector2D();
	output.x = this->x + vec.x;
	output.y = this->y + vec.y;
	return output;
}

vector2D vector2D::operator+=(const vector2D & vec) {
	*this = *this + vec;
	return(*this);
}

vector2D vector2D::operator-(const vector2D & vec) {
	vector2D output = vector2D();
	output.x = this->x - vec.x;
	output.y = this->y - vec.y;
	return output;
}

vector2D vector2D::operator-=(const vector2D & vec) {
	*this = *this - vec;
	return(*this);
}