#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"
#include "Map.h"

typedef struct player{
	Object obj;
	int moveDistance;
	Direction dir;
} *ptrPlayer;

ptrPlayer createPlayer();
void movePlayer(ptrPlayer p, ptrMap m);
void changeDirectionPlayer(ptrPlayer p);
void drawPlayer(ptrPlayer p);

#endif