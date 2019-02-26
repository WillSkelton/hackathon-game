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
	
	//functions

	//setters
	bool setstartindex(int x, int y);
	bool setendindex(int x, int y);
	bool setplayercoordinates(int x, int y);
	bool settileidentifier(int x, int y, Identifier identity);


	//getters
	int getstartcoordinatesx(void);
	int getstartcoordinatesy(void);
	int getendcoordinatesx(void);
	int getendcoordinatesy(void);
	int getplayercoodinatesx(void);
	int getplayercoodinatesy(void);
	Identifier gettileidentity(int x, int y);

	//moves the player if the next tile can be moved from
	bool move(char direction);

private:

	//private variables

	// Map
	MapElement grid[10][10];

	// Start and Finish Indices
	int startIndex[2];
	int endIndex[2];

	// Player
	Player player;


	//private functions

	// Fill Map
	void fillMap();


};