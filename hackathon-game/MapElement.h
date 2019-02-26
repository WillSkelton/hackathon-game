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

	//constructs the mapelement with some basic values, envokes the Sprite constructor for the parts of map
	//element that is not in its constructor
	MapElement() : Sprite(){
		//this->canPass = false;
	};

	/*
	//nondefault constructor 
	//envokes the Sprite constructor inside it
	MapElement(int x, int y, Identifier indentity, bool canpass) : Sprite(x, y, indentity){
		this->canPass = canpass;
	};

	//changes the coordiantes of the element
	void changeCoordinates(int x, int y);

	//changes the element pass to true instead of false
	void brakeElement(void);

	void setcanpass(bool canpass);
	
	bool getcanpass(bool canpass);
	*/

private:

	//whether or not you can pass the object
	//bool canPass;

};