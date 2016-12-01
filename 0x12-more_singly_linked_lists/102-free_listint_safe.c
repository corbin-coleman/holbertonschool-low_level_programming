#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Free a list that may or may not loop,
 * set start of list to NULL
 * @h: Pointer to pointer to the start of the list
 * Return: Size of the list that has been freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *killnode;
	listint_t *current;
	listadd_t *headadd;
	listadd_t *checker;
	size_t count;

	count = 0;
	current = *h;
	headadd = NULL;
	while (current != NULL)
	{
		killnode = current;
		add_nodeaddress(&headadd, current);
		checker = headadd;
		while (checker != NULL)
		{
			if (current->next == checker->address)
			{
				free(current);
				free_listadd(headadd);
				headadd = NULL;
				*h = NULL;
				return (count);
			}
			checker = checker->next;
		}
		current = current->next;
		free(killnode);
		count++;
	}
	free_listadd(headadd);
	headadd = NULL;
	*h = NULL;
	return (count);
}
