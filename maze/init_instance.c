#include "maze.h"

/**
 * init_instance - Initialize an SDL_Instance w/ a window & renderer
 * @instance: The instance to initialize
 * Return: 1 on failure, 0 for success
 **/
int init_instance(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);

	instance->window = SDL_CreateWindow("MAZE", SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (instance->window == NULL)
	{
		SDL_Quit();
		return (1);
	}
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
						SDL_RENDERER_ACCELERATED |
						SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}
	return (0);
}
