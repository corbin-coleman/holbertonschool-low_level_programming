#include "search_algos.h"

/**
 * jump_search - Use a jump search algorithm to find a given value
 * @array: Array to search through
 * @size: Size of the array
 * @value: Value to search for
 * Return: The index of the found value, -1 if value not found
 **/
int jump_search(int *array, size_t size, int value)
{
	size_t step, previous_step;

	previous_step = 0;
	step = 0;

	if (array == NULL)
		return (-1);
	while (array[step] < value && step < size)
	{
		printf("Value checked array[%lu] = [%d]\n", step,
		       array[step]);
		previous_step = step;
		step += sqrt(size);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", previous_step,
	       step);
	while (array[previous_step] <= (int) step && previous_step < size)
	{
		printf("Value checked array[%lu] = [%d]\n", previous_step,
		       array[previous_step]);
		if (array[previous_step] == value)
			return (previous_step);
		if (previous_step == low(step, size))
			return (-1);
		previous_step++;
	}
	return (-1);
}
