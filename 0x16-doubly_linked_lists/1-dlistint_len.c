#include "lists.h"
/**
  * dlistint_len - Return the number of elements in a list
  * @h: Pointer to the first element of the list
  * Return: The number of elements on success
  */
size_t dlistint_len(const dlistint_t *h)
{
	size_t elements;

	elements = 0;
	if (h == NULL)
		return (0);
	while (h->prev != NULL)
		h = h->prev;
	while (h != NULL)
	{
		elements++;
		h = h->next;
	}
	return (elements);
}
