#include "Header.h"
#include "GameApp.h"
#include "Map.h"
#include "Player.h"

int main(int argc, char ** argv) {

	srand(time(0));
	

	

	GameApp theApp;
	return theApp.OnExecute();

	return 0;
}