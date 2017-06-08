#include "maze.h"

void draw_background(SDL_Instance instance)
{
	size_t x;


	for (x = 0; x <= SCREEN_WIDTH; x++)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0xDD, 0xFF, 0xFF);
		SDL_RenderDrawLine(instance.renderer, x, 0, x, SCREEN_HEIGHT / 2);
		SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0, 0xFF, 0xFF);
		SDL_RenderDrawLine(instance.renderer, x, SCREEN_HEIGHT / 2, x, SCREEN_HEIGHT);
	}

}

int main(int argc, char *argv[])
{
	SDL_Instance instance;
	char **map;
	double play_x, play_y, dir_x, dir_y, plane_x, plane_y;

	play_x = 2;
	play_y = 2;
	dir_x = -1;
	dir_y = 0;
	plane_x = 0;
	plane_y = 0.5;
	if (argc < 2)
		return (1);
	map = create_map(argv[1], &play_x, &play_y);
	if (init_instance(&instance) != 0)
		return (1);

	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_background(instance);
		draw_walls(map, play_x, play_y, instance, dir_x, dir_y, plane_x, plane_y);
		SDL_RenderPresent(instance.renderer);
		if (keyboard_events(&play_x, &play_y, &dir_x, &dir_y, &plane_x, &plane_y, map))
			break;
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
