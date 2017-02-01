#include "holberton.h"

/**
 * print_square - Print a nxn square of #
 * @size: Size of square sides
 *
 * Return: Nothing
 */
void print_square(int size)
{
	int x, y;

	if (size > 0)
	{
		y = 0;
		while (y < size)
		{
			x = 0;
			while (x < size)
			{
				_putchar('#');
				x++;
			}
			_putchar('\n');
			y++;
		}
	}
	else
		_putchar('\n');
}
