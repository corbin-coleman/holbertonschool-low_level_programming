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

/**
 * struct SDL_Instance - Struct for SDL rendering in window
 * @SDL_Window: The window to display rendering in
 * @SDL_Renderer: The renderer to render graphics with
 **/
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * struct double_s - Struct for x/y values of doubles
 * @x: X value of the object
 * @y: Y value of the object
 **/
typedef struct double_s
{
	double x;
	double y;
} double_s;

/**
 * struct int_s - Struct for x/y values of ints
 * @x: X value of the object
 * @y: Y value of the object
 **/
typedef struct int_s
{
	int x;
	int y;
} int_s;

typedef struct keys
{
	int up;
	int down;
	int right;
	int left;
} keys;

int init_instance(SDL_Instance *);
void fill_screen_by_line(SDL_Instance instance);
int keyboard_events(keys *key_press);
char **create_map(char *file_string, double_s *play);
void draw_walls(char **map, double_s play, SDL_Instance, double_s, double_s);
void choose_color(SDL_Instance, char **map, int_s coord, int hit_side);
void rotate(double_s *plane, double_s *dir, int rot_dir);
void movement(keys key_press, double_s *plane, double_s *dir, double_s *play, char **map);
void draw_background(SDL_Instance);
#endif
