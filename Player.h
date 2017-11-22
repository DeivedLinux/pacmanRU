#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL2/SDL.h>
#include "Vector.h"

typedef enum 
{
	Prey,
	Predator	
}TypeCharacter;

typedef struct Player
{
	Vector4 pos;
	SDL_Surface* color;
	int speed;
	int dirX;
	int dirY;
	TypeCharacter type;	
	Vector2 diff;
}*ptrPlayer;

typedef struct Player Player;

ptrPlayer newPlayer(TypeCharacter type, Vector4 pos, Uint32 color, int speed, Vector2 diff);
void draw_player(ptrPlayer p);
void update_player(ptrPlayer p);

#endif