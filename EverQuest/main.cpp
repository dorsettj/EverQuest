#include "GameEngine.h"
#include "GUIManager.h"
#include "TileMap.h"


#include "TestLoops.h"
#include "RunTests.h"
int main()
{
	


	TestAnimationLoop();
	sf::Clock clock;
	clock.restart();
	
	
	std::cout << clock.getElapsedTime().asSeconds();
	
	GameEngine game;
	//init gameEngine
	game.init();
	

	//runGameLoop
	while (game.window.isOpen())
	{
		//handle Events
		game.peekState()->HandleEvents(&game);
		game.window.clear();
		game.peekState()->Update(&game);
		game.peekState()->Draw(&game);
		
		game.window.display();
	}

	return 0;
}