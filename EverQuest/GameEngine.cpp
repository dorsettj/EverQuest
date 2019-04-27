#include "GameEngine.h"

void GameEngine::init()
{
	createWindow(800, 1, "Test");
	window.setVerticalSyncEnabled(true);
	pushState(new MainMenu(this));
}

void GameEngine::pushState(GameState *nState)
{
	states.push_back(nState);
}
GameState * GameEngine::peekState()
{
	return states[states.size() - 1];
}
void GameEngine::popState()
{
	states.pop_back();
}
void GameEngine::createWindow(int height, double Ratio, std::string name)
{
	float width = height * Ratio;
	int intWidth = width;
	window.create(sf::VideoMode(intWidth,height), name);
}

