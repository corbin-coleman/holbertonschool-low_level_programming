#include "holberton.h"

/**
 * print_numbers - Print numbers 0 - 9
 *
 * Return: Nothing
 */
void print_numbers(void)
{
	int n;

	n = 0;
	while (n <= 9)
	{
		_putchar(n + '0');
		n++;
	}
	_putchar('\n');
}
