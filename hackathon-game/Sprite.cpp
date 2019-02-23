#include "Sprite.h"

// CTOR
Sprite::Sprite() {
	this->identifier = identifier;

	this->coordinates[0] = 0;
	this->coordinates[1] = 0;

}

Sprite::Sprite(int x, int y, char identifier) {
	this->identifier = identifier;	

	this->coordinates[0] = x;
	this->coordinates[1] = y;

}

// CPY CTOR
Sprite::Sprite(Sprite &src) {
	this->identifier = src.identifier;

	this->coordinates[0] = src.coordinates[0];
	this->coordinates[1] = src.coordinates[1];


}

// DTOR
Sprite::~Sprite(){


}

// Getters
int Sprite::getY(void){
	return this->coordinates[1];
}

int Sprite::getX(void){
	return this->coordinates[0];
}

char Sprite::getIdentifier(void){
	return this->identifier;
}