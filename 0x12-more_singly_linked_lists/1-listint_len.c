#include <stdio.h>
#include "lists.h"

/**
 * listint_len - Find the length of a list
 * @h: The pointer to the start of the list
 *
 * Return: Number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t nodecount;

	nodecount = 0;
	while (h != NULL)
	{
		nodecount++;
		h = h->next;
	}
	return (nodecount);
}
