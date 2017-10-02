#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "controls.h"
#include "boy.h"
#include "spell.h"


class game {
public:
    game();
    const float mBOARD_WIDTH = 100;
    const float mBOARD_HEIGHT = 75;
    bool runPhysicsFrame(controls c);
    void reset();
	boy theBoy;
	std::vector<boy> boys;
	std::vector<spell> activeSpells;

private:
	bool LMB_clicked = false;
	bool RMB_clicked = false;
};

