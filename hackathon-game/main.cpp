#include <SDL.h>
#include <iostream>

int main(int argc, char ** argv)
{


	SDL_Init(SDL_INIT_VIDEO);

	std::cout << "Hey";

	// game code eventually goes here

	SDL_Quit();

	return 0;
}