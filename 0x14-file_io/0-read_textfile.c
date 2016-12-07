#include "holberton.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
  * read_textfile - define function
  * @void: describe argument
  * Return: 0 on success
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
	lread = read(file, buffer,letters);
	if (lread == -1)
		return (0);
	lprint = write(1, buffer, letters);
	if (lprint == -1)
		return (0);
	close(file);
	return (lread);
}
