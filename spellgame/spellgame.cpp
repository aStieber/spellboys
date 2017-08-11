// spellgame.cpp : Defines the entry point for the console application.
//
#include <SFML\Graphics.hpp>

#include "graphics.h"
#include "game.h"


#include "vector2D.h"
int main()
{

	
	game aGame;
	sf::RenderWindow aWindow;
	graphics graphics(&aGame, &aWindow);
	graphics.runGraphicsLoop();
    return 0;
}

