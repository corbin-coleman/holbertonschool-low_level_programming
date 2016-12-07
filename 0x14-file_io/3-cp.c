#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * file1fail - Print error message if can't read file
 * @file: Name of the file that can't be read
 */
void file1fail(char *file)
{
	dprintf(2, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * file2fail - Print error message if can't write to file
 * @file: Name of the file that can't be write to
 */
void file2fail(char *file)
{
	dprintf(2, "Error: Can't write to file %s\n", file);
	exit(99);
}

/**
  * main - copy the content of one file to another
  * @argc: Number of arguments received
  * @argv: Array of arguments received
  *
  * Return: 0 on success
  */
int main(int argc, char *argv[])
{
	int file1, file2, file1rd, file2wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		file1fail(argv[1]);
	}
	file2 = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (file2 == -1)
	{
		file2fail(argv[2]);
	}
	file1rd = read(file1, buffer, 1024);
	if (file1rd == -1)
	{
		file1fail(argv[1]);
	}
	while (file1rd > 0)
	{
		file2wr = write(file2, buffer, file1rd);
		if (file2wr == -1)
		{
			file2fail(argv[2]);
		}
		file1rd = read(file1, buffer, 1024);
		if (file1rd == -1)
		{
			file1fail(argv[1]);
		}
	}
	close(file1);
	close(file2);
	return (0);
}
