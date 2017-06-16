#include "maze.h"

/**
 * main - The main function to run the maze game
 * @argc: The number of arguments passed to the program
 * @argv: All the arguments passed to the program
 * Return: 1 if failure, 0 if successful exit
 **/
int main(int argc, char *argv[])
{
	SDL_Instance instance;
	char **map;
	double_s play = {2, 2};
	double_s dir = {-1, 0};
	double_s plane = {0, 0.5};
	keys key_press = {0, 0, 0, 0};

	if (argc < 2)
		return (1);
	map = create_map(argv[1], &play);
	if (map == NULL)
	{
		printf("Unable to create map\n");
		return (1);
	}
	if (init_instance(&instance) != 0)
	{
		printf("Unable to initialize SDL_Instance\n");
		return (1);
	}
	while (1)
	{
/*		key_press.up = 0;
		key_press.down = 0;
		key_press.left = 0;
		key_press.right = 0;*/
		if (keyboard_events(&key_press))
			break;
		movement(key_press, &plane, &dir, &play, map);
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_background(instance);
		draw_walls(map, play, instance, dir, plane);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
