#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_list - Print all elements of a list_t list
 * @h: Pointer to the first element of the list
 *
 * Return: Number of elements in the list
 */
size_t print_list(const list_t *h)
{
	size_t count;

	if (h == NULL)
		return (0);
	count = 1;
	printf("[%d] %s\n", h->len, h->str);
	if (h->next != NULL)
		count += print_list(h->next);
	return (count);
}
