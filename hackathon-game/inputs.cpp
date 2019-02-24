#include "GameApp.h"
#include "Player.h"
#include "Map.h"

//determines events (such as key presses) and their associated changes (move left etc)
void GameApp::OnEvent(SDL_Event* Event, Map * map) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if(Event->type == SDL_KEYDOWN) //a key has been pressed down
	{
		const Uint8 *state = SDL_GetKeyboardState(NULL); //gets what key has been pressed down
		if(state[SDLK_w])//if the w key was pressed (up)
		{
            map->move('w');
		}
		else if(state[SDLK_a])//if the a key was pressed (left)
		{
            map->move('a');
		}
		else if(state[SDLK_s])//if the s key was pressed (down)
		{
            map->move('s');
		}
		else if(state[SDLK_d])//if the d key was pressed (right)
		{
            map->move('d');
		}
		else if(state[SDL_SCANCODE_SPACE])//if the space key was pressed
		{
            
		}
	}
}