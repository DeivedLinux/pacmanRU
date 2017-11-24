#include "GameManager.h"
#include <stdbool.h>
#include <SDL2/SDL.h>

bool run(void* parameters)
{
	SDL_Event event;
	int quit = 0;

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