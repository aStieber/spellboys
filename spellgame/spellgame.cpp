// spellgame.cpp : Defines the entry point for the console application.
//
#include <SFML\Graphics.hpp>
#include "graphics.h"
#include "game.h"


#include "vector2D.h"
int main() {
	game game;
	sf::RenderWindow window;
	window.setFramerateLimit(120);
	graphics graphics(&game, &window);
	graphics.runGraphicsLoop();
    return 0;
}

