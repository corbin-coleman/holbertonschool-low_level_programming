#include "holberton.h"

/**
 * print_triangle - Print triangle of given size
 * @size: Size of triangle
 *
 * Return: Nothing
 */
void print_triangle(int size)
{
	int c, s;

	if (size > 0)
	{
		c = 0;
		while (c < size)
		{
			s = size - 1;
			while (s > c)
			{
				_putchar(' ');
				s--;
			}
			s = 0;
			while (s < c + 1)
			{
				_putchar('#');
				s++;
			}
			_putchar('\n');
			c++;
		}
	}
	else
		_putchar('\n');
}
