#include "MapElement.h"

//constructs the mapelement with some basic values, envokes the Sprite constructor for the parts of map
//element that is not in its constructor
MapElement::MapElement() : Sprite() {
	
	this->identifier = NONE;

	this->canPass = false;
	
	this->coordinates[0] = 0;
	this->coordinates[1] = 0;
}

//non basic consctor for the map element
MapElement::MapElement(int x, int y, char indentifier) : Sprite() {
	this->identifier = NONE;

	this->canPass = false;

	this->coordinates[0] = x;
	this->coordinates[1] = y;
}

// Setters

//sets coordinates
void MapElement::changeCoordinates(int x, int y){
	this->coordinates[0] = x;
	this->coordinates[1] = y;
}

//'breaks' the object you are looking at
void MapElement::brakeElement(void){
	this->canPass = true;
}

