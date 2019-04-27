#include "TestLoops.h"
#include "AnimationLoader.h"
#include "Animation.h"
#include "AnimatedSprite.h"
void TestAnimationLoop()
{

	sf::RenderWindow window(sf::VideoMode(100, 100), "test");
	sf::Sprite player;
	sf::Texture *pTexture = new sf::Texture;
	
	pTexture->loadFromFile("Assets/spritesheets/testSheet.png");
	AnimationLoader aloader;
	AnimatedSprite as;
	aloader.loadAnimationsFromFile(as, "hero.txt");

	

	
	float deltaTime;
	float totalTime = 0.0f;
	sf::Clock clock;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();// Process events
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

			// Escape key: exit
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
				as.switchAnimation("WalkRight");

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
				as.switchAnimation("WalkLeft");

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
				as.switchAnimation("WalkUp");

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
				as.switchAnimation("WalkDown");
			// Resize event: adjust the viewport
			if (event.type == sf::Event::Resized);

		}
		
		as.sprite.setTextureRect(as.getCurrentFrame());
		window.clear();

		as.Update(deltaTime);
		



		player.setTextureRect(as.getCurrentFrame());
		window.draw(as.getSprite());
		// Finally, display the rendered frame on screen
		window.display();
		
	}
}