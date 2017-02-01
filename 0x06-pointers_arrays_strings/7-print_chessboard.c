#include "holberton.h"

/**
 * print_chessboard - Print a chessboard
 * @a: Given array holding chessboard
 */

void print_chessboard(char (*a)[8])
{
	unsigned int i, j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			_putchar(a[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
