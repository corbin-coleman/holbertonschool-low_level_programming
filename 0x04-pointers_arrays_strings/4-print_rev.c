#include "holberton.h"

/**
 * print_rev - Print a string in rev
 * @s: String to print
 *
 * Return: nothing
 */
void print_rev(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != 0)
	{
		i++;
	}
	i -= 1;
	while (i >= 0)
	{
		_putchar(*(s + i));
		i--;
	}
	_putchar('\n');
}
