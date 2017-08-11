#include "graphics.h"
#include <time.h>
#include <stdio.h>

graphics::graphics() {}

graphics::graphics(game* _game, sf::RenderWindow* _rW) {
    mMasterWindow = _rW;
    mMasterWindow->create(sf::VideoMode(mMasterWindowWidth, mMasterWindowHeight), "make the bubbles gone", sf::Style::Close);
    mGameRenderOffsetFromMaster = sf::Vector2f((mMasterWindowWidth - mGameWindowWidth) / 2, (mMasterWindowHeight - mGameWindowHeight) / 2);
    mGame = _game;

	mHeroRenderTexture.create(mGameWindowWidth, mGameWindowHeight);
    mBackgroundRenderTexture.create(mGameWindowWidth, mGameWindowHeight);
    mBackgroundRenderTexture.clear(sf::Color(160, 200, 220));

    mFont.loadFromFile("Inconsolata-Regular.ttf");
}

void graphics::runGraphicsLoop() {
    sf::Clock clock;
    sf::Time gameTimeAcc;
    sf::Time windowRefreshTimeAcc;
    bool justReset = false;

    while (true) {
        sf::Time t = clock.restart();
        gameTimeAcc += t;
        windowRefreshTimeAcc += t;
        while (gameTimeAcc >= gameInterval) {
			controls c = controls();
			mGame->runPhysicsFrame(c);

			sf::Event event;
			while (mMasterWindow->pollEvent(event)) {
				if (event.type == sf::Event::Closed) { mMasterWindow->close(); exit(0); }
			}
            gameTimeAcc -= gameInterval;
        }
        if (windowRefreshTimeAcc >= windowRefreshInterval) { 
			updateWindow(windowRefreshTimeAcc); 
		}
    }

}

void graphics::updateWindow(sf::Time& windowRefreshTimeAcc) {
    mMasterWindow->clear(sf::Color(20, 20, 20));
	//BACKGROUND
    sf::Sprite backgroundSprite(mBackgroundRenderTexture.getTexture());
    backgroundSprite.setPosition(mGameRenderOffsetFromMaster);
    mMasterWindow->draw(backgroundSprite);
	//HERO
	updateHeroRenderTexture();
	sf::Sprite heroTextureSprite(mHeroRenderTexture.getTexture());
	heroTextureSprite.setPosition(mGameRenderOffsetFromMaster);
	mMasterWindow->draw(heroTextureSprite);

    mMasterWindow->display();
    windowRefreshTimeAcc -= windowRefreshInterval;
}

sf::Vector2f graphics::metersToPixels(sf::Vector2f _meterPos) {
	float x_ratio = (float)mGameWindowWidth / mGame->mBOARD_WIDTH;
	float y_ratio = (float)mGameWindowHeight / mGame->mBOARD_HEIGHT;

	return(sf::Vector2f(_meterPos.x * x_ratio, _meterPos.y * y_ratio));
}

sf::Vector2f graphics::pixelsToMeters(sf::Vector2f _pixelPos) {
	float x_ratio = mGame->mBOARD_WIDTH / (float)mGameWindowWidth;
	float y_ratio = mGame->mBOARD_HEIGHT / (float)mGameWindowHeight;

	return(sf::Vector2f(_pixelPos.x * x_ratio, _pixelPos.y * y_ratio));
}

sf::CircleShape graphics::getBall() {
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setOutlineThickness(10 / -8);
	circle.setOutlineColor(sf::Color(12, 12, 12));
	sf::Vector2f center(5, 5);
	circle.setOrigin(center);

	return(circle);
}

void graphics::updateHeroRenderTexture() {
	mHeroRenderTexture.clear(sf::Color::Transparent);

	sf::CircleShape heroShape = getBall();
	heroShape.setFillColor(sf::Color(255, mGame->hero.health * 2.55, 150));
	heroShape.setPosition(metersToPixels(mGame->hero.location));
	mHeroRenderTexture.draw(heroShape);

	mHeroRenderTexture.display();
}