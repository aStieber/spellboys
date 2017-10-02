#include "game.h"
#include "boy.h"
#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>

void game::reset() {
	sf::Vector2f startingLocation = sf::Vector2f(mBOARD_WIDTH / 2., mBOARD_HEIGHT / 2.);
	theBoy = boy(startingLocation, 100.);
}

game::game() {
    reset();
}

bool game::runPhysicsFrame(controls c) {
	//theBoy movement
	theBoy.applyMovement(c.Keys);
	theBoy.applyFriction();
	theBoy.applyMoment(sf::Vector2i(mBOARD_WIDTH, mBOARD_HEIGHT));
	//theBoy action
	if (c.LMB) {
		if (!LMB_clicked) {
			activeSpells.emplace_back(theBoy.castSelectedSpell(c.MouseMeterPos));
			LMB_clicked = true;
		}
	}
	else LMB_clicked = false;
	if (c.RMB) {
		if (!RMB_clicked) {
			RMB_clicked = true;
		}
	}
	else RMB_clicked = false;
	//Run spells
	std::vector<int> doomedIndexes = std::vector<int>();
	for (int i = 0; i < activeSpells.size(); i++) {
		if (!activeSpells[i].Advance()) {			
			doomedIndexes.emplace_back(i);
		}
	}
	for (int i : doomedIndexes) {
		activeSpells.erase(activeSpells.begin() + i);
	}

	return(true);
}