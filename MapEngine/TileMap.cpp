#include "TileMap.h"
#include <iostream>
#include "SFML/System.hpp"

TileMap::TileMap(std::string mapName)
{
	tileset = nullptr;
	renderTiles = nullptr;
	if (openJson(mapName)) 
	{
		parseJson();
		setTileSize();
		getMapSize(); //gets size of map 
		setTMap(); //initializes tilemap
		tileset = new TileSet(json);

		
		initVertexArray();
		loadTextures();

		
	}
	else std::cout << mapName << " failed to open" << std::endl;
}


TileMap::~TileMap()
{
	delete json;
	deleteTMap();
}




bool TileMap::openJson(std::string mapName)
{
	
	std::ifstream in("Assets/maps/" + mapName);
	if (in.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(in)),
			std::istreambuf_iterator<char>());
		char *temp = new char[contents.length()];
		json = temp;
		
		strcpy(json, contents.c_str());
		return true;
	}
	return false;
}

void TileMap::parseJson()
{
	d.Parse(json);
	std::cout << sizeof(d);
}
void TileMap::setTileSize()
{
	int tileHeight = (int)d["tileheight"].GetInt();
	int tileWidth = (int)d["tilewidth"].GetInt();
	this->tileSize = sf::Vector2i(tileWidth, tileHeight);
}
void TileMap::getMapSize()
{
	//get width
	assert(d.HasMember("width"));
	assert((int)d["width"].IsInt());
	int width = (int)d["width"].GetInt();
	//retrieve height
	assert(d.HasMember("height"));
	assert((int)d["height"].IsInt());
	int height = (int)d["height"].GetInt();

	mapSize = sf::Vector2i(width, height);
	
}
void TileMap::draw(RenderTarget &target, RenderStates states) const
{
	states.transform *= getTransform();

	states.texture = &tileset->mTexture;

	for (int i = 0; i < this->mapSize.y;i++)
	{
		target.draw(renderTiles[i], states);
	}
	

		

	


}


void TileMap::setTMap()
{
	//allocate memory to the heap
	tMap = new Tile*[mapSize.y];
	for (int i = 0; i < mapSize.y; i++)
	{
		tMap[i] = new Tile[mapSize.x];
	}
	
	const rapidjson::Value& layers = d["layers"];
	assert(layers[0].HasMember("data"));
	assert(layers[0]["data"].IsArray());

	const rapidjson::Value& TileLayer = layers[0]["data"];

	//set refrence to passable layer
	assert(layers[1].HasMember("data"));
	assert(layers[1]["data"].IsArray());
	
	const rapidjson::Value& passableLayer = layers[1]["data"];

	for (int i = 0; i < mapSize.y; i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			tMap[i][j].setId((int)TileLayer[i*mapSize.y + j].GetInt());
			if ((int)TileLayer[i*mapSize.y + j].GetInt() != 0) tMap[i][j].setPassable(false);
		}
	}


	/*for (auto& v : data.GetArray())
	{
		
		tMap[i]setId((int)v.GetInt());
		i++;
	}*/
		
	
	
}
void TileMap::initVertexArray()
{
	renderTiles = new VertexArray[mapSize.y];
	for (int i = 0; i < mapSize.y; i++)
	{
		renderTiles[i] = sf::VertexArray(sf::Quads, 4 * mapSize.x);
	}
}

void TileMap::loadTextures()
{
	int size = mapSize.y*mapSize.x;
	for (int i = 0; i < (mapSize.y); i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			(renderTiles)[i][4 * j] = sf::Vector2f(j*tileSize.x, i*tileSize.y);
			(renderTiles)[i][4 * j + 3] = sf::Vector2f((j)*tileSize.x, (i+1)*tileSize.y);
			(renderTiles)[i][4 * j +2] = sf::Vector2f((j+1)*tileSize.x, (i+1)*tileSize.y);
			(renderTiles)[i][4 * j + 1] = sf::Vector2f((j+1)*tileSize.x, (i)*tileSize.y);
			int id = getMapTile(j, i).getId();
			if (id != 2)
			{
				std::cout << "pause";
			}
			int columns = tileset->getColumns();
			int size = tileset->getTileSize();
			float xPos = ((id - 1) % columns)*size;
			float yPos = ((id - (id%columns)) / columns)*size;
			renderTiles[i][4*j].texCoords = sf::Vector2f(xPos, yPos);
			renderTiles[i][4*j+1].texCoords = sf::Vector2f(xPos + tileset->getTileSize(), yPos);
			renderTiles[i][4*j+2].texCoords = sf::Vector2f(xPos + tileset->getTileSize(), yPos + tileset->getTileSize());
			renderTiles[i][4*j+3].texCoords = sf::Vector2f(xPos,yPos + tileset->getTileSize());
		}
		
			
			
	}
}
void TileMap::setTileTexture(sf::VertexArray &array, int x, int y)
{
	//set the position of the tile
	array[0] = sf::Vector2f(x*tileSize.x, y*(tileSize.y));
	array[1] = Vector2f((x + 1)*tileSize.x, y*(tileSize.y));
	array[2] = Vector2f(x*(tileSize.x), (y + 1)*(tileSize.y));
	array[3] = Vector2f((x + 1)*(tileSize.x), (y + 1)*tileSize.y);
	int id = tMap[y][x].getId();
	setTextureCoords(array, id);

}

void TileMap::setTextureCoords(sf::VertexArray &array, int id)
{
	
}

void TileMap::deleteTMap()
{
	for (int i = 0; i < mapSize.y; i++)
	{
		delete tMap[i];
	}
	delete tMap;
}