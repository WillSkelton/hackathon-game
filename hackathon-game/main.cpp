#include "Header.h"
#include "GameApp.h"
#include "Map.h"
#include "Player.h"
#include "FullGame.h"

int main(int argc, char ** argv) {

	srand(time(0));

	FullGame game_app;
	game_app.play_game();



	return 0;
}