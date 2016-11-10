#include <stdlib.h>
#include <stdio.h>
/**
 * array_range - Create array of integers filled with numbers from min to max
 * @min: First number in the array
 * @max: Largest number in the array
 *
 * Return: Pointer to new array, NULL if failed
 */
int *array_range(int min, int max)
{
	int *ar;
	int i, size, n;

	if (min > max)
		return (NULL);
	size = max - min;
	ar = malloc((size + 1) * sizeof(int));
	i = 0;
	n = min;
	while (n <= max)
	{
		ar[i] = n;
		i++;
		n++;
	}
	return (ar);
}
