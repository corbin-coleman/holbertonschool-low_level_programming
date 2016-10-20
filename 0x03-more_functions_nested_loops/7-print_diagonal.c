#include "holberton.h"

/**
 * print_diagonal - Print n number of '\'s
 * @n: Number of '\'s to print
 *
 * Return: Nothing
 */
void print_diagonal(int n)
{
	int c, s;

	c = 0;
	if (n > 0)
	{
		while (c < n)
		{
			s = 0;
			while (s < c)
			{
				_putchar(' ');
				s++;
			}
			_putchar('\\');
			_putchar('\n');
			c++;
		}
	}
	else
		_putchar('\n');
}
