#include "FullGame.h"
#include "Header.h"

FullGame::FullGame() {
	running = true;

	window_display = nullptr;

	temp_surface = nullptr;
	master_surface = nullptr;
	renderer = nullptr;
	temp_texture = nullptr;

	error_log.open("error_log.txt");

	//initialize SDL
	if ((SDL_Init(SDL_INIT_VIDEO) < 0)) {
		error_log << "SDL_image could not properly initialize in constructor!" << std::endl;
	}

}


FullGame::~FullGame() {

}

//controls game flow
void FullGame::play_game() {

	/*initialize values (only need window here)

	while (application is running) {
		update the screen
		process events
		check if exited out
	}

	cleanup data	*/

	//generate a map and create a window for display
	Map myMap;
	create_window();
	create_renderer();

	//test function that proves we are capable of loading .png files
	init_png_loading();

	//control game flow -- keep playing until exited out
	while (running) {

		//update the screen here******
		render_and_display(myMap);

		//SDL_PollEvent takes the most recent event (button press) and stores it to the event variable
		while (SDL_PollEvent(&event) != 0) {

			//process any given event
			process_event(&event, &myMap);
		}
	}
	close();
}

//test function that proves we are capable of loading .png files
void FullGame::init_png_loading() {
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		error_log << "SDL_image could not initialize! -- error thrown in init_png_loading() function" << std::endl;;
	}
}

//controls cleanup of all code (values etc)
void FullGame::close() {
	error_log << "Successfully closed/cleaned file objects";

	//close output filestream
	error_log.close();

	//destroy any surface objects
	SDL_FreeSurface(temp_surface);
	SDL_FreeSurface(master_surface);

	//destroy texture object
	SDL_DestroyTexture(temp_texture);

	//destroy renderer object
	SDL_DestroyRenderer(renderer);

	//Destroy window
	SDL_DestroyWindow(window_display);

	//cleanup SDL_Image items
	IMG_Quit();

	//quit SDL subsystems
	SDL_Quit();

}

void FullGame::render_and_display(Map &myMap) {
	SDL_Rect dest_rect = {0, 0, DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE };
	SDL_Rect source_rect = { SOURCE_TILE_SIZE , SOURCE_TILE_SIZE , SOURCE_TILE_SIZE , SOURCE_TILE_SIZE };

	//clear the screen to black
	SDL_RenderClear(renderer);

	//repeat until every image on the map has been applied to the renderer
	for (int x = 0; x < WWIDTH / DISPLAY_TILE_SIZE; ++x) {
		for (int y = 0; y < WHEIGHT / DISPLAY_TILE_SIZE; ++y) {

			//determine which texture to apply via switch statement and adjust source_rect accordingly
			determine_source_tile(x, y, myMap, source_rect);

			//apply the current texture to the renderer
			apply_texture_to_renderer(dest_rect, source_rect, "assets\\tile_map\\Tilemap\\tilemap_packed.png");

			dest_rect.x += DISPLAY_TILE_SIZE;

		}
		dest_rect.y += DISPLAY_TILE_SIZE;
		dest_rect.x = 0;
	}



	//render player image transparently over map

	//update screen with rendered image
	SDL_RenderPresent(renderer);
}

//determine which texture to apply via switch statement and adjust source_rect accordingly
void FullGame::determine_source_tile(int x, int y, Map &myMap, SDL_Rect &source_rect) {
	int row = 0, col = 0;

	//row and column updated to which row and column that tile is found on the tilemap.jpg
	//remember!! index for counting rows/cols starts at 0
	switch (myMap.grid[x][y].identifier) {
	case GRASS:	
		row = 1;
		col = 1;
		break;
	case DIRT:
		row = 4;
		col = 1;
		break;
	case SHRUB:
		row = 10;
		col = 22;
		break;
	case TREE:
		row = 9;
		col = 22;
		break;
	case ROCK:
		row = 10;
		col = 3;
		break;
	default:	
		//default to basic grass tile
		row = 1;
		col = 1;
	}

	//update source rectangle location based on specified row/column location 
	//(source_rect needs pixel location, so row * tile size = pixel location)
	source_rect.y = row * SOURCE_TILE_SIZE;
	source_rect.x = col * SOURCE_TILE_SIZE;
}

//creates a texture from a provided surface + applies that texture to the renderer, frees up the surface/texture
void FullGame::apply_texture_to_renderer(SDL_Rect &dest_rect, SDL_Rect &source_rect, const std::string path) {

	//generate a surface from the image
	temp_surface = load_surface(path.c_str());

	//turn the surface into a texture
	temp_texture = SDL_CreateTextureFromSurface(renderer, temp_surface);

	//free the surface now that we are done with it
	SDL_FreeSurface(temp_surface);

	//apply texture to renderer
	SDL_RenderCopy(renderer, temp_texture, &source_rect, &dest_rect);

	//destroy the texture now that we are done with it
	SDL_DestroyTexture(temp_texture);

}

//postcondition: surface returned must be deallocated by program that calls it!
SDL_Surface * FullGame::load_surface(const std::string path) {
	//SDL_Surface * temp = SDL_LoadBMP(path.c_str());
	SDL_Surface * temp = IMG_Load(path.c_str());

	if (temp == nullptr) {
		error_log << "Unable to load a surface from the given path." << std::endl;
	}
	return temp;
}

//test function for playing around with blitting as opposed to rendering images
void FullGame::blit_window_test() {
	//generate a window item
	//create_window();

	//link the master_surface with the generated window
	master_surface = SDL_GetWindowSurface(window_display);

	//create a temp_surface value using SDL_LoadBMP()
	temp_surface = IMG_Load("assets\\tile_map\\Tiles\\tile_0006.png");
	//temp_surface = SDL_LoadBMP("assets\\bmp\\Untitled.bmp");


	//blit the temp surface to the master surface
	SDL_Rect tile_size = { DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE };
	SDL_BlitSurface(temp_surface, NULL, master_surface, &tile_size);
	tile_size.x -= DISPLAY_TILE_SIZE;
	tile_size.y -= DISPLAY_TILE_SIZE;
	SDL_BlitSurface(temp_surface, NULL, master_surface, &tile_size);

	//display master surface
	SDL_UpdateWindowSurface(window_display);
}

//creates the game window, returns success/failure as bool
bool FullGame::create_window() {
	if ((window_display = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WWIDTH, WHEIGHT, 0)) == NULL) {

		error_log << "Unable to create 'SDL_Window window_display' object." << std::endl;
		return false;
	}
	return true;
}

//generate a renderer object for the window, returns success bool
bool FullGame::create_renderer() {
	//create renderer object
	renderer = SDL_CreateRenderer(window_display, -1, SDL_RENDERER_ACCELERATED);

	//make the default renderer color black
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	if (renderer == nullptr) {
		error_log << "The renderer was incorrectly linked to the window - see create_renderer() function" << std::endl;
		return false;
	}
	return true;
}

void FullGame::process_event(SDL_Event* Event, Map * map) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	if (Event->type == SDL_QUIT) {
		running = false;
	}
	if (Event->type == SDL_KEYDOWN) //a key has been pressed down
	{
		const Uint8 *state = SDL_GetKeyboardState(NULL); //gets what key has been pressed down
		if (state[SDL_SCANCODE_W])//if the w key was pressed (up)
		{
			map->move('w');
		}
		else if (state[SDL_SCANCODE_A])//if the a key was pressed (left)
		{
			map->move('a');
		}
		else if (state[SDL_SCANCODE_S])//if the s key was pressed (down)
		{
			map->move('s');
		}
		else if (state[SDL_SCANCODE_D])//if the d key was pressed (right)
		{
			map->move('d');
		}
		else if (state[SDL_SCANCODE_SPACE])//if the space key was pressed
		{

		}

	}
}