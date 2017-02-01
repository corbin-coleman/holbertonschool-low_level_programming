#include <stdlib.h>

/**
 * int_index - Search for an integer
 * @array: Array to search through
 * @size: Size of array
 * @cmp: Compare function to use
 *
 * Return: Index of first element that cmp does not return 0, -1 if
 * no elements are reached or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array == NULL)
		return (-1);
	if (cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		i++;
	}
	return (-1);
}
