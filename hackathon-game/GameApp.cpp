
#include "GameApp.h"

//Initalize CApp() to the "on" state. ie, the game is now considered running
GameApp::GameApp() {
	Running = true;

	Window_Display = nullptr;
}

//events queue up actions that the user inputs, and are processed in a loop
int GameApp::OnExecute() {
	//if initializing our game fails, return -1 and close
	if (OnInit() == false) {	
		return -1;
	}

	//create an event for use for storing other events for processing
	SDL_Event Event;

	//we then loop through all inputs in the event queue
	while (Running) {
		//SDL_PollEvent pulls items from the queue until queue empty
		while (SDL_PollEvent(&Event)) {
			//OnEvent takes a given event item and processes it
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

//creates a surface on which everything is drawn
bool GameApp::OnInit() {

	//if we are unable to initialize all values of the surface,
	//exit with false
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	//create the game window, if this fails, then return false and exit this function
	if ((Window_Display = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, 0)) == NULL) {

		return false;
	}

	/*if ((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}*/

	return true;
}

//determines events (such as key presses) and their associated changes (move left etc)
void GameApp::OnEvent(SDL_Event* Event) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
}

void GameApp::OnLoop() {

}

void GameApp::OnRender() {

}


void GameApp::OnCleanup() {
	SDL_Quit();
}