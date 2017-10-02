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
	mSpellRenderTexture.create(mGameWindowWidth, mGameWindowHeight);
	mBackgroundRenderTexture.create(mGameWindowWidth, mGameWindowHeight);
	mBackgroundRenderTexture.clear(sf::Color(160, 200, 220));

	mFont.loadFromFile("Inconsolata-Regular.ttf");

#ifdef _DEBUG //debug gui setup
	ImGui::SFML::SetRenderTarget(*mMasterWindow);
	ImGui::SFML::InitImGuiRendering();
	ImGui::SFML::SetWindow(*mMasterWindow);
	ImGui::SFML::InitImGuiEvents();
#endif // DEBUG	
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
			controls c = controls(pixelsToMeters((sf::Vector2f)sf::Mouse::getPosition(*mMasterWindow) - mGameRenderOffsetFromMaster));
			mGame->runPhysicsFrame(c);

			sf::Event event;
			while (mMasterWindow->pollEvent(event)) {
				if (event.type == sf::Event::Closed) { mMasterWindow->close(); exit(0); }
			}
			gameTimeAcc -= gameInterval;
#ifdef _DEBUG
			ImGui::SFML::ProcessEvent(event);
			ImGuiIO &io = ImGui::GetIO();
			bool tmp = true;
			ImGui::NewFrame();
			ImGui::Begin("window", &tmp);
			ImGui::Text("Hello, world!");
			ImGui::Button("Is this working?!");
			ImGui::End();
			ImGui::Render();
#endif
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
	//SPELLS
	updateSpellRenderTexture();
	sf::Sprite spellTextureSprite(mSpellRenderTexture.getTexture());
	spellTextureSprite.setPosition(mGameRenderOffsetFromMaster);
	mMasterWindow->draw(spellTextureSprite);

	mMasterWindow->display();
	windowRefreshTimeAcc -= windowRefreshInterval;
}

sf::Shape* graphics::resizeShapeForGraphics(sf::Shape* shape) {
	return shape;
	//copy abstract base class?
	//resize and set circle at center
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

sf::CircleShape graphics::getBall(float rad) {
	sf::CircleShape circle;
	circle.setRadius(rad);
	circle.setOutlineThickness(10 / -8);
	circle.setOutlineColor(sf::Color(12, 12, 12));
	sf::Vector2f center(rad / 2, rad / 2);
	circle.setOrigin(center);

	return(circle);
}

void graphics::updateHeroRenderTexture() {
	mHeroRenderTexture.clear(sf::Color::Transparent);

	sf::CircleShape heroShape = getBall(10);
	heroShape.setFillColor(sf::Color(255, mGame->theBoy.health * 2.55, 150));
	heroShape.setPosition(metersToPixels(mGame->theBoy.location));
	mHeroRenderTexture.draw(heroShape);

	mHeroRenderTexture.display();
}

void graphics::updateSpellRenderTexture() {
	mSpellRenderTexture.clear(sf::Color::Transparent);
	
	for (spell& s : mGame->activeSpells) {
		sf::Shape* shape = resizeShapeForGraphics(s.getShape());
		shape->setPosition(metersToPixels(s.getPosition()));
		shape->setFillColor(DAMAGE_COLOR_MAP.find(s.getDamageType())->second);
		mSpellRenderTexture.draw(*shape);
	}

	mSpellRenderTexture.display();
}