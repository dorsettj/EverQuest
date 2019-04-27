#pragma once
#include <SFML/Graphics.hpp>
#include "rapidjson/document.h"
#include <string>
class TileSet
{
public:

	sf::Texture mTexture;
	TileSet(char *json);
	~TileSet();
	sf::Texture & getTexture();
	int getColumns() { return columns; };
	int getTileSize() { return tileSize.y; };

private:
	
	sf::Vector2i tileSize;
	int columns;
	char *json;
	rapidjson::Document d;

	void loadImage(std::string fileName);
	void setTileSize();
};

