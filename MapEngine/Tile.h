#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Tile
{
public:
	
	Tile(int id = 0, bool pass = 1);
	~Tile();

	int getId() { return tileId; };
	int getPassable() { return passable; };
	
	void setId(int nId) { tileId = nId; };
	void setPassable(bool nPass) { passable = nPass; };

private:
	int tileId;
	bool passable;
};



