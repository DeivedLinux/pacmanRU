#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "Screen.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	ptrMap map;
	SDL_Window* window = NULL;
	bool isRunning = true;
    	unsigned long long start;
 

	if(SDL_Init(SDL_INIT_VIDEO))
	{
		puts("Failed to initialize SDL");
		exit(1);
	}
	window = SDL_CreateWindow("PacMan",SDL_WINDOWPOS_UNDEFINED, 
                               SDL_WINDOWPOS_UNDEFINED,getWidthMax(), 
                               getHeightMax(),SDL_WINDOW_SHOWN); 

	if(window == NULL)
	{
		printf("Error %i\n",SDL_GetError());
	}
	else
	{
		screenSurface = SDL_GetWindowSurface(window);
	}

	map = createMapFromFile(argv[1]);
	resizeScreen(map->width, map->height);

	printMap(map);

	while(isRunning)
	{
		start = SDL_GetTicks();

		isRunning = run(NULL); // null por enquanto!

    		SDL_UpdateWindowSurface(window);

    		if((1000u/getFPS()) > (SDL_GetTicks() - start))
        		SDL_Delay((1000u/getFPS()) - (SDL_GetTicks() - start));
	}

	destroyMap(map);
	SDL_FreeSurface(screenSurface);
    	SDL_DestroyWindow(window);
    	SDL_Quit();

	return 0;
}
