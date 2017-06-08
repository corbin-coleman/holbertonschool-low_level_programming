#ifndef MAZE_H
#define MAZE_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SCREEN_HEIGHT 768
#define SCREEN_WIDTH 1024

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int quit_events();
void fill_screen_by_line(SDL_Instance instance);
int keyboard_events(double *play_x, double *play_y, double *dir_x,
		    double *dir_y, double *plane_x, double *plane_y, char **mazeMap);
char **create_map(char *file_string, double *play_x, double *play_y);
void draw_walls(char **map, double play_x, double play_y, SDL_Instance instances,
		double dir_x, double dir_y, double plane_x, double plane_y);
void choose_color(SDL_Instance, char **map, int map_x, int map_y, int hit_side);
#endif
