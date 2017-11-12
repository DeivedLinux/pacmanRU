#include "Game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



bool run(void* parameters)
{
	SDL_Event event;

	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_Quit)
		{
			return false;
		}
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
		            case SDLK_ESCAPE:
		                    
		                return false;
		                break;
		            case SDLK_RETURN:
		           	
		           	break;
	                
				}     				
		}
	}

	

	return true;
}