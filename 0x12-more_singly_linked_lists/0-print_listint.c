#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Print out the integer contained in a listint_t node
 * @h: Pointer to the start of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t nodecount;

	nodecount = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		nodecount++;
		h = h->next;
	}
	return (nodecount);
}
