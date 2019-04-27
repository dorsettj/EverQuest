#include "Animation.h"

#include <iostream>
#include <exception>
#include <thread>

Animation::Animation(float changeTime, sf::Texture *texture)
{
	this->mpSpriteSheet = texture;
	totalTime = 0.0;
	currentFrame = 0;
	totalFrames = 0;
	this->changeTime = changeTime;
}

sf::IntRect Animation::getCurrentSquare()
{
	try 
	{
		return this->frames.at(currentFrame);
	}
	catch (std::exception &e)
	{
		std::cout << "There are no frames";
	}
	return sf::IntRect(-1, -1, -1, -1);
}
void Animation::addFrame(sf::IntRect frameBounds) 
{ 
	frames.push_back(frameBounds); 
	totalFrames = frames.size();
}

sf::IntRect Animation::getFrame(int index)
{
	try 
	{
		return frames.at(index);
	}
	catch (std::exception &e)
	{
		std::cout << "index out of bounds";
	}

}

void Animation::Update(float deltaTime) 
{
	
		totalTime += deltaTime;
		if (totalTime >= changeTime)
		{
			totalTime -= changeTime;
			currentFrame = (currentFrame + 1) % totalFrames;
		}
	
}

void Animation::reset()
{
	totalTime = 0;
	currentFrame = 0;
}
