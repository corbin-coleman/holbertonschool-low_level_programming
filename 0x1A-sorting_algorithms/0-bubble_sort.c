#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int swapped;
	size_t temp;
	size_t tempsize;

	tempsize = size;
	swapped = 1;
	while(swapped)
	{
		swapped = 0;
		j = 0;
		while(j < tempsize - 1)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swapped = 1;
			}
			j++;
		}
		tempsize = j;
	}
}
