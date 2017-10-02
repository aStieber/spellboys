#pragma once
#include <vector>
#include <SFML\System.hpp>
#include "effect.h"
#include "damage.h"

class spell {
public:
	spell();

	bool Advance();
	std::vector<effect> Effects;

	sf::Vector2f getPosition();
	sf::Shape* getShape();
	damageType getDamageType();
private:
	bool advance_STATIONARY(effect& e);
	bool advance_LINEAR(effect& e);
	bool advance_CURVED(effect& e);
	bool advance_TRACKING(effect& e);
};