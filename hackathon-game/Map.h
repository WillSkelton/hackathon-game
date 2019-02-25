#pragma once
#include "MapElement.h"
#include "Player.h"
#include <time.h>
#include <math.h>


class Map {
public:
	
	// CTORs
	Map();
	

	// DTOR
	~Map();
	
	// Fill Map
	void fillMap(Map *map);

	//moves the player if the next tile can be moved from
	bool move(char direction);

	// Map
	MapElement grid[10][10];

	// Start and Finish Indices
	int startIndex[2];
	int endIndex[2];

	// Player
	Player player;
};