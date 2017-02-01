#include <stdio.h>
#include "holberton.h"

/**
 * clear_bit - Set the value of a bit at a given index to 0
 * @n: The unsigned long int to print in binary
 * @index: The index at which to set the value to 0
 *
 * Return: 1 if it succeeds, -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int revnum;
	unsigned long int num;
	unsigned long int count;
	unsigned long int oldn;

	revnum = count = num = 0;
	oldn = *n;
	if (index > 63)
		return (-1);
	while (count < 63)
	{
		revnum = revnum << 1;
		if (count == index)
			revnum += 0;
		else
			revnum += oldn & 1;
		count++;
		oldn = oldn >> 1;
	}
	while (count > 0)
	{
		num = num << 1;
		num += revnum & 1;
		revnum = revnum >> 1;
		count--;
	}
	*n = num;
	return (1);
}
