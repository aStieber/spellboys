#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class controls {
public:
	controls();
	controls(sf::Vector2f _mousePos);
	std::vector<sf::Keyboard::Key> Keys;
	bool LMB;
	bool RMB;
	sf::Vector2f MouseMeterPos;
private:
	void clearVars();
};