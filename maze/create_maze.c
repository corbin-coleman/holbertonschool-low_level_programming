#include "maze.h"

/**
 * get_line_count - Get the number of lines in a file
 * @file_string: The path to the file
 * Return: The number of lines found in the file, 0 for failure
 **/
size_t get_line_count(char *file_string)
{
	FILE *maze_file;
	char *line;
	ssize_t read = 0;
	size_t lines, line_len;

	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
	{
		printf("File does not exist\n");
		return (0);
	}
	lines = 0;
	read = getline(&line, &line_len, maze_file);
	if (read == -1)
		return (0);
	lines++;
	while (read != -1)
	{
		read = getline(&line, &line_len, maze_file);
		lines++;
	}
	fclose(maze_file);
	return (lines);
}

/**
 * get_char_count - Counts characters in a string
 * @line: The string to count
 * Return: The number of characters counted
 **/
size_t get_char_count(char *line)
{
	size_t char_count = 0;

	while (line[char_count] != '\0')
		char_count++;
	return (char_count);
}

/**
 * plot_grid_points - Plot the specific points in the maze
 * @maze: The 2D array representing the map grid
 * @play: The player's x/y position
 * @win: The x/y cooridinates of the win square
 * @cur_char: The current character in the line being read
 * @maze_line: The line in the maze currently being created
 * @line: The line being read from the file
 **/
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char,
		      size_t maze_line, char *line)
{
	static int win_found = 0;

	if (line[cur_char] == 'p')
	{
		play->y = cur_char;
		play->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else if (line[cur_char] == 'w')
	{
		win_found = 1;
		win->y = cur_char;
		win->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else
	{
		if (line[cur_char] == '0' && win_found == 0)
		{
			win->y = cur_char;
			win->x = maze_line;
		}
		maze[maze_line][cur_char] = line[cur_char];
	}
}

/**
 * create_map - Create a 2D array for the map of the maze
 * @file_string: Path to the file containing the representation of the map
 * @play: Player x/y position
 * @win: The x/y cooridinate of the winning space
 * Return: char ** to a representation of the map, NULL if it fails
 **/
char **create_map(char *file_string, double_s *play, int_s *win)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t line_count, maze_line, char_count, cur_char, bufsize, win_spot;

	win_spot = maze_line = 0;
	line_count = get_line_count(file_string);
	if (line_count == 0)
		return (NULL);
	maze = malloc(sizeof(int *) * line_count);
	if (maze == NULL)
		return (NULL);
	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
		return (NULL);
	read = getline(&line, &bufsize, maze_file);
	while (read != -1)
	{
		char_count = get_char_count(line);
		maze[maze_line] = malloc(sizeof(char) * char_count + 1);
		if (maze == NULL)
			return (NULL);
		for (cur_char = 0; cur_char < char_count; cur_char++)
		{
			plot_grid_points(maze, play, win, cur_char, maze_line, line);
		}
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
