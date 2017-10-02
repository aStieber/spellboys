#pragma once
#include <chrono>
#include <SFML\Graphics.hpp>
#include "damage.h"
#include "target.h"
#include "vector2D.h"
enum effectMovementType { STATIONARY, LINEAR, CURVED, TRACKING };

class effect {
public:
	effect();
	
	void setDuration(float d);
	bool isExpired();

	damage Damage;
	sf::CircleShape Shape;
	sf::Vector2f Location;
	target Target;
	vector2D movementVector;
	effectMovementType movementType;
	
private:
	std::chrono::milliseconds Timer_End; //seconds

};
