#pragma once
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Sprite {

public:

	// CTOR
	Sprite();

	Sprite(int x, int y, char identifier);
	
	// CPY CTOR
	Sprite(Sprite &src);
	
	// DTOR
	~Sprite();

	// Getters
	int getX(void);
	int getY(void);

	char getIdentifier(void);


//private:
	char identifier;

	int coordinates[2];
};
