#include "boy.h"


boy::boy() {

}

boy::boy(sf::Vector2f startingLocation, float startingHealth) {
	health = startingHealth;
	location = startingLocation;
	moment = vector2D(0., 0.);
}

void boy::applyMovement(std::vector<sf::Keyboard::Key>& keys) {
	if (keys.size() > 0) {
		vector2D backup = moment;
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

		
		if (moment > maxSpeed)//can't increase magnitude if magnitude is larger than max
			moment = backup;//change this to reduce magnitude by appropriate amount instead
	}
}

void boy::applyFriction() {
	moment.x = (1 - friction) * moment.x;
	moment.y = (1 - friction) * moment.y;
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

spell boy::castSelectedSpell(sf::Vector2f mousePos) {
	//selected spell is fireball
	target t(mousePos);

	spell fireball = getFireball();
	fireball.Target = t;
	return fireball;
}

spell boy::getFireball() {
	spell fireball = spell();
	effect e = effect();
	e.Damage = damage(100, damageType::fire);
	e.Shape = sf::CircleShape(5, 100);
	e.setDuration(5.);
	fireball.Effects.emplace_back(e);
	return(fireball);
}