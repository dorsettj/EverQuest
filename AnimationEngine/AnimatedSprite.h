#pragma once

#include "Animation.h"
#include <map>
#include <string>

using std::map;
class AnimatedSprite
{
public:
	//public data members
	sf::Sprite sprite;

	AnimatedSprite(sf::Texture *nTexture = nullptr);

	Animation getAnimation(std::string key) { return animations[key]; };
	sf::Texture *getTexturePtr() { return this->SpriteSheetTexture; };
	sf::Sprite getSprite() { return sprite; };

	void setAnimation(const std::string &key, Animation value);
	void setTexture(sf::Texture *nTexture) { SpriteSheetTexture = nTexture; };
	void setSpriteTexture() { sprite.setTexture(*SpriteSheetTexture); };

	void loadTextureFromFile(const std::string &filePath);

	void switchAnimation(std::string newAnimation);
	void Update(float deltaTime) { 
		animations[currentAnimation].Update(deltaTime);
		
	};
	sf::IntRect getCurrentFrame() { return animations[currentAnimation].getCurrentSquare(); };
	

private:
	sf::Texture *SpriteSheetTexture;//add getters and setters
	
	std::string currentAnimation;
	map<std::string, Animation> animations;
};