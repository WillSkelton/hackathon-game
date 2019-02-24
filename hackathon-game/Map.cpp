#include "Map.h"

// CTORs
Map::Map() {

	// Randomly generate start and end index
	int startIndex[2] = { (rand() % 10), (rand() % 10) };
	int endIndex[2] = { (rand() % 10), (rand() % 10) };

	int randomObsticle = 0;
	char obsticles[6] = { 'b', 't', 'r', 'w', 'g', 'd' };

	
	// iterate through rows
	for (int row = 0; row < 10; ++row) {

		// iterate through columns
		for (int col = 0; col < 10; ++col) {

			// place random block
			randomObsticle = rand() % 7;
			this->grid[row][col].identifier = obsticles[randomObsticle];
			
			// PLEASE DELETE THIS!!!
			this->grid[row][col].canPass = true;

			if ((this->grid[row][col].identifier == 'd') || (this->grid[row][col].identifier == 'g')) {
				this->grid[row][col].canPass = true;
			}
		}
	}


	// place start marker
	this->grid[startIndex[1]][startIndex[0]].identifier = 's';
	this->grid[endIndex[1]][endIndex[0]].identifier = 'f';

	// place player
	this->player.coordinates[0] = startIndex[0];
	this->player.coordinates[1] = startIndex[1];

	// mark player location
	this->grid[player.coordinates[1]][player.coordinates[0]].identifier = 'p';
}


// DTOR
Map::~Map() {

}

// Fill Map
void Map::fillMap(Map *map) {

}

bool Map::move(char direction) {
	int playerRow = this->player.coordinates[1];
	int playerCol = this->player.coordinates[0];

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

					this->grid[playerRow - 1][playerCol].identifier = 'p';

					
					// report success
					success = true;
				}
				// can't break it
				else {
					success = false;
				}
			}
			// it is passible
			else {
				// move the player

				this->grid[playerRow][playerCol].identifier = this->grid[playerRow - 1][playerCol].identifier;

				this->grid[playerRow - 1][playerCol].identifier = 'p';

				this->player.coordinates[1] -= 1;

				// report success
				success = true;
			}
		}
		else {
			success = false;
		}
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
				// can't break it
				else {
					success = false;
				}
			}
			// it is passible
			else {
				// move the player
				this->player.coordinates[0] -= 1;

				// report success
				success = true;
			}
		}
		else {
			success = false;
		}
		break;

	case 's':

		// if you can move down
		if (playerRow < 10) {

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
				// can't break it
				else {
					success = false;
				}
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
		else {
			success = false;
		}
		break;


	case 'd':
		// if you can move right..
		if (playerCol < 10) {

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
				// can't break it
				else {
					success = false;
				}
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
		else {
			success = false;
		}
		break;

	case 'e':
		break;

	default:
		success = false;
		break;
	}


	return success;
}