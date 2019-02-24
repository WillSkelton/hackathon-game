#pragma once
#include "MapElement.h"
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

	// Map
	vector<vector<MapElement>> grid[10][10];

	// Start and Finish Indices
	int startIndex[2];
	int endIndex[2];


};