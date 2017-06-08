#include "maze.h"

/**
 * check_ray_dir - Which direction is the ray being cast
 * @step_x: The direction to move on the x axis
 * @step_y: The direction to move on the y axis
 * @dist_side_x: X distance to the next square on the grid
 * @dist_side_y: Y distance to the next square on the grid
 * @ray_pos_x: X position of the ray being cast
 * @ray_pos_y: Y position of the ray being cast
 * @map_x: X coordinate on the map
 * @map_y: Y coordinate on the map
 * @dist_delta_x: The difference in distance between two x sides of a grid
 * @dist_delta_y: The difference in distance between two y sides of a grid
 * @ray_dir_x: The ray's x vector direction
 * @ray_dir_y: The ray's y vector direction
 **/
void check_ray_dir(int *step_x, int *step_y, double *dist_side_x,
		   double *dist_side_y, double ray_pos_x, double ray_pos_y,
		   int map_x, int map_y, double dist_delta_x,
		   double dist_delta_y, double ray_dir_x, double ray_dir_y)
{
		if (ray_dir_x < 0)
		{
			*step_x = -1;
			*dist_side_x = (ray_pos_x - map_x) * dist_delta_x;
		}
		else
		{
			*step_x = 1;
			*dist_side_x = (map_x + 1.0 - ray_pos_x) * dist_delta_x;
		}
		if (ray_dir_y < 0)
		{
			*step_y = -1;
			*dist_side_y = (ray_pos_y - map_y) * dist_delta_y;
		}
		else
		{
			*step_y = 1;
			*dist_side_y = (map_y + 1 - ray_pos_y) * dist_delta_y;
		}
}

/**
 * draw_walls - Use Raycasting to draw the walls of the maze
 * @map: A 2D array representing the locations of walls and the player
 * @play_x: The player's current x position
 * @play_y: The player's current y position
 * @instance: An SDL_Instance that contains the window and renderer objects
 * @dir_x: The x direction vector of the player
 * @dir_y: The y direction vector of the player
 * @plane_x: The x value of the camera/projection plane
 * @plane_y: The y value of the camera/projection plane
 **/
void draw_walls(char **map, double play_x, double play_y,
		SDL_Instance instance, double dir_x, double dir_y,
		double plane_x, double plane_y)
{
	double ray_pos_x, ray_pos_y, ray_dir_x, ray_dir_y, dist_side_y, dist_side_x,
		dist_delta_x, dist_delta_y, wall_dist, cam_x;
	int wall_height, wall_start, wall_end, screen_x, hit_side, hit_wall,
		step_x, step_y, map_x, map_y;

	hit_wall = 0;
	for (screen_x = 0; screen_x < SCREEN_WIDTH; screen_x++)
	{
		cam_x = 2 * screen_x / (double)SCREEN_WIDTH - 1;
		ray_pos_x = play_x;
		ray_pos_y = play_y;
		ray_dir_x = dir_x + plane_x * cam_x;
		ray_dir_y = dir_y + plane_y * cam_x;
		map_x = (int)ray_pos_x;
		map_y = (int)ray_pos_y;
		dist_delta_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
		dist_delta_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
		hit_wall = 0;
		check_ray_dir(&step_x, &step_y, &dist_side_x, &dist_side_y,
			      ray_pos_x, ray_pos_y, map_x, map_y, dist_delta_x,
			      dist_delta_y, ray_dir_x, ray_dir_y);
		while (hit_wall == 0)
		{
			if (dist_side_x < dist_side_y)
			{
				dist_side_x += dist_delta_x;
				map_x += step_x;
				hit_side = 0;
			}
			else
			{
				dist_side_y += dist_delta_y;
				map_y += step_y;
				hit_side = 1;
			}
			if (map[map_x][map_y] > '0')
				hit_wall = 1;
		}
		if (hit_side == 0)
			wall_dist = (map_x - ray_pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - ray_pos_y + (1 - step_y) / 2) / ray_dir_y;
		wall_height = (int)(SCREEN_HEIGHT / wall_dist);
		wall_start = -wall_height / 2 + SCREEN_HEIGHT / 2;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = wall_height / 2 + SCREEN_HEIGHT / 2;
		if (wall_end >= SCREEN_HEIGHT)
			wall_end = SCREEN_HEIGHT - 1;
		choose_color(instance, map, map_x, map_y, hit_side);
		SDL_RenderDrawLine(instance.renderer, screen_x, wall_start,
				   screen_x, wall_end);
	}
}

/**
 * choose_color - Choose the color to draw for the wall
 * @instance: An SDL_Instance containing the renderer to draw with
 * @map: 2D array representing the map of the maze
 * @map_x: Current x coordinate in map
 * @map_y: Current y coordinate in map
 * @hit_side: Is the wall N/S or E/W
 **/
void choose_color(SDL_Instance instance, char **map, int map_x, int map_y,
		  int hit_side)
{
		switch (map[map_x][map_y])
		{
		case '1':
			/* Red walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x88, 0, 0, 0xFF);
			break;
		case '2':
			/* Green Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0, 0xFF, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0, 0x88, 0, 0xFF);
			break;
		case '3':
			/* Blue Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0xFF, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0x88, 0xFF);
			break;
		case '4':
			/* Yellow Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x88, 0x88, 0, 0xFF);
			break;
		default:
			/* White Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x88, 0x88, 0x88, 0xFF);
			break;
		}
}
