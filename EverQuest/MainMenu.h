#pragma once
#include "GameState.h"



class TileMap;
class MainMenu : public GameState
{
public:
	MainMenu();
	MainMenu(GameEngine * game);
	~MainMenu();
	void init();
	void cleanup();

	void pause();
	void resume();

	void HandleEvents(GameEngine *game);
	void Update(GameEngine *game);
	void Draw(GameEngine* game);
private:
	void print();
	TileMap *tileMap;


	sf::View view1;
};

