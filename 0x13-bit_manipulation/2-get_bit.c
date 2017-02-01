#include "holberton.h"

/**
 * get_bit - Return the value of a bit at a given index
 * @n: The number to find the bit value from
 * @index: The index of the bit value to look for
 *
 * Return: Value of the bit at the index, -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int count;

	count = 0;
	if (index > 63)
		return (-1);
	while (n > 0)
	{
		if (count == index)
			return (n & 1);
		n = n >> 1;
		count++;
	}
	if (count < index)
		return (0);
	return (-1);
}
