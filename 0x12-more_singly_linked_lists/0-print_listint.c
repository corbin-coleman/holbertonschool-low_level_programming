#include <stdio.h>
#include "lists.h"

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
