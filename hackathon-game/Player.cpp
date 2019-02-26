#include "Player.h"

//default constructor, for now we hav that they have all of the items
Player::Player() : Sprite() {
	/*this->hasAxe = false;
	this->hasPick = false;
	this->hasMachete = false;
	this->hasPlank = false;*/

	//this->hasAxe = true;
	//this->hasPick = true;
	//this->hasPlank = true;
}

/*
//constructor that sets the parementers to the items
Player::Player(bool axe, bool pick, bool machete, bool plank) : Sprite() {

	this->hasAxe = axe;
	this->hasPick = pick;
	this->hasPlank = plank;

}
*/

//player destructor, does not really do anything
Player::~Player() {

}

//sets the position of the player
void Player::setPosition(int x, int y) {
	this->setX(x);
	this->setY(y);
}

/*
//changes the tree map element canpass to true instead of false
bool Player::chopTree(MapElement *adjacentCell) {

	if (this->hasAxe == true) {
		adjacentCell->brakeElement();
		return true;
	}
	return false;
}

//changes the rock map element canpass to true instead of false
bool Player::breakRock(MapElement *adjacentCell) {

	if (this->hasPick == true) {
		adjacentCell->brakeElement();
		return true;
	}
	return false;
}

//changes the rock map element canpass to true instead of false
bool Player::throwPlank(MapElement *adjacentCell) {

	if (this->hasPlank == true) {
		adjacentCell->brakeElement();
		return true;
	}
	return false;
}

// Getters
bool Player::getAxe(void)
{
	return this->hasAxe;
}
bool Player::getPick(void)
{
	return this->hasPick;
}
bool Player::getPlank(void)
{
	return this->hasPlank;
}
*/