#pragma once
#include <SFML\System.hpp>

class target {
public:
	target();
	target(sf::Vector2f location);
	//boy targetBoy; //for tracking
	sf::Vector2f Location;
};
