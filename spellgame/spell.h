#pragma once
#include <vector>
#include <SFML\System.hpp>
#include "effect.h"
#include "damage.h"

class target { //information about movement of spell
public:
	target();
	target(sf::Vector2f location);
	//boy targetBoy;
	sf::Vector2f targetLocation;
};

class spell {
public:
	spell();
	spell(target t);

	bool Advance();
	target Target;
	std::vector<effect> Effects;

	sf::Vector2f getPosition();
};