#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class controls {
public:
	controls();
	std::vector<sf::Keyboard::Key> mKeys;
	sf::Vector2i mMousePixelPos;
	bool mLMB;
	bool mRMB;
private:
	void clearVars();
};