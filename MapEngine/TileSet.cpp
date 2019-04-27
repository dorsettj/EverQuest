#include "TileSet.h"
#include <iostream>


TileSet::TileSet(char *json)
{
	this->json = json;
	d.Parse(this->json);
	const rapidjson::Value& tileset = d["tilesets"];
	setTileSize();
	loadImage(tileset[0]["image"].GetString());
	columns = (int)tileset[0]["columns"].GetInt();
}


TileSet::~TileSet()
{
}

sf::Texture & TileSet::getTexture()
{
	return this->mTexture;
	
}

void TileSet::loadImage(std::string fileName)
{
	mTexture.loadFromFile("Assets/tilesets/" + fileName);
	
}
void TileSet::setTileSize()
{
	int tileHeight = (int)d["tileheight"].GetInt();
	int tileWidth = (int)d["tilewidth"].GetInt();
	this->tileSize = sf::Vector2i(tileWidth, tileHeight);
}
