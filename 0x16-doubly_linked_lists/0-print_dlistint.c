#include "lists.h"
/**
  * print_dlistint - Print all elements of a list
  * @h: Pointer to the first element in a list
  * Return: The number of elements in the list
  */
size_t print_dlistint(const dlistint_t *h)
{
	size_t elements;

	elements = 0;
	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
		while (h != NULL)
		{
			printf("%d\n", h->n);
			elements++;
			h = h->next;
		}
	}
	return (elements);
}
