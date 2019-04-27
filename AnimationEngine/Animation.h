#pragma once
#include "SFML/Graphics.hpp"
#include <vector>




class Animation
{
public:

	Animation(float changeTime = .2, sf::Texture *texture = nullptr);

	int getFrameCount() { return frames.size(); };
	sf::Texture * getSpriteSheet() { return mpSpriteSheet; };
	sf::IntRect getCurrentSquare();


	void setSpriteSheetPtr(sf::Texture &texture) { mpSpriteSheet = &texture; };
	void setChangeTime(float newTime) { changeTime = newTime; };
	//plays animation for time in seconds
	void Update(float totaltime);

	void reset();
	//void play(bool isKeyPressed);


	void addFrame(sf::IntRect frameBounds);


	//functions for testing
	sf::IntRect getFrame(int index);
	
private: 
	sf::Texture *mpSpriteSheet;
	
	std::vector<sf::IntRect> frames;

	float totalTime;
	float changeTime;
	int currentFrame;
	int totalFrames;
};


