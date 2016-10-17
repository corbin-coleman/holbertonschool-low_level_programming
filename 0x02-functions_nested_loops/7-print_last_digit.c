#include "holberton.h"

/**
 * print_last_digit - print last digit of an integer
 * @n - the integer to print the last digit of
 *
 * Return: Value of last digit
 */
int print_last_digit(int n)
{
	if ((n % 10) < 0)
		n *= -1;
	_putchar((n % 10) + '0');
	return (n % 10);
}
