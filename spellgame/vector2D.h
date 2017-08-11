#pragma once

class vector2D {
public:
	float x;
	float y;
	
	float getMagnitude();
	void scale(float x);
	vector2D();
	vector2D(float _x, float _y);
	vector2D operator+ (const vector2D& vec);
	vector2D operator+= (const vector2D& vec);
	vector2D operator- (const vector2D& vec);
	vector2D operator-= (const vector2D& vec);
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

