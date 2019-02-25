#pragma once

#include <SDL.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 40

#define TILE_SIZE 16

#define WWIDTH 500
#define WHEIGHT 500

typedef enum Identifier
{
    NONE, GRASS, DIRT, SHRUB, TREE, ROCK, PUDDLE, FINISH, START, PLAYER
};

//if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
//	return false;
//}




//Things that can change
// - we dont need to display the player over the surface, this may be leading to some issues when the player moves back, 
//   it seems it will replace tiles with the default, in this case puddles. we can slove this by having a bool in the mapelement
//   that describes whether the player is on it or not, if it is, load the player
// - need to look through move, as it wot break the tiles even if you have all of the tools
// -  



//for mk
/*
code GameApp.cpp
code GameApp.h
code Header.h
code inputs.cpp
code main.cpp
code Map.cpp
code MapElement.cpp
code MapElement.h
code Map.h
code Player.cpp
code Player.h
code Sprite.cpp
code Sprite.h
*/