#pragma once
#include "Sprite.h"
#include "MapElement.h"

class Player : public Sprite {
public:

	// CTORs
	Player();
	//Player(bool axe, bool pick, bool machete, bool plank);
	
	// DTOR
	~Player();

	// Setter
	void setPosition(int x, int y);
	/*
	bool setAxe(void);
	bool setPick(void);
	bool setPlank(void);

	// Getters
	bool getAxe(void);
	bool getPick(void);
	bool getPlank(void);
	
	// Player Actions
	bool chopTree(MapElement *adjacentCell);
	bool breakRock(MapElement *adjacentCell);
	bool throwPlank(MapElement *adjacentCell);
	*/
	
	//looks at the next cell and checks if you can break that obsticle
	//bool analizeNextCell(MapElement *adjacentCell);

protected:
	// Items
	/*
	bool hasAxe;
	bool hasPick;
	bool hasPlank;
	*/
};

