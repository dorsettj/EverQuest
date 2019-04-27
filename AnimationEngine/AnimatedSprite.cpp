#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::Texture *nTexture)
{
	this->SpriteSheetTexture = nTexture;
}

void AnimatedSprite::setAnimation(const std::string &key, Animation value) 
{ 
	if (animations.size() == 0) this->currentAnimation = key;
	//value.setSpriteSheetPtr(*SpriteSheetTexture);
	animations[key] = value;
	
}

void AnimatedSprite::switchAnimation(std::string newAnimation)
{
	if (this->animations.count(newAnimation) && newAnimation != currentAnimation)
	{
		animations[currentAnimation].reset();
		currentAnimation = newAnimation;
	}
}
void AnimatedSprite::loadTextureFromFile(const std::string &filePath) 
{ 
	SpriteSheetTexture->loadFromFile(filePath); 
}