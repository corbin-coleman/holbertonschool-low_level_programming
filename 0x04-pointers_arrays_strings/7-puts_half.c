#include "holberton.h"

/**
 * puts_half - Print the second half of a string
 * @str: Given string to print half of
 *
 * Return: Nothing
 */
void puts_half(char *str)
{
	int i, h;

	i = h = 0;
	while (*(str + i) != 0)
	{
		i++;
	}
	if (i % 2 == 0)
		i /= 2;
	else
	{
		h = (i - 1) / 2;
		i -= h;
	}
	while (*(str + i) != 0)
	{
		_putchar(*(str + i));
		i++;
	}
	_putchar('\n');
}
