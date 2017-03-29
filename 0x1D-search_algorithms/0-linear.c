#include "search_algos.h"

/**
 * linear_search - Search linearly through an array for a value
 * @array: Array to search
 * @size: The size of the array
 * @value: The value to be searched through
 * Return: First index that the value is found, -1 if value not found
 **/
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
