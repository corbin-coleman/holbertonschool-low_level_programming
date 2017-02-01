#include "holberton.h"
#include <stdlib.h>

/**
 * binary_to_uint - Convert a string representing a binary number to an
 * unsigned int decimal value
 * @b: The string containing the binary
 *
 * Return: 0 if string contains something other than 1 or 0, or
 * if the string is NULL, return the decimal value on success
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, len;
	unsigned int decval;

	i = len = decval = 0;
	if (b == NULL)
		return (0);
	while (b[len] != '\0')
	{
		if (b[len] == '0' || b[len] == '1')
			len++;
		else
			return (0);
	}
	while (i < len)
	{
		decval = decval << 1;
		if (b[i] == '1')
			decval += 1;
		i++;
	}
	return (decval);
}
