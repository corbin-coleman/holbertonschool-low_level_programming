#include "holberton.h"
#include <stdio.h>
/**
 * print_array - Print a number of items in an array of integers
 * @a: The array to print
 * @n: The number of items from the array to print
 *
 * Return: Nothing
 */
void print_array(int *a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d", *(a + i));
		if (i != n - 1)
			printf(", ");
		i++;
	}
	putchar('\n');
}
