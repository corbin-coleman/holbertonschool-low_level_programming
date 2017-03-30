#include "search_algos.h"

/**
 * print_search_array - Print the array that's being searched
 * @array: The array being searched
 * @start: Index we want to start at
 * @end: Index to finish at
 **/
void print_search_array(int *array, int start, int end)
{
	int i;

	i = start;
	printf("Searching in array: ");
	while (i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * binary_search - Use a binary search to find the given value in an array
 * @array: Array to search
 * @size: Size of the given array
 * @value: Value to search for
 * Return: The first index the value appears, or -1 if the value can't be
 * found
 **/
int binary_search(int *array, size_t size, int value)
{
	int left, right, compare;

	left = compare = 0;
	right = size - 1;

	while (left <= right)
	{
		print_search_array(array, left, right);
		compare = (left + right) / 2;
		if (array[compare] == value)
			return (compare);
		else if (array[compare] > value)
		{
			right = compare;
		}
		else if (array[compare] < value)
		{
			left = compare + 1;
		}
	}
	return (-1);
}
