#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Delete the first item in a list
 * @head: Pointer to the pointer to the start of the list
 *
 * Return: The value stored in the node
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	current = *head;
	if (current == NULL)
		return (0);
	n = current->n;
	*head = current->next;
	free(current);
	return (n);
}
