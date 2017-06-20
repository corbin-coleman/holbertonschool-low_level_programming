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
	int win_value = 0;
	int_s win = {0, 0};
	double_s play = {2, 2};
	double_s dir = {-1, 0};
	double_s plane = {0, 0.5};
	keys key_press = {0, 0, 0, 0};

	if (argc < 2)
		return (1);
	map = create_map(argv[1], &play, &win);
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
		if (keyboard_events(&key_press))
			break;
		movement(key_press, &plane, &dir, &play, map);
		if (check_win(play, win, &win_value))
			break;
		draw(instance, map, play, dir, plane);
	}
	if (win_value)
		print_win();
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
