#include "maze.h"

/**
 * rotate - Rotate the camera left/right
 * @plane: The projection plane
 * @dir: The players direction vector
 * @rot_dir: Rotation direction, -1 for right, 1 for left
 **/
void rotate(double_s *plane, double_s *dir, int rot_dir)
{
	double rotate_speed, old_dir_x, old_plane_x;

	rotate_speed = 0.03 * rot_dir;
	old_dir_x = dir->x;
	dir->x = dir->x * cos(rotate_speed) - dir->y * sin(rotate_speed);
	dir->y = old_dir_x * sin(rotate_speed) + dir->y * cos(rotate_speed);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(rotate_speed) - plane->y * sin(rotate_speed);
	plane->y = old_plane_x * sin(rotate_speed) + plane->y * cos(rotate_speed);
}

void movement(keys key_press, double_s *plane, double_s *dir, double_s *play,
	      char **map)
{
	double move_speed = 0.07;

	if (key_press.right)
	{
		rotate(plane, dir, -1);
	}
	if (key_press.left)
		rotate(plane, dir, 1);
	if (key_press.up)
	{
		if (map[(int)(play->x + dir->x * move_speed)][(int)play->y] == '0')
			play->x += dir->x * move_speed;
		if (map[(int)play->x][(int)(play->y + dir->y * move_speed)] == '0')
			play->y += dir->y * move_speed;
	}
	if (key_press.down)
	{
		if (map[(int)(play->x - dir->x * move_speed)][(int)play->y] == '0')
			play->x -= dir->x * move_speed;
		if (map[(int)play->x][(int)(play->y - dir->y * move_speed)] == '0')
			play->y -= dir->y * move_speed;
	}
}
