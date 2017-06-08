#include "maze.h"

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

size_t get_char_count(char *line)
{
	size_t char_count = 0;

	while (line[char_count] != '\0')
		char_count++;
	return (char_count);
}

char **create_map(char *file_string, double *play_x, double *play_y)
{
	FILE *maze_file;
	char *line = NULL;
	char **maze;
	size_t bufsize;
	ssize_t read = 0;
	size_t line_count, maze_line, char_count, cur_char;

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
		cur_char = 0;
		char_count = get_char_count(line);
		maze[maze_line] = malloc(sizeof(char) * char_count + 1);
		if (maze == NULL)
			return (NULL);
		while (cur_char < char_count)
		{
			if (line[cur_char] == 'p')
			{
				*play_y = cur_char;
				*play_x = maze_line;
				maze[maze_line][cur_char] = '0';
			}
			else
				maze[maze_line][cur_char] = line[cur_char];
			cur_char++;
		}
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
