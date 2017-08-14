#pragma once
#include "damage.h"
#include <chrono>
#include <SFML\Graphics.hpp>
class effect {
public:
	effect();
	
	void setDuration(float d);
	bool isExpired();

	damage Damage;
	sf::CircleShape Shape;
	sf::Vector2f Position;
	
private:
	std::chrono::milliseconds Timer_End; //seconds

};
