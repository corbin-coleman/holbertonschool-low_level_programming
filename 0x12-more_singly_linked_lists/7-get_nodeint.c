#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Find a node at a given index in a list
 * @head: Pointer to the start of the list
 * @index: The index of the node to look for
 *
 * Return: The node, NULL if the node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;

	count = 0;
	while (count != index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		count++;
	}
	return (head);
}
