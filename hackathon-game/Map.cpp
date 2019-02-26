#include "Map.h"

// CTORs
Map::Map() {
	// Randomly generate start and end index
	int startIndex[2] = { (rand() % 10), (rand() % 10) };
	int endIndex[2] = { (rand() % 10), (rand() % 10) };

	int randomObsticle = 0;
	Identifier obsticles[6] = { SHRUB, TREE, ROCK, PUDDLE, GRASS, DIRT };

	this->fillMap();

	// place start marker
	this->settileidentifier(startIndex[1], startIndex[0], START);
	this->settileidentifier(endIndex[1], endIndex[0], FINISH);

	// place player
	this->setplayercoordinates(startIndex[0], startIndex[1]);
}


// DTOR
Map::~Map() {

}

// Fill Map
void Map::fillMap() {
	int randomObsticle = 0;
	Identifier obsticles[6] = { SHRUB, TREE, ROCK, PUDDLE, GRASS, DIRT };
	// iterate through rows
	for (int row = 0; row < 10; ++row) {

		// iterate through columns
		for (int col = 0; col < 10; ++col) {

			// place random block
			randomObsticle = rand() % 7;
			this->settileidentifier(col, row, obsticles[randomObsticle]);
			
			// sets all of the tiles to unpassable
			this->grid[row][col].setcanpass(true);

			//if the tile is grass or dirt it will be passable
			if ((this->gettileidentity(col, row) == DIRT) || (this->gettileidentity(col, row) == GRASS)) {
				this->grid[row][col].setcanpass(true);
			}
		}
	}
}

//attempts to move the player
bool Map::move(char direction) {


	






	/*int playerRow = this->player.coordinates[1];
	int playerCol = this->player.coordinates[0];

	//creates a mapelement so we can look at the next obsticle
	MapElement adjacentObsticle;

	bool success = false;

	switch (direction) {
	case 'w':

		// if you can move up
		if (playerRow > 0) {

			// you can move up so then look at object above you
			adjacentObsticle = this->grid[playerRow - 1][playerCol];

			// if it's impassable...
			if (adjacentObsticle.canPass == false) {
				// check if you can break it
				if (player.analizeNextCell(&adjacentObsticle) == true) {
					// move the player
					this->player.coordinates[1] -= 1;

					this->grid[playerRow][playerCol].identifier = this->grid[playerRow - 1][playerCol].identifier;

					this->grid[playerRow - 1][playerCol].identifier = PLAYER;

					// report success
					success = true;
				}
				// can't break it will return false
			}
			// it is passible
			else {
				// move the player

				this->grid[playerRow][playerCol].identifier = this->grid[playerRow - 1][playerCol].identifier;

				this->grid[playerRow - 1][playerCol].identifier = PLAYER;

				this->player.coordinates[1] -= 1;

				// report success
				success = true;
			}
		}
		//if the player can not move up it will return false
		break;

	case 'a':

		// if you can move left..
		if (playerCol > 0) {

			// you can move left so then look at object to the left of you
			adjacentObsticle = this->grid[playerRow][playerCol - 1];

			// if it's impassable...
			if (adjacentObsticle.canPass == false) {
				// check if you can break it
				if (player.analizeNextCell(&adjacentObsticle) == true) {
					// move the player
					this->player.coordinates[0] -= 1;

					// report success
					success = true;
				}
				// can't break it will return false
			}
			// it is passible
			else {
				// move the player
				this->player.coordinates[0] -= 1;

				// report success
				success = true;
			}
		}
		//if the player can not move left it will return false
		break;

	case 's':

		// if you can move down
		if (playerRow < 9) {

			// you can move down so then look at object below you
			adjacentObsticle = this->grid[playerRow + 1][playerCol];

			// if it's impassable...
			if (adjacentObsticle.canPass == false) {
				// check if you can break it
				if ((player.analizeNextCell(&adjacentObsticle) == true) && (this->player.coordinates[1] < 10)) {
					// move the player
					this->player.coordinates[1] += 1;

					// report success
					success = true;
				}
				// can't break it will return false
			}
			// it is passible
			else {
				if ((this->player.coordinates[0] < 10)) {
					// move the player
					this->player.coordinates[1] += 1;

					// report success
					success = true;
				}
			}
		}
		//if the player can not move down it will return false
		break;


	case 'd':
		// if you can move right..
		if (playerCol < 9) {

			// you can move left so then look at object to the right of you
			adjacentObsticle = this->grid[playerRow][playerCol + 1];

			// if it's impassable...
			if (adjacentObsticle.canPass == false) {
				// check if you can break it
				if ((player.analizeNextCell(&adjacentObsticle)) == true && (this->player.coordinates[0] < 10)) {
					// move the player
					this->player.coordinates[0] += 1;

					// report success
					success = true;
				}
				// can't break it will return false
			}
			// it is passible
			else {

				if ((this->player.coordinates[0] < 10)) {
					// move the player
					this->player.coordinates[0] += 1;

					// report success
					success = true;
				}
			}
		}
		//if the player can not move right it will return false
		break;

	case 'e':
		//there is nothing that e can do yet
		break;

	default:
		success = false;
		break;
	}

	return success;
	*/
}


//setters
bool Map::setstartindex(int x, int y)
{
	this->startIndex[0] = x;
	this->startIndex[1] = y;
	if(this->startIndex[0] == x && this->startIndex[1] == y)
	{
		return true;
	}
	return false;
}
bool Map::setendindex(int x, int y)
{
	this->endIndex[0] = x;
	this->endIndex[1] = y;
		if(this->endIndex[0] == y && this->endIndex[1] == x)
	{
		return true;
	}
	return false;
}
bool Map::setplayercoordinates(int x, int y)
{
	this->player.setPosition(x, y);
	if(this->player.getX() == x && this->player.getY() == y)
	{
		return true;
	}
	return false;
}
bool Map::settileidentifier(int x, int y, Identifier identity)
{
	this->grid[y][x].setidentity(identity);
	if(this->gettileidentity(x,y) == identity)
	{
		return true;
	}
	false;
}

//getters
int Map::getstartcoordinatesx(void)
{
	return startIndex[0];
}
int Map::getstartcoordinatesy(void)
{
	return startIndex[1];
}
int Map::getendcoordinatesx(void)
{
	return endIndex[0];
}
int Map::getendcoordinatesy(void)
{
	return endIndex[0];
}
int Map::getplayercoodinatesx(void)
{
	return this->player.getX();
}
int Map::getplayercoodinatesy(void)
{
	return this->player.getY();
}
Identifier Map::gettileidentity(int x, int y)
{
	return this->grid[y][x].getIdentifier();
}