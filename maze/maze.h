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
void fill_screen_by_line(SDL_Instance);
int keyboard_events(keys *);
char **create_map(char *, double_s *, int_s *);
void draw_walls(char **, double_s, SDL_Instance, double_s, double_s);
void choose_color(SDL_Instance, char **, int_s, int);
void rotate(double_s *, double_s *, int);
void movement(keys, double_s *, double_s *, double_s *, char **);
void draw_background(SDL_Instance);
void print_win(void);
int check_win(double_s, int_s, int *);
void plot_grid_points(char **, double_s *, int_s *, size_t, size_t, char *);
void check_key_release_events(SDL_Event, keys *);
int check_key_press_events(SDL_Event, keys *);
double get_wall_dist(char **, double_s *, int_s *, int_s *, double_s *, int *,
		     double_s *, double_s *);
void check_ray_dir(int_s *, double_s *, double_s, int_s, double_s, double_s);
void draw(SDL_Instance, char **, double_s, double_s, double_s);
#endif
