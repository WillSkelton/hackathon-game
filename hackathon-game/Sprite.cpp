#include "Sprite.h"

// CTOR
Sprite::Sprite() {
	this->identifier = identifier;
}

Sprite::Sprite(int x, int y, Identifier identity) {
	this->identifier = identifier;	

	this->location.setx(x);
	this->location.sety(y);

}

// CPY CTOR
Sprite::Sprite(Sprite &src) {
	this->identifier = src.identifier;

	this->location.setx(src.getX());
	this->location.sety(src.getY());

}

// DTOR
Sprite::~Sprite(){


}

// Getters
int Sprite::getY(void){
	return this->location.gety();;
}

int Sprite::getX(void){
	return this->location.gety();
}

Identifier Sprite::getIdentifier(void){
	return this->identifier;
}

//setters
void Sprite::setX(int x)
{
	this->location.setx(x);
}
void Sprite::setY(int y)
{
	this->location.sety(y);
	
}
void Sprite::setidentity(Identifier identity)
{
	this->identifier = identity;
}