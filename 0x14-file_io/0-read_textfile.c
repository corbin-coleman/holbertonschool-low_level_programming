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
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, lprint, lread, closed;
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
	lprint = write(STDOUT_FILENO, buffer, lread);
	if (lprint == -1)
		return (0);
	closed = close(file);
	if (closed == -1)
		return (0);
	free(buffer);
	return (lread);
}
