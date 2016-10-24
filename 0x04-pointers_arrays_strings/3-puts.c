#include "holberton.h"
/**
 * _puts - Print given string
 * @str: String to print
 *
 * Return: 0
 */
void _puts(char *str)
{
	int i;

	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
	_putchar('\n');
}
