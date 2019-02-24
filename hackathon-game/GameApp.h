#pragma once
#include "Header.h"
#include <SDL.h>

class GameApp {
public:
	GameApp();

	//controlls flow of game
	int OnExecute();

	//creates a surface on which everything is drawn
	bool OnInit();

	//determines events (such as key presses) and their associated changes (move left etc)
	void OnEvent(SDL_Event* Event);

	void OnLoop();
	void OnRender();
	void OnCleanup();

private:
	//whether or not game is currently running
	bool Running;

	//display which is used for screen (think of this as the canvas)
	SDL_Window* Window_Display;
	
};