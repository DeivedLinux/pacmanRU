#include "Screen.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

#define minimum(x,y) x < y?x:y;

static const unsigned int SCREEN_WIDTH = 800;
static const unsigned int SCREEN_HEIHT = 600;
SDL_Surface* screenSurface = NULL;
static unsigned int FPS = 60;

void resizeScreen(int width, int height)
{
	SDL_Rect rects;
	int rectSize;
	unsigned i,j;
	int dx,dy;
	SDL_Surface* rgbBack = NULL;

	rectSize = minimum(SCREEN_WIDTH/width,SCREEN_HEIHT/height);

	dx = (SCREEN_WIDTH-rectSize*width)/2;
	dy = (SCREEN_HEIHT-rectSize*height)/2;

	rects.x = dx;
	rects.y = dy;
	rects.w = dx+rectSize;
	rects.h = dy+rectSize;
	rgbBack = SDL_MapRGB(screenSurface->format,0x00,0x00,0x00);

	for(i = 0; i < getWidthMax(); i++)
	{
		for(j = 0; j < getHeightMax(); j++)
		{
			rects.x = i * rects.w;
			rects.y = j * rects.h;
			SDL_BlitSurface(rgbBack,NULL,screenSurface,&rects);
			rects.w += rectSize;
			rects.h += rectSize;
		}
	}
}

int getWidthMax(void)
{
	return SCREEN_WIDTH;
}

int getHeightMax(void)
{
	return SCREEN_HEIHT;
}

unsigned getFPS(void)
{
	return FPS;
}