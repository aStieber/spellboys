#include "game.h"
#include "boy.h"
#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>

void game::reset() {
	sf::Vector2f startingLocation = sf::Vector2f(mBOARD_WIDTH / 2., mBOARD_HEIGHT / 2.);
	hero = boy(startingLocation, 100.);
}

game::game() {
    reset();
}

float game::getDistanceBetweenPoints(sf::Vector2f _a, sf::Vector2f _b) {
    return(sqrtf((_a.x - _b.x) * (_a.x - _b.x) + (_a.y - _b.y) * (_a.y - _b.y))); //pythagorean
}


bool game::runPhysicsFrame(controls c) {   
	hero.applyMovement(c.mKeys);
	hero.applyFriction();
	hero.applyMoment(sf::Vector2i(mBOARD_WIDTH, mBOARD_HEIGHT));



	return(true);
}