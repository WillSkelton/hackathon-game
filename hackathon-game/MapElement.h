#pragma once

#include "Sprite.h"

class MapElement : public Sprite {

public:

	MapElement();

	MapElement(int x, int y, char indentifier);

	void changeCoordinates(int x, int y);
	void brakeElement(void);
	


//private:

	bool canPass;

};