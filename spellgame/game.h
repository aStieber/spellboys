#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "controls.h"
#include "boy.h"


class game {
public:
    game();
    const float mBOARD_WIDTH = 100;
    const float mBOARD_HEIGHT = 75;
    bool runPhysicsFrame(controls c);
    void reset();
	boy hero;

private:

    float getDistanceBetweenPoints(sf::Vector2f _a, sf::Vector2f _b);
};

