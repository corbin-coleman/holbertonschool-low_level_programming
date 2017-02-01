#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Free all nodes from a list, and set head to NULL
 * @head: Pointer to the pointer to the start of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *killnode;
	listint_t *current;

	if (head != NULL)
	{
		current = *head;
		while (current != NULL)
		{
			killnode = current;
			current = current->next;
			free(killnode);
		}
		*head = NULL;
	}
}
