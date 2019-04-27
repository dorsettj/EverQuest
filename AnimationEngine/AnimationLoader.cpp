#include "AnimationLoader.h"
#define BUFFER_SIZE 50
void AnimationLoader::loadAnimationsFromFile(AnimatedSprite &as, std::string filePath)
{
	reader.open(filePath);

	reader.is_open();
	animSprite = &as;
	this->filePath = filePath;

	readTexture();
	readFrames();

	reader.close();
}

void AnimationLoader::readTexture()
{
	char line[BUFFER_SIZE] = "";
	reader.getline(line,BUFFER_SIZE);
	if (animSprite->getTexturePtr() == nullptr) {
		animSprite->setTexture(new sf::Texture);
		animSprite->loadTextureFromFile(line);
		animSprite->setSpriteTexture();
	}
}
void AnimationLoader::readFrames()
{
	int x, y, width, height,frameCount = 0;
	std::string key;
	float changeTime;
	while (!reader.eof())
	{
		Animation a;
		reader >> key;
		reader >> frameCount;
		reader >> changeTime;
		a.setChangeTime(changeTime);
		for (int i = 0; i < frameCount; i++)
		{
			reader >> x >> y >> width >> height;
			sf::IntRect rect(x, y, width, height);
			a.addFrame(rect);
		}
		animSprite->setAnimation(key, a);
		
	}
}