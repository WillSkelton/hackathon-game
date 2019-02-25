#include "Player.h"

//default constructor, for now we hav that they have all of the items
Player::Player() : Sprite() {
	/*this->hasAxe = false;
	this->hasPick = false;
	this->hasMachete = false;
	this->hasPlank = false;*/

	this->hasAxe = true;
	this->hasPick = true;
	this->hasMachete = true;
	this->hasPlank = true;
}

//constructor that sets the parementers to the items
Player::Player(bool axe, bool pick, bool machete, bool plank) : Sprite() {

	this->hasAxe = axe;
	this->hasPick = pick;
	this->hasMachete = machete;
	this->hasPlank = plank;

}

//player destructor, does not really do anything
Player::~Player() {

}

//sets the position of the player
void Player::setPosition(int x, int y) {
	this->coordinates[0] = x;
	this->coordinates[1] = y;

}

//changes the tree map element canpass to true instead of false
bool Player::chopTree(MapElement *adjacentCell) {

	bool success = false;

	if (this->hasAxe == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

//changes the rock map element canpass to true instead of false
bool Player::breakRock(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasPick == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

//changes the grass map element canpass to true instead of false
bool Player::sliceGrass(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasMachete == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

//changes the rock map element canpass to true instead of false
bool Player::throwPlank(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasPlank == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

//looks at the next cell
bool Player::analizeNextCell(MapElement *adjacentCell) {
	bool success = false;
	switch (adjacentCell->identifier) {
		//finish tile
	case FINISH:
		success = true;
		break;
		//grass tile
	case GRASS:
		success = sliceGrass(adjacentCell);
		break;
		//tree tile
	case TREE:
		success = chopTree(adjacentCell);
		break;
		//rock tile
	case ROCK:
		success = breakRock(adjacentCell);
		break;
		//water tile
	case PUDDLE:
		success = throwPlank(adjacentCell);
		break;
		//dirt tile
	case DIRT:
		success = true;
		break;
		//defaults to can't do anything
	default:
		success = false;
	}
	return false;
}

