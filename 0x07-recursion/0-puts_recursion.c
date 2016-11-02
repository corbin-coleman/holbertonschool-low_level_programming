#include "holberton.h"

/**
 * _puts_recursion - Print the given string w/ _putchar recursively
 * @s: The given string
 * Return: 0 if succesful exit
 */
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else if (*s == '\0')
	{
		_putchar('\n');
	}
}
