#include "maze.h"

/**
 * check_key_release_events - Check for what key was released
 * @event: The event elemenet containing which key was released
 * @key_press: Struct containing significant keys to check if they were pressed
 **/
void check_key_release_events(SDL_Event event, keys *key_press)
{
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
}

/**
 * check_key_press_events - Check the key that was pressed down
 * @event: The event element containing which key was pressed
 * @key_press: Struct containing significant keys to check if they were pressed
 * Return: 1 if ESC is pressed, 0 otherwise
 **/
int check_key_press_events(SDL_Event event, keys *key_press)
{
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
	return (0);
}

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
			if (check_key_press_events(event, key_press))
				return (1);
			break;
		case SDL_KEYUP:
			check_key_release_events(event, key_press);
			break;
		default:
			break;
		}
	}
	return (0);
}
