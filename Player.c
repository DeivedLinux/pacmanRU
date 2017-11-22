#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Screen.h"

ptrPlayer newPlayer(TypeCharacter type, Vector4 pos, Uint32 color, int speed, Vector2 diff)
{
	ptrPlayer player = NULL;

	player = (ptrPlayer)malloc(sizeof(Player));
	if(player == NULL)
		return NULL;
	player->type = type;
	player->pos = pos;
	player->color = color;
	player->speed = speed;
	player->diff = diff;

	return player;
}

void draw_player(ptrPlayer p)
{	
	SDL_Rect rect;
	rect.x = (p->pos.c * p->pos.w) + p->pos.c + p->diff.c;
	rect.y = (p->pos.l * p->pos.h) + p->pos.l + p->diff.l;
	//printf("x: %i y: %i\n", rect.x, rect.y);
	rect.w = p->pos.w;
	rect.h = p->pos.h;
	SDL_FillRect(screenSurface, &rect, p->color);
}

void update_player(ptrPlayer p)
{

}