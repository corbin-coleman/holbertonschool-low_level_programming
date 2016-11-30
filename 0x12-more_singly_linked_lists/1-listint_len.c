#include <stdio.h>
#include "lists.h"

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
