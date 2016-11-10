#include <stdlib.h>

/**
 * _realloc - Reallocate a memory block using malloc
 * @ptr: Old memory block
 * @old_size: Size of of old memory block
 * @new_size: Size the new memory block should be
 *
 * Return: Pointer to new memory space, NULL if it fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}
	if (ptr != NULL && new_size == 0)
		return (NULL);
	if (new_size == old_size)
		return (ptr);
	/*if (new_size < old_size)
		min = new_size;
	else
	min = old_size;*/
	nptr = malloc((new_size + 1) * sizeof(char));
	if (nptr == NULL)
		return (NULL);
	return (nptr);
}
