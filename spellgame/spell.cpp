#include "spell.h"
#include "game.h"
#include "helpers.h"

spell::spell() {}

sf::Vector2f spell::getPosition() {
	return (Effects.back().Location);
}

sf::Shape* spell::getShape() {
	return (&Effects.back().Shape);
}

damageType spell::getDamageType () {
	return (Effects.back().Damage.type);
}

bool spell::Advance() { //returns true if still active
	effect& e = Effects.back();
	bool isAlive = true;

	switch (e.movementType) {
	case effectMovementType::STATIONARY:
		isAlive &= advance_STATIONARY(e);
		break;
	case effectMovementType::LINEAR:
		isAlive &= advance_LINEAR(e);
		break;
	default:
		break;
	}

	if (!isAlive) {
		Effects.pop_back();
	}
	return (Effects.size() > 0);
}

bool spell::advance_STATIONARY(effect& e) { //returns true if still active
	return(!e.isExpired());
}

bool spell::advance_LINEAR(effect& e) { //returns true if still active
	sf::Vector2f newLoc = e.Location;
	newLoc.x += e.movementVector.x;
	newLoc.y += e.movementVector.y;

	float prevDist = getDistanceBetweenPoints(e.Location, e.Target.Location);
	float newDist = getDistanceBetweenPoints(newLoc, e.Target.Location);
	if (newDist < prevDist) {
		e.Location = newLoc;
		return true;
	}
	return false;
}

bool spell::advance_CURVED(effect& e) { //returns true if still active
	return true;
}

bool spell::advance_TRACKING(effect& e) { //returns true if still active
	return true;
}
