#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "Utility.h"

void resizeScreen(ptrMap map);
int getWidthMax(void);
int getHeightMax(void);
unsigned getFPS(void);

extern SDL_Surface* screenSurface;

#endif