#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns number of elements in a list
 * @h: Pointer to first element in list
 *
 * Return: Number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t count;

	if (h == NULL)
		return (0);
	count = 0;
	count++;
	if (h->next != NULL)
		count += list_len(h->next);
	return (count);
}
