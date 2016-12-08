#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
  * create_file - Create a file with a specified name and content
  * @filename: Name of the file to create
  * @text_content: Content to read into the file
  *
  * Return: 1 on success, -1 on any failure
  */
int create_file(const char *filename, char *text_content)
{
	int file, len, closed;
	mode_t mode = S_IRUSR | S_IWUSR;

	len = 0;
	if (filename == NULL)
		return (-1);
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		write(file, text_content, len);
	}
	closed = close(file);
	if (closed == -1)
		return (-1);
	return (1);
}
