#pragma once
#include <SFML\Graphics.hpp>
#include "vector2D.h"
#include "spell.h"

class boy {
public:
	boy();
	boy(sf::Vector2f startingLocation, float startingHealth);

	float friction = .01;
	float pushSpeed = .0008;
	float maxSpeed = .14;

	float health;

	sf::Vector2f location;

	void applyMovement(std::vector<sf::Keyboard::Key>& keys);
	vector2D moment;
	void applyFriction();
	void applyMoment(sf::Vector2i& maxSize);

	spell castSelectedSpell(sf::Vector2f mousePos);

private:
	spell getFireball(target t);
};