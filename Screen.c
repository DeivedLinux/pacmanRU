#include "Screen.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "Vector.h"

#define minimum(x,y) x < y?x:y;

#define WHITE SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF)
#define BLACK SDL_MapRGB(screenSurface->format,0x01,0x40,0x90)

static const unsigned int SCREEN_WIDTH = 800;
static const unsigned int SCREEN_HEIGHT = 600;
SDL_Surface* screenSurface = NULL;
static unsigned int FPS = 60;

void resizeScreen(ptrMap map)
{
	SDL_Rect rects;
	unsigned i,j;
	int dx,dy;
	
	rectSize = minimum(SCREEN_WIDTH/map->column,SCREEN_HEIGHT/map->row);

	dx = (SCREEN_WIDTH-rectSize*map->column)/2;
	dy = (SCREEN_HEIGHT-rectSize*map->row)/2;

	rects.x = dx;
	rects.y = dy;
	rects.w = rectSize;
	rects.h = rectSize;
	
	for(i = 0; i < map->row; i++)
	{
		for(j = 0; j < map->column; j++)
		{
			rects.x = j * rects.w + j + dx;
			rects.y = i * rects.h + i + dy;
			if(map->matrix[i][j] == 1)
				SDL_FillRect(screenSurface, &rects,BLACK);
		}
	}
}

Vector2 getMapStartPos(ptrMap map){

	Vector2 diff;
	diff.c = (SCREEN_WIDTH-rectSize*map->column)/2;
	diff.l = (SCREEN_HEIGHT-rectSize*map->row)/2;

	return diff;
}

int getWidthMax(void)
{
	return SCREEN_WIDTH;
}

int getHeightMax(void)
{
	return SCREEN_HEIGHT;
}

int getRectSize(ptrMap map){

	return minimum(SCREEN_WIDTH/map->column,SCREEN_HEIGHT/map->row) - 1;
}

unsigned getFPS(void)
{
	return FPS;
}

