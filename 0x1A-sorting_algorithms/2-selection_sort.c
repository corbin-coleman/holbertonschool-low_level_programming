#include "sort.h"

/**
 * selection_sort - Find the lowest number and put it in front
 * @array: Array to sort
 * @size: Size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	int temp;
	int compare;
	int min_index;
	int swapped;

	if (array == NULL)
		return;
	while(i < size)
	{
		j = i;
		compare = array[i];
		swapped = 0;
		while(j < size)
		{
			if(compare > array[j])
			{
				compare = array[j];
				min_index = j;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 1)
		{
			temp = array[i];
			array[i] = compare;
			array[min_index] = temp;
			print_array(array, size);
		}
		i++;
	}
}
