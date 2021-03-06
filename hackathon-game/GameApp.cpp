
#include "GameApp.h"

//Initalize CApp() to the "on" state. ie, the game is now considered running
GameApp::GameApp() {
	Running = true;

	Window_Display = nullptr;
	Surface_Display = nullptr;
}

//events queue up actions that the user inputs, and are processed in a loop
int GameApp::OnExecute() {

	//create an instance of map
	Map myMap;
	int i = 0;

	//if initializing our game fails, return -1 and close
	if (OnInit() == false) {	
		return -1;
	}

	//create an event for use for storing other events for processing
	SDL_Event Event;

	//While the app is running we will read inputs and put them on a queue
	while (Running) {
		//SDL_PollEvent pulls items from the queue until queue empty
		while (SDL_PollEvent(&Event)) {
			//OnEvent takes a given event item and processes it
			OnEvent(&Event, &myMap);
			//renders the first time, then waits for a key press to render again
			if (Event.type == SDL_KEYDOWN || i == 0)
			{
				++i;
				//renders the map
				OnRender(myMap);
			}
		}
	}
	//cleans up all the things that may have been used
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

	//this is moved to the render functiond
	//renderer = SDL_CreateRenderer(Window_Display, -1, 0);

	////clear the screen to black
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);

	////create a surface with the image
	//image = SDL_LoadBMP("grass.bmp");	//load the current image

	//texture = SDL_CreateTextureFromSurface(renderer, image);
	//SDL_Rect tile_size = { 0, 0, 50, 50 };

	//SDL_RenderCopy(renderer, texture, NULL, &tile_size);
	//tile_size.x = 50;
	//tile_size.y = 50;
	//SDL_RenderCopy(renderer, texture, NULL, &tile_size);

	//SDL_RenderPresent(renderer);

	//DisplayTiles(renderer, myMap);

	return true;
}

/*
function: void GameApp::DisplayTiles(SDL_Renderer * renderer, Map &map);
descritpion: creates a texture for each image (repeated in a loop 100x)
	it calls SDL_RenderCopy() each time to copy these to the renderer to make the final frame,
	it then calls SDL_RenderPresent() once at the end to update the frame with the compilation image
	stored in the renderer
parameters:
*/
void GameApp::DisplayTiles(SDL_Renderer * renderer, Map &map){
	SDL_Surface* image = nullptr;
	SDL_Texture * texture = nullptr;

	//create a rect object which stores the dimensions of a given tile
	SDL_Rect tile_size = { 0, 0, 50, 50 };

	//print every tile we have a 10 by 10 grid
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			//create a surface with the image
			switch(map.grid[row][col].identifier) {
			case GRASS:
				//grass
				image = SDL_LoadBMP("grass.bmp");
				break;
			case DIRT:
				//dirt
				image = SDL_LoadBMP("dirt.bmp");
				break;
			case SHRUB:
				//bush
				image = SDL_LoadBMP("shrub.bmp");
				break;
			case TREE:
				//tree
				image = SDL_LoadBMP("tree.bmp");
				break;
			case ROCK:
				//rock
				image = SDL_LoadBMP("rock.bmp");
				break;
			default:
				//default is puddle
				image = SDL_LoadBMP("grass-with-puddle.bmp");
				break;
			}

			//cerates a texture, using the rendurer and the images made in the switch statement
			texture = SDL_CreateTextureFromSurface(renderer, image);

			//copy each element to the renderer
			SDL_RenderCopy(renderer, texture, NULL, &tile_size);

			//cleanup image resources
			SDL_FreeSurface(image);

			//moving the x coordinate forward 50 pixels
			tile_size.x += 50;

		}

		//at the end of the row, reset the x value and and moves the y down one
		tile_size.y += 50;
		tile_size.x = 0;
	}

	//superimpose player over map screen
	RenderPlayerLocation(renderer, map);

	//present superimposed image to screen
	SDL_RenderPresent(renderer);

	//cleanup image and renderer
	//SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
}

void GameApp::RenderPlayerLocation(SDL_Renderer * renderer, Map &map) {
	//loads in the image we have for the player
	SDL_Surface* player_image = SDL_LoadBMP("player.bmp");
	
	//sets the location of the tile for the player
	SDL_Rect tile_location = { (map.player.coordinates[0])*50, (map.player.coordinates[1]) * 50, 50, 50 };

	//greates a texture from the player image and coordinates
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, player_image);

	//prints the layer image to the screen
	SDL_RenderCopy(renderer, texture, NULL, &tile_location);

	//cleanup
	SDL_FreeSurface(player_image);
}

void GameApp::OnRender(Map &myMap) {
	//SDL_Surface* image = nullptr;
	SDL_Renderer * renderer = nullptr;
	//SDL_Texture * texture = nullptr;

	//creates a rendurer from the window created earlier
	renderer = SDL_CreateRenderer(Window_Display, -1, 0);

	//displayes the map with the changes
	DisplayTiles(renderer, myMap);
}


void GameApp::OnCleanup() {
	/*SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);*/
	SDL_DestroyWindow(Window_Display);
	SDL_Quit();
}