#pragma once
#include <SFML\Graphics.hpp>
#include "vector2D.h"

class boy {
public:
	boy();
	boy(sf::Vector2f startingLocation, float startingHealth);

	float friction = .01;
	float pushSpeed = .01;
	float maxSpeed = .1;

	float health;

	sf::Vector2f location;
	vector2D moment;

	void applyMovement(std::vector<sf::Keyboard::Key>& keys);
	void applyFriction();
	void applyMoment(sf::Vector2i& maxSize);
	


};