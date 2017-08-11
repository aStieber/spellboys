#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "game.h"
#include "controls.h"

#define DEBUG 1

class graphics {
public:
    graphics();
    graphics(game* _game, sf::RenderWindow* _rW);

    void runGraphicsLoop();
    game* mGame;


private:
    const int mMasterWindowWidth = 1000;
    const int mMasterWindowHeight = 800;

    const int mGameWindowWidth = 800;
    const int mGameWindowHeight = 600;

    const sf::Time gameInterval = sf::milliseconds(8);
    const sf::Time windowRefreshInterval = sf::milliseconds(8);

    sf::RenderWindow* mMasterWindow;
    sf::RenderTexture mHeroRenderTexture;
    sf::RenderTexture mBackgroundRenderTexture;
    sf::Vector2f mGameRenderOffsetFromMaster;

	void updateHeroRenderTexture();
	sf::CircleShape getBall();


	sf::Vector2f metersToPixels(sf::Vector2f _meterPos);
	sf::Vector2f pixelsToMeters(sf::Vector2f _pixelPos);
    void updateWindow(sf::Time& windowRefreshTimeAcc);
    sf::Font mFont;
};
