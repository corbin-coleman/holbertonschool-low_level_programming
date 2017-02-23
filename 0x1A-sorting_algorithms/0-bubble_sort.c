#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - Sort by swapping largest items to end of array
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int swapped;
	size_t temp;
	size_t tempsize;

	if (array == NULL)
		return;
	tempsize = size;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < tempsize - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swapped = 1;
			}
			j++;
		}
		tempsize = j;
	}
}
