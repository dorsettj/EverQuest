#pragma once
#include "SFML/Graphics.hpp"

#include "rapidjson/document.h"
#include "Tile.h"
#include "TileSet.h"
#include <fstream>
using namespace::sf;
class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap(std::string mapName);
	~TileMap();

	sf::Vector2i getTileSize() { return this->tileSize; };
	Tile getMapTile(int x, int y) { return tMap[y][x]; };
	

	
		

private:
	Tile **tMap; //map of tiles
	TileSet *tileset;

	VertexArray *renderTiles;
	//properties
	sf::Vector2i tileSize;
	sf::Vector2i mapSize;
	enum { chunksize = 32 };
	//chunksize
	virtual void draw(RenderTarget &target, RenderStates states) const;
	

	//json reader stuff
	char *json;
	rapidjson::Document d;
	bool openJson(std::string fileName);
	
	void parseJson();
	void setTileSize();
	void getMapSize();
	void setTMap();
	
	void initVertexArray();
	void loadTextures();
	void setTileTexture(sf::VertexArray &array, int x, int y);
	void setTextureCoords(sf::VertexArray &array, int id);

	//detetion functions
	void deleteTMap();
	
};

