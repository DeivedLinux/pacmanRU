#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL2/SDL.h>

typedef enum 
{
	Prey,
	Predator	
}TypeCharacter;

typedef struct Player
{
	//SDL_Surface* sprite;
	SDL_Rect rect;
	SDL_Surface* color;
	int speed;
	int dirX;
	int dirY;
	TypeCharacter type;	
}*ptrPlayer;

typedef struct Player Player;

ptrPlayer newPlayer(TypeCharacter type, SDL_Rect rect,
					SDL_Surface* color, int speed);

#endif