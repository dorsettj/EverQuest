#pragma once
#include "AnimatedSprite.h"
#include <fstream>
class AnimationLoader
{
public:
	AnimationLoader() {};
	void loadAnimationsFromFile(AnimatedSprite &as, std::string filePath);
	
private:
	std::ifstream reader;
	AnimatedSprite *animSprite;
	std::string filePath;
	void readTexture();
	void readFrames();

};