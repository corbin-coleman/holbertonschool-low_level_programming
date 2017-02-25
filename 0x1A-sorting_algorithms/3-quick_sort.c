#include "sort.h"
/**
 *
 *
 *
 *
 */
void quick_sort(int *array, size_t size)
{
	int *whole_array;
	size_t full_size;

	if (array == NULL)
		return;
	whole_array = &array[0];
	full_size = size;
	quick_sort_really(array, size, whole_array, full_size);
}

void quick_sort_really(int *array, size_t size, int *whole_array, size_t full_size)
{
	size_t part;

	part = 0;

	if (size > 1)
	{
		part = partitioner(array, size, whole_array, full_size);
		quick_sort_really(&array[0], part, whole_array, full_size);
		quick_sort_really(&array[part], size - part, whole_array, full_size);
	}

}

size_t partitioner(int *array, size_t size, int *whole_array, size_t full_size)
{
	int pivot;
	long front;
	long end;
	int temp;

	pivot = array[size - 1];
	front = -1;
	end = size;


	while (1)
	{
		do
		{
			front++;
		} while (array[front] < pivot);
		do
		{
			end--;
		} while (array[end] > pivot);

		if (front >= end)
		{
			return ((size_t) front);
		}
		temp = array[front];
		array[front] = array[end];
		array[end] = temp;
		print_array(whole_array, full_size);
	}
	return (end);
}
