#pragma once

#include "Sprite.h"

class MapElement : public Sprite {

public:
	/******Inherits From Sprite************************\
	*												   *
	*	// CTOR										   *
	*	Sprite();									   *
	*										   		   *
	*	Sprite(int x, int y, char identifier);		   *
	*												   *
	*	// CPY CTOR									   *
	*	Sprite(Sprite &src);						   *
	*												   *
	*	// DTOR										   *
	*	~Sprite();									   *
	*												   *
	*	// Getters									   *
	*	int getX(void);								   *
	*	int getY(void);								   *
	*												   *
	*	char getIdentifier(void);					   *
	*												   *
	*	char identifier;							   *
	*												   *
	*	int coordinates[2];							   *
	*												   *
	\**************************************************/

	//default constructor
	MapElement();

	//nondefault constructor 
	MapElement(int x, int y, char indentifier);

	//changes the coordiantes of the element
	void changeCoordinates(int x, int y);

	//changes the element pass to true instead of false
	void brakeElement(void);
	


//private:

	//whether or not you can pass the object
	bool canPass;

};