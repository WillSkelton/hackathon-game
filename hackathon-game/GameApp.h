#pragma once
#include "Header.h"
#include "Map.h"
#include <SDL.h>
#include <vector>

class GameApp {
public:
	GameApp();

	//controlls flow of game
	int OnExecute();

	//creates a surface on which everything is drawn
	bool OnInit();

	//determines events (such as key presses) and their associated changes (move left etc)
	void OnEvent(SDL_Event* Event, Map * map);

	//load_media
	void load_images(Map *map);

	//displays every tile when provided a given map
	void DisplayTiles(Map &map);

	void RenderPlayerLocation(Map &map);

	//renders game images every frame
	void OnRender(Map &myMap);

	void OnCleanup();

private:
	//whether or not game is currently running
	bool Running;

	//display which is used for screen (think of this as the canvas)
	SDL_Window* Window_Display;

	//creates renderer object for the generated map
	SDL_Renderer * renderer;

	//surfaces for individual image and master image for frame
	SDL_Surface * temp_surface;
	//SDL_Surface * map_surface;
	SDL_Surface * master_surface;
};

