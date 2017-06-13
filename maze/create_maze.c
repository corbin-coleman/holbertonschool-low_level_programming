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
		return (0);
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
 * create_map - Create a 2D array for the map of the maze
 * @file_string: Path to the file containing the representation of the map
 * @play: Player x/y position
 * Return: char ** to a representation of the map, NULL if it fails
 **/
char **create_map(char *file_string, double_s *play)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t line_count, maze_line, char_count, cur_char, bufsize;

	maze_line = 0;
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
			if (line[cur_char] == 'p')
			{
				play->y = cur_char;
				play->x = maze_line;
				maze[maze_line][cur_char] = '0';
			}
			else
				maze[maze_line][cur_char] = line[cur_char];
		}
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
