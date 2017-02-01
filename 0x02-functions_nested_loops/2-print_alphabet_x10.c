#include "holberton.h"

/**
 * print_alphabet_x10 - Print alpha a-z 10 times
 *
 * Return: 0;
 */
void print_alphabet_x10(void)
{
	int c, l;

	c = 0;
	while (c < 10)
	{
		l = 'a';
		while (l <= 'z')
		{
			_putchar(l);
			l++;
		}
		_putchar('\n');
		c++;
	}
}
