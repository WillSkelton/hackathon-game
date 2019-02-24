#include "Map.h"

// CTORs
Map::Map() {
	int startIndex[2] = { (rand() % 10), (rand() % 10) };
	int endIndex[2] = { (rand() % 10), (rand() % 10) };

	int randomObsticle = 0;

	char obsticles[6] = { 'b', 't', 'r', 'w', 'g', 'd' };

	

	for (int row = 0; row < 10; ++row) {

		for (int col = 0; col < 10; ++col) {

			randomObsticle = rand() % 7;

			this->grid[row][col].identifier = obsticles[randomObsticle];
		}
	}


	this->player.coordinates[0] = (rand() % 10);
	this->player.coordinates[1] = (rand() % 10);

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

		adjacentObsticle = this->grid[playerRow + 1][playerCol];
		if (adjacentObsticle.canPass == false) {
			if (player.analizeNextCell(&adjacentObsticle) == true) {
				this->player.coordinates[1] += 1;
				success = true;
			}
		}
		else {
			success = false;
		}
		break;

	case 'a':

		adjacentObsticle = this->grid[playerRow][playerCol - 1];
		if (adjacentObsticle.canPass == false) {
			if (player.analizeNextCell(&adjacentObsticle) == true) {
				this->player.coordinates[0] -= 1;
				success = true;
			}
		}
		else {
			success = false;
		}
		break;

	case 's':

		adjacentObsticle = this->grid[playerRow - 1][playerCol];
		if (adjacentObsticle.canPass == false) {
			if (player.analizeNextCell(&adjacentObsticle) == true) {
				this->player.coordinates[1] -= 1;
				success = true;
			}
		}
		else {
			success = false;
		}
		break;


	case 'd':
		adjacentObsticle = this->grid[playerRow][playerCol + 1];
		if (adjacentObsticle.canPass == false) {
			if (player.analizeNextCell(&adjacentObsticle) == true) {
				this->player.coordinates[0] += 1;
				success = true;
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