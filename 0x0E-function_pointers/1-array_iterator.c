#include <stdlib.h>

/**
 * array_iterator - Execute a function as a paramter on each element in array
 * @array: Given array to iterate through
 * @size: Size of array
 * @action: Function to call on array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
