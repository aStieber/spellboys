#pragma once
#include <SFML\System.hpp>

class vector2D {
public:
	float x;
	float y;
	
	float getMagnitude();
	void scale(float x);
	vector2D();
	vector2D(float _x, float _y);
	vector2D(sf::Vector2f source, sf::Vector2f target, float magnitude);
	vector2D operator+ (const vector2D& vec);
	vector2D operator+= (const vector2D& vec);
	vector2D operator- (const vector2D& vec);
	vector2D operator-= (const vector2D& vec);
	bool operator> (vector2D& vec);
	bool operator>= (vector2D& vec);
	bool operator< (vector2D& vec);
	bool operator<= (vector2D& vec);
	bool operator> (float& mag);
	bool operator>= (float& mag);
	bool operator< (float& mag);
	bool operator<= (float& mag);
private:


	/*
Default construction
Construction from components
access to individual components (possibly in non-cartesian representations too)
vector-vector addition and subtraction
Scalar multiplication or "scaling"
vector-vector Scalar or dot product
vector-vector Vector or cross product
"Magnitude" or "length"
	*/

};

