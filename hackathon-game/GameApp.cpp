
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
	SDL_Surface* image = nullptr;
	SDL_Renderer * renderer = nullptr;
	SDL_Texture * texture = nullptr;

	//if we are unable to initialize all values of the surface,
	//exit with false
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	//create the game window, if this fails, then return false and exit this function
	if ((Window_Display = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WWIDTH, WHEIGHT, 0)) == NULL) {

		return false;
	}

	//add textures to the map
	image = SDL_LoadBMP("Untitled.bmp");	//load the current image
	renderer = SDL_CreateRenderer(Window_Display, -1, 0);	//create a renderer to the display
	texture = SDL_CreateTextureFromSurface(renderer, image);	//render the image onto the display

	//create a rect object which stores the dimensions of a given tile
	SDL_Rect tile_size = { 0, 0, 50, 50 };
	SDL_RenderCopy(renderer, texture, NULL, &tile_size);
	
	//present superimposed image to screen
	SDL_RenderPresent(renderer);

	//cleanup image and renderer
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);

	//Window_Display = SDL_LoadBMP("Untitled.jpg");

	return true;
}

void GameApp::DisplayTiles(std::vector <std::vector <MapElement>> &map_key);
	SDL_Surface* image = nullptr;
	SDL_Renderer * renderer = nullptr;
	SDL_Texture * texture = nullptr;

	//create a rect object which stores the dimensions of a given tile
	SDL_Rect tile_size = { 0, 0, 50, 50 };

	SDL_Rect tile_size = { 0, 0, 50, 50 };
	SDL_RenderCopy(renderer, texture, NULL, &tile_size);

	//present superimposed image to screen
	SDL_RenderPresent(renderer);

	//cleanup image and renderer
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	delete &tile_size;
}

//determines events (such as key presses) and their associated changes (move left etc)
void GameApp::OnEvent(SDL_Event* Event) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	//Evenets are broken into types, some are button presses, some are clicks, SDL_QUIT is the exit button
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	/*
	if (Event->type == button_press) {
		//process button press
	}
	*/
}

void GameApp::OnLoop() {

}

void GameApp::OnRender() {

}


void GameApp::OnCleanup() {
	/*SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);*/
	SDL_Quit();
}