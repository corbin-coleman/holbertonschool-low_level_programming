#include "holberton.h"

/**
 * print_number - Print the given int one digit at a time
 * @n: The integer to print
 */
void print_number(int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	else if (n > 0)
		n *= -1;
	else
		_putchar('-');
	if ((n / 10) != 0)
	{
		print_number((n / 10) * -1);
	}
	_putchar((n % 10) * -1 + '0');
}
