#include "maze.h"

/**
 * keyboard_events - Check for key presses
 * @key_press: Struct for up/down/left/right key presses
 * Return: 0 for standard events, 1 for exit events
 **/
int keyboard_events(keys *key_press)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == 0x29)
				return (1);
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				key_press->up = 1;
				break;
			case SDLK_DOWN:
				key_press->down = 1;
				break;
			case SDLK_RIGHT:
				key_press->right = 1;
				break;
			case SDLK_LEFT:
				key_press->left = 1;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				key_press->up = 0;
				break;
			case SDLK_DOWN:
				key_press->down = 0;
				break;
			case SDLK_RIGHT:
				key_press->right = 0;
				break;
			case SDLK_LEFT:
				key_press->left = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	return (0);
}
