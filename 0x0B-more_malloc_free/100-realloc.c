#include <stdlib.h>

/**
 * _memcpy - Copy n bytes from memory area src to memory area dest
 * @dest: Memory area to copy to
 * @src: Memory area to copy from
 * @n: Amount to copy from memory area
 *
 * Return: Pointer to area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

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
	unsigned int min;

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size < old_size)
		min = new_size;
	else
		min = old_size;
	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);
	nptr = _memcpy(nptr, ptr, min);
	free(ptr);
	return (nptr);
}
