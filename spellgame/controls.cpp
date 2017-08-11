#include "controls.h"

controls::controls() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		mKeys.emplace_back(sf::Keyboard::Up);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		mKeys.emplace_back(sf::Keyboard::Right);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		mKeys.emplace_back(sf::Keyboard::Down);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		mKeys.emplace_back(sf::Keyboard::Left);
	}
}

void controls::clearVars() {
	mKeys.clear();
	mMousePixelPos = sf::Vector2i();
	mLMB = mRMB = false;
}