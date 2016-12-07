#include "holberton.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
  * read_textfile - Read an inputted text file and
  * print contents to standard output
  * @filename: Name of the file to read from
  * @letters: The number of characters to read
  *
  * Return: Number of characters actually read, 0 on failure
  */
size_t read_textfile(const char *filename, size_t letters)
{
	int file, lprint, lread;
	char *buffer;

	file = lprint = lread = 0;
	buffer = malloc(letters * sizeof(char));
	if (filename == NULL)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	lread = read(file, buffer, letters);
	if (lread == -1)
		return (0);
	lprint = write(1, buffer, letters);
	if (lprint == -1)
		return (0);
	close(file);
	free(buffer);
	return (lread);
}
