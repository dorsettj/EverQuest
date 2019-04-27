
#include "MainMenu.h"
#include "GameEngine.h"
#include "TileMap.h"
#include <iostream>

MainMenu::MainMenu()
{
}
MainMenu::MainMenu(GameEngine * game)
{
	getRefs(game);
	init();
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	 tileMap = new TileMap("testMap.json");

	 //setup view
	 view1.reset(sf::FloatRect(0, 0, 300, 300));
	 this->windowPtr->setView(view1);
}
void MainMenu::cleanup()
{

}

void MainMenu::pause()
{

}
void MainMenu::resume()
{

}

void MainMenu::HandleEvents(GameEngine *game)
{
	sf::RenderWindow *windowPtr = &(game->window);
	while (game->window.pollEvent(game->event)) {
		/*if (game->event.KeyPressed)
		{
			switch (game->event.key.code)
			{
			case Keyboard::Up:
				view1.move(0, 10);
				windowPtr->setView(view1);
				break;
			case Keyboard::Right:
				view1.move(10, 0);
				windowPtr->setView(view1);
				break;
			case Keyboard::Down:
				view1.move(0, -10);
				windowPtr->setView(view1);
				break;
			case Keyboard::Left:
				view1.move(-10, 0);
				windowPtr->setView(view1);
				break;
			}
		}*/
	}
}
void MainMenu::Update(GameEngine *game)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		view1.move(2, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		view1.move(0, -2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		view1.move(-2, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		view1.move(0, 2);
	}
	windowPtr->setView(view1);
}
void MainMenu::Draw(GameEngine* game)
{
	
	game->window.draw(*tileMap);
	
}



void MainMenu::print()
{
	std::cout << "Hello World";
}