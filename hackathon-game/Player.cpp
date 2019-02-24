#include "Player.h"


Player::Player() {
	this->hasAxe = false;
	this->hasPick = false;
	this->hasMachete = false;
	this->hasPlank = false;
}

Player::Player(bool axe, bool pick, bool machete, bool plank) {

	this->hasAxe = axe;
	this->hasPick = pick;
	this->hasMachete = machete;
	this->hasPlank = plank;

}

Player::~Player() {

}

void Player::setPosition(int x, int y) {
	this->coordinates[0] = x;
	this->coordinates[1] = y;

}

bool Player::chopTree(MapElement *adjacentCell) {

	bool success = false;

	if (this->hasAxe == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

bool Player::breakRock(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasPick == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

bool Player::sliceGrass(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasMachete == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

bool Player::throwPlank(MapElement *adjacentCell) {
	bool success = false;

	if (this->hasPlank == true) {
		adjacentCell->brakeElement();
		success = true;
	}

	return success;
}

bool Player::analizeNextCell(MapElement *adjacentCell) {
	switch (adjacentCell->identifier) {
	case 'b':
		break;
	}

	return false;
}

bool Player::move(char direction) {
	
	bool success = false;

	switch (direction) {
	case 'w':


		break;

	case 'a':
		break;

	case 's':
		break;
	

	case 'd':
		break;

	case 'e':
		break;

	default:
		success = false;
		break;
	}
	
	
	return false;
}
