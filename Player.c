#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Screen.h"

ptrPlayer newPlayer(TypeCharacter type, SDL_Rect rect,
					SDL_Surface* color, int speed)
{
	ptrPlayer player = NULL;

	player = (ptrPlayer)malloc(sizeof(Player));
	if(player == NULL)
		return NULL;
	player->speed = speed;
	player->color = color;
	player->type = type;
	player->rect = rect;

	return player;
}

void draw(ptrPlayer p)
{
	SDL_FillRect(screenSurface, &p->rect, p->color);
}

void update()
{

}