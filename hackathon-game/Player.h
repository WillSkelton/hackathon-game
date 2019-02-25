#pragma once
#include "Sprite.h"
#include "MapElement.h"

class Player : public Sprite {
public:

	// CTORs
	Player();
	Player(bool axe, bool pick, bool machete, bool plank);
	
	// DTOR
	~Player();

	// Setter

	void setPosition(int x, int y);
	
	
	// Player Actions
	bool chopTree(MapElement *adjacentCell);
	bool breakRock(MapElement *adjacentCell);
	bool sliceGrass(MapElement *adjacentCell);
	bool throwPlank(MapElement *adjacentCell);
	
	//looks at the next cell and checks if you can break that obsticle
	bool analizeNextCell(MapElement *adjacentCell);

	// Items
	bool hasAxe;
	bool hasPick;
	bool hasMachete;
	bool hasPlank;

};

