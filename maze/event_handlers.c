#include "maze.h"

int keyboard_events(double *play_x, double *play_y, double *dir_x,
		    double *dir_y, double *plane_x, double *plane_y, char **mazeMap)
{
	SDL_Event event;
	double old_dir_x, old_plane_x, rotate_speed, move_speed;

	move_speed = 1;
	rotate_speed = 0.2;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == 0x29)
				return (1);
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				if (mazeMap[(int)(*play_x + *dir_x * move_speed)][(int)*play_y] == '0')
					*play_x += *dir_x * move_speed;
				if (mazeMap[(int)*play_x][(int)(*play_y + *dir_y * move_speed)] == '0')
					*play_y += *dir_y * move_speed;
				break;
			case SDLK_DOWN:
				if (mazeMap[(int)(*play_x - *dir_x * move_speed)][(int)*play_y] == '0')
					*play_x -= *dir_x * move_speed;
				if (mazeMap[(int)*play_x][(int)(*play_y - *dir_y * move_speed)] == '0')
					*play_y -= *dir_y * move_speed;
				break;
			case SDLK_RIGHT:
				old_dir_x = *dir_x;
				*dir_x = *dir_x * cos(-rotate_speed) - *dir_y * sin(-rotate_speed);
				*dir_y = old_dir_x * sin(-rotate_speed) + *dir_y * cos(-rotate_speed);
				old_plane_x = *plane_x;
				*plane_x = *plane_x * cos(-rotate_speed) - *plane_y * sin(-rotate_speed);
				*plane_y = old_plane_x * sin(-rotate_speed) + *plane_y * cos(-rotate_speed);
				break;
			case SDLK_LEFT:
				old_dir_x = *dir_x;
				*dir_x = *dir_x * cos(rotate_speed) - *dir_y * sin(rotate_speed);
				*dir_y = old_dir_x * sin(rotate_speed) + *dir_y * cos(rotate_speed);
				old_plane_x = *plane_x;
				*plane_x = *plane_x * cos(rotate_speed) - *plane_y * sin(rotate_speed);
				*plane_y = old_plane_x * sin(rotate_speed) + *plane_y * cos(rotate_speed);
				break;
			}
		}
	}
	return (0);
}
