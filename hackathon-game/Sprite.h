#pragma once
#include "Header.h"
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Sprite {

public:

	// CTOR
	Sprite();

	Sprite(int x, int y, Identifier identifier);
	
	// CPY CTOR
	Sprite(Sprite &src);
	
	// DTOR
	~Sprite();

	// Getters
	int getX(void);
	int getY(void);

	char getIdentifier(void);


//private:
	//what block is on the tile 
	Identifier identifier;

	//where the block is
	int coordinates[2];
};
