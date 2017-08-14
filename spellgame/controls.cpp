#include "controls.h"

controls::controls() {}

controls::controls(sf::Vector2f _mousePos) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		Keys.emplace_back(sf::Keyboard::Up);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		Keys.emplace_back(sf::Keyboard::Right);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		Keys.emplace_back(sf::Keyboard::Down);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		Keys.emplace_back(sf::Keyboard::Left);
	}

	MouseMeterPos = _mousePos;
	LMB = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	RMB = sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

void controls::clearVars() {
	Keys.clear();
	MouseMeterPos = sf::Vector2f();
	LMB = RMB = false;
}