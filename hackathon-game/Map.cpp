#include "Map.h"

// CTORs
Map::Map() {

	// Randomly generate start and end index
	int startIndex[2] = { (rand() % 10), (rand() % 10) };
	int endIndex[2] = { (rand() % 10), (rand() % 10) };

	int randomObsticle = 0;
	Identifier obsticles[6] = { SHRUB, TREE, ROCK, PUDDLE, GRASS, DIRT };

	
	// iterate through rows
	for (int row = 0; row < 10; ++row) {

		// iterate through columns
		for (int col = 0; col < 10; ++col) {

			// place random block
			randomObsticle = rand() % 7;
			this->grid[row][col].identifier = obsticles[randomObsticle];
			
			// sets all of the tiles to unpassable
			this->grid[row][col].canPass = false;

			//if the tile is grass or dirt it will be passable
			if ((this->grid[row][col].identifier == DIRT) || (this->grid[row][col].identifier == GRASS)) {
				this->grid[row][col].canPass = true;
			}
		}
	}


	// place start marker
	this->grid[startIndex[1]][startIndex[0]].identifier = START;
	this->grid[endIndex[1]][endIndex[0]].identifier = FINISH;

	// place player
	this->player.coordinates[0] = startIndex[0];
	this->player.coordinates[1] = startIndex[1];

	// mark player location
	this->grid[player.coordinates[1]][player.coordinates[0]].identifier = PLAYER;
}


// DTOR
Map::~Map() {

}

// Fill Map
void Map::fillMap(Map *map) {

}

//attempts to move the player
bool Map::move(char direction) {
	int playerRow = this->player.coordinates[1];
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
}