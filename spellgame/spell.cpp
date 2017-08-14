#include "spell.h"

target::target() {}
spell::spell() {}

spell::spell(target t) {
	Target = t;
}

target::target(sf::Vector2f location) {
	targetLocation = location;
}

bool spell::Advance() { //returns true if still active
	//do stuff
	effect& e = Effects.back();
	e.Position = Target.targetLocation;
	if (e.isExpired()) {
		Effects.pop_back();
		return false;
	}
	return (Effects.size() > 0);
}

sf::Vector2f spell::getPosition() {
	return (Effects[0].Position);
}