#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

void resizeScreen(int width, int height);
int getWidthMax(void);
int getHeightMax(void);
unsigned getFPS(void);

extern SDL_Surface* screenSurface;

#endif