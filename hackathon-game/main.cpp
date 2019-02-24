#include "Header.h"
#include "GameApp.h"
#include "Map.h"
#include "Player.h"

int main(int argc, char ** argv) {

	srand(time(0));
	char map[10][10] = {'\0'};

	//Map myMap;

	//MapElement grass(0, 1, 'g');
	//std::vector <std::vector <MapElement>> map1 = {};

	////initialize a 10x10 vector of MapElements
	//for (int x = 0; x < 10; ++x) {
	//	for (int y = 0; y < 10; ++y) {
	//		map1[x][y] = grass;
	//	}
	//}

	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			map[x][y] = 'g';
		}
	}

	

	GameApp theApp;
	//theApp.DisplayTiles(map);
	return theApp.OnExecute();

	return 0;
}