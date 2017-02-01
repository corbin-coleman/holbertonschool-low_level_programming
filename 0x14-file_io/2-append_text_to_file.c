#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
  * append_text_to_file - Open a file and add text to the end of the file
  * @filename: File to open and append to
  * @text_content: Text to append to file
  *
  * Return: 1 on success, -1 on failures
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, len, wrote;

	len = 0;
	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		wrote = write(file, text_content, len);
		if (wrote == -1)
			return (-1);
	}
	close(file);
	return (1);
}
