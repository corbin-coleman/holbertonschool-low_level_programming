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

/**
 * struct keys - Struct to keep track of key presses
 * @up: Is up pressed (1) or not (0)
 * @down: Is down pressed (1) or not (0)
 * @right: Is right pressed (1) or not (0)
 * @left: Is left pressed (1) or not (0)
 **/
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
char **create_map(char *file_string, double_s *play, int_s *win);
void draw_walls(char **map, double_s play, SDL_Instance, double_s, double_s);
void choose_color(SDL_Instance, char **map, int_s coord, int hit_side);
void rotate(double_s *plane, double_s *dir, int rot_dir);
void movement(keys key_press, double_s *plane, double_s *dir, double_s *play,
	      char **map);
void draw_background(SDL_Instance);
void print_win(void);
int check_win(double_s play, int_s win, int *win_value);
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char,
		      size_t maze_line, char *line);
void check_key_release_events(SDL_Event event, keys *key_press);
int check_key_press_events(SDL_Event event, keys *key_press);
#endif
