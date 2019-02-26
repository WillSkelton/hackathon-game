#pragma once
#include "Header.h"
#include "Map.h"
#include <SDL.h>
#include <vector>

class FullGame {
public:
	//class constructor
	FullGame();

	//destructor -- cleaup images etc
	~FullGame();

	//controls game flow
	void play_game();

	//loads and retrns a given surface using the given relative path to the bmp
	//postcondition: surface returned must be deallocated by program that calls it!
	//string is const to allow passing string literals
	SDL_Surface * load_surface(const std::string path);

	//window design using blitting, blits a grass image to a specified part of screen
	//***delete***
	void blit_window_test();

	//generates a window object for display, returns success bool
	bool create_window();

	//generate a renderer object for the window, returns success bool
	bool create_renderer();

	//creates a texture from a provided surface + applies that texture to the renderer, frees up the surface/texture
	void apply_texture_to_renderer(const std::string path);

	//takes the renderer, applies it to the screen
	void FullGame::render_and_display();

	//initializes PNG loading -- allows us to use more than just .bmp images
	void FullGame::init_png_loading();

	//processes any given event
	void process_event(SDL_Event* Event, Map * map);

	//controls cleanup of all code (values etc)
	void close();

private:
	//control game state
	bool running;

	//handles error output
	std::ofstream error_log;

	//Event handler
	SDL_Event event;

	//window object ptr
	SDL_Window * window_display;

	//renderer object ptr
	SDL_Renderer * renderer;

	//texture object ptr
	SDL_Texture * temp_texture;

	//surfaces for textures (master_surface most useful for blitting)
	SDL_Surface * temp_surface;
	SDL_Surface * master_surface;
};