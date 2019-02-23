#pragma once
#include "Sprite.h"
#include "MapElement.h"

class Player : public Sprite {
public:

	Player();
	Player(bool axe, bool pick, bool machete, bool plank);
	~Player();

	void setPosition(int x, int y);

	bool chopTree(MapElement *adjacentCell);
	bool breakRock(MapElement *adjacentCell);
	bool sliceGrass(MapElement *adjacentCell);
	bool throwPlank(MapElement *adjacentCell);

	bool move(char direction);

	bool hasAxe;
	bool hasPick;
	bool hasMachete;
	bool hasPlank;

};

