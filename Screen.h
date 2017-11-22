#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "Utility.h"
#include "Vector.h"

void resizeScreen(ptrMap map);
int getWidthMax(void);
int getHeightMax(void);
unsigned getFPS(void);
int getRectSize(ptrMap map);
Vector2 getMapStartPos(ptrMap map);


static int rectSize = 0;
extern SDL_Surface* screenSurface;

#endif