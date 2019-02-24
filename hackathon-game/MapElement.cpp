#include "MapElement.h"

MapElement::MapElement() : Sprite() {
	
	this->identifier = ' ';

	this->canPass = false;
	
	this->coordinates[0] = 0;
	this->coordinates[1] = 1;


}

MapElement::MapElement(int x, int y, char indentifier) : Sprite() {
	this->identifier = ' ';

	this->canPass = false;

	this->coordinates[0] = x;
	this->coordinates[1] = y;
}

// Setters
void MapElement::changeCoordinates(int x, int y){
	this->coordinates[0] = x;
	this->coordinates[1] = y;
}

void MapElement::brakeElement(void){
	this->canPass = true;
}

