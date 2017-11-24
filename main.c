#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include "Screen.h"
#include "GameManager.h"
#include "Player.h"
#include "Map.h"
#include "Vector.h"

SDL_Window* window = NULL;
bool isRunning = true;
ptrMap map = NULL;

int init();
void end();
void draw();
void update();
void sdl_update();

#define BLACK SDL_MapRGB(screenSurface->format,0x01,0x40,0x90)

int main(int argc, char* argv[]){	

	if(!init()){
		printf("Failed to initialize!\n");
		return 0;
	}

	map = createMapFromFile(argv[1]);
	resizeMap(map);

	sdl_update();

	end();

	return 0;
}

int init(){
	int sucess = 1;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		sucess = 0;
	}
	else
	{
		window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED, getWidthMax(), 
									getHeightMax(), SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			sucess = 0;
		}
	}

	screenSurface = SDL_GetWindowSurface( window );
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
	SDL_UpdateWindowSurface( window );

	return sucess;
}

void sdl_update(){

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
}

void draw(){

	SDL_Rect rect;
	rect.w = map->rectSize;
	rect.h = map->rectSize;
	for(int i = 0; i < map->rows; i++){
		for(int j = 0; j < map->columns; j++){

			rect.x = j * rect.w + j + map->start_x;
			rect.y = i * rect.h + i + map->start_y;
			if(map->matrix[i][j] == 1)
				SDL_FillRect(screenSurface, &rect,BLACK);
		}
	}
}

void update(){

}

void end(){

	//destroyMap(map);
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}