#include "maze.h"

/**
 * check_ray_dir - Which direction is the ray being cast
 * @step: The direction to move
 * @dist_side: Distance to next square on the grid
 * @ray_pos: The start position of the ray being cast
 * @coord: Coordinates on the grid
 * @dist_del: The difference in distance between two sides of a grid
 * @ray_dir: The ray's vector direction
 **/
void check_ray_dir(int_s *step, double_s *dist_side, double_s ray_pos,
		   int_s coord, double_s dist_del, double_s ray_dir)
{
	if (ray_dir.x < 0)
	{
		step->x = -1;
		dist_side->x = (ray_pos.x - coord.x) * dist_del.x;
	}
	else
	{
		step->x = 1;
		dist_side->x = (coord.x + 1.0 - ray_pos.x) * dist_del.x;
	}
	if (ray_dir.y < 0)
	{
		step->y = -1;
		dist_side->y = (ray_pos.y - coord.y) * dist_del.y;
	}
	else
	{
		step->y = 1;
		dist_side->y = (coord.y + 1 - ray_pos.y) * dist_del.y;
	}
}

/**
 * get_wall_dist - Get the distance from the player to the wall
 * @map: 2D Array representing the map of the maze
 * @dist_side: x/y values of the distance to the next side of the map grid
 * @coord: x/y coordinate of the player in the map
 * @step: direction player will move in on the x/y axes
 * @dist_del: The x/y change between two sides of the map grid
 * @hit_side: Hit N/S vs E/W wall
 * @ray_dir: Direction of the ray vector from the player
 * @ray_pos: X/Y coordinate of the ray
 * Return: Distance from player to the wall
 **/
 double get_wall_dist(char **map, double_s *dist_side, int_s *coord,
		      int_s *step, double_s *dist_del, int *hit_side,
		      double_s *ray_dir, double_s *ray_pos)
{
	double wall_dist;
	int hit_wall = 0;

	while (hit_wall == 0)
	{
		if (dist_side->x < dist_side->y)
		{
			dist_side->x += dist_del->x;
			coord->x += step->x;
			*hit_side = 0;
		}
		else
		{
			dist_side->y += dist_del->y;
			coord->y += step->y;
			*hit_side = 1;
		}
		if (map[coord->x][coord->y] > '0')
			hit_wall = 1;
	}
	if (*hit_side == 0)
		wall_dist = (coord->x - ray_pos->x + (1 - step->x) / 2) / ray_dir->x;
	else
		wall_dist = (coord->y - ray_pos->y + (1 - step->y) / 2) / ray_dir->y;
	return (wall_dist);
}
