#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "Screen.h"
#include "Game.h"
#include "Player.h"

#define YELLOW SDL_MapRGB(screenSurface->format,0xFF,0xFF,0x00)

void start(char* fileName);
void draw();
void update();
void end();

ptrPlayer player = NULL;
ptrMap map = NULL;
SDL_Window* window = NULL;
bool isRunning = true;

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		puts("Failed to initialize SDL");
		exit(1);
	}
	window = SDL_CreateWindow("Pacman",SDL_WINDOWPOS_UNDEFINED, 
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

	start(argv[1]);
	


	unsigned long long start;
	while(isRunning)
	{
		start = SDL_GetTicks();

		isRunning = run(NULL); // null por enquanto!

    	SDL_UpdateWindowSurface(window);

    	update();
    	draw();

		if((1000u/getFPS()) > (SDL_GetTicks() - start))
			SDL_Delay(10);
    		//SDL_Delay((1000u/getFPS()) - (SDL_GetTicks() - start));
	}

	end(map, window);
	

	return 0;
}

void start(char* fileName){
	
	map = createMapFromFile(fileName);
	resizeScreen(map);
	printMap(map);

	Vector4 pos;
	pos.l = 2;
	pos.c = 0;
	pos.h = getRectSize(map);
	pos.w = getRectSize(map);
	Vector2 diff = getMapStartPos(map);
	player = newPlayer(Prey, pos, YELLOW, 10, diff);
}

void draw(){
	draw_player(player);
}

void update(){
	update_player(player, map);
}

void end(ptrMap map, SDL_Window* window){

	destroyMap(map);
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
