#pragma once
#include "Header.h"
#include "Coordinates.h"
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Sprite {

public:

	// CTOR
	Sprite();

	Sprite(int x, int y, Identifier identity);
	
	// CPY CTOR
	Sprite(Sprite &src);
	
	// DTOR
	~Sprite();

	// Getters
	int getX(void);
	int getY(void);

	Identifier getIdentifier(void);

	//setters
	void setX(int x);
	void setY(int y);

	void setidentity(Identifier identity);

private:
	//what block is on the tile 
	Identifier identifier;

	//where the block is
	Coordinates location;
};
