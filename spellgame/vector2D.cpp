#pragma once
#include "vector2D.h"
#include <math.h>

vector2D::vector2D() {}

vector2D::vector2D(float _x, float _y) {
	x = _x;
	y = _y;
}

vector2D::vector2D(sf::Vector2f source, sf::Vector2f target, float magnitude) {
	float x_0 = target.x - source.x;
	float y_0 = target.y - source.y;

	float theta = atan2f(y_0, x_0);
	x = magnitude * cosf(theta);
	y = magnitude * sinf(theta);
}

float vector2D::getMagnitude() {
	return sqrtf((x * x) + (y * y));
}

void vector2D::scale(float z) {
	x *= z;
	y *= z;
}

vector2D vector2D::operator+(const vector2D& vec) {
	vector2D output = vector2D();
	output.x = this->x + vec.x;
	output.y = this->y + vec.y;
	return output;
}

vector2D vector2D::operator+=(const vector2D& vec) {
	*this = *this + vec;
	return(*this);
}

vector2D vector2D::operator-(const vector2D& vec) {
	vector2D output = vector2D();
	output.x = this->x - vec.x;
	output.y = this->y - vec.y;
	return output;
}

vector2D vector2D::operator-=(const vector2D& vec) {
	*this = *this - vec;
	return(*this);
}

bool vector2D::operator>(vector2D & vec) {
	return (this->getMagnitude() > vec.getMagnitude());
}

bool vector2D::operator>=(vector2D & vec) {
	return (this->getMagnitude() >= vec.getMagnitude());
}

bool vector2D::operator<(vector2D & vec) {
	return (this->getMagnitude() < vec.getMagnitude());
}

bool vector2D::operator<=(vector2D & vec) {
	return (this->getMagnitude() <= vec.getMagnitude());
}

bool vector2D::operator>(float & mag) {
	return (this->getMagnitude() > mag);
}

bool vector2D::operator>=(float & mag) {
	return (this->getMagnitude() >= mag);
}

bool vector2D::operator<(float & mag) {
	return (this->getMagnitude() < mag);
}

bool vector2D::operator<=(float & mag) {
	return (this->getMagnitude() <= mag);
}
