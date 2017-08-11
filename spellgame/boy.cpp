#include "boy.h"


boy::boy() {

}

boy::boy(sf::Vector2f startingLocation, float startingHealth) {
	health = startingHealth;
	location = startingLocation;
	moment = vector2D(0., 0.);
}

void boy::applyMovement(std::vector<sf::Keyboard::Key>& keys) {
	for (sf::Keyboard::Key& k : keys) {
		if (k == sf::Keyboard::Right) {
			moment += vector2D(pushSpeed, 0.);
		}
		else if (k == sf::Keyboard::Left) {
			moment += vector2D(-pushSpeed, 0.);

		}
		else if (k == sf::Keyboard::Up) {
			moment += vector2D(0., -pushSpeed);

		}
		else if (k == sf::Keyboard::Down) {
			moment += vector2D(0., pushSpeed);
		}
	}
	
	float magnitude = moment.getMagnitude();
	if (magnitude > maxSpeed) {
		moment.scale(maxSpeed / magnitude);
	}
}

void boy::applyFriction() {
	moment.x = (1 - friction) * moment.x;
	moment.y = (1 - friction) * moment.y;
	/*
	if (abs(moment.x) < .1) 
		moment.x = 0;

	if (abs(moment.y) < .1)
		moment.y = 0;
	*/
}

void boy::applyMoment(sf::Vector2i& maxSize) {
	location.x += moment.x;
	location.y += moment.y;

	if (location.x <= 0
		|| location.x >= maxSize.x) {
		moment.x *= (-1 * (1 - friction));
		location.x = location.x <= 0 ? 0 : maxSize.x;
	}
	if (location.y <= 0
		|| location.y >= maxSize.y) {
		moment.y *= (-1 * (1 - friction));
		location.y = location.y <= 0 ? 0 : maxSize.y;
	}

}